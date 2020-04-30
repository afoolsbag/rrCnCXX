/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2020-04-30
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
#  define RRLIBX_API EXPORT
# else
#  define RRLIBX_API IMPORT
# endif
#else
# define RRLIBX_API
#endif

#endif
