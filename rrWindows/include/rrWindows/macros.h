/*===-- Macro --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 宏。
 *
 * \version 2019-02-20
 * \since 2018-06-12
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

/* 自适应导入、导出宏 */

#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif

/* 间接展开和条件展开 */

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

/* 宏函数变参重载（Macro Function Variadic Overloading） */

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
        SELECT_4TH(PAD_3_TOKENS __VA_ARGS__ (), f0, f1, f2)(__VA_ARGS__)       \
    )
#define MFVO_3(f0, f1, f2, f3, ...)                                            \
    EXPAND(                                                                    \
        SELECT_5TH(PAD_4_TOKENS __VA_ARGS__ (), f0, f1, f2, f3)(__VA_ARGS__)   \
    )
#define MFVO_4(f0, f1, f2, f3, f4, ...)                                        \
    EXPAND(                                                                    \
        SELECT_6TH(PAD_5_TOKENS __VA_ARGS__ (),                                \
                                              f0, f1, f2, f3, f4)(__VA_ARGS__) \
    )
#define MFVO_5(f0, f1, f2, f3, f4, f5, ...)                                    \
    EXPAND(                                                                    \
        SELECT_7TH(PAD_6_TOKENS __VA_ARGS__ (),                                \
                                          f0, f1, f2, f3, f4, f5)(__VA_ARGS__) \
    )
#define MFVO_6(f0, f1, f2, f3, f4, f5, f6, ...)                                \
    EXPAND(                                                                    \
        SELECT_8TH(PAD_7_TOKENS __VA_ARGS__ (),                                \
                                      f0, f1, f2, f3, f4, f5, f6)(__VA_ARGS__) \
    )
#define MFVO_7(f0, f1, f2, f3, f4, f5, f6, f7, ...)                            \
    EXPAND(                                                                    \
        SELECT_9TH(PAD_8_TOKENS __VA_ARGS__ (),                                \
                                  f0, f1, f2, f3, f4, f5, f6, f7)(__VA_ARGS__) \
    )
#define MFVO_8(f0, f1, f2, f3, f4, f5, f6, f7, f8, ...)                        \
    EXPAND(                                                                    \
        SELECT_10TH(PAD_9_TOKENS __VA_ARGS__ (),                               \
                              f0, f1, f2, f3, f4, f5, f6, f7, f8)(__VA_ARGS__) \
    )
#define MFVO_9(f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, ...)                    \
    EXPAND(                                                                    \
        SELECT_11TH(PAD_10_TOKENS __VA_ARGS__ (),                              \
                          f0, f1, f2, f3, f4, f5, f6, f7, f8, f9)(__VA_ARGS__) \
    )
#define MFVO_10(f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, ...)              \
    EXPAND(                                                                    \
        SELECT_12TH(PAD_11_TOKENS __VA_ARGS__ (),                              \
                     f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10)(__VA_ARGS__) \
    )

#define MFVO_BAN __UnsupportedNumberOfParamaters__

/* 常用宏函数 */

#ifndef countof
#define countof(array) (sizeof (array) / sizeof *(array))
#endif
