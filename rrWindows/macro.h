/*===-- Macro --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 宏。
 *
 * \version 2018-08-08
 * \since 2018-06-12
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

/** \brief 宏展开。 */
#define RRWINDOWS_EXPAND(macro) macro

/** \brief 宏展开为字符串。 */
#define RRWINDOWS_STRING(unquoted) #unquoted
#define RRWINDOWS_EXPAND_STRING(macro) RRWINDOWS_STRING(macro)

/** \brief 宏展开为宽字符串。 */
#define RRWINDOWS_WIDE_STRING(unquoted) L#unquoted
#define RRWINDOWS_EXPAND_WIDE_STRING(macro) RRWINDOWS_WIDE_STRING(macro)

/** \brief 字符串宏展开为宽字符串。 */
#define RRWINDOWS_WIDE(string) L##string
#define RRWINDOWS_EXPAND_WIDE(macro) RRWINDOWS_WIDE(macro)

/** \brief 不支持的参数数目。 */
#define RRWINDOWS_VABAN UnsupportedNumberOfParamaters
/** \brief 变参宏函数（1-2参数）。 */
#define RRWINDOWS_VAFUNC2(_1, _2, func2, ...) func2
/** \brief 变参宏函数（1-3参数）。 */
#define RRWINDOWS_VAFUNC3(_1, _2, _3, func3, ...) func3
/** \brief 变参宏函数（1-4参数）。 */
#define RRWINDOWS_VAFUNC4(_1, _2, _3, _4, func4, ...) func4
/** \brief 变参宏函数（1-5参数）。 */
#define RRWINDOWS_VAFUNC5(_1, _2, _3, _4, _5, func5, ...) func5
/** \brief 变参宏函数（1-6参数）。 */
#define RRWINDOWS_VAFUNC6(_1, _2, _3, _4, _5, _6, func6, ...) func6
/** \brief 变参宏函数（1-7参数）。 */
#define RRWINDOWS_VAFUNC7(_1, _2, _3, _4, _5, _6, _7, func7, ...) func7
/** \brief 变参宏函数（1-8参数）。 */
#define RRWINDOWS_VAFUNC8(_1, _2, _3, _4, _5, _6, _7, _8, func8, ...) func8
/** \brief 变参宏函数（1-9参数）。 */
#define RRWINDOWS_VAFUNC9(_1, _2, _3, _4, _5, _6, _7, _8, _9, func9, ...) func9
/** \brief 变参宏函数（1-10参数）。 */
#define RRWINDOWS_VAFUNC10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, func10, ...) func10

/** \brief 条件展开。 */
#ifdef _DEBUG
# define RRWINDOWS_DEBUG_ONLY(macro) macro
# define RRWINDOWS_RELEASE_ONLY(macro) /*nothing*/
#else
# define RRWINDOWS_DEBUG_ONLY(macro) /*nothing*/
# define RRWINDOWS_RELEASE_ONLY(macro) macro
#endif
