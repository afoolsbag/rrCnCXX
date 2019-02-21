/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Intl/UnicodeAndCharacterSets.h"

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
MultiByteAllocWideChar(
    _In_ CONST UINT  codepage,
    _In_ PCSTR CONST src)
{
    CONST INT count = MultiByteToWideChar(codepage, 0, src, -1, NULL, 0);
    if (!count)
        return NULL;
    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    if (!MultiByteToWideChar(codepage, 0, src, -1, heap, count)) {
        HeapFree(GetProcessHeap(), 0, heap);
        return NULL;
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
WideCharAllocMultiByte(
    _In_  CONST UINT  codepage,
    _In_ PCWSTR CONST src)
{
    CONST INT count = WideCharToMultiByte(codepage, 0, src, -1, NULL, 0, NULL, NULL);
    if (!count)
        return NULL;
    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    if (!WideCharToMultiByte(codepage, 0, src, -1, heap, count, NULL, NULL)) {
        HeapFree(GetProcessHeap(), 0, heap);
        return NULL;
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
MultiByteAllocMultiByte(
    _In_ CONST UINT  cp1,
    _In_ PCSTR CONST src,
    _In_ CONST UINT  cp2)
{
    PCWSTR CONST tmp = MultiByteAllocWideChar(cp1, src);
    if (!tmp)
        return NULL;

    PCSTR CONST heap = WideCharAllocMultiByte(cp2, tmp);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
    return heap;
}
