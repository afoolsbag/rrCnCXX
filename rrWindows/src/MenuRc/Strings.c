/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrwindows/MenuRc/Strings.h"

#include <strsafe.h>

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
StringAllocCatA(
    _In_ PCSTR CONST src1,
    _In_ PCSTR CONST src2)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthA(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthA(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    CONST size_t count = length1 + length2 + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatA(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
StringAllocCatW(
    _In_ PCWSTR CONST src1,
    _In_ PCWSTR CONST src2)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthW(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthW(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    CONST size_t count = length1 + length2 + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    {
        CONST HRESULT hr = StringCchCopyW(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatW(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
StringAllocCat3A(
    _In_ PCSTR CONST src1,
    _In_ PCSTR CONST src2,
    _In_ PCSTR CONST src3)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthA(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthA(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length3;
    {
        CONST HRESULT hr = StringCchLengthA(src3, STRSAFE_MAX_CCH, &length3);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    CONST size_t count = length1 + length2 + length3 + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatA(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatA(heap, count, src3);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
StringAllocCat3W(
    _In_ PCWSTR CONST src1,
    _In_ PCWSTR CONST src2,
    _In_ PCWSTR CONST src3)
{
    size_t length1;
    {
        CONST HRESULT hr = StringCchLengthW(src1, STRSAFE_MAX_CCH, &length1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length2;
    {
        CONST HRESULT hr = StringCchLengthW(src2, STRSAFE_MAX_CCH, &length2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    size_t length3;
    {
        CONST HRESULT hr = StringCchLengthW(src3, STRSAFE_MAX_CCH, &length3);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    CONST size_t count = length1 + length2 + length3 + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    {
        CONST HRESULT hr = StringCchCopyW(heap, count, src1);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatW(heap, count, src2);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }
    {
        CONST HRESULT hr = StringCchCatW(heap, count, src3);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }

    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
StringAllocCopyCA(
    _In_        PCSTR CONST src,
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    size_t length;
    {
        CONST HRESULT hr = StringCchLengthA(src, STRSAFE_MAX_CCH, &length);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return NULL;
        }
    }
    CONST size_t count = length + 1;

    PSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(CHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    {
        CONST HRESULT hr = StringCchCopyA(heap, count, src);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            HeapFree(GetProcessHeap(), 0, heap);
            return NULL;
        }
    }

    if (heapCount)
        *heapCount = count;
    return heap;
}

RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
StringAllocCopyCW(
    _In_       PCWSTR CONST src,
    _Out_opt_ PSIZE_T CONST heapCount)
{
    if (heapCount)
        *heapCount = 0;

    size_t length;
    CONST HRESULT hr1 = StringCchLengthW(src, STRSAFE_MAX_CCH, &length);
    if (FAILED(hr1)) {
        SetLastError(HRESULT_CODE(hr1));
        return NULL;
    }
    CONST size_t count = length + 1;

    PWSTR CONST heap = HeapAlloc(GetProcessHeap(), 0, count * sizeof(WCHAR));
    if (!heap) {
        SetLastError(ERROR_OUTOFMEMORY);
        return NULL;
    }

    CONST HRESULT hr2 = StringCchCopyW(heap, count, src);
    if (FAILED(hr2)) {
        SetLastError(HRESULT_CODE(hr2));
        HeapFree(GetProcessHeap(), 0, heap);
        return NULL;
    }

    if (heapCount)
        *heapCount = count;
    return heap;
}
