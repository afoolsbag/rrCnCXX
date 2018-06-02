//===-- Non-Static Data Members ---------------------------------*- C++ -*-===//
///
/// \defgroup g_nst_dat_mbr （对象的）非静态数据成员
/// \ingroup g_class
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

#include "cxxver.hxx"

namespace {

#if N2756
class GamePlayer {
public:
  int mCurrentTurns{0};
};
#else// !N2756
class GamePlayer {
public:
  int mCurrentTurns;
  GamePlayer() : mCurrentTurns(0) {}
};
#endif// !N2756

}// namespace

/// 非静态数据成员初始值设定项
TEST(nst_dat_mbr, nsami) {
  GamePlayer player;
  GTEST_ASSERT_EQ(player.mCurrentTurns, 0);
}

/// @}
