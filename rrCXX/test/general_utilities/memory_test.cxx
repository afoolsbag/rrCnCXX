//===-- Dynamic Memory Management -------------------------------*- C++ -*-===//
///
/// \defgroup gMem 动态内存管理
/// \ingroup gGen
///
/// \sa gPtr
/// \sa ["动态内存管理"](https://zh.cppreference.com/w/cpp/memory). *cppreference.com*.
///     + 智能指针
///         + 独占指针 `unique_ptr`（C++11）
///         + 共享指针 `shared_ptr`（C++11）
///         + 共享指针的弱引用 `weak_ptr`（C++11）
///         + 自动指针 `auto_ptr`
///
/// \version 2018-09-20
/// \since 2018-01-23
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <thread>
#include <memory>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gMem
/// @{

/// \brief 独占指针。
/// \details 独占指针持有所有权。
TEST(memory, std_unique_ptr)
{
    const auto produce {[]()->std::unique_ptr<int> {
        return std::make_unique<int>(6);
    }};

    const auto consume {[](std::unique_ptr<int> ptr) {
        ptr.reset();
    }};

    auto ptr = produce();
    consume(std::move(ptr));
    ASSERT_FALSE(ptr);
}

/// \brief 共享指针。
/// \details 共享指针共享所有权。
TEST(memory, std_shared_ptr)
{
    const auto tfunc {[](std::shared_ptr<int> ptr) {
        using namespace std::chrono_literals;
        ASSERT_EQ(*ptr, 6);
        std::this_thread::sleep_for(100ms);
        ptr.reset();
    }};

    std::shared_ptr<int> ptr {std::make_shared<int>(6)};
    std::thread t1 {tfunc, ptr}, t2 {tfunc, ptr}, t3 {tfunc, ptr};
    ptr.reset();
    t1.join(); t2.join(); t3.join();
}

/// @}

}//namespace rrcxx::test
