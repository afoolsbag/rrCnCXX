/*===-- Definition ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 定义。
 *
 * \version 2018-08-08
 * \since 2018-04-25
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_DEF_H_
#define RRC_DEF_H_

#include <stddef.h>

#include "rrC/cver.h"

/*-B--------------------------------------------------------------------------*/

#ifndef bool
#define bool _Bool
#endif

/*-C--------------------------------------------------------------------------*/

#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

/*-F--------------------------------------------------------------------------*/

#ifndef false
#define false 0
#endif

/*-S--------------------------------------------------------------------------*/

#ifndef static_assert
# if MSC
#  define static_assert _STATIC_ASSERT
# else
#  define static_assert _Static_assert
# endif
#endif

/*-T--------------------------------------------------------------------------*/

#ifndef true
#define true 1
#endif

/*-U--------------------------------------------------------------------------*/

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif

#endif/*RRC_DEF_H_*/
