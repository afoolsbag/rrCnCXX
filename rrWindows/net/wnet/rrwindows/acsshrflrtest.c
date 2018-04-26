/** \copyright The MIT License */

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/acsshrflr.h"
#include "rrwindows/errhdl.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    if (ConnectSharedFolder(
        _T("\\\\127.0.0.1\\path\\to\\folder"),
        _T("username"),
        _T("password")))
        _putts(GetLastErrorText());
    _tsystem(_T("pause"));
    return EXIT_SUCCESS;
}
