/*===-- Application Programming Interface Auxiliary Macro ------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口辅助宏。
 *
 * \version 2019-06-20
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
#ifndef EXTERNC
#ifdef __cplusplus
# define EXTERNC extern "C"
#else
# define EXTERNC extern
#endif
#endif

/**
 * \def EXPORT
 * \brief 导出或可见
 */
#ifndef EXPORT
#if defined(__unix__) || defined(__linux__)
# if defined(__GNUC__)
#  if 4 <= __GNUC__
#   define EXPORT __attribute__ ((visibility ("default")))
#  else
#   define EXPORT
#  endif
# endif
#elif defined(_WIN32) || defined(__CYGWIN__)
# if defined(__GNUC__)
#  define EXPORT __attribute__ ((dllexport))
# elif defined(_MSC_VER)
#  define EXPORT __declspec(dllexport)
# endif
#else
# define EXPORT
#endif
#endif

/**
 * \def IMPORT
 * \brief 导入或可见
 */
#ifndef IMPORT
#if defined(__unix__) || defined(__linux__)
# if defined(__GNUC__)
#  if 4 <= __GNUC__
#   define IMPORT __attribute__ ((visibility ("default")))
#  else
#   define IMPORT
#  endif
# endif
#elif defined(_WIN32) || defined(__CYGWIN__)
# if defined(__GNUC__)
#  define IMPORT __attribute__ ((dllimport))
# elif defined(_MSC_VER)
#  define IMPORT __declspec(dllimport)
# endif
#else
# define IMPORT
#endif
#endif

/**
 * \def LOCAL
 * \brief 隐藏
 */
#ifndef LOCAL
#if defined(__unix__) || defined(__linux__)
# if defined(__GNUC__)
#  if 4 <= __GNUC__
#   define LOCAL __attribute__ ((visibility ("hidden")))
#  else
#   define LOCAL
#  endif
# endif
#elif defined(_WIN32) || defined(__CYGWIN__)
# if defined(__GNUC__)
#  define LOCAL
# elif defined(_MSC_VER)
#  define LOCAL
# endif
#else
# define LOCAL
#endif
#endif

/**
 * \def CDECL
 * \brief C 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/cdecl>
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#ifndef CDECL
#if defined(__GUNC__)
# define CDECL __attribute__ ((cdecl))
#elif defined(_MSC_VER)
# define CDECL __cdecl
#else
# define CDECL
#endif
#endif

/**
 * \def FASTCALL
 * \brief FAST 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/fastcall>
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#ifndef FASTCALL
#if defined(__GUNC__)
# define FASTCALL __attribute__ ((fastcall))
#elif defined(_MSC_VER)
# define FASTCALL __fastcall
#else
# define FASTCALL
#endif
#endif

/**
 * \def THISCALL
 * \brief THIS 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/thiscall>
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#ifndef THISCALL
#if defined(__GUNC__)
# define THISCALL __attribute__ ((thiscall))
#elif defined(_MSC_VER)
# define THISCALL __thiscall
#else
# define THISCALL
#endif
#endif

/**
 * \def STDCALL
 * \brief STD 调用约定
 * \sa <https://docs.microsoft.com/cpp/cpp/stdcall>
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#ifndef STDCALL
#if defined(__GUNC__)
# define STDCALL __attribute__ ((stdcall))
#elif defined(_MSC_VER)
# define STDCALL __stdcall
#else
# define STDCALL
#endif
#endif

/**
 * \def NOEXCEPT
 * \brief C++ 异常约定
 */
#ifndef NOEXCEPT
#ifdef __cplusplus
# if 201103L < __cplusplus || 1900 < _MSC_VER
#  define NOEXCEPT noexcept
# else
#  define NOEXCEPT throw()
# endif
#else
# define NOEXCEPT
#endif
#endif

#endif
