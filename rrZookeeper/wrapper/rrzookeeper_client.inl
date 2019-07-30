/// \copyright Unlicense

#pragma once
#ifndef RRZOOKEEPER_CLIENT_INL_
#define RRZOOKEEPER_CLIENT_INL_

#include "rrzookeeper_client.hxx"

#include <cerrno>
#include <condition_variable>
#include <mutex>

namespace rrzookeeper {

inline client::event client::ztype(int type) noexcept
{
    if (type == ZOO_CREATED_EVENT)     return event::created;
    if (type == ZOO_DELETED_EVENT)     return event::deleted;
    if (type == ZOO_CHANGED_EVENT)     return event::changed;
    if (type == ZOO_CHILD_EVENT)       return event::child;
    if (type == ZOO_SESSION_EVENT)     return event::session;
    if (type == ZOO_NOTWATCHING_EVENT) return event::not_watching;
    return event::unknown;
}

inline client::state client::zstate(int state) noexcept
{
    if (state == 0)                         return state::closed;
    if (state == ZOO_CONNECTING_STATE)      return state::connecting;
    if (state == ZOO_ASSOCIATING_STATE)     return state::association;
    if (state == ZOO_CONNECTED_STATE)       return state::connected;
    if (state == ZOO_EXPIRED_SESSION_STATE) return state::expired_session;
    if (state == ZOO_AUTH_FAILED_STATE)     return state::auth_failed;
    return state::invalid;
}

inline std::optional<std::string> client::zpath(const char *path)
{
    using namespace std;
    if (!path) return nullopt;
    return string {path};
}


inline client::client(ZooLogLevel log_level) noexcept
{
    zoo_set_debug_level(log_level);
}

inline client::~client() noexcept
{
    try {
        disconnect();
    } catch (...) {
        // do nothing if disconnect failed
    }
}

inline void client::set_event_callback(event_callback_t callback, void *p_user_data)
{
    event_callback_ = callback;
    event_callback_p_user_data_ = p_user_data;
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
        throw invalid_argument {"host cannot be empty"};
    if (timeout_.count() < 0)
        throw invalid_argument {"timeout cannot be negative"};

    zh_.reset(zookeeper_init(host_.c_str(), init_watcher, static_cast<int>(timeout_.count()), nullptr, this, 0));
    if (!zh_)
        throw runtime_error {"zookeeper_init failed: "s.append(zerror(errno))};
}

inline void client::disconnect()
{
    using namespace std;

    if (!zh_)
        return;

    const auto zrc = zookeeper_close(zh_.release());
    if (zrc != ZOK)
        throw runtime_error {"zookeeper_close failed: "s.append(zerror(zrc))};
}

inline std::string client::create(const std::string &path, const std::optional<std::string> &value, const create::flag &flags)
{
    using namespace std;

    const auto val = value ? value.value().data() : nullptr;
    const auto siz = value ? static_cast<int>(value.value().length()) + 1 : -1;
    const auto flg = ((flags & create::ephemeral).any() ? ZOO_EPHEMERAL : 0) | ((flags & create::sequence).any() ? ZOO_SEQUENCE : 0);
    char buf[1024] {};

    const auto zrc = zoo_create(zh_.get(), path.c_str(), val, siz, &ZOO_OPEN_ACL_UNSAFE, flg, buf, sizeof buf);

    if (zrc == ZOK) {
        return buf;

    } else if (zrc == ZNONODE && (flags & create::recursive).any()) {
        const auto pos = path.find_last_of('/');
        if (pos == string::npos)
            throw runtime_error {"zoo_create failed: "s.append(zerror(ZNONODE))};
        create(path.substr(0, pos), nullopt, flags & ~create::ephemeral & ~create::sequence);
        return create(path, value, flags & ~create::recursive);

    } else if (zrc == ZNODEEXISTS && (flags & create::set_if_exists).any()) {
        set(path, value);
        return path;

    } else if (zrc == ZNODEEXISTS && (flags & create::ignore_if_exists).any()) {
        return path;

    } else {
        throw runtime_error {"zoo_create failed: "s.append(zerror(zrc))};
    }
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
        throw runtime_error {"zoo_exists failed: "s.append(zerror(zrc))};
}

inline std::optional<std::string> client::get(const std::string &path) const
{
    using namespace std;

    char buf[64 * 1024];
    int len = sizeof buf;
    const auto zrc = zoo_get(zh_.get(), path.c_str(), false, buf, &len, nullptr);
    if (zrc != ZOK)
        throw runtime_error {"zoo_get failed: "s.append(zerror(zrc))};
    return buf;
}

inline std::list<std::string> client::get_children(const std::string &path) const
{
    using namespace std;

    list<string> tmp;

    String_vector vec {};
    const auto zrc = zoo_get_children(zh_.get(), path.c_str(), false, &vec);
    if (zrc != ZOK)
        throw runtime_error {"zoo_get_children failed: "s.append(zerror(zrc))};
    for (auto i = 0; i < vec.count; ++i)
        tmp.emplace_back(vec.data[i]);
    return tmp;
}

inline void client::set(const std::string &path, const std::optional<std::string> &value, const set::flag &flags)
{
    using namespace std;

    const auto val = value ? value.value().data() : nullptr;
    const auto siz = value ? static_cast<int>(value.value().length()) + 1 : -1;
    const auto zrc = zoo_set(zh_.get(), path.c_str(), val, siz, -1);

    if (zrc == ZOK)
        return;
    else if (zrc == ZNONODE && (flags & set::create_if_not_exists).any())
        create(path, value, create::recursive);
    else
        throw runtime_error {"zoo_set failed: "s.append(zerror(zrc))};
}

inline void client::deleta(const std::string &path, const deleta::flag &flags)
{
    using namespace std;

    const auto zrc = zoo_delete(zh_.get(), path.c_str(), -1);

    if (zrc == ZOK) {
        return;

    } else if (zrc == ZNOTEMPTY && (flags & deleta::traversal).any()) {
        auto subs = get_children(path);
        for (const auto &sub : subs)
            deleta(path + "/"s.append(sub), deleta::traversal);
        deleta(path, flags & ~deleta::traversal);

    } else if (zrc == ZNONODE && (flags & deleta::ignore_if_not_exists).any()) {
        return;

    } else {
        throw runtime_error {"zoo_delete failed: "s.append(zerror(zrc))};
    }
}

inline void client::init_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    (void)zh;
    const auto self = reinterpret_cast<client *>(watcherCtx);
    if (self->event_callback_)
        self->event_callback_(self, ztype(type), zstate(state), zpath(path), self->event_callback_p_user_data_);
}

}

#endif
