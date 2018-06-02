/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "dbgprt.h"

#include <stdlib.h>
#include <strsafe.h>

#include "rrwindows/winstr.h"

#define BUFFER_SIZE 1024

RRWINDOWS_API VOID WINAPIV
DebugPrintA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    va_list va; va_start(va, format);
    vsprintf_s(StaticBuffer, _countof(StaticBuffer), format, va);
    va_end(va);
    OutputDebugStringA(StaticBuffer);
}

RRWINDOWS_API VOID WINAPIV
DebugPrintW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    va_list va; va_start(va, format);
    vswprintf_s(StaticBuffer, _countof(StaticBuffer), format, va);
    va_end(va);
    OutputDebugStringW(StaticBuffer);
}
