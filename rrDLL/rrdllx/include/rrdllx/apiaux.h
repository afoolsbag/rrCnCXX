/*===-- Application Programming Interface Auxiliary Macro ------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口辅助宏。
 *
 * \version 2019-03-21
 * \since 2019-03-11
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef APIAUX_H_
#define APIAUX_H_

/**
 * \def EXTERNC
 * \brief C 修饰约定
 */

#ifdef __cplusplus
# define EXTERNC extern "C"
#else
# define EXTERNC extern
#endif

/**
 * \def EXPORT
 * \brief 导出或可见
 *
 * \def IMPORT
 * \brief 导入或可见
 *
 * \def LOCAL
 * \brief 隐藏
 */

#if defined(__unix__) || defined(__linux__)
# if defined(__GNUC__)
#  if 4 <= __GNUC__
#   define EXPORT __attribute__ ((visibility ("default")))
#   define IMPORT __attribute__ ((visibility ("default")))
#   define LOCAL  __attribute__ ((visibility ("hidden")))
#  else
#   define EXPORT
#   define IMPORT
#   define LOCAL
#  endif
# endif
#elif defined(_WIN32) || defined(__CYGWIN__)
# if defined(__GNUC__)
#  define EXPORT __attribute__ ((dllexport))
#  define IMPORT __attribute__ ((dllimport))
#  define LOCAL
# elif defined(_MSC_VER)
#  define EXPORT __declspec(dllexport)
#  define IMPORT __declspec(dllimport)
#  define LOCAL
# endif
#else
# define EXPORT
# define IMPORT
# define LOCAL
#endif

/**
 * \def CDECL
 * \brief C 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/cdecl>
 *
 * \def FASTCALL
 * \brief FAST 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/fastcall>
 *
 * \def THISCALL
 * \brief THIS 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/thiscall>
 *
 * \def STDCALL
 * \brief STD 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/stdcall>
 *
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */

#if defined(__GUNC__)
# define CDECL    __attribute__ ((cdecl))
# define FASTCALL __attribute__ ((fastcall))
# define THISCALL __attribute__ ((thiscall))
# define STDCALL  __attribute__ ((stdcall))
#elif defined(_MSC_VER)
# define CDECL    __cdecl
# define FASTCALL __fastcall
# define THISCALL __thiscall
# define STDCALL  __stdcall
#else
# define CDECL
# define FASTCALL
# define THISCALL
# define STDCALL
#endif

/**
 * \def NOEXCEPT
 * \brief C++ 异常约定
 */

#ifdef __cplusplus
# if 201103L < __cplusplus || 1900 < _MSC_VER
#  define NOEXCEPT noexcept
# else
#  define NOEXCEPT throw()
# endif
#else
# define NOEXCEPT
#endif

#endif/*APIAUX*/
