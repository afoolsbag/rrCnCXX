/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/Intl/UnicodeAndCharacterSets.h"

RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
MultiByteAllocWideChar(
    _In_  CONST UINT  codepage,
    _In_  PCSTR CONST src,
    _Out_ PWSTR*CONST dest)
{
    CONST INT count = MultiByteToWideChar(codepage, 0, src, -1, NULL, 0);
    if (!count) {
        *dest = NULL;
        return 0;
    }
    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    if (!MultiByteToWideChar(codepage, 0, src, -1, heap, count)) {
        HeapFree(GetProcessHeap(), 0, heap);
        *dest = NULL;
        return 0;
    }

    *dest = heap;
    return count;
}

RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
WideCharAllocMultiByte(
    _In_  CONST UINT  codepage,
    _In_ PCWSTR CONST src,
    _Out_  PSTR*CONST dest)
{
    CONST INT count = WideCharToMultiByte(codepage, 0, src, -1, NULL, 0, NULL, NULL);
    if (!count) {
        *dest = NULL;
        return 0;
    }
    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    if (!WideCharToMultiByte(codepage, 0, src, -1, heap, count, NULL, NULL)) {
        HeapFree(GetProcessHeap(), 0, heap);
        *dest = NULL;
        return 0;
    }

    *dest = heap;
    return count;
}

RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
MultiByteAllocMultiByte(
    _In_ CONST UINT  srcCodepage,
    _In_ PCSTR CONST src,
    _In_ CONST UINT  destCodepage,
    _Out_ PSTR*CONST dest)
{
    PWSTR tmp = NULL;
    if (!MultiByteAllocWideChar(srcCodepage, src, &tmp)) {
        *dest = NULL;
        return 0;
    }

    PSTR heap = NULL;
    CONST INT count = WideCharAllocMultiByte(destCodepage, tmp, &heap);
    HeapFree(GetProcessHeap(), 0, tmp);
    if (!count) {
        *dest = NULL;
        return 0;
    }

    *dest = heap;
    return count;
}
