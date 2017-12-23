/** \file
 *  \brief C++ 标准版本。
 *  \sa <https://sourceforge.net/p/predef/wiki/Compilers/>.
 *  \sa <https://clang.llvm.org/cxx_status.html>
 *  \sa <https://gcc.gnu.org/projects/cxx-status.html>.
 *  \sa <https://msdn.microsoft.com/library/hh567368.aspx>.
 *  \author zhengrr
 *  \date 2017-12-13 – 20
 *  \copyright The MIT License */

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

/* Clang */
#ifdef __clang__
# define CXX_CLA
# define CXX_CLA_VER (__clang_major__*10000 + __clang_minor__*100 + __clang_patchlevel__)
#else
# undef CXX_CLA
#endif

#define CXX_CLA_3_5 30500

/* GCC */

#ifdef __GNUC__
# define CXX_GCC
# ifndef __GNUC_PATCHLEVEL__
#  define __GNUC_PATCHLEVEL__ 0
# endif
# define CXX_GCC_VER (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
#else
# undef CXX_GCC
# define CXX_GCC_VER 0
#endif

#define CXX_GCC_7     70000
#define CXX_GCC_4_8_1 40801
#define CXX_GCC_4_4   40400
#define CXX_GCC_4_3   40300

/* Microsoft Visual */

#ifdef _MSC_VER
# define CXX_MVC
# define CXX_MVC_VER _MSC_VER
#else
# undef CXX_MVC
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

/* Language Features */

#define CXX_N2660 (   CXX_STD_11   <= CXX_STD_VER \
                   || CXX_GCC_4_3  <= CXX_GCC_VER \
                   || CXX_MVC_2015 <= CXX_MVC_VER \
                   || 200806       <= __cpp_threadsafe_static_init)

#define CXX_N2535 (   CXX_STD_11   <= CXX_STD_VER \
                   || CXX_GCC_4_4  <= CXX_GCC_VER \
                   || CXX_MVC_2015 <= CXX_MVC_VER)

#define CXX_N1984 (   CXX_STD_11   <= CXX_STD_VER \
                   || CXX_GCC_4_4  <= CXX_GCC_VER \
                   || CXX_MVC_2010 <= CXX_MVC_VER)

#endif// RRCXXLANG_CXX_STANDARD_VERSION_HPP_
