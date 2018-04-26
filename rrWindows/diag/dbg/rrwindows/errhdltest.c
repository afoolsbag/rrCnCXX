/** \copyright The MIT License */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/errhdl.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    GetProcessId(NULL);
    _tprintf_s(_T("%s"), GetLastErrorText());
    _tsystem(_T("pause"));
    return EXIT_SUCCESS;
}
