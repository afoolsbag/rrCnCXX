/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入/导出宏定义
 * \details ELF（Executable and Linkable Format）缺省导出/导出符号；
 *          PE（Portable Executable）缺省隐藏符号。
 *
 * \version 2018-05-05
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRCXX_API_HXX_
#define RRCXX_API_HXX_

#if defined _WIN32 || defined __CYGWIN__
# if defined _MSC_VER
#  define RRCXX_EXPORT __declspec(dllexport)
#  define RRCXX_IMPORT __declspec(dllimport)
#  define RRCXX_LOCAL
# elif defined __GNUC__
#  define RRCXX_EXPORT __attribute__ ((dllexport))
#  define RRCXX_IMPORT __attribute__ ((dllimport))
#  define RRCXX_LOCAL
# endif
#
#elif defined __unix__ || defined __linux__
# if 4 <= __GNUC__
#  define RRCXX_EXPORT __attribute__ ((visibility ("default")))
#  define RRCXX_IMPORT __attribute__ ((visibility ("default")))
#  define RRCXX_LOCAL  __attribute__ ((visibility ("hidden")))
# else
#  define RRCXX_EXPORT
#  define RRCXX_IMPORT
#  define RRCXX_LOCAL
# endif
#
#else
#  define RRCXX_EXPORT
#  define RRCXX_IMPORT
#  define RRCXX_LOCAL
#
#endif

#ifdef RRCXX_SHARED
# ifdef RRCXX_EXPORTS
#  define RRCXX_API   RRCXX_EXPORT
# else
#  define RRCXX_API   RRCXX_IMPORT
# endif
#else
#  define RRCXX_API
#endif

#endif/*RRCXX_API_HXX_*/
