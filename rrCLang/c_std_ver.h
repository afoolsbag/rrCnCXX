/**
 * \file
 * \brief C标准版本
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 * \author zhengrr
 * \date 2018-1-5 – 22
 * \copyright The MIT License
 */

#ifndef RRCLANG_C_STD_VER_H_
#define RRCLANG_C_STD_VER_H_

/* Language Standards */
#ifndef __STDC__
# error A C compiler is required.
#endif

/** \brief C11 */
#define C_STD_11 (201112L <= __STDC_VERSION__)
/** \brief C99 */
#define C_STD_99 (199901L <= __STDC_VERSION__)
/** \brief C95 */
#define C_STD_95 (199409L <= __STDC_VERSION__)
/** \brief C90 */
#define C_STD_90 (!0)
/** \brief C89 */
#define C_STD_89 (!0)

/* Language Features */
/**
 * \brief Extensions to the C Library - Part II: Dynamic allocation functions.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1337
 */
#define C_N1337 (0)

/**
 * \brief Extensions to the C Library Part I: Bounds-checking interfaces.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1225
 */
#define C_N1225 (200509L<=__STDC_LIB_EXT1__)

#endif/* RRCLANG_C_STD_VER_H_*/
