/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入、导出宏定义。
 *
 * \version 2018-04-20
 * \since 2018-04-20
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#ifdef RRMFC_UTILITIES_SHARED
# ifdef RRMFC_UTILITIES_EXPORTS
#  define RRMFC_UTILITIES_API __declspec(dllexport)
# else
#  define RRMFC_UTILITIES_API __declspec(dllimport)
# endif
#else
#  define RRMFC_UTILITIES_API
#endif
