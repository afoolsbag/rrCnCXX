/// \copyright The MIT License

#include "rrcxx/ver.hxx"
#if CXX11 || MSC

#include <thread>

#include <gtest/gtest.h>

namespace {

void thread_alpha_func()
{
    std::cout << "alpha: Thread alpha are called.\n";
}

void thread_beta_func()
{
    std::cout << "beta: Thread beta are called.\n";
}

}// namespace

namespace rrcxx {

TEST(thrd, preliminary)
{
    std::cout << "main: Call ThreadAlpha.\n";
    std::thread thread_alpha(thread_alpha_func);
    std::cout << "main: Call ThreadBeta.\n";
    std::thread thread_beta(thread_beta_func);

    std::cout << "main: Wait for thread alpha finishes.\n";
    thread_alpha.join();
    std::cout << "main: Thread alpha are finished.\n";
    std::cout << "main: Wait for thread beta finishes.\n";
    thread_beta.join();
    std::cout << "main: Thread beta are finished.\n";
}

}// namespace cxx

#endif//CXX11
