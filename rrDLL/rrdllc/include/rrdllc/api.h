/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-04-16
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLC_API_H_
#define RRDLLC_API_H_

#include "apiaux.h"

#if !!(RRDLLC_STATIC) + !!(RRDLLC_SHARED) != 1
#error Single choice options: RRDLLC_STATIC & RRDLLC_SHARED
#endif

#ifdef RRDLLC_SHARED
# ifdef RRDLLC_EXPORTS
#  define RRDLLC_APIp EXTERNC EXPORT
#  define RRDLLC_APIm CDECL
#  define RRDLLC_APIs NOEXCEPT
# else
#  define RRDLLC_APIp EXTERNC IMPORT
#  define RRDLLC_APIm CDECL
#  define RRDLLC_APIs NOEXCEPT
# endif
#else
# define RRDLLC_APIp EXTERNC
# define RRDLLC_APIm CDECL
# define RRDLLC_APIs NOEXCEPT
#endif

#endif/*RRDLLC_API_H_*/
