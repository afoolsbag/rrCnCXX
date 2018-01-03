/** \file
 *  \brief *Programming Windows* 1.3.2 & 2.2.4.
 *  \author zhengrr
 *  \date 2016-10-12 – 2018-1-2
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

/** \param hInstance     实例句柄（Instance Handle）；
 *  \param hPrevInstance 前一实例句柄，ＷＩＮ３２中弃置，恒为`NULL`；
 *  \param szCmdLine     命令行（Command Line）；
 *  \param iCmdShow      显示方式。
 *  \return 退出状态（exit status）。
 */
INT WINAPI _tWinMain(HINSTANCE Instance, HINSTANCE PrevInstance,
                     PTSTR CmdLine, INT CmdShow)
{
    MessageBox(NULL, _T("Hello, Windows 98!"), _T("HelloMsg"), MB_OK);

    return EXIT_SUCCESS;
}
