/// \copyright Unlicense

#pragma once
#ifndef RRCXX_DSA_ALLOCATOR_INL_
#define RRCXX_DSA_ALLOCATOR_INL_

#include "rrcxx/dsa/allocator.hxx"

namespace rrcxx::dsa {

template <typename T>
constexpr allocator<T>::allocator() noexcept
{
    // do nothing
}

template <typename T>
constexpr allocator<T>::allocator(const allocator &other) noexcept
{
    // do nothing
}

template <typename T>
template <typename U>
constexpr allocator<T>::allocator(const allocator<U> &other) noexcept
{
    // do nothing
}

template <typename T>
constexpr allocator<T>::~allocator()
{
    // do nothing
}

template <typename T>
constexpr T* allocator<T>::allocate(std::size_t n)
{
    if (n == 0)
        return nullptr;
    else
        return reinterpret_cast<T *>(::operator new(n * sizeof(T)));
}

template <typename T>
constexpr void allocator<T>::deallocate(T* p, std::size_t n)
{
    ::operator delete(p);
}

}

#endif
