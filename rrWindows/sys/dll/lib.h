/**
 * \file
 * \brief “掷骰子”库
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 * \author zhengrr
 * \date 2017-1-6 – 2018-1-15
 * \copyright The MIT License
 */

#ifndef RRWINDOWS_LIB_H_
#define RRWINDOWS_LIB_H_

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#ifdef RRWINDOWS_EXPORTS
# define RRWINDOWS_API  __declspec(dllexport)
#else
# define RRWINDOWS_API  __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef int INT;

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

#endif/* RRWINDOWS_LIB_H_*/
