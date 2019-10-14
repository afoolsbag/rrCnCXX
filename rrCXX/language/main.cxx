//===-- Main Function -------------------------------------------*- C++ -*-===//
///
/// \defgroup gMain 主函数
/// \ingroup gLanguage
///
/// \version 2019-08-20
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <locale>

#include <gtest/gtest.h>

using namespace std;

/// \brief 入口点（主函数）。
///
/// \param argc 参数计数（argument count）。
/// \param argv 参数矢量（argument vector）。
/// \return 退出状态（exit status）。
///
/// \sa \ref sReturnVsExitVsAbort
/// \sa <https://zh.cppreference.com/w/cpp/language/main_function>
int main(int argc, char *argv[])
{
#ifndef NDEBUG
    locale::global(locale {"zh_CN.UTF-8"});
#endif
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

namespace rrcxx {
/// \addtogroup gMain
/// @{

/// @}
}
