/** \copyright The Unlicense */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "Data/FileIO/_test.h"

/**
 * \remarks
 * INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[]);\n
 * INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpCmdLine, INT nCmdShow);
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    SRunner *CONST tr = srunner_create(NULL);
    srunner_add_suite(tr, tsFileIO());
    srunner_run_all(tr, CK_NORMAL);
    CONST INT err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
