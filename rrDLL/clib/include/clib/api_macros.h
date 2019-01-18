/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-01-18
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef CLIB_API_MACROS_H_
#define CLIB_API_MACROS_H_

#ifdef __cplusplus
# define CLIB_EXTERN_C extern "C"
#else
# define CLIB_EXTERN_C extern
#endif

#if defined __unix__ || defined __linux__
# if defined __GNUC__
#  if 4 <= __GNUC__
#   define CLIB_EXPORT __attribute__ ((visibility ("default")))
#   define CLIB_IMPORT __attribute__ ((visibility ("default")))
#   define CLIB_LOCAL  __attribute__ ((visibility ("hidden")))
#  else
#   define CLIB_EXPORT
#   define CLIB_IMPORT
#   define CLIB_LOCAL
#  endif
# endif
#elif defined _WIN32 || defined __CYGWIN__
# if defined _MSC_VER
#  define CLIB_EXPORT __declspec(dllexport)
#  define CLIB_IMPORT __declspec(dllimport)
#  define CLIB_LOCAL
# elif defined __GNUC__
#  define CLIB_EXPORT __attribute__ ((dllexport))
#  define CLIB_IMPORT __attribute__ ((dllimport))
#  define CLIB_LOCAL
# endif
#else
# define CLIB_EXPORT
# define CLIB_IMPORT
# define CLIB_LOCAL
#endif

/**
 * \brief 修饰约定（Decorating Convention）
 */
#define CLIB_DECORATING CLIB_EXTERN_C

/**
 * \macro CLIB_PORTING
 * \brief 导入和导出约定（import/export convention）
 * \note ELF 格式默认符号可见，PE 格式默认符号隐藏。
 */
#ifdef CLIB_SHARED
# ifdef CLIB_EXPORTS
#  define CLIB_IMEXPORT CLIB_EXPORT
# else
#  define CLIB_IMEXPORT CLIB_IMPORT
# endif
#else
#  define CLIB_IMEXPORT
#endif

/**
 * \brief 调用约定（Calling Convention）
 * \note 明确调用约定，以避免因默认调用约定不同而造成的麻烦。
 * \sa <https://stackoverflow.com/questions/3404372/stdcall-and-cdecl>
 */
#define CLIB_CALLING __cdecl

#endif/*CLIB_API_MACROS_H_*/
