/*===-- Definition ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 定义。
 *
 * \version 2018-06-27
 * \since 2018-06-26
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#include "macro.h"

/*-A--------------------------------------------------------------------------*/

#ifndef ATFUNCNLA
#define ATFUNCNLA " @" __FUNCTION__ ".\n"
#endif
#ifndef ATFUNCNLW
#define ATFUNCNLW L" @" EXPAND_WIDE(__FUNCTION__) L".\n"
#endif
#ifndef ATFUNCNL
# ifdef _UNICODE
#  define ATFUNCNL ATFUNCNLW
# else
#  define ATFUNCNL ATFUNCNLA
# endif
#endif

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

#ifndef FILELINEA
#define FILELINEA __FILE__ "(" EXPAND_STRING(__LINE__) "): "
#endif
#ifndef FILENAMEW
#define FILELINEW EXPAND_WIDE(__FILE__) L"(" EXPAND_WIDE(EXPAND_STRING(__LINE__)) L"): "
#endif
#ifndef FILELINE
# ifdef _UNICODE
#  define FILELINE FILELINEW
# else
#  define FILELINE FILELINEA
# endif
#endif
