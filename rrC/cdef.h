/*===-- C Definition -------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C定义。
 *
 * \version 2018-04-25
 * \since 2018-04-25
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_CDEF_H_
#define RRC_CDEF_H_

#include <stddef.h>

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif/*UNUSED*/

#ifndef bool
#define bool _Bool
#endif

#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

#ifndef false
#define false 0
#endif

#ifndef static_assert
#define static_assert _Static_assert
#endif

#ifndef true
#define true 1
#endif

#endif/*RRC_CDEF_H_*/
