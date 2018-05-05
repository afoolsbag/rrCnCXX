/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入、导出宏定义。
 * \details ELF（Executable and Linkable Format）缺省导出、导出符号；
 *          PE（Portable Executable）缺省隐藏符号。
 *
 * \version 2018-05-05
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
#  define RRC_EXPORT __declspec(dllexport)
#  define RRC_IMPORT __declspec(dllimport)
#  define RRC_LOCAL
# elif defined __GNUC__
#  define RRC_EXPORT __attribute__ ((dllexport))
#  define RRC_IMPORT __attribute__ ((dllimport))
#  define RRC_LOCAL
# endif
#
#elif defined __unix__ || defined __linux__
# if 4 <= __GNUC__
#  define RRC_EXPORT __attribute__ ((visibility ("default")))
#  define RRC_IMPORT __attribute__ ((visibility ("default")))
#  define RRC_LOCAL  __attribute__ ((visibility ("hidden")))
# else
#  define RRC_EXPORT
#  define RRC_IMPORT
#  define RRC_LOCAL
# endif
#
#else
#  define RRC_EXPORT
#  define RRC_IMPORT
#  define RRC_LOCAL
#a
#endif

#ifdef RRC_SHARED
# ifdef RRC_EXPORTS
#  define RRC_API   RRC_EXPORT
# else
#  define RRC_API   RRC_IMPORT
# endif
#else
#  define RRC_API
#endif

#endif/*RRC_API_H_*/
