/** \file
 *  \brief 标准线程。
 *  \sa [Standard library header thread](http://en.cppreference.com/w/cpp/header/thread).
 *  \author zhengrr
 *  \date 2016-11-7 – 2017-12-13
 *  \copyright The MIT License
 */
#include "cxx_standard_version.hpp"

#if    CXX_STD_11 <= CXX_STD_VER \
    && 0          == CXX_GCC_VER

#include <iostream>
#include <thread>

/*
 * 议题："\n" 还是 std::endl
 *
 * 　　除了明确指定二进制输出，"\n" 在底层会依据系统环境自动判断为 "\n"、"\r\n" 或
 * "\r"，因而在输出的含义上，二者等效。
 * 　　真正的区别在于 std::endl 会刷新缓冲区，而 "\n" 不会。因而需要强即时性的输出
 * 宜使用 std::endl，而大段大段的输出则宜使用 "\n"。
 *
 * 　　又，在多线程环境下，std::cout 仅保证单个 << 操作的原子性，所以在多线程环境
 * 中应使用 "\n" 以保证输出不畸形。
 *
 * 参见：<http://stackoverflow.com/questions/213907>
 */

void thread_alpha_func()
{
    std::cout << "alpha: Thread alpha are called.\n";
}

void thread_beta_function()
{
    std::cout << "beta: Thread beta are called.\n";
}

int altmain(int argc, char *argv[])
{
    std::cout << "main: Call ThreadAlpha.\n";
    std::thread thread_alpha(thread_alpha_func);
    std::cout << "main: Call ThreadBeta.\n";
    std::thread thread_beta(thread_beta_function);

    std::cout << "main: Wait for thread alpha finishes.\n";
    thread_alpha.join();
    std::cout << "main: Thread alpha are finished.\n";
    std::cout << "main: Wait for thread beta finishes.\n";
    thread_beta.join();
    std::cout << "main: Thread beta are finished.\n";

    return 0;
}

#ifdef RRCXXLANG_INLINE_NAMESPACE_CPP_
int main(int argc, char* argv[]) { return altmain(argc, argv); }
#endif

#endif// C++11 & !GCC