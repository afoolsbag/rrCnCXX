/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief “掷骰子”库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2018-04-16
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#ifdef RRWINDOWS_EXPORTS
# define RRWINDOWS_API  __declspec(dllexport)
#else
# define RRWINDOWS_API  __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 掷骰子·美国国家标准学会适配 */
RRWINDOWS_API INT WINAPI DiceA();

/** \brief 掷骰子·宽字符适配 */
RRWINDOWS_API INT WINAPI DiceW();

#ifdef UNICODE
# define Dice DiceW
#else
# define Dice DiceA
#endif

#ifdef __cplusplus
}
#endif
