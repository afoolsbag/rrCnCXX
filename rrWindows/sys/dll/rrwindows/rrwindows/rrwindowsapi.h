/*===-- API Import/Export Macro Definition ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口导入、导出宏定义。
 *
 * \version 2018-06-15
 * \since 2018-05-02
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#ifdef __cplusplus
# ifndef EXTERN_C
# define EXTERN_C       extern "C"
# endif
# ifndef EXTERN_C_START
# define EXTERN_C_START extern "C" {
# endif
# ifndef EXTERN_C_END
# define EXTERN_C_END   }
# endif
#else
# ifndef EXTERN_C
# define EXTERN_C       extern
# endif
# ifndef EXTERN_C_START
# define EXTERN_C_START
# endif
# ifndef EXTERN_C_END
# define EXTERN_C_END
# endif
#endif

#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif
