//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库的 C++ 包装。
///
/// \version 2019-04-16
/// \since 2019-02-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLLCXX_LIB_HXX_
#define RRDLLCXX_LIB_HXX_

#include <exception>

#include "rrdllcxx/lib.h"

namespace rrdllcxx {

using status_t = rrdllcxx_status_t;
using version_t = rrdllcxx_version_t;

/// \brief 错误包装类。
/// \details 用于异常抛出。
class error: public std::exception {
public:
    explicit error(status_t e) noexcept: e_ {e} {};
    status_t code() const noexcept { return e_; };
private:
    status_t e_;
};

/// \brief 获取版本。
inline version_t version();

/// \brief 实例包装类。
class rrdllcxx_t final {
public:
    inline explicit rrdllcxx_t();
    inline void plus(int n);
    inline void minus(int n);
    inline int equals() const;
    inline ~rrdllcxx_t();
private:
    rrdllcxx_handle_t h_ {nullptr};
};

}//namespace rrdllcxx

#include "lib.inl"

#endif//RRDLLCXX_LIB_HXX_
