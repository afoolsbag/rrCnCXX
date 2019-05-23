//===-- Instance ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库 rrDLLx 的 C++ 实例类。
///
/// \version 2019-05-23
/// \since 2019-05-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLX_INSTANCE_HXX_
#define RRDLLX_INSTANCE_HXX_

#include <cstdint>
#include <exception>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

#include "rrdllx/rrdllx.h"

namespace rrdllx {

using status_t = rrdllx_status_t;                                                      ///< 状态码（status）
using version_t = rrdllx_version_t;                                                    ///< 版本（version）
using handle_t = rrdllx_handle_t;                                                      ///< 实例句柄（instant handle）
using byte8_rarray_t = rrdllx_byte8_rarray_t;                                          ///< 八位字节原始数组（8-bit byte raw array）
using byte8_sarray_t = rrdllx_byte8_sarray_t;                                          ///< 八位字节结构数组（8-bit byte structured array）
using byte8_parray_t = std::pair<std::size_t, byte8_rarray_t>;                         ///< 八位字节对值数组（8-bit byte pair array）
using byte8_oarray_t = std::pair<std::size_t, std::unique_ptr<const std::uint8_t[]>>;  ///< 八位字节有权数组（8-bit byte owner array）
using char_rarray_t = rrdllx_char_rarray_t;                                            ///< 字符原始数组（char raw array）
using char_sarray_t = rrdllx_char_sarray_t;                                            ///< 字符结构数组（char structured array）
using char_parray_t = std::pair<std::size_t, char_rarray_t>;                           ///< 字符对值数组（char pair array）
using char_oarray_t = std::pair<std::size_t, std::unique_ptr<const char[]>>;           ///< 字符有权数组（char owner array）
using zstring_t = rrdllx_zstring_t;                                                    ///< 空终止字符串（zero-terminated string）
using zstring_rarray_t = rrdllx_zstring_rarray_t;                                      ///< 空终止字符串原始数组（zero-terminated string raw array）
using zstring_sarray_t = rrdllx_zstring_sarray_t;                                      ///< 空终止字符串结构数组（zero-terminated string structured array）
using zstring_parray_t = std::pair<std::size_t, zstring_rarray_t>;                     ///< 空终止字符串对值数组（zero-terminated string pair array）
using zstring_oarray_t = std::pair<std::size_t, std::unique_ptr<const zstring_t[]>>;   ///< 空终止字符串有权数组（zero-terminated string owner array）

class exception_t final : public std::exception {
public:
    explicit exception_t(status_t status) : status_ {status} {}
    [[nodiscard]] status_t status() const { return status_; }
private:
    status_t status_;
};

class rrdllx_t final {
public:
    [[nodiscard]] static handle_t  alloc_instance();
    static rrdllx_t &              instance(handle_t handle);
    static void                    free_instance(handle_t handle);

    [[nodiscard]] byte8_parray_t   alloc_byte8_array(const std::vector<std::uint8_t> &value);
    void                           free_byte8_array(byte8_rarray_t byte8_rarray);

    [[nodiscard]] char_parray_t    alloc_char_array(const std::vector<char> &value);
    void                           free_char_array(char_rarray_t char_rarray);

    [[nodiscard]] zstring_t        alloc_zstring(const std::string &value);
    [[nodiscard]] zstring_t        alloc_last_internal_error_zstring();
    void                           free_zstring(zstring_t zstring);

    [[nodiscard]] zstring_parray_t alloc_zstring_array(const std::vector<std::string> &value);
    void                           free_zstring_array(zstring_rarray_t zstring_rarray);

    void                           free_all();

private:
    static std::map<handle_t, std::unique_ptr<rrdllx_t>> instance_owner_;

    std::map<byte8_rarray_t, byte8_oarray_t>             byte8_array_owner_;
    std::map<char_rarray_t, char_oarray_t>               char_array_owner_;
    std::map<zstring_rarray_t, zstring_oarray_t>         zstring_array_owner_;

    void last_internal_error(const std::string &txt);
    std::string last_internal_error();
    std::map<std::thread::id, std::string>               last_internal_error_;
};//class rrdllx_t

}//namespace rrdllx

/// \def RRDLLX_ETS_TRY
/// \def RRDLLX_ETS_CATCH_ALL
/// \brief 异常转状态码（exception to status）
#define RRDLLX_ETS_TRY                                                         \
    try
#define RRDLLX_ETS_CATCH_ALL                                                   \
      catch (const rrdllx::exception_t &e) {                                   \
        return e.status();                                                     \
    } catch (const std::invalid_argument &) {                                  \
        return rrdllx_invalid_argument;                                        \
    } catch (const std::domain_error &) {                                      \
        return rrdllx_domain_error;                                            \
    } catch (const std::length_error &) {                                      \
        return rrdllx_length_error;                                            \
    } catch (const std::out_of_range &) {                                      \
        return rrdllx_out_of_range;                                            \
    } catch (const std::logic_error &) {                                       \
        return rrdllx_logic_error;                                             \
    } catch (const std::range_error &) {                                       \
        return rrdllx_range_error;                                             \
    } catch (const std::overflow_error &) {                                    \
        return rrdllx_overflow_error;                                          \
    } catch (const std::underflow_error &) {                                   \
        return rrdllx_underflow_error;                                         \
    } catch (const std::runtime_error &) {                                     \
        return rrdllx_runtime_error;                                           \
    } catch (const std::bad_typeid &) {                                        \
        return rrdllx_bad_typeid;                                              \
    } catch (const std::bad_cast &) {                                          \
        return rrdllx_bad_cast;                                                \
    } catch (const std::bad_alloc &) {                                         \
        return rrdllx_bad_alloc;                                               \
    } catch (const std::bad_exception &) {                                     \
        return rrdllx_bad_exception;                                           \
    } catch (const std::exception &) {                                         \
        return rrdllx_exception;                                               \
    } catch (...) {                                                            \
        return rrdllx_unexpected_exception;                                    \
    }

#endif//RRDLLX_INSTANCE_HXX_
