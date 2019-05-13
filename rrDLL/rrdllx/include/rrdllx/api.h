/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-05-10
 * \since 2017-01-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLX_API_H_
#define RRDLLX_API_H_

#include "apiaux.h"

#if !!(RRDLLX_STATIC) + !!(RRDLLX_SHARED) != 1
#error Single choice options: RRDLLX_STATIC & RRDLLX_SHARED
#endif

#ifdef RRDLLX_SHARED
# ifdef RRDLLX_EXPORTS
#  define RRDLLX_APIp EXTERNC EXPORT
#  define RRDLLX_APIm CDECL
#  define RRDLLX_APIs NOEXCEPT
# else
#  define RRDLLX_APIp EXTERNC IMPORT
#  define RRDLLX_APIm CDECL
#  define RRDLLX_APIs NOEXCEPT
# endif
#else
# define RRDLLX_APIp EXTERNC
# define RRDLLX_APIm CDECL
# define RRDLLX_APIs NOEXCEPT
#endif

#endif/*RRDLLX_API_H_*/
