//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gThreadSimple 线程示例
/// \ingroup gThread
///
/// \version 2019-01-28
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
/// @addtogroup gThread
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

/// @}
}
