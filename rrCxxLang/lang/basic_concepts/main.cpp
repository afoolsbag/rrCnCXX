/**
 * \file
 * \brief 主函数
 * \sa \ref p_main_func
 * \author zhengrr
 * \date 2016-10-12 – 2018-1-24
 * \copyright The MIT License
 */

#include <gtest/gtest.h>

/**
 * \brief 主函数
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \return 退出状态（exit status）
 * \sa \ref s_return_vs_exit_vs_abort
 * \sa ["Main function"](http://en.cppreference.com/w/cpp/language/main_function). *cppreference.com*.
 */
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
