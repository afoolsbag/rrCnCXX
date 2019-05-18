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
#include <functional>
#include <string>
#include <vector>

#include "rrdllx.h"

namespace rrdllx {

using status_t = rrdllx_status_t;
using version_t = rrdllx_version_t;
using handle_t = rrdllx_handle_t;
using zstring_deref_t = rrdllx_zstring_deref_t;
using zstring_t = rrdllx_zstring_t;
using zstring_array_deref_t = rrdllx_zstring_array_deref_t;
using zstring_array_t = rrdllx_zstring_array_t;
using binary_deref_t = rrdllx_binary_deref_t;
using binary_t = rrdllx_binary_t;

class exception_t final : public std::exception {
public:
    explicit exception_t(status_t status) : status_{status} {}
    [[nodiscard]] status_t status() const { return status_; }
private:
    status_t status_;
};

inline version_t version();

class rrdllx_t final {
public:
    inline explicit rrdllx_t();
    inline ~rrdllx_t();

    inline zstring_t       alloc_zstring(const std::string &value);
    inline void            free_zstring(zstring_t zstring);
    inline zstring_array_t alloc_zstring_array(const std::vector<std::string> &value);
    inline void            free_zstring_array(zstring_array_t zstring_array);
    inline binary_t        alloc_binary(const std::vector<std::uint8_t> &value);
    inline void            free_binary(binary_t binary);
    inline void            free_all();

private:
    handle_t h_{nullptr};
};

}//namespace rrdllx

#include "rrdllx.inl"

#endif//RRDLLX_RRDLLX_HXX_
