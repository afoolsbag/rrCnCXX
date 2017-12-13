/** \file
 *  \brief 线程.
 *  \author zhengrr
 *  \date 2016-11-7
 *  \copyright The MIT License
 */
#include <iostream>
#include <thread>

namespace {

void ThreadAlpha()
{
    /*
     * 议题："\n" 还是 std::endl
     *
     * 　　除了明确指定二进制输出，\n 在底层会依据系统环境自动判断为 \n、\r\n 或 \r，
     * 因而在输出的含义上，二者区别不大。
     * 　　真正的区别在于 std::endl 会刷新缓冲区，而 \n 不会。因而需要强即时性的输出
     * 宜使用 std::endl，而大段大段的输出则宜使用 \n。
     *
     * 　　又，在多线程环境下，std::cout 仅保证单个 << 操作的原子性，所以在多线程环境
     * 中应使用 \n 以保证输出不畸形。
     *
     * 另见：<http://stackoverflow.com/questions/213907>
     * 　　　ISO/IEC 14882:2011 (C++ 11) §27.4.1.
     */
    std::cout << "ThreadAlpha: Thread alpha are called.\n";
}

void ThreadBeta()
{
    std::cout << "ThreadBeta: Thread beta are called.\n";
}

int altmain()
{
    std::cout << "main: Call ThreadAlpha.\n";
    std::thread alpha(ThreadAlpha);
    std::cout << "main: Call ThreadBeta.\n";
    std::thread beta(ThreadBeta);

    std::cout << "main: Wait for thread alpha finishes.\n";
    alpha.join();
    std::cout << "main: Thread alpha are finished.\n";
    std::cout << "main: Wait for thread beta finishes.\n";
    beta.join();
    std::cout << "main: Thread beta are finished.\n";

    return 0;
}

}// namespace

#ifdef ENTRY_SWITCH
int main() { return altmain(); }
#endif// ENTRY SWITCH
