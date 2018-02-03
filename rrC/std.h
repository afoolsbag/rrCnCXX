/*===-- C Standard Version -------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C标准版本
 *
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *
 * \author zhengrr
 * \date 2018-1-5 – 2018-2-3
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

/** \brief ANSI X3.159-1989
 */
#define C89 (!0)

/* Language Features */

/** \brief Thread-based parallelism
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n2170 */
#define N2170 (201709L<=__STDC_PARALLEL_EXT__)

/** \brief Vulnerability descriptions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n2169 */
#define N2169 (0)

/** \brief Supplementary attributes
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n2004 */
#define N2004 (201000L<=__STDC_IEC_60559_ATTRIBS__)

/** \brief Transactional Memory
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1961 */
#define N1961 (0)

/** \brief Supplementary functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1950 */
#define N1950 (201506L<=__STDC_IEC_60559_FUNCS__)

/** \brief Interchange and extended types
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1945 */
#define N1945 (201506L<=__STDC_IEC_60559_TYPES__)

/** \brief Decimal floating-point arithmetic
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1912 */
#define N1912 (201000L<=__STDC_IEC_60559_DFP__)

/** \brief Binary floating-point arithmetic
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1778 */
#define N1778 (201000L<=__STDC_IEC_60559_BFP__)

/** \brief Secure coding rules
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1624 */
#define N1624 (0)

/** \brief Dynamic allocation functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1248 */
#define N1248 (200000<=__STDC_ALLOC_LIB__)

/** \brief Decimal floating-point arithmetic
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1241 */
#define N1241 (200704L<=__STDC_DEC_FP__)

/** \brief Bounds-checking interfaces
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1225 */
#define N1225 (200509L<=__STDC_LIB_EXT1__)

/** \brief Mathematical special functions
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1182 */
#define N1182 (0)

/** \brief Embedded processors
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1169 */
#define N1169 (0)

/** \brief New character data types
 *  \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1040 */
#define N1040 (0)

#endif/* RRC_STD_H_*/
