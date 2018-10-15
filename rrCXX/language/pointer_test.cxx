//===-- Pointer -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gPtr 指针
/// \ingroup gLang
///
/// \version 2018-10-10
/// \since 2018-09-20
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>
#include <thread>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

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
    owner<const int *> ptr {new const int {6}};

    ASSERT_EQ(*ptr, 6);

    delete ptr;
    ptr = nullptr;
}

/// \brief 独占指针。
/// \details 独占指针持有所有权。
TEST(pointer, std_unique_ptr)
{
    const auto produce {[]()->unique_ptr<int> {
        return make_unique<int>(6);
    }};

    const auto consume {[](unique_ptr<int> ptr) {
        ptr.reset();
    }};

    auto ptr = produce();
    consume(move(ptr));
    ASSERT_FALSE(ptr);
}

/// \brief 共享指针。
/// \details 共享指针共享所有权。
TEST(pointer, std_shared_ptr)
{
    const auto thrd_func {[](shared_ptr<int> ptr) {
        using namespace chrono_literals;
        ASSERT_EQ(*ptr, 6);
        this_thread::sleep_for(100ms);
        ptr.reset();
    }};
 
    shared_ptr<int> ptr {make_shared<int>(6)};

    thread t1 {thrd_func, ptr};
    thread t2 {thrd_func, ptr};
    thread t3 {thrd_func, ptr};

    ptr.reset();

    t1.join();
    t2.join();
    t3.join();
}

/// \brief 非空指针。
/// \details 若指针不可为空，应将其包装为非空指针。\n
///          常用于限定函数参数。
TEST(pointer, gsl_not_null)
{
    const auto dereference {[](const not_null<const int *> ptr) {
        return *ptr;
    }};

    constexpr int numbers[] {0, 1, 2, 3, 4, 5, 6};
    const int *const ptr {numbers + 6};

    ASSERT_EQ(dereference(not_null(ptr)), 6);
}

/// @}

}//namespace rrcxx::test
