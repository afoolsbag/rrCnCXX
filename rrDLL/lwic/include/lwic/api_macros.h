/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-01-15
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLL_LWIC_API_MACROS_H_
#define RRDLL_LWIC_API_MACROS_H_

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef RRDLL_LWIC_SHARED
#define RRDLL_LWIC_API
#elif defined RRDLL_LWIC_EXPORTS
#define RRDLL_LWIC_API __declspec(dllexport)
#else
#define RRDLL_LWIC_API __declspec(dllimport)
#endif

#ifndef APIENTRY
#ifdef _WIN32
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif
#endif

#endif/*RRDLL_LWIC_API_MACROS_H_*/
