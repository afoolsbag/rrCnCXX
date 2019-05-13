//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库的 C++ 包装。
///
/// \version 2019-05-10
/// \since 2019-02-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLX_LIB_HXX_
#define RRDLLX_LIB_HXX_

#include <exception>
#include <string>

#include "rrdllx/lib.h"

namespace rrdllx {

using status_t = rrdllx_status_t;
using version_t = rrdllx_version_t;

/// \brief 错误包装类。
/// \details 用于异常抛出。
class error: public std::exception {
public:
    explicit error(status_t e) noexcept: e_ {e} {}
    status_t code() const noexcept { return e_; }
private:
    status_t e_;
};

/// \brief 获取版本。
inline version_t version();

/// \brief 实例包装类。
class rrdllx_t final {
public:
    inline explicit rrdllx_t();
    inline ~rrdllx_t();
    inline std::string alloc_string();
private:
    rrdllx_handle_t h_ {nullptr};
};

}//namespace rrdllx

#include "lib.inl"

#endif//RRDLLX_LIB_HXX_
