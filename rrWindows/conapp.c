/*===-- Windows Console Application ----------------------------*- C -*-===*//**
 *
 * \defgroup gWinConApp Windows®控制台应用程序
 * \ingroup gDvlp
 *
 * \version 2018-04-26
 * \since 2016-10-12
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * \brief Windows®控制台应用入口
 *
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \param envp 环境变量（environment pointer）
 * \return 退出代码（exit code）
 *
 * \sa \ref sHungarianNotation
 * \sa https://docs.microsoft.com/cpp/cpp/main-program-startup
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    _putts(TEXT("Hello, windows."));

    return EXIT_SUCCESS;
}

/** @} */
