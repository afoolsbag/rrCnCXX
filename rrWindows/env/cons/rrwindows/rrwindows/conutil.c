/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "conutil.h"

#include <stdarg.h>
#include <conio.h>

RRWINDOWS_API VOID WINAPI
SetConsoleColor(
    _In_ CONST enum ConsoleColor backGroundColor,
    _In_ CONST enum ConsoleColor foreGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    csbi.wAttributes &= 0xFF00;
    csbi.wAttributes |= backGroundColor << 4;
    csbi.wAttributes |= foreGroundColor;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes)) return;
}

RRWINDOWS_API VOID WINAPI
SetConsoleBackGroundColor(
    _In_ CONST enum ConsoleColor backGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    csbi.wAttributes &= 0xFF0F;
    csbi.wAttributes |= backGroundColor << 4;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes)) return;
}

RRWINDOWS_API VOID WINAPI
SetConsoleForeGroundColor(
    _In_ CONST enum ConsoleColor foreGroundColor)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    csbi.wAttributes &= 0xFFF0;
    csbi.wAttributes |= foreGroundColor;
    if (!SetConsoleTextAttribute(stdOutput, csbi.wAttributes)) return;
}

RRWINDOWS_API VOID WINAPIV
ConsoleColorPrintA(
    _In_                           CONST enum ConsoleColor textColor,
    _In_z_ _Printf_format_string_ LPCSTR CONST             format,
    ...)
{
    CONST enum ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (textColor != oldColor)
        SetConsoleForeGroundColor(textColor);
    va_list va; va_start(va, format);
    _vcprintf_s(format, va);
    va_end(va);
    if (oldColor != textColor)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API VOID WINAPIV
ConsoleColorPrintW(
    _In_                            CONST enum ConsoleColor textColor,
    _In_z_ _Printf_format_string_ LPCWSTR CONST             format,
    ...)
{
    CONST enum ConsoleColor oldColor = GetConsoleForeGroundColor();
    if (textColor != oldColor)
        SetConsoleForeGroundColor(textColor);
    va_list va; va_start(va, format);
    _vcwprintf_s(format, va);
    va_end(va);
    if (oldColor != textColor)
        SetConsoleForeGroundColor(oldColor);
}

RRWINDOWS_API VOID WINAPI
ClearConsoleScreenA(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    CONST DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterA(stdOutput, ' ', size, coord, &charsWritten)) return;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    if (!FillConsoleOutputAttribute(stdOutput, csbi.wAttributes, size, coord, &charsWritten)) return;
    if (!SetConsoleCursorPosition(stdOutput, coord)) return;
}

RRWINDOWS_API VOID WINAPI
ClearConsoleScreenW(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    CONST DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
    CONST COORD coord = {0, 0};
    DWORD charsWritten;
    if (!FillConsoleOutputCharacterW(stdOutput, L' ', size, coord, &charsWritten)) return;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return;
    if (!FillConsoleOutputAttribute(stdOutput, csbi.wAttributes, size, coord, &charsWritten)) return;
    if (!SetConsoleCursorPosition(stdOutput, coord)) return;
}
