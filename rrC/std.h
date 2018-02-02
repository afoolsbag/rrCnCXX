/*===-- C Standard Version -------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C标准版本
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *
 * \author zhengrr
 * \date 2018-1-5 – 2018-2-2
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#ifndef RRC_STD_H_
#define RRC_STD_H_

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

/** \brief ISO/IEC 9899/AMD1:1995
 *  \sa https://iso.org/standard/23909.html */
#define C95 (199409L <= __STDC_VERSION__)

/** \brief ISO/IEC 9899:1990
 *  \sa https://iso.org/standard/17782.html */
#define C90 (!0)

/**
 * \brief ANSI X3.159-1989
 */
#define C89 (!0)

/* Language Features */

/** \brief Floating-point extensions for C, Part 1: Binary floating-point arithmetic
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/1778 */
#define N1778 (200ymmL<=__STDC_ALLOC_LIB__)

/** \brief Extensions to the C Library, Part II: Dynamic allocation functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1337 */
#define N1337 (200nnnL<=__STDC_ALLOC_LIB__)

/** \brief Extensions to the C Library, Part II: Dynamic Allocation Functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1248 */
#define N1248 (200nnnL<=__STDC_ALLOC_LIB__)

/** \brief Extension to support decimal floating-point arithmetic
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1241 */
#define N1241 (200704L<=__STDC_DEC_FP__)

/** \brief Extensions to the C Library, Part I: Bounds-checking interfaces
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1225 */
#define N1225 (200509L<=__STDC_LIB_EXT1__)

/** \brief Extensions to the C Library, to Support Mathematical Special Functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1182 */
#define N1182 (0)

/** \brief Extensions to support embedded processors
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1169 */
#define N1169 (0)

/** \brief Extensions to support new character data types
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1040 */
#define N1014 (0)

#endif/* RRC_STD_H_*/
