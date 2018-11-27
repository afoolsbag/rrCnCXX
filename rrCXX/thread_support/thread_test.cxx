//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gThreadSimple 线程示例
/// \ingroup gThread
///
/// \version 2018-11-27
/// \since 2018-09-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)
#pragma warning(disable: 5039)

#include <thread>

#include <gtest/gtest.h>

#pragma warning(pop)

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {

/// @addtogroup gThread
/// @{

TEST(thread, test)
{
#if N2497
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

}//namespace rrcxx
