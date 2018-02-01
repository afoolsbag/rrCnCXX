/*===-- C Standard Version -------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C标准版本
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *
 * \author zhengrr
 * \date 2018-1-5 – 2018-2-1
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#ifndef RRC_STD_H_
#define RRC_STD_H_

/* Language Standards */
#ifndef __STDC__
# error A C compiler is required.
#endif

/**
 * ISO/IEC 9899:2011
 * \sa https://iso.org/standard/57853.html
 */
#define C11 (201112L <= __STDC_VERSION__)
/**
 * ISO/IEC 9899:1999
 * \sa https://iso.org/standard/29237.html
 */
#define C99 (199901L <= __STDC_VERSION__)
/**
 * ISO/IEC 9899/AMD1:1995
 * \sa https://iso.org/standard/23909.html
 */
#define C95 (199409L <= __STDC_VERSION__)
/**
 * ISO/IEC 9899:1990
 * \sa https://iso.org/standard/17782.html
 */
#define C90 (!0)
/**
 * ANSI X3.159-1989
 */
#define C89 (!0)

/* Language Features */
/**
 * Extensions to the C Library - Part II: Dynamic allocation functions.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1337
 */
#define N1337 (0)

/**
 * Extensions to the C Library Part I: Bounds-checking interfaces.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1225
 */
#define N1225 (200509L<=__STDC_LIB_EXT1__)

#endif/* RRC_STD_H_*/
