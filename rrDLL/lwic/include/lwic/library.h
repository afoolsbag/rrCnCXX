/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2019-01-15
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLL_LWIC_LIBRARY_H_
#define RRDLL_LWIC_LIBRARY_H_

#include <time.h>

#include "lwic/api_macros.h"

/**
 * \brief 库版本信息结构体。
 */
typedef struct rrdll_lwic_version_t_ {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
} rrdll_lwic_version_t;

/**
 * \brief 获取库版本信息。
 */
EXTERN_C
RRDLL_LWIC_API
rrdll_lwic_version_t
APIENTRY
rrdll_lwic_version(void);

#endif/*RRDLL_LWIC_LIBRARY_H_*/
