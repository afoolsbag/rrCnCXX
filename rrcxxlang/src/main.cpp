/** \file
 *  \brief 主函数。
 *  \sa [Main function](http://en.cppreference.com/w/cpp/language/main_function).
 *  \author zhengrr
 *  \date 2016-10-12 – 2017-12-13
 *  \copyright The MIT License
 */
#include <iostream>

/*
 * 议题：在 main 函数中，使用 return、exit()、还是 abort()：
 *
 * 　　使用 exit() 将不会触发函数中局部对象的析构, 但静态对象与全局对象不受影响；
 * 　　使用 abort() 则不会触发任何对象的析构，包括局部、静态、和全局对象。
 *
 * 参见：<http://stackoverflow.com/questions/461449>。
 */

int altmain(int argc, char *argv[])
{
    std::cout << "hello, world" << std::endl;

    return 0;
}

#ifdef RRCXXLANG_MAIN_CPP_
int main(int argc, char* argv[]) { return altmain(argc, argv); }
#endif
