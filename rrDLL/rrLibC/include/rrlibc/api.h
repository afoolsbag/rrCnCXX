/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-06-20
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBC_API_H_
#define RRLIBC_API_H_

#include "apiaux.h"

#if !!(RRLIBC_STATIC) + !!(RRLIBC_SHARED) != 1
#error Single choice options: RRLIBC_STATIC & RRLIBC_SHARED
#endif

#ifdef RRLIBC_SHARED
# ifdef RRLIBC_EXPORTS
#  define RRLIBC_APIp EXTERNC EXPORT
#  define RRLIBC_APIm CDECL
#  define RRLIBC_APIs NOEXCEPT
# else
#  define RRLIBC_APIp EXTERNC IMPORT
#  define RRLIBC_APIm CDECL
#  define RRLIBC_APIs NOEXCEPT
# endif
#else
# define RRLIBC_APIp EXTERNC
# define RRLIBC_APIm CDECL
# define RRLIBC_APIs NOEXCEPT
#endif

#endif
