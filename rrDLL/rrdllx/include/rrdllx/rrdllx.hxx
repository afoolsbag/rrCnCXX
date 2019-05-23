//===-- rrDLLx --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库 rrDLLx 的 C++ 包装。
///
/// \version 2019-05-18
/// \since 2019-02-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLX_RRDLLX_HXX_
#define RRDLLX_RRDLLX_HXX_

#include <exception>
#include <memory>
#include <functional>
#include <string>
#include <vector>

#include "rrdllx.h"

namespace rrdllx {

using status_t = rrdllx_status_t;                                   ///< 状态码（status）
using version_t = rrdllx_version_t;                                 ///< 版本（version）
using handle_t = rrdllx_handle_t;                                   ///< 实例句柄（instant handle）
using byte8_rarray_t = rrdllx_byte8_rarray_t;                       ///< 八位字节原始数组（8-bit byte raw array）
using byte8_sarray_t = rrdllx_byte8_sarray_t;                       ///< 八位字节结构数组（8-bit byte structured array）
using byte8_parray_t = std::pair<std::size_t, byte8_rarray_t>;      ///< 八位字节对值数组（8-bit byte pair array）
using char_rarray_t = rrdllx_char_rarray_t;                         ///< 字符原始数组（char raw array）
using char_sarray_t = rrdllx_char_sarray_t;                         ///< 字符结构数组（char structured array）
using char_parray_t = std::pair<std::size_t, char_rarray_t>;        ///< 字符对值数组（char pair array）
using zstring_t = rrdllx_zstring_t;                                 ///< 空终止字符串（zero-terminated string）
using zstring_rarray_t = rrdllx_zstring_rarray_t;                   ///< 空终止字符串原始数组（zero-terminated string raw array）
using zstring_sarray_t = rrdllx_zstring_sarray_t;                   ///< 空终止字符串结构数组（zero-terminated string structured array）
using zstring_parray_t = std::pair<std::size_t, zstring_rarray_t>;  ///< 空终止字符串对值数组（zero-terminated string pair array）

using byte8_rarray_delete_t = std::function<void(byte8_rarray_t)>;
using byte8_rarray_unique_ptr = std::unique_ptr<const std::uint8_t[], byte8_rarray_delete_t>;
using byte8_sparray_t = std::pair<std::size_t, byte8_rarray_unique_ptr>;  ///< smart pair array

using char_rarray_delete_t = std::function<void(char_rarray_t)>;
using char_rarray_unique_ptr = std::unique_ptr<const char[], char_rarray_delete_t>;
using char_sparray_t = std::pair<std::size_t, char_rarray_unique_ptr>;  ///< smart pair array

using zstring_rarray_delete_t = std::function<void(zstring_rarray_t)>;
using zstring_rarray_unique_ptr = std::unique_ptr<const zstring_t[], zstring_rarray_delete_t>;
using zstring_sparray_t = std::pair<std::size_t, zstring_rarray_unique_ptr>;  ///< smart pair array

class exception_t final : public std::exception {
public:
    explicit exception_t(status_t status) : status_ {status} {}
    [[nodiscard]] status_t status() const { return status_; }
private:
    status_t status_;
};

inline version_t version();

class rrdllx_t final {
public:
    inline explicit rrdllx_t();
    inline ~rrdllx_t();

    byte8_parray_t   alloc_byte8_array(const std::vector<std::uint8_t> &value);
    void             free_byte8_array(byte8_rarray_t byte8_rarray);

    char_parray_t    alloc_char_array(const std::vector<char> &value);
    void             free_char_array(char_rarray_t char_rarray);

    zstring_t        alloc_zstring(const std::string &value);
    zstring_t        alloc_last_internal_error_zstring();
    void             free_zstring(zstring_t zstring);

    zstring_parray_t alloc_zstring_array(const std::vector<std::string> &value);
    void             free_zstring_array(zstring_rarray_t zstring_rarray);

    void             free_all();

private:
    handle_t h_ {nullptr};

    const byte8_rarray_delete_t byte8_rarray_delete_ {std::bind(&rrdllx_t::free_byte8_array, this, std::placeholders::_1)};
    const char_rarray_delete_t char_rarray_delete_ {std::bind(&rrdllx_t::free_char_array, this, std::placeholders::_1)};
    const zstring_rarray_delete_t zstring_rarray_delete_ {std::bind(&rrdllx_t::free_zstring_array, this, std::placeholders::_1)};

};//class rrdllx_t

}//namespace rrdllx

#include "rrdllx.inl"

#endif//RRDLLX_RRDLLX_HXX_
