//===-- Array ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 数组。
/// \details 仿照标准库实现的数组。
///
/// \sa <https://zh.cppreference.com/w/cpp/container/array>
///
/// \version 2019-11-29
/// \since 2019-11-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DSA_ARRAY_HXX_
#define RRCXX_DSA_ARRAY_HXX_

#include <cstddef>
#include <array>

namespace rrcxx::dsa {

/// \brief 数组常迭代器。
/// \tparam T 值类型。
/// \tparam N 值数目。
template<
    typename T,
    std::size_t N
> using array_const_iterator = std::_Array_const_iterator<T, N>;

/// \brief 数组迭代器。
/// \tparam T 值类型。
/// \tparam N 值数目。
template<
    typename T,
    std::size_t N
> using array_iterator = std::_Array_iterator<T, N>;

/// \brief 封装固定大小数组的容器。
/// \tparam T 值类型。
/// \tparam N 值数目。
template<
    typename T,
    std::size_t N
> struct array {
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type & ;
    using const_reference = const value_type &;
    using pointer = value_type * ;
    using const_pointer = const value_type *;
    using iterator = array_iterator<T, N>;
    using const_iterator = array_const_iterator<T, N>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // 元素访问

    /// \brief 返回位于指定位置 `pos` 的元素的引用，有边界检查。
    /// \details 若 `pos` 不在容器范围内，则抛出 `std::out_of_range` 类型的异常。
    constexpr reference at(size_type pos);
    constexpr const_reference at(size_type pos) const;

    /// \brief 返回位于指定位置 `pos` 的元素的引用。不进行边界检查。
    constexpr reference operator[](size_type pos);
    constexpr const_reference operator[](size_type pos) const;

    /// \brief 返回到容器首元素的引用。
    /// \details 在空容器上对 `front()` 的调用是未定义的。
    constexpr reference front();
    constexpr const_reference front() const;

    /// \brief 返回到容器中最后一个元素的引用。
    /// \details 在空容器上对 back 的调用是未定义的。
    constexpr reference back();
    constexpr const_reference back() const;

    /// \brief 返回指向作为元素存储工作的底层数组的指针。
    /// \details 指针满足范围 `[data(); data() + size())` 始终是合法范围，即使容器为空（该情况下 `data()` 不可解引用）。
    constexpr T* data() noexcept;
    constexpr const T* data() const noexcept;

    // 迭代器

    /// \brief 返回指向容器首元素的迭代器。
    /// \details 若容器为空，则返回的迭代器将等于 `end()`。
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr const_iterator cbegin() const noexcept;

    /// \brief 返回指向容器末元素后一元素的迭代器。
    /// \details 此元素表现为占位符；试图访问它导致未定义行为。
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
    constexpr const_iterator cend() const noexcept;

    /// \brief 返回指向逆向容器首元素的逆向迭代器。
    /// \details 它对应非逆向容器的末元素。
    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;

    /// \brief 返回指向逆向容器末元素后一元素的逆向迭代器。
    /// \details 它对应非逆向容器首元素的前一元素。此元素表现为占位符，试图访问它导致未定义行为。
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;

    // 容量

    /// \brief 检查容器是否无元素，即是否 `begin() == end()`。
    [[nodiscard]] constexpr bool empty() const noexcept;

    /// \brief 返回容器中的元素数，即 `std::distance(begin(), end())`。
    size_type size() const noexcept;

    /// \brief 返回根据系统或库实现限制的容器可保有的元素最大数量，即对于最大容器的 `std::distance(begin(), end())`。
    constexpr size_type max_size() const noexcept;

    // 操作

    //TODO:

    T elems[N];
};

}

#include "rrcxx/dsa/array.inl"

#endif
