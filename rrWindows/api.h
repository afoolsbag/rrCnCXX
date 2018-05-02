/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入、导出宏定义。
 *
 * \version 2018-05-02
 * \since 2018-05-02
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif
