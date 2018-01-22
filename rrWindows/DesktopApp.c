/**
 * \file
 * \brief Windows®桌面应用程序入口
 * \sa *Programming Windows®* §1.3.2 & §2.2.4
 * \author zhengrr
 * \date 2016-10-12 – 2018-1-18
 * \copyright The MIT License
 */

#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \brief Windows® 桌面应用入口
 * \param hInstance     实例句柄（Instance Handle）
 * \param hPrevInstance 前一实例句柄，Win32 中弃置，恒为`NULL`
 * \param szCmdLine     命令行（Command Line）
 * \param codeCmdShow   显示方式
 * \return 退出状态（exit status）
 * \sa ["WinMain entry point"](https://msdn.microsoft.com/library/ms633559). *Microsoft® Developer Network*.
 */
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		     PTSTR szCmdLine, INT codeCmdShow)
{
	MessageBox(NULL, TEXT("Hello, Windows 98!"), TEXT("HelloMsg"), MB_OK);

	return EXIT_SUCCESS;
}
