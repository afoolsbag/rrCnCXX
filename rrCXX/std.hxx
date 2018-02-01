//===-- C++ Standard Version ------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++标准版本
///
/// \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
/// \sa ["C++ compiler support"](http://en.cppreference.com/w/cpp/compiler_support). *cppreference.com*.
/// \sa ["Clang - C++17, C++14, C++11 and C++98 Status"](https://clang.llvm.org/cxx_status.html). *The LLVM Compiler Infrastructure Project*.
/// \sa ["C++ Standards Support in GCC"](https://gcc.gnu.org/projects/cxx-status.html). *Free Software Foundation*.
/// \sa ["Support For C++11/14/17 Features (Modern C++)"](https://msdn.microsoft.com/library/hh567368). *Microsoft Developer Network*.
///
/// \author zhengrr
/// \date 2017-12-13 – 2018-2-1
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#ifndef RRCXX_STD_HXX_
#define RRCXX_STD_HXX_

// Language Standards
#ifndef __cplusplus
# error A C++ compiler is required.
#endif

/// ISO/IEC 14882:2017
/// https://iso.org/standard/68564.html
#define CXX17 (201703L <= __cplusplus)

/// ISO/IEC 14882:2014
/// \sa https://iso.org/standard/64029.html
#define CXX14 (201402L <= __cplusplus)

/// ISO/IEC 14882:2011
/// \sa https://iso.org/standard/50372.html
#define CXX11 (201103L <= __cplusplus)

/// ISO/IEC 14882:1998
/// \sa https://iso.org/standard/25845.html
#define CXX98 (199711L <= __cplusplus)

// Clang
#ifdef __clang__
# define CLANG_VER (__clang_major__*10000 + __clang_minor__*100 + __clang_patchlevel__)
#else
# undef CLANG_VER
#endif

// GCC C/C++
#ifdef __GNUC__
# define GNUC_VER (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
#else
# undef GNUC_VER
#endif

// Microsoft Visual C++
#ifdef _MSC_VER
# define MSC_VER _MSC_VER
#else
# undef MSC_VER
#endif

// Language Features

/// Non-static data member initializers.
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2756
#define N2756 (CXX11 || 40700<=GNUC_VER || 1800<=MSC_VER || 200809<=__cpp_nsdmi)

/// Dynamic Initialization and Destruction with Concurrency.
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2660
#define N2660 (CXX11 || 40300<=GNUC_VER || 1900<=MSC_VER || 200806<=__cpp_threadsafe_static_init)

/// Namespace Association ("inline namespace").
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2535
#define N2535 (CXX11 || 40300<=GNUC_VER || 1900<=MSC_VER)

/// Deducing the type of variable from its initializer expression.
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1984
#define N1984 (CXX11 || 40400<=GNUC_VER || 1900<=MSC_VER)

#endif// RRCXX_STD_HXX_
