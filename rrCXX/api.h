/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入/导出宏定义
 * \details ELF（Executable and Linkable Format）缺省导出/导出符号；
 *          PE（Portable Executable）缺省隐藏符号。
 *
 * \version 2018-03-31
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRCXX_API_H_
#define RRCXX_API_H_

#if defined _WIN32 || defined __CYGWIN__
# if defined _MSC_VER
#  define RRCXX_DL_EXPORT_ __declspec(dllexport)
#  define RRCXX_DL_IMPORT_ __declspec(dllimport)
#  define RRCXX_DL_LOCAL_
# elif defined __GNUC__
#  define RRCXX_DL_EXPORT_ __attribute__ ((dllexport))
#  define RRCXX_DL_IMPORT_ __attribute__ ((dllimport))
#  define RRCXX_DL_LOCAL_
# endif
#
#elif defined __unix__ || defined __linux__
# if 4 <= __GNUC__
#  define RRCXX_DL_EXPORT_ __attribute__ ((visibility ("default")))
#  define RRCXX_DL_IMPORT_ __attribute__ ((visibility ("default")))
#  define RRCXX_DL_LOCAL_  __attribute__ ((visibility ("hidden")))
# else
#  define RRCXX_DL_EXPORT_
#  define RRCXX_DL_IMPORT_
#  define RRCXX_DL_LOCAL_
# endif
#
#else
#  define RRCXX_DL_EXPORT_
#  define RRCXX_DL_IMPORT_
#  define RRCXX_DL_LOCAL_
#
#endif

#if defined RRCXX_DL || !defined RRCXX_SL
# if defined RRCXX_EXPORTS || defined RRCXX_DL_EXPORTS
#  define RRCXX_API   RRCXX_DL_EXPORT_
#  define RRCXX_LOCAL RRCXX_DL_LOCAL_
# else
#  define RRCXX_API   RRCXX_DL_IMPORT_
#  define RRCXX_LOCAL RRCXX_DL_LOCAL_
# endif
#else
#  define RRCXX_API
#  define RRCXX_LOCAL
#endif

#endif/*RRCXX_API_H_*/
