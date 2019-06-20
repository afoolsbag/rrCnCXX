/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-06-20
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBX_API_H_
#define RRLIBX_API_H_

#include "apiaux.h"

#if !!(RRLIBX_STATIC) + !!(RRLIBX_SHARED) != 1
#error Single choice options: RRLIBX_STATIC & RRLIBX_SHARED
#endif

#ifdef RRLIBX_SHARED
# ifdef RRLIBX_EXPORTS
#  define RRLIBX_APIp EXTERNC EXPORT
#  define RRLIBX_APIm CDECL
#  define RRLIBX_APIs NOEXCEPT
# else
#  define RRLIBX_APIp EXTERNC IMPORT
#  define RRLIBX_APIm CDECL
#  define RRLIBX_APIs NOEXCEPT
# endif
#else
# define RRLIBX_APIp EXTERNC
# define RRLIBX_APIm CDECL
# define RRLIBX_APIs NOEXCEPT
#endif

#endif
