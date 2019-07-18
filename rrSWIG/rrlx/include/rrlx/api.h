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
#ifndef RRLX_API_H_
#define RRLX_API_H_

#include "apiaux.h"

#if !!(RRLX_STATIC) + !!(RRLX_SHARED) != 1
#error Single choice options: RRLX_STATIC & RRLX_SHARED
#endif

#ifdef RRLX_SHARED
# ifdef RRLX_EXPORTS
#  define RRLX_APIp EXTERNC EXPORT
#  define RRLX_APIm CDECL
#  define RRLX_APIs NOEXCEPT
# else
#  define RRLX_APIp EXTERNC IMPORT
#  define RRLX_APIm CDECL
#  define RRLX_APIs NOEXCEPT
# endif
#else
# define RRLX_APIp EXTERNC
# define RRLX_APIm CDECL
# define RRLX_APIs NOEXCEPT
#endif

#endif
