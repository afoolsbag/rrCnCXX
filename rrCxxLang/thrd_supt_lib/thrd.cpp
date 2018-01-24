/**
 * \file
 * \brief 线程支持库
 * \sa \ref p_thrd_supt_lib
 * \sa \ref index
 * \author zhengrr
 * \date 2016-11-7 – 2018-1-24
 * \copyright The MIT License
 */

#include "cxx_std_ver.hpp"

#if CXX_STD_11 && !CXX_GNUC_VER

#include <thread>

#include <gtest/gtest.h>

namespace {

void thread_alpha_func() {
  std::cout << "alpha: Thread alpha are called.\n";
}

void thread_beta_func() {
  std::cout << "beta: Thread beta are called.\n";
}

}// namespace

/**
 * \brief GoogleTest thrd preliminary
 * \sa \ref s_stdendl_vs_n
 * \sa ["thread"](http://cplusplus.com/reference/thread/thread/). *The C++ Resources Network*.
 * \sa ["Thread support library (线程支持库)"](http://en.cppreference.com/w/cpp/thread). *cppreference.com*.
 */
TEST(thrd, preliminary) {
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

#endif// CXX_STD_11 && !CXX_GNUC_VER
