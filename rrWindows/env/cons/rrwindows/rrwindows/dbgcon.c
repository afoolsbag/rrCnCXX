/** \copyright The MIT License */

#define DEBUG
#define RRWINDOWS_EXPORTS
#include "dbgcon.h"

#include <stdarg.h>
#include <conio.h>

RRWINDOWS_API VOID WINAPIV
DebugConsolePrintA(
    _In_                          CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCSTR format,
    ...)
{
    SetConFgCol(textColor);
    va_list va;
    va_start(va, format);
    _vcprintf_s(format, va);
    va_end(va);
}

RRWINDOWS_API VOID WINAPIV
DebugConsolePrintW(
    _In_                          CONST ConCol  textColor,
    _In_z_ _Printf_format_string_ CONST LPCWSTR format,
    ...)
{
    SetConFgCol(textColor);
    va_list va;
    va_start(va, format);
    _vcwprintf_s(format, va);
    va_end(va);
}