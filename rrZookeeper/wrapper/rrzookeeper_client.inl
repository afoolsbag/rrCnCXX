/// \copyright Unlicense

#pragma once
#ifndef RRZOOKEEPER_CLIENT_INL_
#define RRZOOKEEPER_CLIENT_INL_

#include <cerrno>

#include "rrzookeeper_client.hxx"

namespace rrzookeeper {

inline client::client(ZooLogLevel log_level) noexcept
    : timeout_ {0}, zh_ {nullptr, &zookeeper_close}
{
    zoo_set_debug_level(log_level);
}

inline client::~client() noexcept
{
    try {
        disconnect();
    } catch (...) {
        // Do nothing if disconnect failed.
    }
}

inline void client::connect(const std::string &host, const std::chrono::milliseconds &timeout)
{
    host_ = host;
    timeout_ = timeout;
    reconnect();
}

inline void client::reconnect()
{
    using namespace std;

    if (host_.empty())
        throw invalid_argument("Host cannot be empty.");
    if (timeout_.count() < 0)
        throw invalid_argument("Timeout cannot be negative.");

    zh_.reset(zookeeper_init(host_.c_str(), nullptr, static_cast<int>(timeout_.count()), nullptr, nullptr, 0));
    if (!zh_)
        throw runtime_error("zookeeper_init failed: "s + zerror(errno));
}

inline void client::disconnect()
{
    using namespace std;

    if (!zh_)
        return;

    const auto zrc = zookeeper_close(zh_.release());
    if (zrc != ZOK)
        throw runtime_error("zookeeper_close failed: "s + zerror(zrc));
}

inline std::string client::create(const std::string &path, const std::optional<std::string> &value, int flags)
{
    using namespace std;

    const auto val = value ? value.value().data() : nullptr;
    const auto siz = value ? static_cast<int>(value.value().length()) + 1 : -1;
    const auto flg = (flags & cf_ephemeral ? ZOO_EPHEMERAL : 0) | (flags & cf_sequence ? ZOO_SEQUENCE : 0);
    char buf[1024] {};

    const auto zrc = zoo_create(zh_.get(), path.c_str(), val, siz, &ZOO_OPEN_ACL_UNSAFE, flg, buf, sizeof buf);

    if (zrc == ZOK) {
        return buf;
    } else if (zrc == ZNONODE && flags & cf_recursive) {
        const auto pos = path.find_last_of('/');
        if (pos == path.npos)
            throw runtime_error("zoo_create failed: "s + zerror(ZNONODE));
        create(path.substr(0, pos), nullopt, flags & ~cf_ephemeral & ~cf_sequence);
        return create(path, value, flags & ~cf_recursive);
    } else if (zrc == ZNODEEXISTS && flags & cf_set_if_exists) {
        set(path, value);
        return path;
    } else if (zrc == ZNODEEXISTS && flags & cf_ignore_if_exists) {
        return path;
    } else {
        throw runtime_error("zoo_create failed: "s + zerror(zrc));
    }
}

inline std::string client::create(const std::string &path, int flags)
{
    return create(path, std::nullopt, flags);
}

inline bool client::exists(const std::string &path) const
{
    using namespace std;

    const auto zrc = zoo_exists(zh_.get(), path.c_str(), false, nullptr);
    if (zrc == ZOK)
        return true;
    else if (zrc == ZNONODE)
        return false;
    else
        throw runtime_error("zoo_exists failed: "s + zerror(zrc));
}

inline std::optional<std::string> client::get(const std::string &path) const
{
    using namespace std;

    char buf[64 * 1024];
    int len = sizeof buf;
    const auto zrc = zoo_get(zh_.get(), path.c_str(), false, buf, &len, nullptr);
    if (zrc != ZOK)
        throw runtime_error("zoo_get failed: "s + zerror(zrc));
    return buf;
}

inline std::list<std::string> client::get_children(const std::string &path) const
{
    using namespace std;

    list<string> tmp;

    String_vector vec {};
    const auto zrc = zoo_get_children(zh_.get(), path.c_str(), false, &vec);
    if (zrc != ZOK)
        throw runtime_error("zoo_get_children failed: "s + zerror(zrc));
    for (auto i = 0; i < vec.count; ++i)
        tmp.push_back(vec.data[i]);
    return tmp;
}

inline void client::set(const std::string &path, const std::optional<std::string> &value, int flags)
{
    using namespace std;

    const auto val = value ? value.value().data() : nullptr;
    const auto siz = value ? static_cast<int>(value.value().length()) + 1 : -1;
    const auto zrc = zoo_set(zh_.get(), path.c_str(), val, siz, -1);

    if (zrc == ZOK)
        return;
    else if (zrc == ZNONODE && flags & sf_create_if_not_exists)
        create(path, value, cf_recursive);
    else
        throw runtime_error("zoo_set failed: "s + zerror(zrc));
}

inline void client::deleta(const std::string &path, int flags)
{
    using namespace std;

    const auto zrc = zoo_delete(zh_.get(), path.c_str(), -1);
    if (zrc == ZOK) {
        return;
    } else if (zrc == ZNOTEMPTY && flags & df_traversal) {
        auto subs = get_children(path);
        for (const auto &sub : subs)
            deleta(path + "/"s + sub, df_traversal);
        deleta(path, flags & ~df_traversal);
    } else if (zrc == ZNONODE && flags & df_ignore_if_not_exists) {
        return;
    } else {
        throw runtime_error("zoo_delete failed: "s + zerror(zrc));
    }
}

}//namespace rrzookeeper

#endif//RRZOOKEEPER_CLIENT_INL_