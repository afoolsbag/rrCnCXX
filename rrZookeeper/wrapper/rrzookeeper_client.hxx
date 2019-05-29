/// \copyright Unlicense

#pragma once
#ifndef RRZOOKEEPER_CLIENT_HXX_
#define RRZOOKEEPER_CLIENT_HXX_

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
    /// \brief 额外标记。
    enum {
        cf_none = 0,
        cf_ephemeral = 0x00'00'01,         ///< 创建临时节点
        cf_sequence = 0x00'00'02,          ///< 创建顺序节点
        cf_recursive = 0x00'00'04,         ///< 若节点悬空，则递归创建中间节点，然后创建该节点
        cf_set_if_exists = 0x00'00'08,     ///< 若节点已存在，则变更该节点内容
        cf_ignore_if_exists = 0x00'00'10,  ///< 若节点已存在，则忽略本次操作
        cf_force = cf_recursive | cf_set_if_exists,

        sf_none = 0,
        sf_create_if_not_exists = 0x00'01'00,  ///< 若节点不存在，则递归创建该节点
        sf_force = sf_create_if_not_exists,

        df_none = 0,
        df_traversal = 0x01'00'00,             ///< 若节点挂载有子节点，则遍历删除子节点，然后删除该节点
        df_ignore_if_not_exists = 0x02'00'00,  ///< 若节点不存在，则忽略本次操作
        df_force = df_traversal | df_ignore_if_not_exists
    };

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
    inline std::string create(const std::string &path, const std::optional<std::string> &value, int flags = cf_none);
    inline std::string create(const std::string &path, int flags = cf_none);

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
    inline void set(const std::string &path, const std::optional<std::string> &value = std::nullopt, int flags = sf_none);

    /// \brief 删除节点。
    /// \param path 节点路径。
    /// \param flags  额外标记。
    /// \remarks 因与 C++ 关键词冲突，刻意将 `delete` 拼写为 `deleta`。
    inline void deleta(const std::string &path, int flags = df_none);

private:
    std::string host_;
    std::chrono::milliseconds timeout_;

    using zhandle_unique_ptr = std::unique_ptr<zhandle_t, decltype(&zookeeper_close)>;
    zhandle_unique_ptr zh_;
};

}//namespace rrzookeeper

#include "rrzookeeper_client.inl"

#endif//RRZOOKEEPER_CLIENT_HXX_
