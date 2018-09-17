//===-- Application Programming Interface Import/Export Macros --*- C++ -*-===//
///
/// \file
/// \brief 应用程序接口导入、导出宏。
/// \details ELF（Executable and Linkable Format）格式缺省导出符号，
///          PE（Portable Executable）格式缺省隐藏符号。\n
///
/// \version 2018-09-17
/// \since 2017-01-12
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_APIIEMS_HXX_
#define RRCXX_APIIEMS_HXX_

#if defined __unix__ || defined __linux__
# // UNIX or Linux
# if defined __GNUC__
#  // GNU C/C++
#  if 4 <= __GNUC__
#   define API_EXPORT __attribute__ ((visibility ("default")))
#   define API_IMPORT __attribute__ ((visibility ("default")))
#   define API_LOCAL  __attribute__ ((visibility ("hidden")))
#  else
#   define API_EXPORT
#   define API_IMPORT
#   define API_LOCAL
#  endif
# endif
#
#elif defined _WIN32 || defined __CYGWIN__ 
# // Windows or Cygwin
# if defined _MSC_VER
#  // Visual C++
#  define API_EXPORT __declspec(dllexport)
#  define API_IMPORT __declspec(dllimport)
#  define API_LOCAL
# elif defined __GNUC__
#  // GNU C/C++
#  define API_EXPORT __attribute__ ((dllexport))
#  define API_IMPORT __attribute__ ((dllimport))
#  define API_LOCAL
# endif
#
#else
# // Unknown
# define API_EXPORT
# define API_IMPORT
# define API_LOCAL
#
#endif

#ifdef RRCXX_SHARED
# ifdef RRCXX_EXPORTS
#  define RRCXX_API API_EXPORT
# else
#  define RRCXX_API API_IMPORT
# endif
#else
# define RRCXX_API
#endif

#endif//RRCXX_APIIEMS_HXX_
