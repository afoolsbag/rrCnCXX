/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "exepath.h"

#include <stdlib.h>
#include <Shlwapi.h>

static LPSTR ExePathA(VOID)
{
    __declspec(thread) static CHAR StaticBuffer[MAX_PATH];

    if (ERROR_SUCCESS == GetModuleFileNameA(NULL, StaticBuffer, _countof(StaticBuffer)))
        return StaticBuffer;
    else
        return NULL;
}

static LPWSTR ExePathW(VOID)
{
    __declspec(thread) static WCHAR StaticBuffer[MAX_PATH];

    if (ERROR_SUCCESS == GetModuleFileNameW(NULL, StaticBuffer, _countof(StaticBuffer)))
        return StaticBuffer;
    else
        return NULL;
}

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecuteblePathA(VOID)
{
    return ExePathA();
}

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecuteblePathW(VOID)
{
    return ExePathW();
}

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecutebleDirectoryPathA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (path) {
        PathRemoveFileSpecA(path);
        return path;
    } else {
        return NULL;
    }
}

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecutebleDirectoryPathW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (path) {
        PathRemoveFileSpecW(path);
        return path;
    } else {
        return NULL;
    }
}
