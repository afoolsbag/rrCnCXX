/** \file
 *  \brief C++ 标准版本。
 *  \sa [Pre-defined C/C++ Compiler Macros](https://sourceforge.net/p/predef/wiki/Compilers/).
 *  \sa [C++ Standards Support in GCC](https://gcc.gnu.org/projects/cxx-status.html).
 *  \sa [Support For C++11/14/17 Features (Modern C++)](https://msdn.microsoft.com/library/hh567368.aspx).
 *  \author zhengrr
 *  \date 2017-12-13
 *  \copyright The MIT License
 */
#ifndef RRCXXLANG_CXX_STANDARD_VERSION_HPP_
#define RRCXXLANG_CXX_STANDARD_VERSION_HPP_

/* Language Standards */

#ifdef __cplusplus
# define CXX_STD_VER __cplusplus
#else
# error "__cplusplus NOT DEFINED"
#endif

#define CXX_STD_17 201703L
#define CXX_STD_14 201402L
#define CXX_STD_11 201103L
#define CXX_STD_98 199711L

/* GCC C/C++ */

#ifdef __GNUC__
# ifndef __GNUC_PATCHLEVEL__
#  define __GNUC_PATCHLEVEL__ 0
# endif
# define CXX_GCC_VER (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
# define CXX_GCC_VER 0
#endif

#define CXX_GCC_7     70000
#define CXX_GCC_4_8_1 40801
#define CXX_GCC_4_4_3 40403
#define CXX_GCC_4_4   40400
#define CXX_GCC_4_3   40300

/* Microsoft Visual C++ */

#ifdef _MSC_VER
# define CXX_MVC_VER _MSC_VER
#else
# define CXX_MVC_VER 0
#endif

#define CXX_MVC_2017 1910
#define CXX_MVC_2015 1900
#define CXX_MVC_2013 1800
#define CXX_MVC_2012 1700
#define CXX_MVC_2010 1600
#define CXX_MVC_2008 1500
#define CXX_MVC_2005 1400
#define CXX_MVC_2003 1310
#define CXX_MVC_7_0  1300
#define CXX_MVC_6_0  1200
#define CXX_MVC_5_0  1100
#define CXX_MVC_4_2  1020
#define CXX_MVC_4_0  1000
#define CXX_MVC_3_0   900
#define CXX_MVC_1_0   800


#endif// RRCXXLANG_CXX_STANDARD_VERSION_HPP_
