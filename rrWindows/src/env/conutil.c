/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rrwindows/env/conutil.h"

#include <stdarg.h>
#include <conio.h>

RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleBackGroundColor(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return Black;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return Black;
    return (ConsoleColor)((csbi.wAttributes & 0x00F0) >> 4);
}

RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleForeGroundColor(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return White;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return White;
    return (ConsoleColor)(csbi.wAttributes & 0x000F);
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleColor(
    _In_ CONST ConsoleColor backGroundColor,
    _In_ CONST ConsoleColor foreGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    csbi.wAttributes &= 0xFF00;
    csbi.wAttributes |= backGroundColor << 4;
    csbi.wAttributes |= foreGroundColor;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleBackGroundColor(
    _In_ CONST ConsoleColor backGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    csbi.wAttributes &= 0xFF0F;
    csbi.wAttributes |= backGroundColor << 4;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
SetConsoleForeGroundColor(
    _In_ CONST ConsoleColor foreGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    csbi.wAttributes &= 0xFFF0;
    csbi.wAttributes |= foreGroundColor;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes))
        return;
}

RRWINDOWS_API
VOID
WINAPI
ConsoleColorPutA(
    _In_    CONST ConsoleColor color,
    _In_z_ LPCSTR CONST        text)
{
    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);
    _cputs(text);
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
    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);
    _cputws(text);
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
    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);
    va_list va;
    va_start(va, format);
    _vcprintf_s(format, va);
    va_end(va);
    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API
VOID
WINAPIV
ConsoleColorPrintW(
    _In_                            CONST ConsoleColor color,
    _In_z_ _Printf_format_string_ LPCWSTR CONST        format,
    ...)
{
    CONST ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (color != oldColor)
        SetConsoleForeGroundColor(color);
    va_list va;
    va_start(va, format);
    _vcwprintf_s(format, va);
    va_end(va);
    if (oldColor != color)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreenA(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    CONST DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterA(stdOutput, ' ', size, coord, &charsWritten))
        return;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    if (!FillConsoleOutputAttribute(stdOutput, csbi.wAttributes, size, coord, &charsWritten))
        return;
    if (!SetConsoleCursorPosition(stdOutput, coord))
        return;
}

RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreenW(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    CONST DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterW(stdOutput, L' ', size, coord, &charsWritten))
        return;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi))
        return;
    if (!FillConsoleOutputAttribute(stdOutput, csbi.wAttributes, size, coord, &charsWritten))
        return;
    if (!SetConsoleCursorPosition(stdOutput, coord))
        return;
}
