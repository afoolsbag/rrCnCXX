/** \file
 *  \brief C 标准版本
 *  \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *  \author zhengrr
 *  \date 2018-1-5
 *  \copyright The MIT License */

#ifndef RRCLANG_C_STANDARD_VERSION_HPP_
#define RRCLANG_C_STANDARD_VERSION_HPP_

/* Language Standards */
#ifndef __STDC__
# error A C compiler is required.
#endif

/** C11 */
#define CSTD11 (199901L <= __STDC_VERSION__)
/** C99 */
#define CSTD99 (199901L <= __STDC_VERSION__)
/** C94 */
#define CSTD94 (199409L <= __STDC_VERSION__)
/** C90 */
#define CSTD90 (!0)
/** C89 */
#define CSTD89 (!0)

#endif// RRCLANG_C_STANDARD_VERSION_HPP_
