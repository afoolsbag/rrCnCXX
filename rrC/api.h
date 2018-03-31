/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入/导出宏定义
 * \details ELF（Executable and Linkable Format）缺省导出/导出符号；
 *          PE（Portable Executable）缺省隐藏符号。
 *
 * \version 2018-03-31
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_API_H_
#define RRC_API_H_

#if defined _WIN32 || defined __CYGWIN__
# if defined _MSC_VER
#  define RRC_DL_EXPORT_ __declspec(dllexport)
#  define RRC_DL_IMPORT_ __declspec(dllimport)
#  define RRC_DL_LOCAL_
# elif defined __GNUC__
#  define RRC_DL_EXPORT_ __attribute__ ((dllexport))
#  define RRC_DL_IMPORT_ __attribute__ ((dllimport))
#  define RRC_DL_LOCAL_
# endif
#
#elif defined __unix__ || defined __linux__
# if 4 <= __GNUC__
#  define RRC_DL_EXPORT_ __attribute__ ((visibility ("default")))
#  define RRC_DL_IMPORT_ __attribute__ ((visibility ("default")))
#  define RRC_DL_LOCAL_  __attribute__ ((visibility ("hidden")))
# else
#  define RRC_DL_EXPORT_
#  define RRC_DL_IMPORT_
#  define RRC_DL_LOCAL_
# endif
#
#else
#  define RRC_DL_EXPORT_
#  define RRC_DL_IMPORT_
#  define RRC_DL_LOCAL_
#
#endif

#if defined RRC_DL || !defined RRC_SL
# if defined RRC_EXPORTS || defined RRC_DL_EXPORTS
#  define RRC_API   RRC_DL_EXPORT_
#  define RRC_LOCAL RRC_DL_LOCAL_
# else
#  define RRC_API   RRC_DL_IMPORT_
#  define RRC_LOCAL RRC_DL_LOCAL_
# endif
#else
#  define RRC_API
#  define RRC_LOCAL
#endif

#endif/*RRC_API_H_*/
