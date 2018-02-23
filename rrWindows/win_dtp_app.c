/*===-- Windows Desktop Application ----------------------------*- C -*-===*//**
 *
 * \defgroup g_win_dtp_app Windows®桌面应用程序
 * \ingroup g_dvlp
 *
 * \sa *Programming Windows®* §1.3.2 & §2.2.4
 *
 * \author zhengrr
 * \version 2018-2-23
 * \since 2016-10-12
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
 * \param hInstance     实例句柄（instance handle）
 * \param hPrevInstance 前一实例句柄（previous instance handle），Win32中弃置，恒为`NULL`
 * \param lpCmdLine     命令行（command line）
 * \param nCmdShow      显示方式（command show）
 * \return 退出代码（exit code）
 *
 * \sa ["WinMain entry point"](https://msdn.microsoft.com/library/ms633559). *Microsoft® Developer Network*.
 */
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpCmdLine, INT nCmdShow)
{
    MessageBox(NULL, TEXT("Hello, Windows 98!"), TEXT("Hello Message"), MB_OK);

    return EXIT_SUCCESS;
}

/** @} */
