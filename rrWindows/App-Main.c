/**
 * \file
 * \brief Windows®控制台应用入口
 * \sa \ref page_main
 * \author zhengrr
 * \date 2016-10-12 – 2018-1-18
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \page page_main
 * \section sec_hungarian_notation 匈牙利命名法
 *
 * 在业务级编程里，
 * 不要使用系统匈牙利命名法（System Hungarian Notation），那太蠢了；
 * 推荐使用应用匈牙利命名法（Apps Hungarian Notation）。
 *
 * > 匈牙利命名法由 Simonyi Károly 发明，其名称源自对 Simonyi 祖籍的一种讽刺：
 * > 匈牙利人的姓名习惯，与多数其它欧洲人的姓名习惯是互反的，即姓在前而名在后。
 *
 * 类似的，一般变量的描述习惯，是修饰词在前，名词在后，如 `aLongLongLongNameVar`；
 * 而匈牙利命名法将其命名为 `varLongLongLongName`，突出其本质是一个变量（`var`）。
 *
 * \sa ["Hungarian notation"](https://wikipedia.org/wiki/Hungarian_notation). *Wikipedia*.
 * \sa ["Why use prefixes on member variables in C++ classes"](https://stackoverflow.com/questions/1228161). *Stack Overflow*.
 */

/**
 * \brief Windows® 控制台应用入口
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \param envp 环境变量（environment pointer）
 * \sa ["main: Program Startup"](https://docs.microsoft.com/cpp/cpp/main-program-startup). *Microsoft® Docs*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	_tprintf_s(TEXT("Hello, Windows 98!"));

	return EXIT_SUCCESS;
}
