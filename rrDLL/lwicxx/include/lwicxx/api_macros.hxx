//===-- Application Programming Interface Macros ----------------*- C++ -*-===//
///
/// \file
/// \brief 应用程序接口宏。
///
/// \version 2019-01-15
/// \since 2017-01-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLL_LWICXX_API_MACROS_HXX_
#define RRDLL_LWICXX_API_MACROS_HXX_

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef RRDLL_LWICXX_SHARED
#define RRDLL_LWICXX_API
#elif defined RRDLL_LWICXX_EXPORTS
#define RRDLL_LWICXX_API __declspec(dllexport)
#else
#define RRDLL_LWICXX_API __declspec(dllimport)
#endif

#ifndef APIENTRY
#ifdef _WIN32
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif
#endif

#endif//RRDLL_LWICXX_API_MACROS_HXX_
