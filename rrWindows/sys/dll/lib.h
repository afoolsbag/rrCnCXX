/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief “掷骰子”库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2018-04-26
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 掷骰子（ANSI适配）。 */
RRWINDOWS_API INT WINAPI
DiceA(VOID);

/** \brief 掷骰子（UNICODE适配）。 */
RRWINDOWS_API INT WINAPI
DiceW(VOID);

#ifdef UNICODE
# define Dice DiceW
#else
# define Dice DiceA
#endif

#ifdef __cplusplus
}
#endif
