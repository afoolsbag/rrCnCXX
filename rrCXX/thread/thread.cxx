//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \defgroup groupThreadSimple 线程示例
/// \ingroup groupThread
///
/// \version 2020-01-09
/// \since 2018-09-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <thread>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {
/// @addtogroup groupThread
/// @{

TEST(thread, test)
{
#if FEATURE_N2497
    using namespace chrono_literals;

    cout << "main: call thread 1.\n";
    thread thread_1_manager([]() {
        cout << "thread 1: lalala.\n";
        cout << "thread 1: sleep for 400ms.\n";
        this_thread::sleep_for(400ms);
        cout << "thread 1: awake!\n";
    });

    cout << "main: call thread 2.\n";
    thread thread_2_manager([]() {
        cout << "thread 2: yayaya.\n";
        cout << "thread 2: sleep for 200ms.\n";
        this_thread::sleep_for(200ms);
        cout << "thread 2: awake!\n";
    });

    cout << "main: waiting for threads wawkes.\n";
    thread_1_manager.join();
    thread_2_manager.join();
    cout << "main: threads are finished.\n";
#endif
}

TEST(thread, ref)
{
    static const auto func = [](int &i) {
        cout << i;
        ++i;
    };

    int i1 {1}, i2 {2}, i3 {3};
    thread t1 {func, ref(i1)};
    thread t2 {func, ref(i2)};
    thread t3 {func, ref(i3)};
    t1.join();
    t2.join();
    t3.join();
}

/// @}
}
