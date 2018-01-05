/** \file
 *  \brief Windows® 桌面应用入口
 *  \sa *Programming Windows®* 1.3.2 & 2.2.4
 *  \author zhengrr
 *  \date 2016-10-12 – 2018-1-5
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

/** \brief Windows® 桌面应用入口
 *  \param hInstance     实例句柄（Instance Handle）；
 *  \param hPrevInstance 前一实例句柄，ＷＩＮ３２中弃置，恒为`NULL`；
 *  \param szCmdLine     命令行（Command Line）；
 *  \param codeCmdShow   显示方式。
 *  \return 退出状态（exit status）。
 *  \sa ["WinMain entry point"](http://msdn.microsoft.com/ms633559). *MSDN*. */
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     PTSTR szCmdLine, INT codeCmdShow)
{
        MessageBox(NULL, _T("Hello, Windows 98!"), _T("HelloMsg"), MB_OK);

        return EXIT_SUCCESS;
}
