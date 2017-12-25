/** \file
 *  \brief C++ 标准版本。
 *  \sa <https://sourceforge.net/p/predef/wiki/Compilers/>
 *  \sa <https://clang.llvm.org/cxx_status.html>
 *  \sa <https://gcc.gnu.org/projects/cxx-status.html>
 *  \sa <https://msdn.microsoft.com/library/hh567368.aspx>
 *  \author zhengrr
 *  \date 2017-12-13 – 25
 *  \copyright The MIT License */

#ifndef RRCXXLANG_CXX_STANDARD_VERSION_HPP_
#define RRCXXLANG_CXX_STANDARD_VERSION_HPP_

/* Language Standards */

#ifdef __cplusplus
  #define CXX_STANDARD_VERSION __cplusplus
#else
  #error A C++ compiler is required.
#endif

#define CXX_STANDARD_17 201703L
#define CXX_STANDARD_14 201402L
#define CXX_STANDARD_11 201103L
#define CXX_STANDARD_98 199711L

#define CXXSTD17 (CXX_STANDARD_17 <= CXX_STANDARD_VERSION)
#define CXXSTD14 (CXX_STANDARD_14 <= CXX_STANDARD_VERSION)
#define CXXSTD11 (CXX_STANDARD_11 <= CXX_STANDARD_VERSION)
#define CXXSTD98 (CXX_STANDARD_98 <= CXX_STANDARD_VERSION)

/* Clang */
#ifdef __clang__
# define CXX_CLANG_VERSION (__clang_major__*10000 + __clang_minor__*100 + __clang_patchlevel__)
#else
# undef CXX_CLANG_VERSION
#endif

#define CXX_CLANG_3_5 30500

/* GCC C/C++ */

#ifdef __GNUC__
# define CXX_GNUC_VERSION (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
#else
# undef CXX_GNUC_VERSION
#endif

#define CXX_GNUC_7     70000
#define CXX_GNUC_4_8_1 40801
#define CXX_GNUC_4_4   40400
#define CXX_GNUC_4_3   40300

/* Microsoft Visual C++ */

#ifdef _MSC_VER
# define CXX_MSC_VERSION _MSC_VER
#else
# undef CXX_MSC_VERSION
#endif

#define CXX_MSC_2017 1910
#define CXX_MSC_2015 1900
#define CXX_MSC_2013 1800
#define CXX_MSC_2012 1700
#define CXX_MSC_2010 1600
#define CXX_MSC_2008 1500
#define CXX_MSC_2005 1400
#define CXX_MSC_2003 1310
#define CXX_MSC_7_0  1300
#define CXX_MSC_6_0  1200
#define CXX_MSC_5_0  1100
#define CXX_MSC_4_2  1020
#define CXX_MSC_4_0  1000
#define CXX_MSC_3_0   900
#define CXX_MSC_1_0   800

/* Language Features */

#define CXXN2660 (   CXXSTD11 \
                   || CXX_GNUC_4_3 <= CXX_GNUC_VERSION \
                   || CXX_MSC_2015 <= CXX_MSC_VERSION \
                   || 200806       <= __cpp_threadsafe_static_init)

#define CXXN2535 (   CXXSTD11 \
                   || CXX_GNUC_4_4 <= CXX_GNUC_VERSION \
                   || CXX_MSC_2015 <= CXX_MSC_VERSION)

#define CXXN1984 (   CXXSTD11 \
                   || CXX_GNUC_4_4 <= CXX_GNUC_VERSION \
                   || CXX_MSC_2015 <= CXX_MSC_VERSION)

#endif// RRCXXLANG_CXX_STANDARD_VERSION_HPP_
