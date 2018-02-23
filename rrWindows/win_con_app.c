/*===-- Windows Console Application ----------------------------*- C -*-===*//**
 *
 * \defgroup g_win_con_app Windows®控制台应用程序
 * \ingroup g_dvlp
 *
 * \author zhengrr
 * \version 2018-2-23
 * \since 2016-10-12
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \brief Windows®控制台应用入口
 *
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \param envp 环境变量（environment pointer）
 * \return 退出代码（exit code）
 *
 * \sa \ref s_hungarian_notation
 * \sa ["main: Program Startup"](https://docs.microsoft.com/cpp/cpp/main-program-startup). *Microsoft® Docs*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    _putts(TEXT("Hello, windows."));

    return EXIT_SUCCESS;
}

/** @} */
