/// \copyright Unlicense

#pragma once
#ifndef RRX_LIB_INL_
#define RRX_LIB_INL_

#include "rrx/lib.hxx"

namespace rrx {

inline version_t version()
{
    version_t v;
    const auto e = rrx_version(&v);
    if (e != rrx_success)
        throw error(e);
    return v;
}

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

#endif//RRX_LIB_INL_
