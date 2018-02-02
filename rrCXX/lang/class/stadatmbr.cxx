//===-- Static Data Members -------------------------------------*- C++ -*-===//
///
/// \defgroup g_sta_dat_mbr （类的）静态数据成员
/// \ingroup g_class
///
/// \sa ["static members"](http://en.cppreference.com/w/cpp/language/static). *cppreference.com*.
///
/// \author zhengrr
/// \date 2018-2-1
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

namespace {

class GamePlayer {
public:
  static const int kMaxTurns = 50;
};

const int GamePlayer::kMaxTurns;

}// namespace

/// 常静态数据成员
TEST(st_data_mbrs, st_const_data_mbrs) {
  GTEST_ASSERT_EQ(GamePlayer::kMaxTurns, 50);
}

/// @}
