/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "prtdbgstr.h"

#include <strsafe.h>

#include "rrwindows/def.h"

#define BUFFER_SIZE 1024

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAma(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va)
{
    CONST INT cnt = _vscprintf(format, va) + 1/*'\0'*/;
    if (0 == cnt) {
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: _vscprintf failed." ATFUNCNLA);
        return;
    }
    CHAR *CONST buf = HeapAlloc(GetProcessHeap(), 0, cnt * sizeof(CHAR));
    if (NULL == buf) {
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: HeapAlloc failed." ATFUNCNLA);
        return;
    }
    if (FAILED(StringCchVPrintfA(buf, cnt, format, va))) {
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: StringCchVPrintfA failed." ATFUNCNLA);
        goto return_freeheap;
    }
    OutputDebugStringA(buf);

return_freeheap:
    if (FALSE == HeapFree(GetProcessHeap(), 0, buf))
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: HeapFree failed." ATFUNCNLA);
}

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringWma(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va)
{
    CONST INT cnt = _vscwprintf(format, va) + 1/*L'\0'*/;
    if (0 == cnt) {
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error: _vscwprintf failed." ATFUNCNLW);
        return;
    }
    WCHAR *CONST buf = HeapAlloc(GetProcessHeap(), 0, cnt * sizeof(WCHAR));
    if (NULL == buf) {
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, HeapAlloc failed." ATFUNCNLW);
        return;
    }
    if (FAILED(StringCchVPrintfW(buf, cnt, format, va))) {
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, StringCchVPrintfW failed." ATFUNCNLW);
        goto return_freeheap;
    }
    OutputDebugStringW(buf);

return_freeheap:
    if (FALSE == HeapFree(GetProcessHeap(), 0, buf))
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, HeapFree failed." ATFUNCNLW);
}

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAsb(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    switch (StringCchVPrintfA(StaticBuffer, countof(StaticBuffer), format, va)) {
    case S_OK:
        OutputDebugStringA(StaticBuffer);
        break;
    case STRSAFE_E_INVALID_PARAMETER:
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: StringCchVPrintfA failed with STRSAFE_E_INVALID_PARAMETER." ATFUNCNLA);
        break;
    case STRSAFE_E_INSUFFICIENT_BUFFER:
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational warn: StringCchVPrintfA failed with STRSAFE_E_INSUFFICIENT_BUFFER." ATFUNCNLA);
        OutputDebugStringA(StaticBuffer);
        break;
    default:
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: StringCchVPrintfA failed with Unknown HRESULT." ATFUNCNLA);
        break;
    }
}

RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringWsb(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    switch (StringCchVPrintfW(StaticBuffer, countof(StaticBuffer), format, va)) {
    case S_OK:
        OutputDebugStringW(StaticBuffer);
        break;
    case STRSAFE_E_INVALID_PARAMETER:
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error: StringCchVPrintfW failed with STRSAFE_E_INVALID_PARAMETER." ATFUNCNLW);
        break;
    case STRSAFE_E_INSUFFICIENT_BUFFER:
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational warn: StringCchVPrintfW failed with STRSAFE_E_INSUFFICIENT_BUFFER." ATFUNCNLW);
        OutputDebugStringW(StaticBuffer);
        break;
    default:
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error: StringCchVPrintfW failed with Unknown HRESULT." ATFUNCNLW);
        break;
    }
}
