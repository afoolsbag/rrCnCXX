/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-07-19
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
#  define RRLX_API EXPORT
# else
#  define RRLX_API IMPORT
# endif
#else
# define RRLX_API
#endif

#endif
