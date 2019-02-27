/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-02-27
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRX_API_H_
#define RRX_API_H_

/*----------------------------------------------------------------------------*/

#if defined __unix__ || defined __linux__
# if defined __GNUC__
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
#elif defined _WIN32 || defined __CYGWIN__
# if defined __GNUC__
#  define EXPORT __attribute__ ((dllexport))
#  define IMPORT __attribute__ ((dllimport))
#  define LOCAL
# elif defined _MSC_VER
#  define EXPORT __declspec(dllexport)
#  define IMPORT __declspec(dllimport)
#  define LOCAL
# endif
#else
# define EXPORT
# define IMPORT
# define LOCAL
#endif

#if defined __GUNC__
# define CDECL    __attribute__ ((cdecl))
# define FASTCALL __attribute__ ((fastcall))
# define THISCALL __attribute__ ((thiscall))
# define STDCALL  __attribute__ ((stdcall))
#elif defined _MSC_VER
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

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
#define RRX_DECORATING extern "C"
#else
#define RRX_DECORATING extern
#endif

#ifdef RRX_SHARED
# ifdef RRX_EXPORTS
#  define RRX_PORTING EXPORT
# else
#  define RRX_PORTING IMPORT
# endif
#else
# define RRX_PORTING
#endif

#define RRX_CALLING CDECL

#endif/*RRX_API_H_*/
