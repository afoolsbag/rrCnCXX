/// \copyright Unlicense

#include "rrdllx/lib.h"

#include <map>
#include <memory>
#include <string>

#include "cfg.hxx"

using namespace std;

/// \brief 实例包装。
/// \details 管理实例资源。
struct rrdllx_t {
    /// \brief 字符串映射。
    /// \details 管理实例字符串。
    map<rrdllx_string_t, unique_ptr<const char[]>> string_map;

    /// \brief 字符串索引映射。
    /// \details 管理实例字符串索引。
    map<rrdllx_string_index_t, unique_ptr<const rrdllx_string_t[]>> string_index_map;

    /// \brief 字符串结构数组映射。
    /// \details 管理实例字符串结构数组。
    map<rrdllx_string_array_t, unique_ptr<rrdllx_string_array_dereference_t>> string_array_map;
};

/// \brief 实例映射。
/// \details 管理所有实例。
LOCAL map<rrdllx_handle_t, unique_ptr<rrdllx_t>> instances_map;

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_version(rrdllx_version_t *rv)
RRDLLX_APIs
{
    if (!rv)
        return rrdllx_invalid_argument;

    (*rv).major = static_cast<int>(rrdllx::project_version_major);
    (*rv).minor = static_cast<int>(rrdllx::project_version_minor);
    (*rv).patch = static_cast<int>(rrdllx::project_version_patch);
    (*rv).tweak = static_cast<int>(rrdllx::project_version_tweak);

    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs
{
    if (!rh || (*rh) != nullptr)
        return rrdllx_invalid_argument;

    auto mov_ptr = make_unique<rrdllx_t>();
    if (!mov_ptr)
        return rrdllx_bad_alloc;
    const auto handle = mov_ptr.get();
    instances_map.insert(make_pair(handle, move(mov_ptr)));

    (*rh) = handle;
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs
{
    if (!h)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;

    instances_map.erase(h);
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string(rrdllx_handle_t h, rrdllx_string_t v, rrdllx_string_t *rs)
RRDLLX_APIs
{
    if (!h || !rs || (*rs) != nullptr)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;

    const string str {v ? v : "This is string that managed by the dll."};

    auto mov_ptr = make_unique<char[]>(str.length() + 1);
    if (!mov_ptr)
        return rrdllx_bad_alloc;
    const auto raw_ptr = mov_ptr.get();
    h->string_map.insert(make_pair(raw_ptr, move(mov_ptr)));

    strcpy_s(raw_ptr, str.length() + 1, str.c_str());

    (*rs) = raw_ptr;
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string(rrdllx_handle_t h, rrdllx_string_t s)
RRDLLX_APIs
{
    if (!h || !s)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;
    if (!h->string_map.count(s))
        return rrdllx_out_of_range;

    h->string_map.erase(s);
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string_array(rrdllx_handle_t h, size_t s, rrdllx_string_array_t *ra)
RRDLLX_APIs
{
    if (!h || !ra || (*ra) != nullptr)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;

    // naked array
    auto naked_mov_ptr = make_unique<rrdllx_string_t[]>(s);
    if (!naked_mov_ptr)
        return rrdllx_bad_alloc;
    const auto naked_raw_ptr = naked_mov_ptr.get();
    h->string_index_map.insert(make_pair(naked_raw_ptr, move(naked_mov_ptr)));

    for (size_t i = 0; i < s; ++i) {
        rrdllx_string_t tmp = nullptr;
        const auto stat = rrdllx_alloc_string(h, nullptr, &tmp);
        if (stat != rrdllx_success)
            return stat;
        naked_raw_ptr[i] = tmp;
    }

    // structured array
    auto mov_ptr = make_unique<rrdllx_string_array_dereference_t>(rrdllx_string_array_dereference_t {s, naked_raw_ptr});
    if (!mov_ptr)
        return rrdllx_bad_alloc;
    const auto raw_ptr = mov_ptr.get();
    h->string_array_map.insert(make_pair(raw_ptr, move(mov_ptr)));

    (*ra) = raw_ptr;
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string_array(rrdllx_handle_t h, rrdllx_string_array_t a)
RRDLLX_APIs
{
    if (!h || !a)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;
    if (!h->string_array_map.count(a))
        return rrdllx_out_of_range;

    if (!a->v)
        return rrdllx_invalid_argument;
    if (!h->string_index_map.count(a->v))
        return rrdllx_out_of_range;

    for (size_t i = 0; i < a->c; ++i) {
        if (!a->v[i])
            return rrdllx_invalid_argument;
        if (!h->string_map.count(a->v[i]))
            return rrdllx_out_of_range;

        h->string_map.erase(a->v[i]);
    }
    h->string_index_map.erase(a->v);
    h->string_array_map.erase(a);
    return rrdllx_success;
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs
{
    if (!h)
        return rrdllx_invalid_argument;
    if (!instances_map.count(h))
        return rrdllx_out_of_range;

    h->string_array_map.clear();
    h->string_index_map.clear();
    h->string_map.clear();
    return rrdllx_success;
}
