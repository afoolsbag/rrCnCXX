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
    explicit error(status_t e): e_ {std::move(e)} {};
    status_t code() const { return e_; };
private:
    status_t e_;
};

/// \brief 获取版本。
inline version_t version()
{
    version_t v;
    const auto e = rrx_version(&v);
    if (e != rrx_success)
        throw error(e);
    return v;
}

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

inline rrx_t::rrx_t()
{
    rrx_construct(&h_);
}

inline void rrx_t::plus(int n)
{
    const auto e = rrx_plus(h_, n);
    if (e != rrx_success)
        throw error(e);
}

inline void rrx_t::minus(int n)
{
    const auto e = rrx_minus(h_, n);
    if (e != rrx_success)
        throw error(e);
}

inline int rrx_t::equals()
{
    int n;
    const auto e = rrx_equals(h_, &n);
    if (e != rrx_success)
        throw error(e);
    return n;
}

inline rrx_t::~rrx_t()
{
    rrx_destruct(h_);
}

}//namespace rrx

#endif//RRX_LIB_HXX_
