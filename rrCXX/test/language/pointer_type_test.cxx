//===-- Pointer Type --------------------------------------------*- C++ -*-===//
///
/// \defgroup gPtr 指针类型
/// \ingroup gLang
///
/// \sa gMem
///
/// \version 2018-09-20
/// \since 2018-09-20
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <gsl/gsl>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gPtr
/// @{

/// \brief 裸指针。
/// \details 裸指针应仅用于标记位置，不持所有权。
TEST(pointer, naked_pointer)
{
    constexpr int numbers[] {0, 1, 2, 3, 4, 5, 6};
    const int *const ptr {numbers + 6};

    ASSERT_EQ(*ptr, 6);
}

/// \brief 占有指针。
/// \details 若裸指针不恰当地持有了所有权，应将其包装为占有指针，或重构为更好的智能指针。
TEST(pointer, gsl_owner)
{
    gsl::owner<const int *> ptr {new const int {6}};

    ASSERT_EQ(*ptr, 6);

    delete ptr;
    ptr = nullptr;
}

/// \brief 非空指针。
/// \details 若指针不可为空，应将其包装为非空指针。\n
///          常用于限定函数参数。
TEST(pointer, gsl_not_null)
{
    const auto dereference {[](const gsl::not_null<const int *> ptr) {
        return *ptr;
    }};

    constexpr int numbers[] {0, 1, 2, 3, 4, 5, 6};
    const int *const ptr {numbers + 6};

    ASSERT_EQ(dereference(gsl::not_null(ptr)), 6);
}

/// @}

}//namespace rrcxx::test
