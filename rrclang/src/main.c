/** \file
 *  \brief 程序入口。
 *  \sa <http://en.cppreference.com/w/c/language/main_function>
 *  \author zhengrr
 *  \date 2016-10-9 – 11-14
 *  \copyright The MIT License
 */
#include <stdlib.h>
#include <stdio.h>

#ifdef ENTRY_SWITCH
/** \brief 程序入口。
 *  \param argc 参数计数。
 *  \param argv 参数向量。
 *  \return 退出状态。
 */
int main(int argc, char *argv[])
{
        printf("hello, world\n");
        return EXIT_SUCCESS;
}
#endif// ENTRY SWITCH
