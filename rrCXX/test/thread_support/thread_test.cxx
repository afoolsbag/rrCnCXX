//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gThrdSmp 线程示例
/// \ingroup gThrd
///
/// \version 2018-09-17
/// \since 2018-09-17
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <thread>

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// @addtogroup gThrd
/// @{

TEST(thread, test)
{
#if N2497
    using namespace std::chrono_literals;

    std::cout << "main: call thread 1.\n";
    std::thread thread_1_manager([]() {
        std::cout << "thread 1: lalala.\n";
        std::cout << "thread 1: sleep for 400ms.\n";
        std::this_thread::sleep_for(400ms);
        std::cout << "thread 1: awake!\n";
    });

    std::cout << "main: call thread 2.\n";
    std::thread thread_2_manager([]() {
        std::cout << "thread 2: yayaya.\n";
        std::cout << "thread 2: sleep for 200ms.\n";
        std::this_thread::sleep_for(200ms);
        std::cout << "thread 2: awake!\n";
    });

    std::cout << "main: waiting for threads wawkes.\n";
    thread_1_manager.join();
    thread_2_manager.join();
    std::cout << "main: threads are finished.\n";
#endif
}

/// @}

}//namespace rrcxx::test
