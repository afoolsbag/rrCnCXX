/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2020-04-30
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
#  define RRLIBC_API EXPORT
# else
#  define RRLIBC_API IMPORT
# endif
#else
# define RRLIBC_API
#endif

#endif
