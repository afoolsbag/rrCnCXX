/**
 * \page p_main_func 主函数
 * \tableofcontents
 *
 * \sa main.cpp
 * \author zhengrr
 * \date 2018-1-23 – 24
 * \copyright The MIT License
 *
 *
 * ----------------------------------
 * \section s_return_vs_exit_vs_abort 主函数中 `return`、`exit` 和 `abort` 的差异
 *
 * `exit` 不会触发函数中局部对象的析构, 但静态对象与全局对象不受影响；
 *
 * `abort` 不会触发任何对象的析构，包括局部、静态、和全局对象。
 *
 * \sa ["return statement vs exit() in main()"](http://stackoverflow.com/questions/461449). *Stack Overflow*.
 */
