/*===-- C Version ----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C 版本。
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki)
 *
 * \version 2018-08-07
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_CVER_H_
#define RRC_CVER_H_

/*-Compilers------------------------------------------------------------------*/

#ifdef __clang__
# define CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#else
# define CLANG 0
#endif

#ifdef __GNUC__
# define GNUC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
# define GNUC 0
#endif

#ifdef _MSC_VER
# define MSC (_MSC_VER)
#else
# define MSC 0
#endif

/*-Language-Standards---------------------------------------------------------*/

#if !defined(__STDC__) && !MSC
# error A C compiler is required.
#endif

/** \brief ISO/IEC 9899:2011
 *  \sa <https://iso.org/standard/57853.html> */
#if 201112L <= __STDC_VERSION__
# define C11 201112L
#else
# define C11 0
#endif

/** \brief ISO/IEC 9899:1999
 *  \sa <https://iso.org/standard/29237.html> */
#if 199901L <= __STDC_VERSION__
# define C99 199901L
#else
# define C99 0
#endif

/** \brief ISO/IEC 9899:1990/Amd 1:1995
 *  \sa <https://iso.org/standard/23909.html> */
#if 199410L <= __STDC_VERSION__
# define C95 199410L
# define C94 199410L
#else
# define C95 0
# define C95 0
#endif

/** \brief ISO/IEC 9899:1990
 *  \sa <https://iso.org/standard/17782.html> */
#ifdef __STDC__
# define C90 1
#else
# define C90 0
#endif

/** \brief ANSI X3.159-1989 */
#ifdef __STDC__
# define C89 1
#else
# define C89 0
#endif

/*-Language-Features----------------------------------------------------------*/

/** \brief 支持动态分配函数的扩展。
 *  \sa <https://zh.cppreference.com/w/c/experimental/dynamic>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1248> */
#ifdef __STDC_ALLOC_LIB__
# define ALLOC_LIB 1
#else
# define ALLOC_LIB 0
#endif

#if C11 && defined(__STDC_ANALYZABLE__)
# define ANALYZABLE 1
#else
# define ANALYZABLE 0
#endif

#if C11 && !defined(__STDC_NO_ATOMICS__)
# define ATOMICS 1
#else
# define ATOMICS 0
#endif

#if C11 && !defined(__STDC_NO_COMPLEX__)
# define COMPLEX 1
#else
# define COMPLEX 0
#endif

#if C99 && defined(__STDC_IEC_559__)
# define IEC_559 1
#else
# define IEC_599 0
#endif

#if C99 && defined(__STDC_IEC_559_COMPLEX__)
# define IEC_559_COMPLEX 1
#else
# define IEC_559_COMPLEX 0
#endif

/** \brief 浮点扩展：二进制浮点算术。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext1>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1778> */
#if (201000L <= __STDC_IEC_60559_BFP__)
# define IEC_60559_BFP 1 
#else
# define IEC_60559_BFP 0
#endif

#if (201000L <= __STDC_IEC_60559_COMPLEX__)
# define IEC_60559_COMPLEX 1
#else
# define IEC_60559_COMPLEX 0
#endif

/** \brief 浮点扩展：补充函数。
 *  \sa <https://zh.cppreference.com/w/c/experimental/fpext4>
 *  \sa <http://open-std.org/JTC1/SC22/WG14/www/docs/n1950> */
#if (201506L <= __STDC_IEC_60559_FUNCS__)
# define IEC_60559_FUNCS 1
#else
# define IEC_60559_FUNCS 0
#endif

#if C99 && 199100L < __STDC_ISO_10646__
# define ISO_10646 1
#else
# define ISO_10646 0
#endif

/** \brief 边界检查接口。
 *  \sa <http://open-std.org/jtc1/sc22/wg14/www/docs/n1225> */
#if C11 && (201112L <= __STDC_LIB_EXT1__) || MSC
# define LIB_EXT1 1
#else
# define LIB_EXT1 0
#endif

#if C99 && defined(__STDC_MB_MIGHT_NEQ_WC__)
# define MB_MIGHT_NEQ_WC 1
#else
# define MB_MIGHT_NEQ_WC 0
#endif

#if C11 && !defined(__STDC_NO_THREADS__)
# define THREADS 1
#else
# define THREADS 0
#endif

#if C11 && defined(__STDC_UTF_16__)
# define UTF_16 1
#else
# define UTF_16 0
#endif

#if C11 && defined(__STDC_UTF_32__)
# define UTF_32 1
#else
# define UTF_32 0
#endif

#if C11 && !defined(__STDC_NO_VLA__)
# define VLA 1
#else
# define VLA 0
#endif

#endif/*RRC_CVER_H_*/
