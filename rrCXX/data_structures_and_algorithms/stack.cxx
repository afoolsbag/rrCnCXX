//===-- Stack ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gStack 栈
/// \ingroup gDataStructuresAndAlgorithms
///
/// \version 2019-11-28
/// \since 2019-11-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cassert>
#include <memory>
#include <mutex>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {

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

TEST(stack, first_step)
{
    stack<int> stk;
    ASSERT_EQ(stk.size(), 0);
    ASSERT_TRUE(stk.empty());

    stk.push(1);
    ASSERT_EQ(stk.top(), 1);
    ASSERT_EQ(stk.size(), 1);
    ASSERT_FALSE(stk.empty());

    stk.push(2);
    ASSERT_EQ(stk.top(), 2);
    ASSERT_EQ(stk.size(), 2);
    ASSERT_FALSE(stk.empty());

    ASSERT_EQ(stk.pop(), 2);
    ASSERT_EQ(stk.top(), 1);
    ASSERT_EQ(stk.size(), 1);
    ASSERT_FALSE(stk.empty());

    ASSERT_EQ(stk.pop(), 1);
    ASSERT_EQ(stk.size(), 0);
    ASSERT_TRUE(stk.empty());
}

}
