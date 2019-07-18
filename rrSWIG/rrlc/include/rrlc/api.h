/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-07-18
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLC_API_H_
#define RRLC_API_H_

#include "apiaux.h"

#if !!(RRLC_STATIC) + !!(RRLC_SHARED) != 1
#error Single choice options: RRLC_STATIC & RRLC_SHARED
#endif

#ifdef RRLC_SHARED
# ifdef RRLC_EXPORTS
#  define RRLC_APIp EXTERNC EXPORT
#  define RRLC_APIm CDECL
#  define RRLC_APIs NOEXCEPT
# else
#  define RRLC_APIp EXTERNC IMPORT
#  define RRLC_APIm CDECL
#  define RRLC_APIs NOEXCEPT
# endif
#else
# define RRLC_APIp EXTERNC
# define RRLC_APIm CDECL
# define RRLC_APIs NOEXCEPT
#endif

#endif
