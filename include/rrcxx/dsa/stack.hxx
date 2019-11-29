//===-- Stack ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 栈
///
/// \version 2019-11-29
/// \since 2019-11-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_DSA_STACK_HXX_
#define RRCXX_DSA_STACK_HXX_

#include <cassert>
#include <memory>
#include <mutex>

#include <gtest/gtest.h>

namespace rrcxx::sda {

/// \brief 栈（容器适配器）
template<
    typename T,
    typename Container = deque<T>
> class stack {
public:
    virtual void push(ValueType value);
};

/// \brief 栈
/// \tparam T 值类型
/// \warning 未考虑并发
template<typename T>
class stack {
    struct node {
        using ptr = unique_ptr<node>;
        T value;
        ptr down;
        explicit node(T value, unique_ptr<node> down) : value {move(value)}, down {move(down)} {}
    };
    using node_ptr = typename node::ptr;

public:
    void push(const T &value)
    {
        node_ptr new_node = make_unique<node>(value, move(top_));
        top_ = move(new_node);
        ++count_;
    }

    T pop()
    {
        node_ptr old_node {top_.release()};
        top_ = move(old_node->down);
        --count_;
        return old_node->value;
    }

    [[nodiscard]] const T &top() const { assert(count_); return top_->value; }
    [[nodiscard]] size_t size() const { return count_; }
    [[nodiscard]] bool empty() const { return !count_; }

private:
    unique_ptr<node> top_;
    size_t count_ {};
};

}

#endif
