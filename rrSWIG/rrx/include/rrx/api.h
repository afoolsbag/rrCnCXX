/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2020-06-03
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRX_API_H_
#define RRX_API_H_

#include "apiaux.h"

#if !!(RRX_STATIC) + !!(RRX_SHARED) != 1
#error Single choice options: RRX_STATIC & RRX_SHARED
#endif

#ifdef RRX_SHARED
# ifdef RRX_EXPORTS
#  define RRX_API EXPORT
# else
#  define RRX_API IMPORT
# endif
#else
# define RRX_API
#endif

#endif
