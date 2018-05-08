//===-- Main Function -------------------------------------------*- C++ -*-===//
///
/// \defgroup gMain 主函数
/// \ingroup gFlCtrl
///
/// \version 2018-05-05
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

/// \brief 主函数
///
/// \param argc 参数计数（argument count）。
/// \param argv 参数矢量（argument vector）。
/// \return 退出状态（exit status）。
///
/// \sa \ref sReturnVsExitVsAbort
/// \sa <http://en.cppreference.com/w/cpp/language/main_function>
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/// @}
