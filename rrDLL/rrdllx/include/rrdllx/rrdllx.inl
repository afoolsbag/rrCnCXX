/// \copyright Unlicense

#pragma once
#ifndef RRDLLX_RRDLLX_INL_
#define RRDLLX_RRDLLX_INL_

#include "rrdllx.hxx"
#include <memory>

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

inline zstring_t rrdllx_t::alloc_zstring(const std::string &value)
{
    zstring_t tmp = nullptr;
    const auto e = rrdllx_alloc_zstring(h_, value.c_str(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return tmp;
}

inline void rrdllx_t::free_zstring(zstring_t zstring)
{
    const auto e = rrdllx_free_zstring(h_, zstring);
    if (e != rrdllx_success)
        throw exception_t(e);
}

inline zstring_array_t rrdllx_t::alloc_zstring_array(const std::vector<std::string> &value)
{
    const auto v = std::make_unique<zstring_t[]>(value.size());
    for (std::size_t i = 0; i < value.size(); ++i)
        v[i] = value[i].data();
    zstring_array_t tmp = nullptr;
    const auto e = rrdllx_alloc_zstring_array(h_, v.get(), value.size(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return tmp;
}

inline void rrdllx_t::free_zstring_array(zstring_array_t zstring_array)
{
    const auto e = rrdllx_free_zstring_array(h_, zstring_array);
    if (e != rrdllx_success)
        throw exception_t(e);
}

inline binary_t rrdllx_t::alloc_binary(const std::vector<std::uint8_t> &value)
{
    binary_t tmp = nullptr;
    const auto e = rrdllx_alloc_binary(h_, value.data(), value.size(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return tmp;
}

inline void rrdllx_t::free_binary(binary_t binary)
{
    const auto e = rrdllx_free_binary(h_, binary);
    if (e != rrdllx_success)
        throw exception_t(e);
}

inline void rrdllx_t::free_all()
{
    const auto e = rrdllx_free_all(h_);
    if (e != rrdllx_success)
        throw exception_t(e);
}

}//namespace rrdllx

#endif//RRDLLX_RRDLLX_INL_
