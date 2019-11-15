//===-- Linked List ---------------------------------------------*- C++ -*-===//
///
/// \defgroup gLinkedList 链表
/// \ingroup gDataStructuresAndAlgorithms
///
/// \version 2019-11-07
/// \since 2019-11-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>
#include <mutex>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {

/// \brief 链表（双向循环链表）
/// \tparam T 值类型
/// \warning 未考虑并发
template<typename T>
class linked_list {
public:
    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = value_type & ;
    using const_reference = const value_type &;

private:
    /// \brief 节点
    struct node {
        value_type value;
        weak_ptr<node> prev;
        shared_ptr<node> next;
        explicit node(const_reference v) : value(v) {}
    };

public:
    virtual ~linked_list() noexcept;

    value_type front() const;
    void push_front(const_reference value);
    void pop_front();

    value_type back() const;
    void push_back(const_reference value);
    void pop_back();

    [[nodiscard]] size_type size() const { return count_; }
    [[nodiscard]] bool empty() const { return !count_; }

private:
    shared_ptr<node> first_;
    weak_ptr<node> last_;
    size_type count_{};
};

template <typename T>
linked_list<T>::~linked_list() noexcept
{
    if (auto last = last_.lock())
        last->next.reset();
}

template <typename T>
typename linked_list<T>::value_type linked_list<T>::front() const
{
    assert(first_);
    return first_->value;
}

template <typename T>
void linked_list<T>::push_front(const_reference value)
{
    // TODO:

    ++count_;
}

template <typename T>
void linked_list<T>::pop_front()
{
    // TODO:

    --count_;
}

template <typename T>
typename linked_list<T>::value_type linked_list<T>::back() const
{
    auto last = last_.lock();
    assert(last);
    return last->value;
}

template <typename T>
void linked_list<T>::push_back(const_reference value)
{
    // TODO:

    ++count_;
}

template <typename T>
void linked_list<T>::pop_back()
{
    // TODO:

    --count_;
}

TEST(linked_list, first_step)
{
#if 0
    linked_list<int> list;

    list.push_front(5);
    ASSERT_EQ(5, list.front());
    ASSERT_EQ(5, list.back());

    list.push_back(7);
    ASSERT_EQ(5, list.front());
    ASSERT_EQ(7, list.back());
#endif
}

}