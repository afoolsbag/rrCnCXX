//===-- Main Function -------------------------------------------*- C++ -*-===//
///
/// \defgroup gMain 主函数
/// \ingroup gLanguage
///
/// \version 2018-11-27
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)

#include <gtest/gtest.h>

#pragma warning(pop)

namespace rrcxx {

/// \addtogroup gMain
/// @{

/// \brief 入口点（主函数）。
///
/// \param argc 参数计数（argument count）。
/// \param argv 参数矢量（argument vector）。
/// \return 退出状态（exit status）。
///
/// \sa \ref sReturnVsExitVsAbort
/// \sa <https://zh.cppreference.com/w/cpp/language/main_function>
int entry_point(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/// @}

}//namespace rrcxx
