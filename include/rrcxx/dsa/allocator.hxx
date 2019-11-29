//===-- Allocator -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 分配器。
/// \details 仿照标准库实现的分配器。
///
/// \sa <https://zh.cppreference.com/w/cpp/memory/allocator>
///
/// \version 2019-11-29
/// \since 2019-11-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DSA_ALLOCATOR_HXX_
#define RRCXX_DSA_ALLOCATOR_HXX_

#include <cstddef>
#include <type_traits>

namespace rrcxx::dsa {

/// \brief rrCXX-DSA 的默认分配器。
/// \tparam T 值类型。
template <typename T>
struct allocator {
    static_assert(!std::is_const_v<T>,
                  "The C++ Standard forbids containers of const elements "
                  "because allocator<const T> is ill-formed.");

    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assignment = std::true_type;
    using is_always_equal = std::true_type;

    /// \brief 构造默认分配器。
    /// \details 因为默认分配器是无状态的，故构造函数无可见效应。
    /// \sa <https://zh.cppreference.com/w/cpp/memory/allocator/allocator>
    constexpr allocator() noexcept;
    constexpr allocator(const allocator &other) noexcept;
    template<typename U>
    constexpr allocator(const allocator<U> &other) noexcept;

    /// \brief 销毁默认分配器。
    /// \sa <https://zh.cppreference.com/w/cpp/memory/allocator/~allocator>
    constexpr ~allocator();

    /// \brief 分配。
    /// \details 调用 ::operator new(std::size_t, std::align_val_t) 分配 n * sizeof(T) 字节的未初始化存储，但何时及如何调用此函数是未指定的。
    /// \sa <https://zh.cppreference.com/w/cpp/memory/allocator/allocate>
    [[nodiscard]] constexpr T *allocate(std::size_t n);

    /// \brief 解分配。
    /// \details 从指针 p 所引用的存储解分配。
    /// \param p 指针必须是通过先前对 allocate() 获得的指针。
    /// \param n 参数 n 必须等于对原先生成 p 的 allocate() 调用的首参数；否则行为未定义。
    /// \sa <https://zh.cppreference.com/w/cpp/memory/allocator/deallocate>
    constexpr void deallocate(T *p, std::size_t n);
};

}

#include "rrcxx/dsa/allocator.inl"

#endif
