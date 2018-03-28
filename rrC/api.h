/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入/导出宏定义
 *
 * \version 2018-03-28
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_API_H_
#define RRC_API_H_

#if defined(_MSC_VER) || defined(__CYGWIN__)
# define RRC_EXPORT_ __declspec(dllexport)
# define RRC_IMPORT_ __declspec(dllimport)
# define RRC_LOCAL_
#elif 4 <= __GNUC__
# define RRC_EXPORT_ __attribute__((visibility("default")))
# define RRC_IMPORT_ __attribute__((visibility("default")))
# define RRC_LOCAL_ __attribute__((visibility("hidden")))
#else
# define RRC_EXPORT_
# define RRC_IMPORT_
# define RRC_LOCAL_
#endif

#ifdef RRC_EXPORTS
# define RRC_API RRC_EXPORT_
#else
# define RRC_API RRC_IMPORT_
#endif

#endif/*RRC_API_H_*/
