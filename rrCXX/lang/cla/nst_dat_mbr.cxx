//===-- Non-Static Data Members ---------------------------------*- C++ -*-===//
///
/// \defgroup g_nst_dat_mbr （对象的）非静态数据成员
/// \ingroup g_cla
///
/// \sa ["Non-static data members"](http://en.cppreference.com/w/cpp/language/data_members). *cppreference.com*.
///
/// \author zhengrr
/// \date 2017-12-25 – 2018-2-1
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

#include "std.hxx"

#if CXX_STD_11

namespace {

class GamePlayer {
public:
  int mCurrentTurns{0};
};

}// namespace

/// 默认成员初始化器
TEST(nonstatic_data_members, default_member_initializer) {
  GamePlayer player;
  GTEST_ASSERT_EQ(player.mCurrentTurns, 0);
}

#endif// CXX_STD_11
