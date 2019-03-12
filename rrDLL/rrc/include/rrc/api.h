/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2019-03-11
 * \since 2016-08-01
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_API_H_
#define RRC_API_H_

#include "apiaux.h"

#if !!(RRC_STATIC) + !!(RRC_SHARED) != 1
#error Single choice options: RRC_STATIC & RRC_SHARED
#endif

#ifdef RRC_SHARED
# ifdef RRC_EXPORTS
#  define RRC_APIp EXTERNC EXPORT
#  define RRC_APIm CDECL
#  define RRC_APIs NOEXCEPT
# else
#  define RRC_APIp EXTERNC IMPORT
#  define RRC_APIm CDECL
#  define RRC_APIs NOEXCEPT
# endif
#else
#  define RRC_APIp EXTERNC
#  define RRC_APIm CDECL
#  define RRC_APIs NOEXCEPT
#endif

#endif/*RRC_API_H_*/
