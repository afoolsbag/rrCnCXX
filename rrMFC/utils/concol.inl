//===-- Console Color -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 控制台颜色。
///
/// \version 2018-04-18
/// \since 2018-04-14
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 控制台颜色。
enum ConsoleColor: WORD {
    Black = 0x0, Blue = 0x1, Green = 0x2, Aqua = 0x3,
    Red = 0x4, Purple = 0x5, Yellow = 0x6, White = 0x7,
    Gray = 0x8, LightBlue = 0x9, LightGreen = 0xA, LightAqua = 0xB,
    LightRed = 0xC, LightPurple = 0xD, LightYellow = 0xE, BrightWhite = 0xF
};
/// \brief 控制台颜色（缩写）。
typedef enum ConsoleColor ConCol;

#define GetConFgCol GetConsoleForeGroundColor
static WORD
GetConsoleForeGroundColor()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x000F;
}

#define GetConBgCol GetConsoleBackGroundColor
static WORD
GetConsoleBackGroundColor()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x00F0;
}

#define SetConCol SetConsoleColor
static VOID
SetConsoleColor(CONST ConCol backGroundColor, CONST ConCol foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF00;
    csbi.wAttributes |= backGroundColor << 4;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

#define SetConBgCol SetConsoleBackGroundColor
static VOID
SetConsoleBackGroundColor(CONST ConCol backGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF0F;
    csbi.wAttributes |= backGroundColor << 4;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

#define SetConFgCol SetConsoleForeGroundColor
static VOID
SetConsoleForeGroundColor(CONST ConCol foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFFF0;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}
