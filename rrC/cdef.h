/*===-- C Definition -------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C定义。
 *
 * \version 2018-06-19
 * \since 2018-04-25
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_CDEF_H_
#define RRC_CDEF_H_

#include <stddef.h>

/* B */

#ifndef bool
#define bool _Bool
#endif

/* C */

#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

/* F */

#ifndef false
#define false 0
#endif

/* S */

#ifndef static_assert
#define static_assert _Static_assert
#endif

/* T */

#ifndef true
#define true 1
#endif

/* U */

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif/*UNUSED*/

#endif/*RRC_CDEF_H_*/
