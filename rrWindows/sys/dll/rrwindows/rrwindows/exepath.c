/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "exepath.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

static LPSTR WINAPI ExePathA(VOID)
{
    __declspec(thread) static CHAR StaticBuffer[MAX_PATH];

    if (0 == GetModuleFileNameA(NULL, StaticBuffer, _countof(StaticBuffer)))
        return NULL;
    return StaticBuffer;
}

static LPWSTR WINAPI ExePathW(VOID)
{
    __declspec(thread) static WCHAR StaticBuffer[MAX_PATH];

    if (0 == GetModuleFileNameW(NULL, StaticBuffer, _countof(StaticBuffer)))
        return NULL;
    return StaticBuffer;
}

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecutablePathA(VOID)
{
    return ExePathA();
}

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecutablePathW(VOID)
{
    return ExePathW();
}

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecutableDirectoryPathA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    PathRemoveFileSpecA(path);
    return path;
}

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecutableDirectoryPathW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    PathRemoveFileSpecW(path);
    return path;
}

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
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

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
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

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
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

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
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

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
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

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
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

/**
 * \brief 当前进程的初始化文件路径（ANSI适配）。
 * \details 形如`path\\to\\folder\\file.ini`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
InitializationPathA(VOID)
{
    LPSTR CONST path = ExePathA();
    if (NULL == path)
        return NULL;
    PathRemoveExtensionA(path);
    if (FAILED(StringCchCatA(path, MAX_PATH, ".ini")))
        return NULL;
    return path;
}

/**
 * \brief 当前进程的初始化文件路径（UNICODE适配）。
 * \details 形如`path\\to\\folder\\file.ini`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
InitializationPathW(VOID)
{
    LPWSTR CONST path = ExePathW();
    if (NULL == path)
        return NULL;
    PathRemoveExtensionW(path);
    if (FAILED(StringCchCatW(path, MAX_PATH, L".ini")))
        return NULL;
    return path;

}
