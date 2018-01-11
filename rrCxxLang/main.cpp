/** \file
 *  \brief 程序入口
 *  \sa \ref page_main
 *  \author zhengrr
 *  \date 2016-10-12 – 2018-1-5
 *  \copyright The MIT License */

#include <gtest/gtest.h>

/** \page page_main
 *  \section sec_return_vs_exit_vs_abort 主函数中`return`、`exit`和`abort`的差异
 *
 *  `exit`不会触发函数中局部对象的析构, 但静态对象与全局对象不受影响；
 *
 *  `abort`则不会触发任何对象的析构，包括局部、静态、和全局对象。
 *
 *  \sa ["return statement vs exit() in main()"](http://stackoverflow.com/questions/461449). *Stack Overflow*. */

/// 主函数
/** \param argc 参数计数（argument count）；
 *  \param argv 参数矢量（argument vector）。
 *  \return 退出状态（exit status）。
 *  \sa ["Main function"](http://en.cppreference.com/w/cpp/language/main_function). *cppreference.com*. */
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 主函数中，若无显式返回，则隐式地在末尾返回`0`。
}
