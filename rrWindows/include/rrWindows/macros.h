/*===-- Macro --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 宏。
 *
 * \version 2019-03-28
 * \since 2018-06-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

/*------------------------------------------------------------------------------
 * 自适应导入、导出宏
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

/*------------------------------------------------------------------------------
 * 间接展开和条件展开
 */

#ifndef EXPAND
#define EXPAND(macro) macro
#endif

#ifdef _DEBUG
# ifndef DEBUG_ONLY
# define DEBUG_ONLY(macro) macro
# endif
# ifndef RELEASE_ONLY
# define RELEASE_ONLY(macro)
# endif
#else
# ifndef DEBUG_ONLY
# define DEBUG_ONLY(macro)
# endif
# ifndef RELEASE_ONLY
# define RELEASE_ONLY(macro) macro
# endif
#endif

#ifdef _UNICODE
# ifndef ANSI_ONLY
# define ANSI_ONLY(macro)
# endif
# ifndef MBCS_ONLY
# define MBCS_ONLY(macro)
# endif
# ifndef UNOCODE_ONLY
# define UNICODE_ONLY(macro) macro
# endif
#elif defined _MBCS
# ifndef ANSI_ONLY
# define ANSI_ONLY(macro)
# endif
# ifndef MBCS_ONLY
# define MBCS_ONLY(macro) macro
# endif
# ifndef UNOCODE_ONLY
# define UNICODE_ONLY(macro)
# endif
#else
# ifndef ANSI_ONLY
# define ANSI_ONLY(macro) macro
# endif
# ifndef MBCS_ONLY
# define MBCS_ONLY(macro)
# endif
# ifndef UNOCODE_ONLY
# define UNICODE_ONLY(macro)
# endif
#endif

/*------------------------------------------------------------------------------
 * 宏函数变参重载（Macro Function Variadic Overloading）
 * 
 * 如何实现的？
 *
 * 1. 藉由宏的 __VA_ARGS__ 特性，构造 SELECT 宏，将参数个数和函数记号联系起来：
 *
 *    譬如现有三个函数：
 *    f1(p1)
 *    f2(p1, p2)
 *    f3(p1, p2, p3)
 *
 *    构造路由宏：
 *    fv(...) SELECT_4TH(__VA_ARGS__, f3, f2, f1)(__VA_ARGS__)
 *
 *    预处理阶段会被替换为：
 *    fv(p1)
 *        => SELECT_4TH(p1, f3, f2, f1)(p1)
 *            => f1(p1)
 *    fv(p1, p2)
 *        => SELECT_4TH(p1, p2, f3, f2, f1)(p1, p2)
 *            => f2(p1, p2)
 *    fv(p1, p2, p3)
 *        => SELECT_4TH(p1, p2, p3, f3, f2, f1)(p1, p2, p3)
 *            => f3(p1, p2, p3)
 *
 *    但仅用该技巧，无法支持零个参数的情况：
 *    fv()
 *        => SELECT_4TH( , f3, f2, f1, f0)()
 *            => f1()
 *
 * 2. 藉由预处理阶段的替换特性，修正零参数时的情形：
 * 
 *    构造路由宏：
 *    fv(...) SELECT_5TH(PAD_4_TOKENS __VA_ARGS__ (), f0, f3, f2, f1)(__VA_ARGS__)
 *
 *    当 __VA_ARGS__ 不为空时：
 *    fv(p1)
 *        => SELECT_5TH(PAD_4_TOKENS p1 (), f0, f3, f2, f1)(p1)
 *            => f1(p1)
 *    fv(p1, p2)
 *        => SELECT_5TH(PAD_4_TOKENS p1, p2 (), f0, f3, f2, f1)(p1, p2)
 *            => f2(p1, p2)
 *    fv(p1, p2, p3)
 *        => SELECT_5TH(PAD_4_TOKENS p1, p2, p3 (), f0, f3, f2, f1)(p1, p2, p3)
 *            => f3(p1, p2, p3)
 *
 *    当 __VA_ARGS__ 为空时：
 *    fv()
 *        => SELECT_5TH(PAD_4_TOKENS (), f0, f3, f2, f1)()
 *            => SELECT_5TH(_1, _2, _3, _4, f0, f3, f2, f1)()
 *                => f0()
 *
 * 3. 由于 MSC 的预处理特性，使用 __VA_ARGS__ 向 SELECT 宏传参会被认为是单个记号，
 *    需要使用 EXPAND 将 SELECT 间接展开，以达到预期作用。
 *
 * 4. 将该技巧封装为 MFVO 宏，便于使用，如：
 *    
 *    #define fv(...) MFVO_10(f0,                                              \
 *                            f1,                                              \
 *                            f2,                                              \
 *                            MFVO_BAN,                                        \
 *                            MFVO_BAN,                                        \
 *                            MFVO_BAN,                                        \
 *                            f6,                                              \
 *                            MFVO_BAN,                                        \
 *                            MFVO_BAN,                                        \
 *                            MFVO_BAN,                                        \
 *                            f10, __VA_ARGS__)
 */

#define SELECT_1ST(_1, ...) _1
#define SELECT_2ND(_1, _2, ...) _2
#define SELECT_3RD(_1, _2, _3, ...) _3
#define SELECT_4TH(_1, _2, _3, _4, ...) _4
#define SELECT_5TH(_1, _2, _3, _4, _5, ...) _5
#define SELECT_6TH(_1, _2, _3, _4, _5, _6, ...) _6
#define SELECT_7TH(_1, _2, _3, _4, _5, _6, _7, ...) _7
#define SELECT_8TH(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define SELECT_9TH(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
#define SELECT_10TH(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define SELECT_11TH(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) _11
#define SELECT_12TH(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) _12

#define PAD_1_TOKEN() _1
#define PAD_2_TOKENS() _1, _2
#define PAD_3_TOKENS() _1, _2, _3
#define PAD_4_TOKENS() _1, _2, _3, _4
#define PAD_5_TOKENS() _1, _2, _3, _4, _5
#define PAD_6_TOKENS() _1, _2, _3, _4, _5, _6
#define PAD_7_TOKENS() _1, _2, _3, _4, _5, _6, _7
#define PAD_8_TOKENS() _1, _2, _3, _4, _5, _6, _7, _8
#define PAD_9_TOKENS() _1, _2, _3, _4, _5, _6, _7, _8, _9
#define PAD_10_TOKENS() _1, _2, _3, _4, _5, _6, _7, _8, _9, _10
#define PAD_11_TOKENS() _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11

#define MFVO_1(f0, f1, ...)                                                    \
    EXPAND(                                                                    \
        SELECT_3RD(PAD_2_TOKENS __VA_ARGS__ (), f0, f1)(__VA_ARGS__)           \
    )
#define MFVO_2(f0, f1, f2, ...)                                                \
    EXPAND(                                                                    \
        SELECT_4TH(PAD_3_TOKENS __VA_ARGS__ (), f0, f2, f1)(__VA_ARGS__)       \
    )
#define MFVO_3(f0, f1, f2, f3, ...)                                            \
    EXPAND(                                                                    \
        SELECT_5TH(PAD_4_TOKENS __VA_ARGS__ (), f0, f3, f2, f1)(__VA_ARGS__)   \
    )
#define MFVO_4(f0, f1, f2, f3, f4, ...)                                        \
    EXPAND(                                                                    \
        SELECT_6TH(PAD_5_TOKENS __VA_ARGS__ (),                                \
                                              f0, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_5(f0, f1, f2, f3, f4, f5, ...)                                    \
    EXPAND(                                                                    \
        SELECT_7TH(PAD_6_TOKENS __VA_ARGS__ (),                                \
                                          f0, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_6(f0, f1, f2, f3, f4, f5, f6, ...)                                \
    EXPAND(                                                                    \
        SELECT_8TH(PAD_7_TOKENS __VA_ARGS__ (),                                \
                                      f0, f6, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_7(f0, f1, f2, f3, f4, f5, f6, f7, ...)                            \
    EXPAND(                                                                    \
        SELECT_9TH(PAD_8_TOKENS __VA_ARGS__ (),                                \
                                  f0, f7, f6, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_8(f0, f1, f2, f3, f4, f5, f6, f7, f8, ...)                        \
    EXPAND(                                                                    \
        SELECT_10TH(PAD_9_TOKENS __VA_ARGS__ (),                               \
                              f0, f8, f7, f6, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_9(f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...)                    \
    EXPAND(                                                                    \
        SELECT_11TH(PAD_10_TOKENS __VA_ARGS__ (),                              \
                          f0, f9, f8, f7, f6, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )
#define MFVO_10(f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, ...)              \
    EXPAND(                                                                    \
        SELECT_12TH(PAD_11_TOKENS __VA_ARGS__ (),                              \
                     f0, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1)(__VA_ARGS__) \
    )

#define MFVO_BAN __UnsupportedNumberOfParamaters__

/*------------------------------------------------------------------------------
 * 常用宏常量
 */

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/*------------------------------------------------------------------------------
 * 常用宏函数
 */

#ifndef countof
#define countof(array) (sizeof (array) / sizeof *(array))
#endif
