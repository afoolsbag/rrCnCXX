/*===-- Application Programming Interface Auxiliary Macro ------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口辅助宏。
 *
 * \version 2019-07-19
 * \since 2019-03-11
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef APIAUX_H_
#define APIAUX_H_

/*==============================================================================
 * 语言连接：LANGUAGE LINKAGE
 * 影响调用约定和名字重整，参见 <https://zh.cppreference.com/w/cpp/language/language_linkage>
 *----------------------------------------------------------------------------*/

/**
 * \def EXTERN_C
 * \brief C 语言连接
 */
#ifdef __cplusplus
# ifndef EXTERN_C
# define EXTERN_C extern "C"
# endif
# ifndef EXTERN_C_FP
# define EXTERN_C_FP extern "C"
# endif
# ifndef EXTERN_C_START
# define EXTERN_C_START extern "C" {
# endif
# ifndef EXTERN_C_END
# define EXTERN_C_END }
# endif
#else
# ifndef EXTERN_C
# define EXTERN_C extern
# endif
# ifndef EXTERN_C_FP
# define EXTERN_C_FP
# endif
# ifndef EXTERN_C_START
# define EXTERN_C_START
# endif
# ifndef EXTERN_C_END
# define EXTERN_C_END
# endif
#endif

/**
 * \def EXTERN_CPP
 * \brief C++ 语言连接
 */
#ifdef __cplusplus
# ifndef EXTERN_CPP
# define EXTERN_CPP extern "C++"
# endif
# ifndef EXTERN_CPP_START
# define EXTERN_CPP_START extern "C++" {
# endif
# ifndef EXTERN_CPP_END
# define EXTERN_CPP_END }
# endif
#else
# ifndef EXTERN_CPP
# define EXTERN_CPP extern
# endif
# ifndef EXTERN_CPP_START
# define EXTERN_CPP_START
# endif
# ifndef EXTERN_CPP_END
# define EXTERN_CPP_END
# endif
#endif

/*==============================================================================
 * 符号可见性：SYMBOLS VISIBILITY
 * 参见 <https://gcc.gnu.org/wiki/Visibility>
 * 参见 <https://docs.microsoft.com/cpp/cpp/dllexport-dllimport>
 *----------------------------------------------------------------------------*/

/**
 * \def EXPORT
 * \brief 导出或可见
 * \def IMPORT
 * \brief 导入或可见
 * \def LOCAL
 * \brief 本地或隐藏
 */
#if defined(__unix__) || defined(__linux__)
# if defined(__GNUC__)
#  if (4 <= __GNUC__)
#   ifndef EXPORT
#   define EXPORT __attribute__ ((visibility ("default")))
#   endif
#   ifndef IMPORT
#   define IMPORT __attribute__ ((visibility ("default")))
#   endif
#   ifndef LOCAL
#   define LOCAL __attribute__ ((visibility ("hidden")))
#   endif
#  else
#   ifndef EXPORT
#   define EXPORT
#   endif
#   ifndef IMPORT
#   define IMPORT
#   endif
#   ifndef LOCAL
#   define LOCAL
#   endif
#  endif
# endif
#
#elif defined(_WIN32) || defined(__CYGWIN__)
# if defined(__GNUC__)
#  ifndef EXPORT
#  define EXPORT __attribute__ ((dllexport))
#  endif
#  ifndef IMPORT
#  define IMPORT __attribute__ ((dllimport))
#  endif
#  ifndef LOCAL
#  define LOCAL
#  endif
# elif defined(_MSC_VER)
#  ifndef EXPORT
#  define EXPORT __declspec(dllexport)
#  endif
#  ifndef IMPORT
#  define IMPORT __declspec(dllimport)
#  endif
#  ifndef LOCAL
#  define LOCAL
#  endif
# endif
#
#else
# ifndef EXPORT
# define EXPORT
# endif
# ifndef IMPORT
# define IMPORT
# endif
# ifndef LOCAL
# define LOCAL
# endif
#endif

/*==============================================================================
 * 调用约定：CALLING CONVENTION
 * 参见 <https://docs.microsoft.com/cpp/cpp/cdecl>
 * 参见 <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 *----------------------------------------------------------------------------*/

#if defined(__GUNC__)
# ifndef CDECL
# define CDECL __attribute__ ((cdecl))
# endif
# ifndef FASTCALL
# define FASTCALL __attribute__ ((fastcall))
# endif
# ifndef THISCALL
# define THISCALL __attribute__ ((thiscall))
# endif
# ifndef STDCALL
# define STDCALL __attribute__ ((stdcall))
# endif
#
#elif defined(_MSC_VER)
# ifndef CDECL
# define CDECL __cdecl
# endif
# ifndef FASTCALL
# define FASTCALL __fastcall
# endif
# ifndef THISCALL
# define THISCALL __thiscall
# endif
# ifndef STDCALL
# define STDCALL __stdcall
# endif
#
#else
# ifndef CDECL
# define CDECL
# endif
# ifndef FASTCALL
# define FASTCALL
# endif
# ifndef THISCALL
# define THISCALL
# endif
# ifndef STDCALL
# define STDCALL
# endif
#endif

/*==============================================================================
 * 异常声明：EXCEPTION DECLARATION
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
# if 201103L < __cplusplus || 1900 < _MSC_VER
#  ifndef NOEXCEPT
#  define NOEXCEPT noexcept
#  endif
# else
#  ifndef NOEXCEPT
#  define NOEXCEPT throw()
#  endif
# endif
#
#else
# ifndef NOEXCEPT
# define NOEXCEPT
# endif
#endif

#endif
