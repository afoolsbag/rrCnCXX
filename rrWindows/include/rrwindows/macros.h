/*===-- Macro --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 宏。
 *
 * \version 2018-10-18
 * \since 2018-06-12
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

/**
 * \def RRWINDOWS_API
 * \brief 自适应导入、导出宏。
 */
#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif

/**
 * \brief 间接展开。
 */
#define EXPAND(macro) macro

/**
 * \def DEBUG_ONLY
 * \brief 条件展开。
 */
#ifndef DEBUG_ONLY
# ifdef _DEBUG
#  define DEBUG_ONLY(macro) macro
# else
#  define DEBUG_ONLY(macro)
# endif
#endif

/**
 * \def RELEASE_ONLY
 * \brief 条件展开。
 */
#ifndef RELEASE_ONLY
# ifdef _DEBUG
#  define RELEASE_ONLY(macro)
# else
#  define RELEASE_ONLY(macro) macro
# endif
#endif

/**
 * \def ANSI_ONLY
 * \brief 条件展开。
 */
#ifndef ANSI_ONLY
# if defined _MBCS || defined _UNICODE
#  define ANSI_ONLY(macro)
# else
#  define ANSI_ONLY(macro) macro
# endif
#endif

/**
 * \def ANSI_NONE
 * \brief 条件展开。
 */
#ifndef ANSI_NONE
# if defined _MBCS || defined _UNICODE
#  define ANSI_NONE(macro) macro
# else
#  define ANSI_NONE(macro)
# endif
#endif

/**
 * \def MBCS_ONLY
 * \brief 条件展开。
 */
#ifndef MBCS_ONLY
# ifdef _MBCS
#  define MBCS_ONLY(macro) macro
# else
#  define MBCS_ONLY(macro)
# endif
#endif

/**
 * \def MBCS_NONE
 * \brief 条件展开。
 */
#ifndef MBCS_NONE
# ifdef _MBCS
#  define MBCS_NONE(macro)
# else
#  define MBCS_NONE(macro) macro
# endif
#endif

/**
 * \def UNICODE_ONLY
 * \brief 条件展开。
 */
#ifndef UNICODE_ONLY
# ifdef _UNICODE
#  define UNICODE_ONLY(macro) macro
# else
#  define UNICODE_ONLY(macro)
# endif
#endif

/**
 * \def UNICODE_NONE
 * \brief 条件展开。
 */
#ifndef UNICODE_NONE
# ifdef _UNICODE
#  define UNICODE_NONE(macro)
# else
#  define UNICODE_NONE(macro) macro
# endif
#endif

/** \brief 不支持的参数数目。 */
#define VABAN UnsupportedNumberOfParamaters
/** \brief 变参宏函数（1-2参数）。 */
#define VAFUNC2(_1, _2, func2, ...) func2
/** \brief 变参宏函数（1-3参数）。 */
#define VAFUNC3(_1, _2, _3, func3, ...) func3
/** \brief 变参宏函数（1-4参数）。 */
#define VAFUNC4(_1, _2, _3, _4, func4, ...) func4
/** \brief 变参宏函数（1-5参数）。 */
#define VAFUNC5(_1, _2, _3, _4, _5, func5, ...) func5
/** \brief 变参宏函数（1-6参数）。 */
#define VAFUNC6(_1, _2, _3, _4, _5, _6, func6, ...) func6
/** \brief 变参宏函数（1-7参数）。 */
#define VAFUNC7(_1, _2, _3, _4, _5, _6, _7, func7, ...) func7
/** \brief 变参宏函数（1-8参数）。 */
#define VAFUNC8(_1, _2, _3, _4, _5, _6, _7, _8, func8, ...) func8
/** \brief 变参宏函数（1-9参数）。 */
#define VAFUNC9(_1, _2, _3, _4, _5, _6, _7, _8, _9, func9, ...) func9
/** \brief 变参宏函数（1-10参数）。 */
#define VAFUNC10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, func10, ...) func10
