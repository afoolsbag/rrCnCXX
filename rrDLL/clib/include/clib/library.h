/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2019-01-18
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef CLIB_LIBRARY_H_
#define CLIB_LIBRARY_H_

#include "clib/api_macros.h"

/**
 * \brief 库版本信息结构体。
 */
typedef struct clib_version_t_ {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
} clib_version_t;

/**
 * \brief 获取库版本信息。
 */
CLIB_DECORATING CLIB_IMEXPORT clib_version_t CLIB_CALLING clib_version(void);

#endif/*CLIB_LIBRARY_H_*/
