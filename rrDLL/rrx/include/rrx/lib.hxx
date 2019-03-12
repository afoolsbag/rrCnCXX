//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库的 C++ 包装。
///
/// \version 2019-02-27
/// \since 2019-02-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRX_LIB_HXX_
#define RRX_LIB_HXX_

#include <exception>

#include "rrx/lib.h"

namespace rrx {

using status_t = rrx_status_t;
using version_t = rrx_version_t;

/// \brief 错误包装类。
/// \details 用于异常抛出。
class error: public std::exception {
public:
    explicit error(status_t e): e_ {e} {};
    status_t code() const { return e_; };
private:
    status_t e_;
};

/// \brief 获取版本。
inline version_t version();

/// \brief 实例包装类。
class rrx_t final {
public:
    inline explicit rrx_t();
    inline void plus(int n);
    inline void minus(int n);
    inline int equals();
    inline ~rrx_t();
private:
    rrx_handle_t h_;
};

}//namespace rrx

#include "lib.inl"

#endif//RRX_LIB_HXX_
