/**
 * \defgroup g_unique_ptr 独有指针
 * \ingroup g_dyn_mem_mgmt
 *
 * \sa ["unique_ptr (独有指针)"](http://en.cppreference.com/w/cpp/memory/unique_ptr). *cppreference.com*.
 * \author zhengrr
 * \date 2018-1-23 – 25
 * \copyright The MIT License
 *
 * @{
 */

#include <cassert>

#include <memory>

#include <gtest/gtest.h>

#include "cxx_std_ver.hpp"

/// unique_ptr preliminary
TEST(unique_ptr, preliminary) {

#if CXX_STD_14
  auto pint = std::make_unique<int>(666);
#elif CXX_STD_11
  std::unique_ptr<int> pint(new int);
  *pint = 666;
#endif

  EXPECT_EQ(*pint, 666);
}

/** @} */
