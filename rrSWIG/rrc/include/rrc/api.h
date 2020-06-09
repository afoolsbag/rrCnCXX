/*===-- Application Programming Interface Macros ---------------*- C -*-===*//**
 *
 * \file
 * \brief 应用程序接口宏。
 *
 * \version 2020-06-03
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
#  define RRC_API EXPORT
# else
#  define RRC_API IMPORT
# endif
#else
# define RRC_API
#endif

#endif
