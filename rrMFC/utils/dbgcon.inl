//===-- Debug Console -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 调试控制台。
///
/// \version 2018-04-19
/// \since 2018-04-18
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#ifdef DEBUG
# include <conio.h>
# include <cstdarg>
#
# include "concol.inl"
# include "sysmsgstr.inl"

static VOID
_NewDebugConsole(CONST ConCol textColor, CONST LPCTSTR format, ...)
{
    if (!AllocConsole())
        AfxMessageBox(TEXT("Allocate debug console failed!"), MB_ICONEXCLAMATION);
    SetConFgCol(textColor);
    std::va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
}

static VOID
_DeleteDebugConsole(CONST ConCol textColor, CONST LPCTSTR format, ...)
{
    SetConFgCol(textColor);
    std::va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
    if (!FreeConsole())
        AfxMessageBox(TEXT("Free debug console failed!"), MB_ICONEXCLAMATION);
}

static VOID
_DebugConsolePrint(CONST ConCol textColor, CONST LPCTSTR format, ...)
{
    SetConFgCol(textColor);
    std::va_list va;
    va_start(va, format);
    _tcprintf_s(format, va);
    va_end(va);
}

static VOID
_DebugConsolePrintWindowMessage(
    CONST ConCol textColor, CONST LPCTSTR prefix,
    UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    SetConFgCol(textColor);
    _tcprintf_s(TEXT("%s 0x%04X(%s), with %u, %ld, 0x%p\n"), prefix, message, SysMsgStr(message), wParam, lParam, pResult);
}

# define NewDebugConsole _NewDebugConsole
# define DeleteDebugConsole _DeleteDebugConsole
# define DebugConsolePrintWindowMessage _DebugConsolePrintWindowMessage
# define DebugConsolePrint _DebugConsolePrint
#else//DEBUG
# define NewDebugConsole(x) ((void)(0))
# define DeleteDebugConsole(x) ((void)(0))
# define DebugConsolePrintWindowMessage(x) ((void)(0))
# define DebugConsolePrint(x) ((void)(0))
#endif//DEBUG

#define NewDbgCon NewDebugConsole
#define DelDbgCon DeleteDebugConsole
#define DbgConPrt DebugConsolePrint
#define DbgConPrtWndMsg DebugConsolePrintWindowMessage
