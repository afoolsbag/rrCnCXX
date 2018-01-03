/** \file
 *  \brief *Programming Windows* 1.3.2.
 *  \author zhengrr
 *  \date 2018-1-2
 *  \copyright The MIT License */

#include <windows.h>

/** \param hInstance     实例句柄（Instance Handle）；
 *  \param hPrevInstance 前一实例句柄，ＷＩＮ３２中弃置，恒为`NULL`；
 *  \param szCmdLine     命令行（Command Line）；
 *  \param iCmdShow      显示方式。
 *  \return 退出状态（exit status）。
 *  \sa <http://msdn.microsoft.com/ms633559>
 */
INT WINAPI WinMain(HINSTANCE Instance, HINSTANCE PrevInstance,
                   PSTR CmdLine, INT CmdShow)
{
    MessageBox(NULL, "Hello, Windows 98!", "HelloMsg", MB_OK);

    return EXIT_SUCCESS;
}
