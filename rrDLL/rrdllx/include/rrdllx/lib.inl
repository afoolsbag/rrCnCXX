/// \copyright Unlicense

#pragma once
#ifndef RRDLLX_LIB_INL_
#define RRDLLX_LIB_INL_

#include "rrdllx/lib.hxx"

namespace rrdllx {

inline version_t version()
{
    version_t v;
    const auto e = rrdllx_get_version(&v);
    if (e != rrdllx_success)
        throw error(e);
    return v;
}

inline rrdllx_t::rrdllx_t()
{
    rrdllx_construct(&h_);
}

inline rrdllx_t::~rrdllx_t()
{
    rrdllx_destruct(h_);
}

inline std::string rrdllx_t::alloc_string()
{
    const char *s = nullptr;
    const auto e = rrdllx_alloc_string(h_, nullptr, &s);
    if (e != rrdllx_success)
        throw error(e);
    return s;
}

}//namespace rrdllx

#endif//RRDLLX_LIB_INL_
