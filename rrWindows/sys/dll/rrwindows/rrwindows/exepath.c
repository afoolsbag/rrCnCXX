/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "exepath.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

#include "rrwindows/def.h"

static
_Success_(return != NULL)
LPSTR
WINAPI
ExePathA(VOID)
{
    __declspec(thread) static CHAR StaticBuffer[MAX_PATH];

    if (0 == GetModuleFileNameA(NULL, StaticBuffer, countof(StaticBuffer)))
        return NULL;
    return StaticBuffer;
}

static
_Success_(return != NULL)
LPWSTR
WINAPI
ExePathW(VOID)
{
    __declspec(thread) static WCHAR StaticBuffer[MAX_PATH];

    if (0 == GetModuleFileNameW(NULL, StaticBuffer, countof(StaticBuffer)))
        return NULL;
    return StaticBuffer;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutablePathA(VOID)
{
    return ExePathA();
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutablePathW(VOID)
{
    return ExePathW();
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableDirectoryPathA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    if (FALSE == PathRemoveFileSpecA(path))
        return NULL;
    return path;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableDirectoryPathW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    if (FALSE == PathRemoveFileSpecW(path))
        return NULL;
    return path;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableNameA(VOID)
{
    LPCSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    LPCSTR CONST name = PathFindFileNameA(path);
    if (name == path)
        return NULL;
    return name;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableNameW(VOID)
{
    LPCWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    LPCWSTR CONST name = PathFindFileNameW(path);
    if (name == path)
        return NULL;
    return name;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableBaseNameA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    LPSTR CONST base = PathFindFileNameA(path);
    if (base == path)
        return NULL;
    PathRemoveExtensionA(base);
    return base;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableBaseNameW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    LPWSTR CONST base = PathFindFileNameW(path);
    if (base == path)
        return NULL;
    PathRemoveExtensionW(base);
    return base;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableExtensionNameA(VOID)
{
    LPCSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    LPCSTR CONST ext = PathFindExtensionA(path);
    if ('\0' == *ext)
        return NULL;
    return ext;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableExtensionNameW(VOID)
{
    LPCWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    LPCWSTR CONST ext = PathFindExtensionW(path);
    if (L'\0' == *ext)
        return NULL;
    return ext;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
InitializationPathA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    if (!PathRenameExtensionA(path, ".ini"))
        return NULL;
    return path;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
InitializationPathW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    if (!PathRenameExtensionW(path, L".ini"))
        return NULL;
    return path;

}
