/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "prtdbgstr.h"

#include <stdlib.h>

#include "rrwindows/winstr.h"

#define BUFFER_SIZE 1024

RRWINDOWS_API VOID WINAPIV
PrintDebugStringAma(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);

    CONST INT cnt = _vscprintf(format, va) + 1/*'\0'*/;
    CHAR *CONST buf = HeapAlloc(GetProcessHeap(), 0, cnt * sizeof(CHAR));
    if (NULL == buf) {
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: HeapAlloc failed." ATFUNCNLA);
        goto out_endva;
    }
    if (FAILED(StringCchVPrintfA(buf, cnt, format, va))) {
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: StringCchVPrintfA failed." ATFUNCNLA);
        goto out_freeheap;
    }
    OutputDebugStringA(buf);

out_freeheap:
    if (FALSE == HeapFree(GetProcessHeap(), 0, buf))
        OutputDebugStringA(FILELINEA "RrwindowsLib foundational error: HeapFree failed." ATFUNCNLA);
out_endva:
    va_end(va);
}

RRWINDOWS_API VOID WINAPIV
PrintDebugStringAsb(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    va_list va;
    va_start(va, format);

    switch (StringCchVPrintfA(StaticBuffer, _countof(StaticBuffer), format, va)) {
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

    va_end(va);
}

RRWINDOWS_API VOID WINAPIV
PrintDebugStringWma(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);

    CONST INT cnt = _vscwprintf(format, va) + 1/*L'\0'*/;
    WCHAR *CONST buf = HeapAlloc(GetProcessHeap(), 0, cnt * sizeof(WCHAR));
    if (NULL == buf) {
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, HeapAlloc failed." ATFUNCNLW);
        goto out_endva;
    }
    if (FAILED(StringCchVPrintfW(buf, cnt, format, va))) {
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, StringCchVPrintfW failed." ATFUNCNLW);
        goto out_freeheap;
    }
    OutputDebugStringW(buf);

out_freeheap:
    if (FALSE == HeapFree(GetProcessHeap(), 0, buf))
        OutputDebugStringW(FILELINEW L"RrwindowsLib foundational error, HeapFree failed." ATFUNCNLW);
out_endva:
    va_end(va);
}

RRWINDOWS_API VOID WINAPIV
PrintDebugStringWsb(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    va_list va;
    va_start(va, format);

    switch (StringCchVPrintfW(StaticBuffer, _countof(StaticBuffer), format, va)) {
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

    va_end(va);
}
