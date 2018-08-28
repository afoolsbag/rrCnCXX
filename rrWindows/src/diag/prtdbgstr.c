/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rrwindows/diag/prtdbgstr.h"

#include <strsafe.h>

#include "rrwindows/svc/memsim.h"
#include "rrwindows/def.h"

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va)
{
    CONST INT cnt = _vscprintf(format, va) + 1/*'\0'*/;
    if (cnt < 0) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: _vscprintf failed.\n");
        return;
    }
    CHAR *CONST buf = HeapAllocS(cnt * sizeof(CHAR));
    if (NULL == buf) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapAlloc failed.\n");
        return;
    }
    if (FAILED(StringCchVPrintfA(buf, cnt, format, va))) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
        goto return_freeheap;
    }

    OutputDebugStringA(buf);

return_freeheap:
    if (FALSE == HeapFreeS(buf))
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapFree failed.\n");
}

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va)
{
    CONST INT cnt = _vscwprintf(format, va) + 1/*L'\0'*/;
    if (cnt < 0) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: _vscwprintf failed.\n");
        return;
    }
    WCHAR *CONST buf = HeapAllocS(cnt * sizeof(WCHAR));
    if (NULL == buf) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapAlloc failed.\n");
        return;
    }
    if (FAILED(StringCchVPrintfW(buf, cnt, format, va))) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfW failed.\n");
        goto return_freeheap;
    }

    OutputDebugStringW(buf);

return_freeheap:
    if (FALSE == HeapFreeS(buf))
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapFree failed.\n");
}
