/*===-- Services -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gServices 服务
 * \ingroup gDevelop
 *
 * \sa ["Services"](https://docs.microsoft.com/windows/desktop/Services/services). *Microsoft Docs*.
 *     *   [The Complete Service Sample](https://docs.microsoft.com/windows/desktop/Services/the-complete-service-sample)
 *
 * \version 2019-03-27
 * \since 2019-01-04
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check.h>

TCase *tcServices(void);

inline Suite *tsServices(void)
{
    Suite *const ts = suite_create(__func__);
    return ts;
}
