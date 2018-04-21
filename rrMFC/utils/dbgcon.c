/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define DEBUG
#define RRMFC_UTILITIES_EXPORTS
#include "dbgcon.h"

#include <stdarg.h>
#include <conio.h>
#include <tchar.h>

#include "sysmsgstr.h"

RRMFC_UTILITIES_API VOID WINAPI
_NewDebugConsole(
    _In_ CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...)
{
    AllocConsole();
    SetConFgCol(textColor);
    va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
}

RRMFC_UTILITIES_API VOID WINAPI
_DeleteDebugConsole(
    _In_ CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...)
{
    SetConFgCol(textColor);
    va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
    FreeConsole();
}

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrint(
    _In_ CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...)
{
    SetConFgCol(textColor);
    va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
}

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrintWindowMessage(
    _In_ CONST ConCol textColor,
    _In_z_ CONST LPCTSTR prefix,
    _In_ CONST UINT message,
    _In_ CONST WPARAM wParam,
    _In_ CONST LPARAM lParam,
    _In_ CONST PVOID pResult)
{
    SetConFgCol(textColor);
    _tcprintf_s(_T("%s 0x%04X(%s), with %u, %ld, 0x%p\n"), prefix, message, SysMsgStr(message), wParam, lParam, pResult);
}

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrintCommandMessage(
    _In_ CONST ConCol textColor,
    _In_z_ CONST LPCTSTR prefix,
    _In_ CONST UINT nID,
    _In_ CONST INT nCode,
    _In_ CONST PVOID pExtra,
    _In_ CONST PVOID pHandlerInfo)
{
    SetConFgCol(textColor);
    _tcprintf_s(_T("%s %u with %d, 0x%p, 0x%p\n"), prefix, nID, nCode, pExtra, pHandlerInfo);
}
