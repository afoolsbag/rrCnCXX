/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Console/Consoles.h"

#include <stdarg.h>

#include "rrWindows/Memory/MemoryManagement.h"
#include <rrWindows/MenuRc/Strings.h>

RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleBackGroundColor(VOID)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return ConsoleBlack;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return ConsoleBlack;

    return (ConsoleColor)((info.wAttributes & 0x00F0) >> 4);
}

RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleForeGroundColor(VOID)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return ConsoleWhite;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return ConsoleWhite;

    return (ConsoleColor)(info.wAttributes & 0x000F);
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleColor(
    _In_ CONST ConsoleColor backGroundColor,
    _In_ CONST ConsoleColor foreGroundColor)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return;
    info.wAttributes &= 0xFF00;
    info.wAttributes |= backGroundColor << 4;
    info.wAttributes |= foreGroundColor;

    if (!SetConsoleTextAttribute(hdl, info.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleBackGroundColor(
    _In_ CONST ConsoleColor backGroundColor)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return;
    info.wAttributes &= 0xFF0F;
    info.wAttributes |= backGroundColor << 4;

    if (!SetConsoleTextAttribute(hdl, info.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleForeGroundColor(
    _In_ CONST ConsoleColor foreGroundColor)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return;
    info.wAttributes &= 0xFFF0;
    info.wAttributes |= foreGroundColor;

    if (!SetConsoleTextAttribute(hdl, info.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
ConsoleColorPutA(
    _In_    CONST ConsoleColor color,
    _In_z_ LPCSTR CONST        text)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);

    WriteConsoleA(hdl, text, (DWORD)StringCchLengthSA(text), NULL, NULL);

    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API
VOID
WINAPI
ConsoleColorPutW(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCWSTR CONST        text)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);

    WriteConsoleW(hdl, text, (DWORD)StringCchLengthSW(text), NULL, NULL);

    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API
VOID
WINAPIV
ConsoleColorPrintA(
    _In_                           CONST ConsoleColor color,
    _In_z_ _Printf_format_string_ LPCSTR CONST        format,
    ...)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        goto exit;

    va_list va;
    va_start(va, format);

    SIZE_T cnt = 128;
    PSTR buf = HeapAllocS(cnt * sizeof(CHAR));
    if (!buf)
        goto exit_va_end;

    while (TRUE) {
        CONST HRESULT hr = StringCchVPrintfA(buf, cnt, format, va);
        if (SUCCEEDED(hr)) {
            break;
        } else if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
            cnt *= 2;
            PSTR CONST tmp = HeapReAllocS(buf, cnt * sizeof(CHAR));
            if (!tmp)
                goto exit_buf_free;
            buf = tmp;
            continue;
        } else {
            goto exit_buf_free;
        }
    }

    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);

    WriteConsoleA(hdl, buf, (DWORD)StringCchLengthSA(buf), NULL, NULL);

    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);

exit_buf_free:
    HeapFreeS(buf);
exit_va_end:
    va_end(va);
exit:
    return;
}

RRWINDOWS_API
VOID
WINAPIV
ConsoleColorPrintW(
    _In_                            CONST ConsoleColor color,
    _In_z_ _Printf_format_string_ LPCWSTR CONST        format,
    ...)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        goto exit;

    va_list va;
    va_start(va, format);

    SIZE_T cnt = 128;
    PWSTR buf = HeapAllocS(cnt * sizeof(WCHAR));
    if (!buf)
        goto exit_va_end;

    while (TRUE) {
        CONST HRESULT hr = StringCchVPrintfW(buf, cnt, format, va);
        if (SUCCEEDED(hr)) {
            break;
        } else if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
            cnt *= 2;
            PWSTR CONST tmp = HeapReAllocS(buf, cnt * sizeof(WCHAR));
            if (!tmp)
                goto exit_buf_free;
            buf = tmp;
            continue;
        } else {
            goto exit_buf_free;
        }
    }

    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);

    WriteConsoleW(hdl, buf, (DWORD)StringCchLengthSW(buf), NULL, NULL);

    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);

exit_buf_free:
    HeapFreeS(buf);
exit_va_end:
    va_end(va);
exit:
    return;
}

RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreen(VOID)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == hdl)
        return;

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return;

    CONST DWORD size = info.dwSize.X * info.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterA(hdl, ' ', size, coord, &charsWritten))
        return;
#if 0
    if (!GetConsoleScreenBufferInfo(hdl, &info))
        return;
#endif
    if (!FillConsoleOutputAttribute(hdl, info.wAttributes, size, coord, &charsWritten))
        return;
    if (!SetConsoleCursorPosition(hdl, coord))
        return;
}
