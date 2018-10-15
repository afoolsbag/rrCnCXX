/*===-- Adaptation ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 适配。
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki)
 *
 * \version 2018-08-23
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_ADP_H_
#define RRC_ADP_H_

/*-Compilers------------------------------------------------------------------*/

#define MKVER(v,r,p) (((v) << 24) + ((r) << 16) + (p))

#ifdef __clang__
#  define CLANG MKVER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#endif

#ifdef __GNUC__
# ifdef __GNUC_PATCHLEVEL__
#  define GNUC MKVER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
# else
#  define GNUC MKVER(__GNUC__, __GNUC_MINOR__, 0)
# endif
#endif

#ifdef _MSC_VER
# if 1400 <= _MSC_VER
#  define MSC MKVER(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, _MSC_FULL_VER % 100000)
# elif 1200 <= _MSC_VER
#  define MSC MKVER(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
# else
#  define MSC MKVER(_MSC_VER / 100, _MSC_VER % 100, 0)
# endif
#endif

/*-Language-Standards---------------------------------------------------------*/

#if !defined(__STDC__) && !defined(_MSC_VER)
# error A C compiler is required.
#endif

/** \brief ISO/IEC 9899:2018
 *  \sa <https://iso.org/standard/74528.html> */
#define C18 (201710L<=__STDC_VERSION__)
#define C17 (201710L<=__STDC_VERSION__)

/** \brief ISO/IEC 9899:2011
 *  \sa <https://iso.org/standard/57853.html> */
#define C11 (201112L<=__STDC_VERSION__)

/** \brief ISO/IEC 9899:1999
 *  \sa <https://iso.org/standard/29237.html> */
#define C99 (199901L<=__STDC_VERSION__)

/** \brief ISO/IEC 9899:1990/Amd 1:1995
 *  \sa <https://iso.org/standard/23909.html> */
#define C95 (199410L<=__STDC_VERSION__)
#define C94 (199410L<=__STDC_VERSION__)

/** \brief ISO/IEC 9899:1990
 *  \sa <https://iso.org/standard/17782.html> */
#define C90 (__STDC__)

/** \brief ANSI X3.159-1989 */
#define C89 (__STDC__)

/*-Language-Features----------------------------------------------------------*/

/** \brief 支持动态分配函数的扩展。
 *  \sa <https://zh.cppreference.com/w/c/experimental/dynamic>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1248> */
#define ALLOC_LIB         (__STDC_ALLOC_LIB__)

#define ANALYZABLE        (C11 || __STDC_ANALYZABLE__)

#define ATOMICS           (C11 && !__STDC_NO_ATOMICS__)

#define COMPLEX           (C11 && !__STDC_NO_COMPLEX__)

#define IEC_559           (C99 && __STDC_IEC_599_)

#define IEC_559_COMPLEX   (C99 && __STDC_IEC_559_COMPLEX__)

/** \brief 浮点扩展：二进制浮点算术。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext1>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1778> */
#define IEC_60559_BFP     (201000L<=__STDC_IEC_60559_BFP__)

#define IEC_60559_COMPLEX (201000L<=__STDC_IEC_60559_COMPLEX__)

/** \brief 浮点扩展：补充函数。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext4>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1950> */
#define IEC_60559_FUNCS   (201506L<=__STDC_IEC_60559_FUNCS__)

#define ISO_10646         (C99 && 199100L<__STDC_ISO_10646__)

/** \brief 边界检查接口。
 *  \sa <http://open-std.org/jtc1/sc22/wg14/www/docs/n1225> */
#define LIB_EXT1          (C11 && 201112L<=__STDC_LIB_EXT1__ || MSC)

#define MB_MIGHT_NEQ_WC   (C99 && __STDC_MB_MIGHT_NEQ_WC__)

#define THREADS           (C11 && !__STDC_NO_THREADS__)

#define UTF_16            (C11 && __STDC_UTF_16__)

#define UTF_32            (C11 && __STDC_UTF_32__)

#define VLC               (C11 && !__STDC_NO_VLA__)

#endif/*RRC_ADP_H_*/
