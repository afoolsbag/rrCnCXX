/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/MenuRc/Strings.h"

#include <strsafe.h>

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCatA(
    _In_     PCSTR CONST src1,
    _In_     PCSTR CONST src2,
    _Outptr_ PSTR *CONST dest)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthA(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return FALSE;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthA(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return FALSE;
        }
    }
    CONST size_t size = length1 + length2 + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, size * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return FALSE;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, size, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return FALSE;
        }
    }
    {
        CONST HRESULT hr = StringCchCatA(heap, size, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return FALSE;
        }
    }

    *dest = heap;
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCatW(
    _In_     PCWSTR CONST src1,
    _In_     PCWSTR CONST src2,
    _Outptr_ PWSTR *CONST dest)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthW(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return FALSE;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthW(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return FALSE;
        }
    }
    CONST size_t size = length1 + length2 + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, size * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return FALSE;
    }

    {
        CONST HRESULT hr = StringCchCopyW(heap, size, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return FALSE;
        }
    }
    {
        CONST HRESULT hr = StringCchCatW(heap, size, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return FALSE;
        }
    }

    *dest = heap;
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCopyA(
    _In_     PCSTR CONST src,
    _Outptr_ PSTR *CONST dest)
{
    size_t length;
    {
        CONST HRESULT hr = StringCchLengthA(src, STRSAFE_MAX_CCH, &length);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return FALSE;
        }
    }
    CONST size_t size = length + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, size * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return FALSE;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, size, src);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return FALSE;
        }
    }

    *dest = heap;
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCopyW(
    _In_     PCWSTR CONST src,
    _Outptr_ PWSTR *CONST dest)
{
    size_t length;
    CONST HRESULT hr1 = StringCchLengthW(src, STRSAFE_MAX_CCH, &length);
    if (FAILED(hr1)) {
        SetLastError(HRESULT_CODE(hr1));
        *dest = NULL;
        return FALSE;
    }
    CONST size_t size = length + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, size * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return FALSE;
    }

    CONST HRESULT hr2 = StringCchCopyW(heap, size, src);
    if (FAILED(hr2)) {
        SetLastError(HRESULT_CODE(hr2));
        HeapFree(GetProcessHeap(), 0, heap);
        *dest = NULL;
        return FALSE;
    }

    *dest = heap;
    return TRUE;
}
