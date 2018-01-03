/** \file
 *  \brief Ｗｉｎｄｏｗｓ控制台应用程序入口。
 *  \author zhengrr
 *  \date 2016-10-12 – 2018-1-3
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

#include <stdio.h>

/** Ｗｉｎｄｏｗｓ控制台应用程序入口。
 *  \param argc 参数计数（argument count）；
 *  \param argv 参数矢量（argument vector）；
 *  \param envp 环境变量（environment pointer）。
 *  \sa ["main: Program Startup"](https://msdn.microsoft.com/6wd819wh). *MSDN*. */
INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
        _tprintf(_T("Hello, Windows 98!"));

        return EXIT_SUCCESS;
}
