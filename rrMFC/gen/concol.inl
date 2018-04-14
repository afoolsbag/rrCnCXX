//===-- Console Color -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 控制台颜色。
///
/// \version 2018-04-14
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

static WORD GetConsoleForeGroundColor()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x000F;
}

static WORD GetConsoleBackGroundColor()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x00F0;
}

static VOID SetConsoleColor(CONST ConsoleColor backGroundColor, CONST ConsoleColor foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF00;
    csbi.wAttributes |= backGroundColor << 4;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

static VOID SetConsoleBackFroundColor(CONST ConsoleColor backGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFF0F;
    csbi.wAttributes |= backGroundColor << 4;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}

static VOID SetConsoleForeFroundColor(CONST ConsoleColor foreGroundColor)
{
    CONST HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdOutput, &csbi);
    csbi.wAttributes &= 0xFFF0;
    csbi.wAttributes |= foreGroundColor;
    SetConsoleTextAttribute(stdOutput, csbi.wAttributes);
}
