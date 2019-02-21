/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Dlls/DynamicLinkLibrary.h"

#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#endif
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrWindows/Intl/UnicodeAndCharacterSets.h"
#include "rrWindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
AllocExecutablePath_CountA(
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    for (DWORD count = MAX_PATH; ; count *= 2) {
        PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
        if (!heap) {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        CONST DWORD length = GetModuleFileNameA(NULL, heap, count);
        if (length < count) {
            if (heapCount)
                *heapCount = count;
            return heap;
        }
        HeapFree(GetProcessHeap(), 0, heap);
    }
}

RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocExecutablePath_CountW(
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    for (DWORD count = MAX_PATH; ; count *= 2) {
        PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
        if (!heap) {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        CONST DWORD length = GetModuleFileNameW(NULL, heap, count);
        if (length < count) {
            if (heapCount)
                *heapCount = count;
            return heap;
        }
        HeapFree(GetProcessHeap(), 0, heap);
    }
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableDirectoryPathA(VOID)
{
    PCWSTR CONST unicode = AllocExecutableDirectoryPathW();
    if (!unicode)
        return NULL;
    PCSTR CONST ansi = WideCharAllocMultiByte(CP_ACP, unicode);
    HeapFree(GetProcessHeap(), 0, (PVOID)unicode);
    if (!ansi)
        return NULL;
    return ansi;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableDirectoryPathW(VOID)
{
    SIZE_T count = 0;
    PWSTR CONST path = AllocExecutablePath_CountW(&count);
    if (!path)
        return NULL;
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    CONST HRESULT hr = PathCchRemoveFileSpec(path, count);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        HeapFree(GetProcessHeap(), 0, path);
        return NULL;
    }
#else
    PathRemoveFileSpecW(path);
#endif
    return path;
}

RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
AllocExecutableName_CountA(
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    PCSTR CONST path = AllocExecutablePathA();
    if (!path)
        return NULL;
    PCSTR CONST name = PathFindFileNameA(path);
    if (name == path) {
        HeapFree(GetProcessHeap(), 0, (PVOID)path);
        return NULL;
    }
    SIZE_T count = 0;
    PSTR CONST heap = StringAllocCopyCA(name, &count);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);

    if (heapCount)
        *heapCount = count;
    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocExecutableName_CountW(
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    PCWSTR CONST path = AllocExecutablePathW();
    if (!path)
        return NULL;
    PCWSTR CONST name = PathFindFileNameW(path);
    if (name == path) {
        HeapFree(GetProcessHeap(), 0, (PVOID)path);
        return NULL;
    }
    SIZE_T count = 0;
    PWSTR CONST heap = StringAllocCopyCW(name, &count);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);

    if (heapCount)
        *heapCount = count;
    return heap;
}


RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableBaseNameA(VOID)
{
    PCWSTR CONST unicode = AllocExecutableBaseNameW();
    if (!unicode)
        return NULL;
    PCSTR CONST ansi = WideCharAllocMultiByte(CP_ACP, unicode);
    HeapFree(GetProcessHeap(), 0, (PVOID)unicode);
    if (!ansi)
        return NULL;
    return ansi;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableBaseNameW(VOID)
{
    SIZE_T count = 0;
    PWSTR CONST name = AllocExecutableName_CountW(&count);
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    CONST HRESULT hr = PathCchRemoveExtension(name, count);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        HeapFree(GetProcessHeap(), 0, name);
        return NULL;
    }
#else
    PathRemoveExtensionW(name);
#endif
    return name;
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableExtensionNameA(VOID)
{
    PCWSTR CONST unicode = AllocExecutableExtensionNameW();
    if (!unicode)
        return NULL;
    PCSTR CONST ansi = WideCharAllocMultiByte(CP_ACP, unicode);
    HeapFree(GetProcessHeap(), 0, (PVOID)unicode);
    if (!ansi)
        return NULL;
    return ansi;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableExtensionNameW(VOID)
{
    SIZE_T count = 0;
    PCWSTR CONST path = AllocExecutablePath_CountW(&count);
    if (!path)
        return NULL;
    PCWSTR ext = NULL;
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    CONST HRESULT hr = PathCchFindExtension(path, count, &ext);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        HeapFree(GetProcessHeap(), 0, (PVOID)path);
        return NULL;
    }
#else
    ext = PathFindExtensionW(path);
#endif
    PCWSTR CONST heap = StringAllocCopyW(ext);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocInitializationPathA(VOID)
{
    PCWSTR CONST unicode = AllocInitializationPathW();
    if (!unicode)
        return NULL;
    PCSTR CONST ansi = WideCharAllocMultiByte(CP_ACP, unicode);
    HeapFree(GetProcessHeap(), 0, (PVOID)unicode);
    if (!ansi)
        return NULL;
    return ansi;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocInitializationPathW(VOID)
{
    SIZE_T count = 0;
    PWSTR CONST path = AllocExecutablePath_CountW(&count);
    if (!path)
        return NULL;
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    CONST HRESULT hr = PathCchRenameExtension(path, count, L".ini");
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        HeapFree(GetProcessHeap(), 0, (PVOID)path);
        return NULL;
    }
#else
    PathRenameExtensionW(path, L".ini");
#endif
    return path;
}
