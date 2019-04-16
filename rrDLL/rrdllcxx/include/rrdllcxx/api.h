/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-04-16
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLCXX_API_H_
#define RRDLLCXX_API_H_

#include "apiaux.h"

#if !!(RRDLLCXX_STATIC) + !!(RRDLLCXX_SHARED) != 1
#error Single choice options: RRDLLCXX_STATIC & RRDLLCXX_SHARED
#endif

#ifdef RRDLLCXX_SHARED
# ifdef RRDLLCXX_EXPORTS
#  define RRDLLCXX_APIp EXTERNC EXPORT
#  define RRDLLCXX_APIm CDECL
#  define RRDLLCXX_APIs NOEXCEPT
# else
#  define RRDLLCXX_APIp EXTERNC IMPORT
#  define RRDLLCXX_APIm CDECL
#  define RRDLLCXX_APIs NOEXCEPT
# endif
#else
# define RRDLLCXX_APIp EXTERNC
# define RRDLLCXX_APIm CDECL
# define RRDLLCXX_APIs NOEXCEPT
#endif

#endif/*RRDLLCXX_API_H_*/
