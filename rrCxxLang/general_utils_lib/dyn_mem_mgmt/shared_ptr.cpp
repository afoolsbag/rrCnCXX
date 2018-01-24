/**
 * \file
 * \brief
 * \sa \ref p_dyn_mem_mgmt
 * \sa ["shared_ptr (共享指针)"](http://en.cppreference.com/w/cpp/memory/shared_ptr). *cppreference.com*.
 * \author zhengrr
 * \date 2018-1-23 – 23
 * \copyright The MIT License
 */

#include <cassert>

#include <memory>

#include <gtest/gtest.h>

#include "cxx_std_ver.hpp"

TEST(shared_ptr, preliminary) {

#if CXX_STD_14
  auto pint = std::make_shared<int>(666);
#elif CXX_STD_11
  std::shared_ptr<int> pint(new int);
  *pint = 666;
#endif

  EXPECT_EQ(*pint, 666);
}
