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

/*-Compilers-Normalization----------------------------------------------------*/

#define MKVER(v,r,p) (((v) << 24) + ((r) << 16) + (p))

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

/** \brief ISO/IEC 9899:2018 \sa <https://iso.org/standard/74528.html> */
#define C18 (201710L <= __STDC_VERSION__)
#define C17 (201710L <= __STDC_VERSION__)
/** \brief ISO/IEC 9899:2011 \sa <https://iso.org/standard/57853.html> */
#define C11 (201112L <= __STDC_VERSION__)
/** \brief ISO/IEC 9899:1999 \sa <https://iso.org/standard/29237.html> */
#define C99 (199901L <= __STDC_VERSION__)
/** \brief ISO/IEC 9899:1990/Amd 1:1995 \sa <https://iso.org/standard/23909.html> */
#define C95 (199410L <= __STDC_VERSION__)
#define C94 (199410L <= __STDC_VERSION__)
/** \brief ISO/IEC 9899:1990 \sa <https://iso.org/standard/17782.html> */
#define C90 (__STDC__)
/** \brief ANSI X3.159-1989 */
#define C89 (__STDC__)

/*-Language-Features----------------------------------------------------------*/

/** \brief 支持动态分配函数的扩展。
 *  \sa <https://zh.cppreference.com/w/c/experimental/dynamic>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1248> */
#ifdef __STDC_ALLOC_LIB__
# define RRC_ALLOC_LIB 1
#else
# define RRC_ALLOC_LIB 0
#endif

#if RRC_C11 && defined(__STDC_ANALYZABLE__)
# define RRC_ANALYZABLE 1
#else
# define RRC_ANALYZABLE 0
#endif

#if RRC_C11 && !defined(__STDC_NO_ATOMICS__)
# define RRC_ATOMICS 1
#else
# define RRC_ATOMICS 0
#endif

#if RRC_C11 && !defined(__STDC_NO_COMPLEX__)
# define RRC_COMPLEX 1
#else
# define RRC_COMPLEX 0
#endif

#if RRC_C99 && defined(__STDC_IEC_559__)
# define RRC_IEC_559 1
#else
# define RRC_IEC_599 0
#endif

#if RRC_C99 && defined(__STDC_IEC_559_COMPLEX__)
# define RRC_IEC_559_COMPLEX 1
#else
# define RRC_IEC_559_COMPLEX 0
#endif

/** \brief 浮点扩展：二进制浮点算术。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext1>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1778> */
#if (201000L <= __STDC_IEC_60559_BFP__)
# define RRC_IEC_60559_BFP 1 
#else
# define RRC_IEC_60559_BFP 0
#endif

#if (201000L <= __STDC_IEC_60559_COMPLEX__)
# define RRC_IEC_60559_COMPLEX 1
#else
# define RRC_IEC_60559_COMPLEX 0
#endif

/** \brief 浮点扩展：补充函数。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext4>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1950> */
#if (201506L <= __STDC_IEC_60559_FUNCS__)
# define RRC_IEC_60559_FUNCS 1
#else
# define RRC_IEC_60559_FUNCS 0
#endif

#if RRC_C99 && 199100L < __STDC_ISO_10646__
# define RRC_ISO_10646 1
#else
# define RRC_ISO_10646 0
#endif

/** \brief 边界检查接口。
 *  \sa <http://open-std.org/jtc1/sc22/wg14/www/docs/n1225> */
#if RRC_C11 && (201112L <= __STDC_LIB_EXT1__) || RRC_MSC
# define RRC_LIB_EXT1 1
#else
# define RRC_LIB_EXT1 0
#endif

#if RRC_C99 && defined(__STDC_MB_MIGHT_NEQ_WC__)
# define RRC_MB_MIGHT_NEQ_WC 1
#else
# define RRC_MB_MIGHT_NEQ_WC 0
#endif

#if RRC_C11 && !defined(__STDC_NO_THREADS__)
# define RRC_THREADS 1
#else
# define RRC_THREADS 0
#endif

#if RRC_C11 && defined(__STDC_UTF_16__)
# define RRC_UTF_16 1
#else
# define RRC_UTF_16 0
#endif

#if RRC_C11 && defined(__STDC_UTF_32__)
# define RRC_UTF_32 1
#else
# define RRC_UTF_32 0
#endif

#if RRC_C11 && !defined(__STDC_NO_VLA__)
# define RRC_VLA 1
#else
# define RRC_VLA 0
#endif

#endif/*RRC_ADP_H_*/
