/** \copyright The Unlicense */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "Debug/_test.h"
#include "Dlls/_test.h"
#include "FileIO/_test.h"
#include "Intl/_test.h"
#include "MenuRc/_test.h"
#include "SysInfo/_test.h"

/**
 * \remarks
 * 控制台应用入口：\n
 * INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[]);\n
 * 桌面应用入口：\n
 * INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpCmdLine, INT nCmdShow);
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    SRunner *CONST tr = srunner_create(NULL);
    srunner_add_suite(tr, tsDebug());
    srunner_add_suite(tr, tsDlls());
    srunner_add_suite(tr, tsFileIO());
    srunner_add_suite(tr, tsIntl());
    srunner_add_suite(tr, tsMenuRc());
    srunner_add_suite(tr, tsSysInfo());
    srunner_run_all(tr, CK_NORMAL);
    CONST INT err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
