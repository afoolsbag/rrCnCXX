/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-02-27
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_API_H_
#define RRC_API_H_

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

/**
 * \def RRC_DECORATING
 * \brief 修饰约定（Decorating Convention）
 */
#ifdef __cplusplus
#define RRC_DECORATING extern "C"
#else
#define RRC_DECORATING extern
#endif

/**
 * \def RRC_PORTING
 * \brief 导入和导出约定（Import/Export Convention）
 * \note ELF 格式默认符号可见，PE 格式默认符号隐藏。
 */
#ifdef RRC_SHARED
# ifdef RRC_EXPORTS
#  define RRC_PORTING EXPORT
# else
#  define RRC_PORTING IMPORT
# endif
#else
# define RRC_PORTING
#endif

/**
 * \def RRC_CALLING
 * \brief 调用约定（Calling Convention）
 * \note 明确调用约定，以避免因默认调用约定不同而造成的麻烦。
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#define RRC_CALLING CDECL

#endif/*RRC_API_H_*/
