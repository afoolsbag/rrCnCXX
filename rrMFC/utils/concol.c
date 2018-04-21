/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define RRMFC_UTILITIES_EXPORTS
#include "concol.h"

RRMFC_UTILITIES_API ConCol WINAPI
GetConsoleBackGroundColor(VOID)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return (csbi.wAttributes & 0x00F0) >> 4;
}

RRMFC_UTILITIES_API ConCol WINAPI
GetConsoleForeGroundColor(VOID)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x000F;
}

RRMFC_UTILITIES_API VOID WINAPI
SetConsoleColor(
    _In_ CONST ConCol backGroundColor,
    _In_ CONST ConCol foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF00;
    csbi.wAttributes |= backGroundColor << 4;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

RRMFC_UTILITIES_API VOID WINAPI
SetConsoleBackGroundColor(
    _In_ CONST ConCol backGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF0F;
    csbi.wAttributes |= backGroundColor << 4;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

RRMFC_UTILITIES_API VOID WINAPI
SetConsoleForeGroundColor(
    _In_ CONST ConCol foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFFF0;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}
