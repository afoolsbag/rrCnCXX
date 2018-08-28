/*===-- Definition ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 定义。
 *
 * \version 2018-08-28
 * \since 2018-06-26
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#include "rrwindows/macro.h"

/*-A--------------------------------------------------------------------------*/

/*-C--------------------------------------------------------------------------*/

#ifndef countof
#define countof(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

/*-E--------------------------------------------------------------------------*/

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/*-F--------------------------------------------------------------------------*/

/**
 * \def FLCS
 * \brief 文件、行号、冒号、空格。\n
 *        File-Line-Colon-Space.
 * \details Visual Studio 支持的文件行号形式。\n
 *          宏展开形如 `"path\\to\\source.c" "(" "666" "): "` 或对应的宽字符形式。
 * \sa <https://docs.microsoft.com/cpp/ide/formatting-the-output-of-a-custom-build-step-or-build-event>
 */

#ifndef FLCSA
#define FLCSA __FILE__ "(" EXPAND_STRING(__LINE__) "): "
#endif

#ifndef FLCSW
#define FLCSW EXPAND_WIDE(__FILE__) L"(" EXPAND_WIDE_STRING(__LINE__) L"): "
#endif

#ifndef FLCS
# ifdef _UNICODE
#  define FLCS FLCSW
# else
#  define FLCS FLCSA
# endif
#endif
