/// \copyright Unlicense

#pragma once
#ifndef RRDLLX_RRDLLX_WRAP_INL_
#define RRDLLX_RRDLLX_WARP_INL_

#include "rrdllx.wrap.hxx"

namespace rrdllx {

inline version_t version()
{
    version_t v;
    const auto e = rrdllx_get_version(&v);
    if (e != rrdllx_success)
        throw exception_t(e);
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

}//namespace rrdllx

#endif//RRDLLX_RRDLLX_WRAP_INL_
