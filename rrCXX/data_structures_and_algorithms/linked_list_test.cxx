//===-- Linked List ---------------------------------------------*- C++ -*-===//
///
/// \defgroup gLinkedList 链表
/// \ingroup gDataStructuresAndAlgorithms
///
/// \version 2019-11-28
/// \since 2019-11-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>
#include <mutex>

#include <gtest/gtest.h>

#include "rrcxx/dsa/linked_list.hxx"

using namespace std;

namespace rrcxx {

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