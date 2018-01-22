/** \file
 *  \brief C++ 标准版本
 *  \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
 *  \sa ["Clang - C++17, C++14, C++11 and C++98 Status"](https://clang.llvm.org/cxx_status.html). *The LLVM Compiler Infrastructure Project*.
 *  \sa ["C++ Standards Support in GCC"](https://gcc.gnu.org/projects/cxx-status.html). *Free Software Foundation*.
 *  \sa ["Support For C++11/14/17 Features (Modern C++)"](https://msdn.microsoft.com/library/hh567368). *Microsoft Developer Network*.
 *  \author zhengrr
 *  \date 2017-12-13 – 2018-1-5
 *  \copyright The MIT License */

#ifndef RRCXXLANG_CXX_STANDARD_VERSION_HPP_
#define RRCXXLANG_CXX_STANDARD_VERSION_HPP_

/* Language Standards */
#ifndef __cplusplus
# error A C++ compiler is required.
#endif

/** C++17 */
#define CXXSTD17 (201703L <= __cplusplus)
/** C++14 */
#define CXXSTD14 (201402L <= __cplusplus)
/** C++11 */
#define CXXSTD11 (201103L <= __cplusplus)
/** C++98 */
#define CXXSTD98 (199711L <= __cplusplus)

/* Clang */
#ifdef __clang__
# define CXX_CLANG_VERSION (__clang_major__*10000 + __clang_minor__*100 + __clang_patchlevel__)
#else
# undef CXX_CLANG_VERSION
#endif

/* GCC C/C++ */
#ifdef __GNUC__
# define CXX_GNUC_VERSION (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
#else
# undef CXX_GNUC_VERSION
#endif

/* Microsoft Visual C++ */
#ifdef _MSC_VER
# define CXX_MSC_VERSION _MSC_VER
#else
# undef CXX_MSC_VERSION
#endif

/* Language Features */
/** Dynamic Initialization and Destruction with Concurrency.
 *  \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2660 */
#define CXXN2660 (CXXSTD11 || 40300<=CXX_GNUC_VERSION || 1900<=CXX_MSC_VERSION || 200806<=__cpp_threadsafe_static_init)

/** Namespace Association ("inline namespace").
 *  \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2535 */
#define CXXN2535 (CXXSTD11 || 40300<=CXX_GNUC_VERSION || 1900<=CXX_MSC_VERSION)

/** Deducing the type of variable from its initializer expression.
 *  \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1984 */
#define CXXN1984 (CXXSTD11 || 40400<=CXX_GNUC_VERSION || 1900<=CXX_MSC_VERSION)

#endif// RRCXXLANG_CXX_STANDARD_VERSION_HPP_
