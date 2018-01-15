/**
 * \file
 * \brief C 标准版本
 * \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 * \author zhengrr
 * \date 2018-1-5 – 15
 * \copyright The MIT License
 */

#ifndef RRCLANG_C_STANDARD_VERSION_HPP_
#define RRCLANG_C_STANDARD_VERSION_HPP_

/* Language Standards */
#ifndef __STDC__
# error A C compiler is required.
#endif

/** \brief C11 */
#define CSTD11 (201112L <= __STDC_VERSION__)
/** \brief C99 */
#define CSTD99 (199901L <= __STDC_VERSION__)
/** \brief C95 */
#define CSTD95 (199409L <= __STDC_VERSION__)
/** \brief C90 */
#define CSTD90 (!0)
/** \brief C89 */
#define CSTD89 (!0)

/* Language Features */
/**
 * \brief Extensions to the C Library - Part II: Dynamic allocation functions.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1337
 */
#define CN1337 (0)

/**
 * \brief Extensions to the C Library Part I: Bounds-checking interfaces.
 * \sa http://open-std.org/JTC1/SC22/WG14/www/docs/n1225
 */
#define CN1225 (200509L<=__STDC_LIB_EXT1__)

#endif/* RRCLANG_C_STANDARD_VERSION_HPP_*/
