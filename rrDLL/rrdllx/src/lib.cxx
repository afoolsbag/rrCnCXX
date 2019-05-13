/// \copyright Unlicense

#include "rrdllx/lib.h"

#define _CRT_SECURE_NO_WARNINGS
#include <exception>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "cfg.hxx"

using namespace std;

//==============================================================================
//  ________  _________ _      ________  ___ _____ _   _ _____ ___ _____ _____ _____ _   _
// |_   _|  \/  || ___ \ |    |  ___|  \/  ||  ___| \ | |_   _/ _ \_   _|_   _|  _  | \ | |
//   | | | .  . || |_/ / |    | |__ | .  . || |__ |  \| | | |/ /_\ \| |   | | | | | |  \| |
//   | | | |\/| ||  __/| |    |  __|| |\/| ||  __|| . ` | | ||  _  || |   | | | | | | . ` |
//  _| |_| |  | || |   | |____| |___| |  | || |___| |\  | | || | | || |  _| |_\ \_/ / |\  |
//  \___/\_|  |_/\_|   \_____/\____/\_|  |_/\____/\_| \_/ \_/\_| |_/\_/  \___/ \___/\_| \_/

/// \brief 状态包装类。
/// \details 包装状态码，用于异常抛出。
class rrdllx_exception_t: public exception {
public:
    explicit rrdllx_exception_t(rrdllx_status_t status): status_ {status} {}
    [[nodiscard]] rrdllx_status_t status() const { return status_; }
private:
    rrdllx_status_t status_;
};

/// \brief 异常转状态码（exception to status）`try`
#define RRDLLX_ETS_TRY                                                         \
    try

/// \brief 异常转状态码（exception to status）`catch`
#define RRDLLX_ETS_CATCH_ALL                                                   \
      catch (const rrdllx_exception_t &e) {                                    \
        return e.status();                                                     \
    } catch (const invalid_argument &) {                                       \
        return rrdllx_invalid_argument;                                        \
    } catch (const domain_error &) {                                           \
        return rrdllx_domain_error;                                            \
    } catch (const length_error &) {                                           \
        return rrdllx_length_error;                                            \
    } catch (const out_of_range &) {                                           \
        return rrdllx_out_of_range;                                            \
    } catch (const logic_error &) {                                            \
        return rrdllx_logic_error;                                             \
    } catch (const range_error &) {                                            \
        return rrdllx_range_error;                                             \
    } catch (const overflow_error &) {                                         \
        return rrdllx_overflow_error;                                          \
    } catch (const underflow_error &) {                                        \
        return rrdllx_underflow_error;                                         \
    } catch (const runtime_error &) {                                          \
        return rrdllx_runtime_error;                                           \
    } catch (const bad_typeid &) {                                             \
        return rrdllx_bad_typeid;                                              \
    } catch (const bad_cast &) {                                               \
        return rrdllx_bad_cast;                                                \
    } catch (const bad_alloc &) {                                              \
        return rrdllx_bad_alloc;                                               \
    } catch (const bad_exception &) {                                          \
        return rrdllx_bad_exception;                                           \
    } catch (const exception &) {                                              \
        return rrdllx_exception;                                               \
    } catch (...) {                                                            \
        return rrdllx_unexpected_exception;                                    \
    }

/// \brief 实例包装类。
/// \details 管理实例资源。
struct rrdllx_t {
public:
    static rrdllx_handle_t alloc_instance();
    static rrdllx_t &instance(rrdllx_handle_t h);
    static void free_instance(rrdllx_handle_t h);

    rrdllx_string_t alloc_string(const string &v = "This is string that managed by the dll.");
    void free_string(rrdllx_string_t s);

    rrdllx_string_array_t alloc_string_array(const vector<string> &v = {"This is string array that managed by the dll."});
    void free_string_array(rrdllx_string_array_t a);

    void free_all();

private:
    /// \brief 实例映射。
    /// \details 管理所有实例。
    static map<rrdllx_handle_t, unique_ptr<rrdllx_t>> instances_map_;

    /// \brief 字符串映射。
    /// \details 管理实例字符串。
    map<rrdllx_string_t, unique_ptr<const char[]>> string_map_;

    /// \brief 字符串索引映射。
    /// \details 管理实例字符串索引。
    map<rrdllx_string_index_t, unique_ptr<const rrdllx_string_t[]>> string_index_map_;

    /// \brief 字符串结构数组映射。
    /// \details 管理实例字符串结构数组。
    map<rrdllx_string_array_t, unique_ptr<rrdllx_string_array_dereference_t>> string_array_map_;
};

rrdllx_handle_t rrdllx_t::alloc_instance()
{
    auto mov_ptr = make_unique<rrdllx_t>();
    const auto handle = mov_ptr.get();
    instances_map_.insert(make_pair(handle, move(mov_ptr)));
    return handle;
}

rrdllx_t &rrdllx_t::instance(rrdllx_handle_t h)
{
    if (!h)
        throw rrdllx_exception_t(rrdllx_invalid_argument_nullptr);
    if (!instances_map_.count(h))
        throw rrdllx_exception_t(rrdllx_out_of_range_handle);
    return *instances_map_.at(h);
}

void rrdllx_t::free_instance(rrdllx_handle_t h)
{
    if (!h)
        throw rrdllx_exception_t(rrdllx_invalid_argument_nullptr);
    if (!instances_map_.count(h))
        throw rrdllx_exception_t(rrdllx_out_of_range_handle);
    instances_map_.erase(h);
}

rrdllx_string_t rrdllx_t::alloc_string(const string &v)
{
    auto mov_ptr = make_unique<char[]>(v.length() + 1);
    const auto raw_ptr = mov_ptr.get();
    string_map_.insert(make_pair(raw_ptr, move(mov_ptr)));
    strcpy(raw_ptr, v.c_str());
    return raw_ptr;
}

void rrdllx_t::free_string(rrdllx_string_t s)
{
    if (!s)
        throw rrdllx_exception_t(rrdllx_invalid_argument_nullptr);
    if (!string_map_.count(s))
        throw rrdllx_exception_t(rrdllx_out_of_range_instance_string);
    string_map_.erase(s);
}

rrdllx_string_array_t rrdllx_t::alloc_string_array(const vector<string> &v)
{
    auto index_mov_ptr = make_unique<rrdllx_string_t[]>(v.size());
    const auto index_raw_ptr = index_mov_ptr.get();
    string_index_map_.insert(make_pair(index_raw_ptr, move(index_mov_ptr)));
    for (size_t i = 0; i < v.size(); ++i)
        index_raw_ptr[i] = alloc_string(v.at(i));

    auto array_mov_ptr = make_unique<rrdllx_string_array_dereference_t>(rrdllx_string_array_dereference_t {v.size(), index_raw_ptr});
    const auto array_raw_ptr = array_mov_ptr.get();
    string_array_map_.insert(make_pair(array_raw_ptr, move(array_mov_ptr)));
    return array_raw_ptr;
}

void rrdllx_t::free_string_array(rrdllx_string_array_t a)
{
    if (!a)
        throw rrdllx_exception_t(rrdllx_invalid_argument_nullptr);
    if (!string_array_map_.count(a))
        throw rrdllx_exception_t(rrdllx_out_of_range_instance_string_array);
    if (!string_index_map_.count(a->v))
        throw rrdllx_exception_t(rrdllx_out_of_range_instance_string_index);
    for (size_t i = 0; i < a->c; ++i)
        free_string(a->v[i]);
    string_index_map_.erase(a->v);
    string_array_map_.erase(a);
}

void rrdllx_t::free_all()
{
    string_array_map_.clear();
    string_index_map_.clear();
    string_map_.clear();
}

map<rrdllx_handle_t, unique_ptr<rrdllx_t>> rrdllx_t::instances_map_;

//==============================================================================
//  _____ _   _ _____ _________________ ___  _____  _____
// |_   _| \ | |_   _|  ___| ___ \  ___/ _ \/  __ \|  ___|
//   | | |  \| | | | | |__ | |_/ / |_ / /_\ \ /  \/| |__
//   | | | . ` | | | |  __||    /|  _||  _  | |    |  __|
//  _| |_| |\  | | | | |___| |\ \| |  | | | | \__/\| |___
//  \___/\_| \_/ \_/ \____/\_| \_\_|  \_| |_/\____/\____/

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_get_version(rrdllx_version_t *rv)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!rv)
        return rrdllx_invalid_argument_nullptr;
    rv->major = static_cast<int>(rrdllx::project_version_major);
    rv->minor = static_cast<int>(rrdllx::project_version_minor);
    rv->patch = static_cast<int>(rrdllx::project_version_patch);
    rv->tweak = static_cast<int>(rrdllx::project_version_tweak);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!rh)
        return rrdllx_invalid_argument_nullptr;
    if (*rh != nullptr)
        return rrdllx_invalid_argument_reference_to_notnull;
    *rh = rrdllx_t::alloc_instance();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    rrdllx_t::free_instance(h);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string(rrdllx_handle_t h, rrdllx_string_t v, rrdllx_string_t *rs)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!rs)
        return rrdllx_invalid_argument_nullptr;
    if (*rs != nullptr)
        return rrdllx_invalid_argument_reference_to_notnull;
    *rs = v ? rrdllx_t::instance(h).alloc_string(v) : rrdllx_t::instance(h).alloc_string();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string(rrdllx_handle_t h, rrdllx_string_t s)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    rrdllx_t::instance(h).free_string(s);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string_array(rrdllx_handle_t h, rrdllx_string_array_t *ra)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    if (!ra)
        return rrdllx_invalid_argument_nullptr;
    if (*ra != nullptr)
        return rrdllx_invalid_argument_reference_to_notnull;
    *ra = rrdllx_t::instance(h).alloc_string_array({"Test string 1/3.", "Test string 2/3.", "Test string 3/3."});
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string_array(rrdllx_handle_t h, rrdllx_string_array_t a)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    rrdllx_t::instance(h).free_string_array(a);
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}

RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs
{
    RRDLLX_ETS_TRY {
    rrdllx_t::instance(h).free_all();
    return rrdllx_success;
    } RRDLLX_ETS_CATCH_ALL
}
