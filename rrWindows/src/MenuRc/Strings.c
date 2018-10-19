/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/MenuRc/Strings.h"

#include <strsafe.h>

RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
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
            return 0;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthA(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return 0;
        }
    }
    CONST size_t count = length1 + length2 + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return 0;
        }
    }
    {
        CONST HRESULT hr = StringCchCatA(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return 0;
        }
    }

    *dest = heap;
    return count;
}

RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
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
            return 0;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthW(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            *dest = NULL;
            return 0;
        }
    }
    CONST size_t count = length1 + length2 + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    {
        CONST HRESULT hr = StringCchCopyW(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return 0;
        }
    }
    {
        CONST HRESULT hr = StringCchCatW(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return 0;
        }
    }

    *dest = heap;
    return count;
}

RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
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
            return 0;
        }
    }
    CONST size_t count = length + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, count, src);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            *dest = NULL;
            return 0;
        }
    }

    *dest = heap;
    return count;
}

RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
StringAllocCopyW(
    _In_     PCWSTR CONST src,
    _Outptr_ PWSTR *CONST dest)
{
    size_t length;
    CONST HRESULT hr1 = StringCchLengthW(src, STRSAFE_MAX_CCH, &length);
    if (FAILED(hr1)) {
        SetLastError(HRESULT_CODE(hr1));
        *dest = NULL;
        return 0;
    }
    CONST size_t count = length + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        *dest = NULL;
        return 0;
    }

    CONST HRESULT hr2 = StringCchCopyW(heap, count, src);
    if (FAILED(hr2)) {
        SetLastError(HRESULT_CODE(hr2));
        HeapFree(GetProcessHeap(), 0, heap);
        *dest = NULL;
        return 0;
    }

    *dest = heap;
    return count;
}
