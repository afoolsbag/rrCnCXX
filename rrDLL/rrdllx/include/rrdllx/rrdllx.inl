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

inline byte8_parray_t rrdllx_t::alloc_byte8_array(const std::vector<std::uint8_t> &value)
{
    byte8_sarray_t tmp {};
    const auto e = rrdllx_alloc_byte8_array(h_, value.data(), value.size(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return std::make_pair(tmp.size, tmp.data);
}

inline void rrdllx_t::free_byte8_array(byte8_rarray_t byte8_rarray)
{
    const auto e = rrdllx_free_byte8_array(h_, byte8_rarray);
    if (e != rrdllx_success)
        throw exception_t(e);
}

inline char_parray_t rrdllx_t::alloc_char_array(const std::vector<char> &value)
{
    char_sarray_t tmp {};
    const auto e = rrdllx_alloc_char_array(h_, value.data(), value.size(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return std::make_pair(tmp.size, tmp.data);
}

inline void rrdllx_t::free_char_array(char_rarray_t char_rarray)
{
    const auto e = rrdllx_free_char_array(h_, char_rarray);
    if (e != rrdllx_success)
        throw exception_t(e);
}

inline zstring_t rrdllx_t::alloc_zstring(const std::string &value)
{
    zstring_t tmp = nullptr;
    const auto e = rrdllx_alloc_zstring(h_, value.c_str(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return tmp;
}

inline zstring_t rrdllx_t::alloc_last_internal_error_zstring()
{
    zstring_t tmp = nullptr;
    const auto e = rrdllx_alloc_last_internal_error_zstring(h_, &tmp);
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

inline zstring_parray_t rrdllx_t::alloc_zstring_array(const std::vector<std::string> &value)
{
    const auto v = std::make_unique<zstring_t[]>(value.size());
    for (std::size_t i = 0; i < value.size(); ++i)
        v[i] = value[i].data();

    zstring_sarray_t tmp {};
    const auto e = rrdllx_alloc_zstring_array(h_, v.get(), value.size(), &tmp);
    if (e != rrdllx_success)
        throw exception_t(e);
    return std::make_pair(tmp.size, tmp.data);
}

inline void rrdllx_t::free_zstring_array(zstring_rarray_t zstring_array)
{
    const auto e = rrdllx_free_zstring_array(h_, zstring_array);
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
