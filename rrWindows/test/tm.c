/**
 * \copyright Unlicense
 */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "Console/tsConsole.h"
#include "Debug/tsDebug.h"
#include "Dlls/tsDlls.h"
#include "FileIO/tsFileIO.h"
#include "Intl/tsIntl.h"
#include "MenuRc/tsMenuRc.h"
#include "ProcThread/tsProcThread.h"
#include "Services/tsServices.h"
#include "Shell/tsShell.h"
#include "Sync/tsSync.h"
#include "SysInfo/tsSysInfo.h"
#include "WinSock/tsWinSock.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

/* 控制台应用入口 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    SRunner *CONST tr = srunner_create(NULL);
    srunner_add_suite(tr, tsConsole());
    srunner_add_suite(tr, tsDebug());
    srunner_add_suite(tr, tsDlls());
    srunner_add_suite(tr, tsFileIO());
    srunner_add_suite(tr, tsIntl());
    srunner_add_suite(tr, tsMenuRc());
    srunner_add_suite(tr, tsProcThread());
    srunner_add_suite(tr, tsServices());
    srunner_add_suite(tr, tsShell());
    srunner_add_suite(tr, tsSync());
    srunner_add_suite(tr, tsSysInfo());
    srunner_add_suite(tr, tsWinSock());
    srunner_run_all(tr, CK_NORMAL);
    CONST INT err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}

/* 桌面应用入口 */
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpCmdLine, INT nCmdShow)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);
    return EXIT_SUCCESS;
}
