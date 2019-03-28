/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Console/Consoles.h"

#include <stdarg.h>

#include "rrWindows/Memory/MemoryManagement.h"
#include "rrWindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
VPrintfConsoleA(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCSTR  format,
    _In_                          va_list argList)
{
    BOOL rv = FALSE;

    SIZE_T cnt = 128;
    PSTR buf = HeapAllocS(cnt * sizeof(CHAR));
    if (!buf)
        goto exit;

    while (TRUE) {
        CONST HRESULT hr = StringCchVPrintfA(buf, cnt, format, argList);
        if (SUCCEEDED(hr)) {
            break;
        } else if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
            cnt *= 2;
            CONST PSTR tmp = HeapReAllocS(buf, cnt * sizeof(CHAR));
            if (!tmp)
                goto exit_buf_free;
            buf = tmp;
            continue;
        } else {
            goto exit_buf_free;
        }
    }

    rv = WriteConsoleA(hConsoleOutput, buf, (DWORD)StringCchLengthSA(buf), NULL, NULL);

exit_buf_free:
    HeapFreeS(buf);
exit:
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
VPrintfConsoleW(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCWSTR format,
    _In_                          va_list argList)
{
    BOOL rv = FALSE;

    SIZE_T cnt = 128;
    PWSTR buf = HeapAllocS(cnt * sizeof(WCHAR));
    if (!buf)
        goto exit;

    while (TRUE) {
        CONST HRESULT hr = StringCchVPrintfW(buf, cnt, format, argList);
        if (SUCCEEDED(hr)) {
            break;
        } else if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
            cnt *= 2;
            CONST PWSTR tmp = HeapReAllocS(buf, cnt * sizeof(WCHAR));
            if (!tmp)
                goto exit_buf_free;
            buf = tmp;
            continue;
        } else {
            goto exit_buf_free;
        }
    }

    rv = WriteConsoleW(hConsoleOutput, buf, (DWORD)StringCchLengthSW(buf), NULL, NULL);

exit_buf_free:
    HeapFreeS(buf);
exit:
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfConsoleA(
    _In_                          HANDLE hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...)
{
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleA(hConsoleOutput, format, va);
    va_end(va);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfConsoleW(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCWSTR format,
    ...)
{
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleW(hConsoleOutput, format, va);
    va_end(va);
    return rv;
}

#ifdef _UNICODE
# define PrintfConsole PrintfConsoleW
#else
# define PrintfConsole PrintfConsoleA
#endif

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStdoutA(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...)
{
    CONST HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleA(outHdl, format, va);
    va_end(va);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStdoutW(
    _In_z_ _Printf_format_string_ LPCWSTR format,
    ...)
{
    CONST HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleW(outHdl, format, va);
    va_end(va);
    return rv;
}

#ifdef _UNICODE
# define PrintfStdout PrintfStdoutW
#else
# define PrintfStdout PrintfStdoutA
#endif

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStderrA(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...)
{
    HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleA(errHdl, format, va);
    va_end(va);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStderrW(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...)
{
    HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    va_list va;
    va_start(va, format);
    CONST BOOL rv = VPrintfConsoleA(errHdl, format, va);
    va_end(va);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ClearConsoleScreen(
    _In_ HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &info))
        return FALSE;

    CONST DWORD size = info.dwSize.X * info.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterA(hConsoleOutput, ' ', size, coord, &charsWritten))
        return FALSE;
#if 0
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return FALSE;
#endif
    if (!FillConsoleOutputAttribute(hConsoleOutput, info.wAttributes, size, coord, &charsWritten))
        return FALSE;
    if (!SetConsoleCursorPosition(hConsoleOutput, coord))
        return FALSE;
    return TRUE;
}
