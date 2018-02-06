/*===-- Windows Desktop Application ----------------------------*- C -*-===*//**
 *
 * \defgroup g_dtapp Windows®桌面应用程序
 * \ingroup g_dvlp
 *
 * \sa *Programming Windows®* §1.3.2 & §2.2.4
 *
 * \author zhengrr
 * \date 2016-10-12 – 2018-2-5
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \brief Windows®桌面应用入口
 *
 * \param inst     实例句柄（instance handle）
 * \param instPrev 前一实例句柄，Win32中弃置，恒为`NULL`
 * \param cmdline  命令行（command line）
 * \param cmdshow  显示方式（command show）
 * \return 退出代码（exit code）
 *
 * \sa ["WinMain entry point"](https://msdn.microsoft.com/library/ms633559). *Microsoft® Developer Network*.
 */
INT WINAPI _tWinMain(HINSTANCE inst, HINSTANCE instPrev, PTSTR cmdline, INT cmdshow)
{
	MessageBox(NULL, TEXT("Hello, Windows 98!"), TEXT("Hello Message"), MB_OK);

	return EXIT_SUCCESS;
}

/** @} */
