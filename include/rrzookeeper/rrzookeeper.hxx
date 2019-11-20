//===-- rrZookeeper Wrapper -------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-09-18
/// \since 2019-05-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRZOOKEEPER_HXX_
#define RRZOOKEEPER_HXX_

#include <bitset>
#include <chrono>
#include <list>
#include <memory>
#include <optional>
#include <string>

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable: 4201)
#endif
#include <zookeeper.h>
#ifdef _MSC_VER
# pragma warning(pop)
#endif

namespace rrzookeeper {

class client {
public:
    enum class event { created, deleted, changed, child, session, not_watching, unknown };
    inline static event ztype(int type) noexcept;
    enum class state { closed, connecting, association, connected, expired_session, auth_failed, invalid };
    inline static state zstate(int state) noexcept;
    inline static std::optional<std::string> zpath(const char *path);

    struct create {
    private:
        enum { _ephemeral, _sequence, _recursive, _set_if_exists, _ignore_if_exists, _count };
    public:
        using flag = std::bitset<_count>;
        static constexpr flag ephemeral {1uLL << _ephemeral};                ///< 创建临时节点
        static constexpr flag sequence {1uLL << _sequence};                  ///< 创建顺序节点
        static constexpr flag recursive {1uLL << _recursive};                ///< 若节点悬空，则递归创建中间节点，然后创建该节点
        static constexpr flag set_if_exists {1uLL << _set_if_exists};        ///< 若节点已存在，则变更该节点内容
        static constexpr flag ignore_if_exists {1uLL << _ignore_if_exists};  ///< 若节点已存在，则忽略本次操作
        static constexpr flag force {1uLL << _recursive | 1uLL << _set_if_exists};
    };
    struct set {
    private:
        enum { _create_if_not_exists, _count };
    public:
        using flag = std::bitset<_count>;
        static constexpr flag create_if_not_exists {1uLL << _create_if_not_exists};  ///< 若节点不存在，则递归创建该节点
        static constexpr flag force {1uLL << _create_if_not_exists};
    };
    struct deleta {
    private:
        enum { _traversal, _ignore_if_not_exists, _count };
    public:
        using flag = std::bitset<_count>;
        static constexpr flag traversal {1uLL << _traversal};                        ///< 若节点挂载有子节点，则遍历删除子节点，然后删除该节点
        static constexpr flag ignore_if_not_exists {1uLL << _ignore_if_not_exists};  ///< 若节点不存在，则忽略本次操作
        static constexpr flag force {1uLL << _traversal | 1uLL << _ignore_if_not_exists};
    };

    typedef void(*event_callback_t)(client *self, const event &type, const state &state, const std::optional<std::string> &path, void *p_user_data);

    inline explicit client(ZooLogLevel log_level = ZOO_LOG_LEVEL_ERROR) noexcept;
    inline explicit client(const client &) = delete;
    inline client &operator=(const client &) = delete;
    inline explicit client(client &&) noexcept = default;
    inline client &operator=(client &&) noexcept = default;
    inline virtual ~client() noexcept;

    /// \brief 设定事件回调。
    inline void set_event_callback(event_callback_t callback = nullptr,
                                   void *p_user_data = nullptr);

    /// \brief 连接到服务。
    inline void connect(const std::string &host,
                        const std::chrono::milliseconds &timeout = std::chrono::seconds {10});
    inline void reconnect();
    inline void disconnect();

    /// \brief 创建节点。
    /// \param path  节点路径。
    /// \param value 节点值。
    /// \param flags 额外标记。
    /// \returns 节点路径，主要用于 `sequence` 标记生效时的情形。
    inline std::string create(const std::string &path,
                              const std::optional<std::string> &value = std::nullopt,
                              const create::flag &flags = {});

    /// \brief 检查节点是否存在。
    /// \param path 节点路径。
    [[nodiscard]]
    inline bool exists(const std::string &path) const;

    /// \brief 获取节点内容。
    /// \param path 节点路径。
    [[nodiscard]]
    inline std::optional<std::string> get(const std::string &path) const;

    /// \brief 获取子节点列表。
    /// \param path 节点路径。
    [[nodiscard]]
    inline std::list<std::string> get_children(const std::string &path) const;

    /// \brief 变更节点。
    /// \param path  节点路径。
    /// \param value 节点值。
    /// \param flags 额外标记。
    inline void set(const std::string &path,
                    const std::optional<std::string> &value = std::nullopt,
                    const set::flag &flags = {});

    /// \brief 删除节点。
    /// \param path  节点路径。
    /// \param flags 额外标记。
    /// \remarks 因与 C++ 关键词冲突，刻意将 `delete` 拼写为 `deleta`。
    inline void deleta(const std::string &path, const deleta::flag &flags = {});

private:
    std::string host_;
    std::chrono::milliseconds timeout_ {};

    std::unique_ptr<zhandle_t, decltype(&zookeeper_close)> zh_ {nullptr, &zookeeper_close};

    static inline void init_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx);
    event_callback_t event_callback_ {nullptr};
    void *event_callback_p_user_data_ {nullptr};
};

}

#include "rrzookeeper.inl"

#endif
