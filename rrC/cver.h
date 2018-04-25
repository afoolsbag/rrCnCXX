/*===-- C Version ----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C版本。
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *
 * \version 2018-04-25
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_CVER_H_
#define RRC_CVER_H_

/* Language Standards */

#ifndef __STDC__
# error A C compiler is required.
#endif

/** \brief ISO/IEC 9899:2011
 *  \sa https://iso.org/standard/57853.html */
#define C11 (201112L <= __STDC_VERSION__)

/** \brief ISO/IEC 9899:1999
 *  \sa https://iso.org/standard/29237.html */
#define C99 (199901L <= __STDC_VERSION__)

/** \brief ISO/IEC 9899:1990/Cor 1:1994
 *  \sa https://iso.org/standard/24271.html */
#define C95 C94
#define C94 (199409L <= __STDC_VERSION__)

/** \brief ISO/IEC 9899:1990
 *  \sa https://iso.org/standard/17782.html */
# define C90 (defined(__STDC__))

/** \brief ANSI X3.159-1989
 */
# define C89 (defined(__STDC__))

/* Language Features */

/** \brief 支持动态分配函数的扩展。
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1248 */
#define ALLOC_LIB (defined(__STDC_ALLOC_LIB__))

#define ATOMICS (C11 && !defined(__STDC_NO_ATOMICS__))

#define COMPLEX (C99 && !defined(__STDC_NO_COMPLEX__))

#define IEC_559_COMPLEX (C11 && defined(__STDC_IEC_559_COMPLEX__))

/** \brief 浮点扩展：二进制浮点算术。
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1778 */
#define IEC_60559_BFP (201000<=__STDC_IEC_60559_BFP__)

#define IEC_60559_COMPLEX (201000<=__STDC_IEC_60559_COMPLEX__)

/** \brief 浮点扩展：补充函数。
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1950 */
#define IEC_60559_FUNCS (201506<=__STDC_IEC_60559_FUNCS__)

#define LIB_EXT1 (C11 && defined(__STDC_LIB_EXT1__))

#define THREADS (C11 && !defined(__STDC_NO_THREADS__))

#endif/*RRC_CVER_H_*/
