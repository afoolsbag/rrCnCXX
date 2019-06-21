/*===-- C Versions ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C 版本。
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki)
 *
 * \version 2019-03-21
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_C_VERSIONS_H_
#define RRC_C_VERSIONS_H_

/*----- Compilers ------------------------------------------------------------*/

/**
 * \brief 一般化版本号（Normalized Version）
 * \details 形如 `0xVVRRPPPP`。
 * \param v 主版本号（version）
 * \param r 次版本号（revision)
 * \param p 补丁版本号（patch）
 */
#define NORMALIZED_VERSION(v, r, p) (((v) << 24) + ((r) << 16) + (p))

/**
 * \def NORMALIZED_CLANG_VERSION
 * \brief 一般化 clang 版本号
 */
#ifdef __clang__
#define NORMALIZED_CLANG_VERSION    NORMALIZED_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#else
#define NORMALIZED_CLANG_VERSION    0
#endif

/**
 * \def NORMALIZED_GNUC_VERSION
 * \brief 一般化 GNUC 版本号
 */
#ifdef __GNUC__
#ifdef __GNUC_PATCHLEVEL__
#define NORMALIZED_GNUC_VERSION     NORMALIZED_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#else
#define NORMALIZED_GNUC_VERSION     NORMALIZED_VERSION(__GNUC__, __GNUC_MINOR__, 0)
#endif
#else
#define NORMALIZED_GNUC_VERSION     0
#endif

/**
 * \def NORMALIZED_MSC_VERSION
 * \brief 一般化 MSC 版本号
 */
#ifdef _MSC_VER
#if 1400 <= _MSC_VER
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, _MSC_FULL_VER % 100000)
#elif 1200 <= _MSC_VER
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
#else
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif
#else
#define NORMALIZED_MSC_VERSION      0
#endif

/*----- Standards ------------------------------------------------------------*/

#if !defined(__STDC__) && !NORMALIZED_MSC_VERSION
#error A C compiler is required.
#endif

/**
 * \def STANDARD_C18
 * \brief ISO/IEC 9899:2018
 * \sa <https://iso.org/standard/74528.html>
 */
#if defined(__STDC_VERSION__) && 201710L<=__STDC_VERSION__
#define STANDARD_C18                1
#else
#define STANDARD_C18                0
#endif

/**
 * \def STANDARD_C11
 * \brief ISO/IEC 9899:2011
 * \sa <https://iso.org/standard/57853.html>
 */
#if defined(__STDC_VERSION__) && 201112L<=__STDC_VERSION__
#define STANDARD_C11                1
#else
#define STANDARD_C11                0
#endif

/**
 * \def STANDARD_C99
 * \brief ISO/IEC 9899:1999
 * \sa <https://iso.org/standard/29237.html>
 */
#if defined(__STDC_VERSION__) && 199901L<=__STDC_VERSION__
#define STANDARD_C99                1
#else
#define STANDARD_C99                0
#endif

/**
 * \def STANDARD_C95
 * \brief ISO/IEC 9899:1990/Amd 1:1995
 * \sa <https://iso.org/standard/23909.html>
 */
#if defined(__STDC_VERSION__) && 199410L<=__STDC_VERSION__
#define STANDARD_C95                1
#else
#define STANDARD_C95                0
#endif

/**
 * \def STANDARD_C90
 * \brief ISO/IEC 9899:1990
 * \sa <https://iso.org/standard/17782.html>
 */
#ifdef __STDC__
#define STANDARD_C90                1
#else
#define STANDARD_C90                0
#endif

/**
 * \def STANDARD_C89
 * \brief ANSI X3.159-1989
 */
#ifdef __STDC__
#define STANDARD_C89                1
#else
#define STANDARD_C89                0
#endif

/*----- Features -------------------------------------------------------------*/

/**
 * \def FEATURE_ALLOC_LIB
 * \brief 支持动态分配函数的扩展。
 * \sa <https://zh.cppreference.com/w/c/experimental/dynamic>
 * \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1248>
 */
#ifdef __STDC_ALLOC_LIB__
#define FEATURE_ALLOC_LIB           1
#else
#define FEATURE_ALLOC_LIB           0
#endif

/**
 * \def FEATURE_ANALYZABLE
 * \brief 可分析性。
 * \sa <https://zh.cppreference.com/w/c/language/analyzability>
 */
#if STANDARD_C11 && defined(__STDC_ANALYZABLE__)
#define FEATURE_ANALYZABLE          1
#else
#define FEATURE_ANALYZABLE          0
#endif

/**
 * \def FEATURE_ATOMICS
 * \brief 原子类型。
 * \sa <https://zh.cppreference.com/w/c/language/atomic>
 */
#if STANDARD_C11 && !defined(__STDC_NO_ATOMICS__)
#define FEATURE_ATOMICS             1
#else
#define FEATURE_ATOMICS             0
#endif

/**
 * \def FEATURE_COMPLEX
 * \brief 复数算术。
 * \sa <https://zh.cppreference.com/w/c/numeric/complex>
 */
#if STANDARD_C11 && !defined(__STDC_NO_COMPLEX__)
#define FEATURE_COMPLEX             1
#else
#define FEATURE_COMPLEX             0
#endif

#if STANDARD_C99 && defined(__STDC_IEC_599__)
#define FEATURE_IEC_559             1
#else
#define FEATURE_IEC_559             0
#endif

#if STANDARD_C99 && defined(__STDC_IEC_559_COMPLEX__)
#define FEATURE_IEC_559_COMPLEX     1
#else
#define FEATURE_IEC_559_COMPLEX     0
#endif

/**
 * \def FEATURE_IEC_60559_BFP
 * \def FEATURE_IEC_60559_COMPLEX
 * \brief 浮点扩展：二进制浮点算术。
 * \sa <https://zh.cppreference.com/w/c/experimental/fpext1>
 * \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1778>
 */
#if defined(__STDC_IEC_60559_BFP__) && 201000L<=__STDC_IEC_60559_BFP__
#define FEATURE_IEC_60559_BFP       1
#else
#define FEATURE_IEC_60559_BFP       0
#endif

#if defined(__STDC_IEC_60559_COMPLEX__) && 201000L<=__STDC_IEC_60559_COMPLEX__
#define FEATURE_IEC_60559_COMPLEX   1
#else
#define FEATURE_IEC_60559_COMPLEX   0
#endif

/**
 * \brief 浮点扩展：补充函数。
 * \sa <https://zh.cppreference.com/w/c/experimental/fpext4>
 * \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1950>
 */
#if defined(__STDC_IEC_60559_FUNCS__) && 201506L<=__STDC_IEC_60559_FUNCS__
#define FEATURE_IEC_60559_FUNCS     1
#else
#define FEATURE_IEC_60559_FUNCS     0
#endif

#if defined(__STDC_ISO_10646__) && 201506L<=__STDC_ISO_10646__
#define FEATURE_ISO_10646           1
#else
#define FEATURE_ISO_10646           0
#endif

/**
 * \brief 边界检查接口。
 * \sa <http://open-std.org/jtc1/sc22/wg14/www/docs/n1225>
 */
#if STANDARD_C11 && defined(__STDC_LIB_EXT1__) && 201112L<=__STDC_LIB_EXT1__ || 0 < NORMALIZED_MSC_VERSION
#define FEATURE_LIB_EXT1            1
#else
#define FEATURE_LIB_EXT1            0
#endif

#if STANDARD_C99 && defined(__STDC_MB_MIGHT_NEQ_WC__)
#define FEATURE_MB_MIGHT_NEQ_WC     1
#else
#define FEATURE_MB_MIGHT_NEQ_WC     0
#endif

/**
 * \def FEATURE_THREADS
 * \brief 线程支持库。
 * \sa <https://zh.cppreference.com/w/c/thread>
 */
#if STANDARD_C11 && !defined(__STDC_NO_THREADS__)
#define FEATURE_THREADS             1
#else
#define FEATURE_THREADS             0
#endif

#if STANDARD_C11 && defined(__STDC_UTF_16__)
#define FEATURE_UTF_16              1
#else
#define FEATURE_UTF_16              0
#endif

#if STANDARD_C11 && defined(__STDC_UTF_32__)
#define FEATURE_UTF_32              1
#else
#define FEATURE_UTF_32              0
#endif

#if STANDARD_C11 && !defined(__STDC_NO_VLA__)
#define FEATURE_VLA                 1
#else
#define FEATURE_VLA                 0
#endif

#endif
