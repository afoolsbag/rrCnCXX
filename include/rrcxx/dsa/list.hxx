//===-- Linked List ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 链表
///
/// \version 2019-11-28
/// \since 2019-11-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DSA_LINKED_LIST_HXX_
#define RRCXX_DSA_LINKED_LIST_HXX_

#include <cstddef>

namespace rrcxx::dsa {

/// \brief 带哨兵的双向循环链表
/// \tparam T 值类型
/// \warning 未考虑并发
template<typename T>
class linked_list {
private:
    struct node {
        T *value {};
        node *prev {};
        node *next {};
    };

public:
    explicit linked_list() noexcept;
    virtual ~linked_list() noexcept;

private:
    node *const sentinel_;  ///< 哨兵
    std::size_t count_;
};

}

#include "rrcxx/dsa/linked_list.inl"

#endif
