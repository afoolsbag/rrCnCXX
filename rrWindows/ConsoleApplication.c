/** \file
 *  \brief Windows® 控制台应用入口
 *  \sa [字符集编码与 C/C++ 源文件字符编译乱弹](http://jimmee.iteye.com/blog/2165685)
 *  \sa [UTF8 中文编码处理探究](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 *  \author zhengrr
 *  \date 2016-10-12 – 2018-1-6
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

#include <stdio.h>

/** \brief Windows® 控制台应用入口
 *  \param argc 参数计数（argument count）
 *  \param argv 参数矢量（argument vector）
 *  \param envp 环境变量（environment pointer）
 *  \sa ["main: Program Startup"](https://docs.microsoft.com/cpp/cpp/main-program-startup). *Microsoft® Docs*. */
INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
	system("chcp 65001");
	_tprintf(_T("Hello, Windows 98! 你好"));

	return EXIT_SUCCESS;
}
