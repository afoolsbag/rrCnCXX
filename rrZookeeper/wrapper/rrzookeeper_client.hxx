//===-- rrZookeeper Client Wrapper ------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-17
/// \since 2019-05-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRZOOKEEPER_CLIENT_HXX_
#define RRZOOKEEPER_CLIENT_HXX_

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
#include <zookeeper/zookeeper.h>
#ifdef _MSC_VER
# pragma warning(pop)
#endif

namespace rrzookeeper {

class client {
public:
    enum { _cf_ephemeral, _cf_sequence, _cf_recursive, _cf_set_if_exists, _cf_ignore_if_exists, _cf_count };
    using create_flag = std::bitset<_cf_count>;
    static constexpr create_flag cf_ephemeral {1 << _cf_ephemeral};                ///< 创建临时节点
    static constexpr create_flag cf_sequence {1 << _cf_sequence};                  ///< 创建顺序节点
    static constexpr create_flag cf_recursive {1 << _cf_recursive};                ///< 若节点悬空，则递归创建中间节点，然后创建该节点
    static constexpr create_flag cf_set_if_exists {1 << _cf_set_if_exists};        ///< 若节点已存在，则变更该节点内容
    static constexpr create_flag cf_ignore_if_exists {1 << _cf_ignore_if_exists};  ///< 若节点已存在，则忽略本次操作
    static constexpr create_flag cf_force {1 << _cf_recursive | 1 << _cf_set_if_exists};

    enum { _sf_create_if_not_exists, _sf_count };
    using set_flag = std::bitset<_sf_count>;
    static constexpr set_flag sf_create_if_not_exists {1 << _sf_create_if_not_exists};  ///< 若节点不存在，则递归创建该节点
    static constexpr set_flag sf_force {1 << _sf_create_if_not_exists};

    enum { _df_traversal, _df_ignore_if_not_exists, _df_count };
    using delete_flag = std::bitset<_df_count>;
    static constexpr delete_flag df_traversal {1 << _df_traversal};                        ///< 若节点挂载有子节点，则遍历删除子节点，然后删除该节点
    static constexpr delete_flag df_ignore_if_not_exists {1 << _df_ignore_if_not_exists};  ///< 若节点不存在，则忽略本次操作
    static constexpr delete_flag df_force {1 << _df_traversal | 1 << _df_ignore_if_not_exists};

    inline explicit client(ZooLogLevel log_level = ZOO_LOG_LEVEL_WARN) noexcept;
    inline virtual ~client() noexcept;

    inline void connect(const std::string &host,
                        const std::chrono::milliseconds &timeout = std::chrono::seconds {10});
    inline void reconnect();
    inline void disconnect();

    /// \brief 创建节点。
    /// \param path  节点路径。
    /// \param value 节点值。
    /// \param flags  额外标记。
    /// \returns 节点路径，主要用于 `sequence` 标记生效时的情形。
    inline std::string create(const std::string &path, const std::optional<std::string> &value, const create_flag &flags = {});
    inline std::string create(const std::string &path, const create_flag &flags = {});

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
    inline void set(const std::string &path, const std::optional<std::string> &value = std::nullopt, const set_flag &flags = {});

    /// \brief 删除节点。
    /// \param path 节点路径。
    /// \param flags  额外标记。
    /// \remarks 因与 C++ 关键词冲突，刻意将 `delete` 拼写为 `deleta`。
    inline void deleta(const std::string &path, const delete_flag &flags = {});

private:
    std::string host_;
    std::chrono::milliseconds timeout_;

    using zhandle_unique_ptr = std::unique_ptr<zhandle_t, decltype(&zookeeper_close)>;
    zhandle_unique_ptr zh_;

    static inline void init_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx);
};

}

#include "rrzookeeper_client.inl"

#endif
