/// \copyright Unlicense

#pragma once
#ifndef RRDLLCXX_LIB_INL_
#define RRDLLCxX_LIB_INL_

#include "rrdllcxx/lib.hxx"

namespace rrdllcxx {

inline version_t version()
{
    version_t v;
    const auto e = rrdllcxx_version(&v);
    if (e != rrdllcxx_success)
        throw error(e);
    return v;
}

inline rrdllcxx_t::rrdllcxx_t()
{
    rrdllcxx_construct(&h_);
}

inline void rrdllcxx_t::plus(int n)
{
    const auto e = rrdllcxx_plus(h_, n);
    if (e != rrdllcxx_success)
        throw error(e);
}

inline void rrdllcxx_t::minus(int n)
{
    const auto e = rrdllcxx_minus(h_, n);
    if (e != rrdllcxx_success)
        throw error(e);
}

inline int rrdllcxx_t::equals() const
{
    int n;
    const auto e = rrdllcxx_equals(h_, &n);
    if (e != rrdllcxx_success)
        throw error(e);
    return n;
}

inline rrdllcxx_t::~rrdllcxx_t()
{
    rrdllcxx_destruct(h_);
}

}//namespace rrdllcxx

#endif//RRDLLCXX_LIB_INL_
