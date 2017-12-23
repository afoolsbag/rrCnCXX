/** \file
 *  \brief 主函数。
 *  \sa <http://en.cppreference.com/w/cpp/language/main_function>
 *  \author zhengrr
 *  \date 2016-10-12 – 2017-12-21
 *  \copyright The MIT License */

#include <iostream>

/* 议题：在主函数中，使用ｒｅｔｕｒｎ、ｅｘｉｔ、还是ａｂｏｒｔ：
 * 　使用ｅｘｉｔ不会触发函数中局部对象的析构, 但静态对象与全局对象不受影响；
 * 　使用ａｂｏｒｔ则不会触发任何对象的析构，包括局部、静态、和全局对象。
 *
 * 参见：<http://stackoverflow.com/questions/461449> */

int main(int argc, char *argv[])
{
    std::cout << "hello, world" << std::endl;

    /* 主函数中，若无显式返回，则隐式地在末尾返回０。 */
    return 0;
}
