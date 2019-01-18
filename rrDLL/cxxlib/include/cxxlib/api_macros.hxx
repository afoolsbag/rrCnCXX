//===-- Application Programming Interface Macros ----------------*- C++ -*-===//
///
/// \file
/// \brief 应用程序接口宏。
///
/// \version 2019-01-18
/// \since 2017-01-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef CXXLIB_API_MACROS_HXX_
#define CXXLIB_API_MACROS_HXX_

#ifdef __cplusplus
# define CXXLIB_EXTERN_C extern "C"
#else
# define CXXLIB_EXTERN_C extern
#endif

#if defined __unix__ || defined __linux__
# if defined __GNUC__
#  if 4 <= __GNUC__
#   define CXXLIB_EXPORT __attribute__ ((visibility ("default")))
#   define CXXLIB_IMPORT __attribute__ ((visibility ("default")))
#   define CXXLIB_LOCAL  __attribute__ ((visibility ("hidden")))
#  else
#   define CXXLIB_EXPORT
#   define CXXLIB_IMPORT
#   define CXXLIB_LOCAL
#  endif
# endif
#elif defined _WIN32 || defined __CYGWIN__
# if defined _MSC_VER
#  define CXXLIB_EXPORT __declspec(dllexport)
#  define CXXLIB_IMPORT __declspec(dllimport)
#  define CXXLIB_LOCAL
# elif defined __GNUC__
#  define CXXLIB_EXPORT __attribute__ ((dllexport))
#  define CXXLIB_IMPORT __attribute__ ((dllimport))
#  define CXXLIB_LOCAL
# endif
#else
# define CXXLIB_EXPORT
# define CXXLIB_IMPORT
# define CXXLIB_LOCAL
#endif

#define CXXLIB_DECORATING CXXLIB_EXTERN_C

#ifdef CXXLIB_SHARED
# ifdef CXXLIB_EXPORTS
#  define CXXLIB_IMEXPORT CXXLIB_EXPORT
# else
#  define CXXLIB_IMEXPORT CXXLIB_IMPORT
# endif
#else
#  define CXXLIB_IMEXPORT
#endif

#define CXXLIB_CALLING __cdecl

#endif//CXXLIB_API_MACROS_HXX_
