//===-- C++ Versiosn---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 版本。
///
/// \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
/// \sa ["C++ 编译器支持情况表"](https://zh.cppreference.com/w/cpp/compiler_support). *cppreference.com*.
///
/// \version 2018-09-17
/// \since 2017-12-13
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_CXX_VERSIONS_HXX_
#define RRCXX_CXX_VERSIONS_HXX_

//-Compilers--------------------------------------------------------------------

/// \brief 构造版本。\n
///        Make Version.
/// \details 形如 `0xVVRRPPPP`。
/// \param v 主版本（version/major）
/// \param r 次版本（revision/minor)
/// \param p 补丁版本（patch）
#define MKVER(v, r, p) (((v) << 24) + ((r) << 16) + (p))

/// \def CLANG
/// \brief Clang identification and version.
#ifdef __clang__
# define CLANG MKVER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#endif

/// \def GNUC
/// \brief GNU C/C++ identification and version.
#ifdef __GNUC__
# ifdef __GNUC_PATCHLEVEL__
#  define GNUC MKVER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
# else
#  define GNUC MKVER(__GNUC__, __GNUC_MINOR__, 0)
# endif
#endif

/// \def MSC
/// \brief Microsoft Visual C++ identification and version.
#ifdef _MSC_VER
# if 1400 <= _MSC_VER
#  // From 8.0 (2005), VVRRPPPPP
#  define MSC MKVER(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, _MSC_FULL_VER % 100000)
# elif 1200 <= _MSC_VER
#  // From 6.0, VVRRPPPP
#  define MSC MKVER(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
# else
#  // Earlier, VVRR
#  define MSC MKVER(_MSC_VER / 100, _MSC_VER % 100, 0)
# endif
#endif

//-Language-Standards-----------------------------------------------------------

#ifndef __cplusplus
# error A C++ compiler is required.
#endif

/// \brief C++20
/// \sa <https://isocpp.org/std/status>
#define CXX20 (0)

/// \brief ISO/IEC 14882:2017
/// \sa <https://iso.org/standard/68564.html>
#define CXX17 (201703L<=__cplusplus)

/// \brief ISO/IEC 14882:2014
/// \sa <https://iso.org/standard/64029.html>
#define CXX14 (201402L<=__cplusplus)

/// \brief ISO/IEC 14882:2011
/// \sa <https://iso.org/standard/50372.html>
#define CXX11 (201103L<=__cplusplus)

/// \brief ISO/IEC 14882:1998
/// \sa <https://iso.org/standard/25845.html>
#define CXX98 (199711L<=__cplusplus)

//-Language-Features------------------------------------------------------------

/// \brief Wording Paper, C++ extensions for Concepts
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0734r0
#define P0734R0 (CXX20)

/// \brief Fixing const-qualified pointers to members
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0704r1
#define P0704R1 (CXX20)

/// \brief Language support for Constructor Template Argument Deduction
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0702r1
#define P0702R1 (CXX20)

/// \brief Default member initializers for bit-fields (revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0683r1
#define P0683R1 (CXX20)

/// \brief Extending make_shared to Support Arrays
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0674r1
#define P0674R1 (CXX20)

/// \brief Utility to convert a pointer to a raw pointer
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0653r2
#define P0653R2 (CXX20)

/// \brief Range-based for statements with initializer
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0614r1
#define P0614R1 (CXX20)

/// \brief Transformation Trait remove_cvref
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0550r2
#define P0550R2 (CXX20)

/// \brief DR: Matching of template template-arguments excludes compatible templates
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0522r0
#define P0522R0 (CXX17)

/// \brief Consistent comparison
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0515r3
#define P0515R3 (CXX20)

/// \brief endian, Just endian
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0463r1
#define P0463R1 (CXX20)

/// \brief String Prefix and Suffix Checking
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0457r2
#define P0457R2 (CXX20)

/// \brief Familiar template syntax for generic lambdas
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0428r2
#define P0428R2 (CXX20)

/// \brief Constexpr for std::complex
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0415r1
#define P0415R1 (CXX20)

/// \brief Allow lambda capture [=, this]
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0409r2
#define P0409R2 (CXX20)

/// \brief Inline Variables
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0386r2
#define P0386R2 (CXX17)

/// \brief Designated Initialization Wording
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0329r4
#define P0329R4 (CXX20)

/// \brief Comma omission and comma deletion
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0306r4
#define P0306R4 (CXX20)

/// \brief Selection statements with initializer
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0305r1
#define P0305R1 (CXX17)

/// \brief constexpr if: A slightly different syntax
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0292r2
#define P0292R2 (CXX17)

/// \brief Standard and non-standard attributes
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0283r2
#define P0283R2 (CXX17)

/// \brief Hexadecimal floating literals for C++
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1
#define P0245R1 (CXX17)

/// \brief Proposed wording for structured bindings
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0217r3
#define P0217R3 (CXX17)

/// \brief Wording for [[maybe_unused]] attribute
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1
#define P0212R1 (CXX17 || MKVER(7,0,0)<=GNUC || __has_cpp_attribute(maybe_unused))

/// \brief Add Constexpr Modifiers to Functions in \<algorithm\> and \<utility\> Headers
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0202r3
#define P0202R3 (CXX20)

/// \brief Pack expansions in using-declarations
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0195r2
#define P0195R2 (CXX17)

/// \brief Wording for [[nodiscard]] attribute
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1
#define P0189R1 (CXX17 || MKVER(7,0,0)<=GNUC || __has_cpp_attribute(nodiscard))

/// \brief Wording for [[fallthrough]] attribute
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1
#define P0188R1 (CXX17 || MKVER(7,0,0)<=GNUC || __has_cpp_attribute(fallthrough))

/// \brief Generalizing the Range-Based For Loop
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0
#define P0184R0 (CXX17 || MKVER(6,0,0)<=GNUC || 201603<=__cpp_range_based_for)

/// \brief Wording for Constexpr Lambda
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1
#define P0170R1 (CXX17 || MKVER(7,0,0)<=GNUC || 201603<=__cpp_constexpr)

/// \brief Refining Expression Evaluation Order for Idiomatic C++
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0145r3
#define P0145R3 (CXX17)

/// \brief Construction Rules for enum class Values
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2
#define P0138R2 (CXX17 || MKVER(7,0,0)<=GNUC)

/// \brief Rewording inheriting constructors (core issue 1941 et al)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0136r1
#define P0136R1 (CXX17)

/// \brief Declaring non-type template parameters with auto
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2
#define P0127R2 (CXX17)

/// \brief Template argument deduction for class templates (Rev. 6)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3
#define P0091R3 (CXX17)

/// \brief Splicing Maps and Sets (Revision 5)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3
#define P0083R3 (CXX17)

/// \brief Elementary string conversions, revision 5
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5
#define P0067R5 (CXX17)

/// \brief __has_include for C++17
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0061r1
#define P0061R1 (CXX17)

/// \brief C++ Synchronized Buffered Ostream
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0053r7
#define P0053R7 (CXX20)

/// \brief Unary Folds and Empty Parameter Packs (revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0
#define P0036R0 (CXX17 || MKVER(6,0,0)<=GNUC || 201603<=__cpp_fold_expressions)

/// \brief Dynamic memory allocation for over-aligned data
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0035r4
#define P0035R4 (CXX17)

/// \brief Using attribute namespaces without repetition
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0028r4
#define P0028R4 (CXX17)

/// \brief The Parallelism TS Should be Standardized
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2
#define P0024R2 (CXX17)

/// \brief Floating Point Atomic
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0020r6
#define P0020R6 (CXX20)

/// \brief Lambda Capture of *this by Value as [=,*this]
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3
#define P0018R3 (CXX17 || MKVER(7,0,0)<=GNUC || 201603<=__cpp_capture_star_this)

/// \brief Extension to aggregate initialization
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1
#define P0017R1 (CXX17 || MKVER(7,0,0)<=GNUC || 201603<=__cpp_aggregate_bases)

/// \brief Make exception specifications be part of the type system, version 5
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0012r1
#define P0012R1 (CXX17)

/// \brief Removing Deprecated Exception Specifications from C++17
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5
#define P0003R5 (CXX17)

/// \brief Remove Deprecated operator++(bool)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0002r1
#define P0002R1 (CXX17)

/// \brief Remove Deprecated Use of the register Keyword
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1
#define P0001R1 (CXX17)

/// \brief N4508: A proposal to add shared_mutex (untimed) (Revision 4)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4508
#define N4508 (CXX17)

/// \brief Improving pair and tuple, revision 3
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4387
#define N4387 (CXX17)

/// \brief Folding expressions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295
#define N4295 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_fold_expressions)

/// \brief Allow constant evaluation for all non-type template arguments
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268
#define N4268 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_nontype_template_args )

/// \brief Adding u8 character literals
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267
#define N4267 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_unicode_characters)

/// \brief Attributes for namespaces and enumerators
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266
#define N4266 (CXX17 || MKVER(6,0,0)<=GNUC || (201411<=__cpp_namespace_attributes&&201411<=__cpp_enumerator_attributes ))

/// \brief Wording for std::uncaught_exceptions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4259
#define N4259 (CXX17)

/// \brief 嵌套命名空间定义（修订版二）\n
///        Nested namespace definition (revision 2)
/// \sa <http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230>
#define N4230 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_nested_namespace_definitions)

/// \brief Removing trigraphs??!
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4086
#define N4086 (CXX17 || MKVER(5,1,0)<=GNUC)

/// \brief Allow typename in a template template parameter
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051
#define N4051 (CXX17 || MKVER(5,0,0)<=GNUC)

/// \brief Extending static_assert, v2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928
#define N3928 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_static_assert)

/// \brief New Rules for auto deduction from braced-init-list
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922
#define N3922 (CXX17 || MKVER(5,0,0)<=GNUC)

/// \brief string_view: a non-owning reference to a string, revision 7
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3921
#define N3921 (CXX17)

/// \brief Single-Quotation-Mark as a Digit Separator
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781
#define N3781 (CXX14)

/// \brief C++ Sized Deallocation
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3778
#define N3778 (CXX14)

/// \brief [[deprecated]] attribute
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3760
#define N3760 (CXX14)

/// \brief Making non-modifying sequence operations more robust: Revision 2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3671
#define N3671 (CXX14)

/// \brief Wording for Addressing Tuples by Type: Revision 2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3670
#define N3670 (CXX14)

/// \brief Fixing constexpr member functions without const
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3669
#define N3669 (CXX14)

/// \brief exchange() utility function, revision 3
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3668
#define N3668 (CXX14)

/// \brief Clarifying Memory Allocation
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3664
#define N3664 (CXX14)

/// \brief Shared locking in C++ Revision 2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3659
#define N3659 (CXX14)

/// \brief Compile-time integer sequences
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3658
#define N3658 (CXX14)

/// \brief Adding heterogeneous comparison lookup to associative containers (rev 4)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3657
#define N3657 (CXX14)

/// \brief Quoted Strings Library Proposal (Revision 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3654
#define N3654 (CXX14)

/// \brief Member initializers and aggregates
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653
#define N3653 (CXX14)

/// \brief Relaxing constraints on constexpr functions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652
#define N3652 (CXX14)

/// \brief Variable Templates (Revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3651
#define N3651 (CXX14)

/// \brief Generic (Polymorphic) Lambda Expressions (Revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3649
#define N3649 (CXX14)

/// \brief Wording Changes for Generalized Lambda-capture
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3648
#define N3648 (CXX14)

/// \brief Null Forward Iterators
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3644
#define N3644 (CXX14)

/// \brief User-defined Literals for Standard Library Types (part 1 - version 4)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3642
#define N3642 (CXX14)

/// \brief Return type deduction for normal functions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3638
#define N3638 (CXX14)

/// \brief An Incremental Improvement to integral_constant
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3545
#define N3545 (CXX14)

/// \brief Binary Literals in the C++ Core Language
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472
#define N3472 (CXX14)

/// \brief Constexpr Library Additions: utilities, v3
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3471
#define N3471 (CXX14)

/// \brief Constexpr Library Additions: containers, v2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3470
#define N3470 (CXX14)

/// \brief Constexpr Library Additions: chrono, v3
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3467
#define N3467 (CXX14)

/// \brief std::result_of and SFINAE
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3462
#define N3462 (CXX14)

/// \brief A Proposal to Tweak Certain C++ Contextual Conversions, v3
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3323
#define N3323 (CXX14)

/// \brief Constexpr Library Additions: complex, v2
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3302
#define N3302 (CXX14)

/// \brief US22/DE9 Revisited: Decltype and Call Expressions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3276
#define N3276 (CXX11)

/// \brief Follow-up on override control
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3272
#define N3272 (CXX11)

/// \brief Override control: Eliminating Attributes
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3206
#define N3206 (CXX11)

/// \brief Defining Move Special Member Functions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3053
#define N3053 (CXX11)

/// \brief Allowing Move Constructors to Throw (Rev. 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3050
#define N3050 (CXX11)

/// \brief Range-Based For Loop Wording (Without Concepts)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2930
#define N2930 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief Explicit Virtual Overrides
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2928
#define N2928 (CXX11)

/// \brief New wording for C++0x Lambdas (rev. 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2927
#define N2927 (CXX11)

/// \brief Fixing a Safety Problem with Rvalue References: Proposed Wording (Revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2844
#define N2844 (CXX11)

/// \brief User-defined Literals (revision 5)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2765
#define N2765 (CXX11)

/// \brief Forward declaration of enumerations (rev. 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2764
#define N2764 (CXX11)

/// \brief Towards support for attributes in C++ (Revision 6)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761
#define N2761 (CXX11)

/// \brief Non-static data member initializers
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2756
#define N2756 (CXX11 || MKVER(4,7,0)<=GNUC || MKVER(18,0,0)<=MSC || 200809<=__cpp_nsdmi)

/// \brief Initializer List proposed wording
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2672
#define N2672 (CXX11)

/// \brief Minimal Support for Garbage Collection and Reachability-Based Leak Detection (revised)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2670
#define N2670 (CXX11)

/// \brief 有并发的动态初始化及析构\n
///        Dynamic Initialization and Destruction with Concurrency
/// \sa <http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2660>
#define N2660 (CXX11 || MKVER(4,3,0)<=GNUC || MKVER(19,0,0)<=MSC || 200806<=__cpp_threadsafe_static_init)

/// \brief Thread-Local Storage
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2659
#define N2659 (CXX11)

/// \brief Constness of Lambda Functions (Revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2658
#define N2658 (CXX11)

/// \brief Local and Unnamed Types as Template Arguments
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2657
#define N2657 (CXX11)

/// \brief Extending Variadic Template Template Parameters (Revision 1)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2555
#define N2555 (CXX11)

/// \brief Lambda Expressions and Closures: Wording for Monomorphic Lambdas (Revision 4)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2550
#define N2550 (CXX11)

/// \brief Unrestricted Unions (Revision 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2544
#define N2544 (CXX11)

/// \brief New Function Declarator Syntax Wording
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2541
#define N2541 (CXX11 || MKVER(4,4,0)<=GNUC || MKVER(16,0,0)<=MSC)

/// \brief Inheriting Constructors (revision 5)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2540
#define N2540 (CXX11)

/// \brief Namespace Association ("inline namespace")
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2535
#define N2535 (CXX11 || MKVER(4,3,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief Multi-threading Library for Standard C++ (Revision 1)
/// \sa <http://open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2497>
#define N2497 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief Raw and Unicode String Literals; Unified Proposal (Rev. 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2442
#define N2442 (CXX11)

/// \brief Extending move semantics to *this (revised wording)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2439
#define N2439 (CXX11)

/// \brief Explicit Conversion Operator Draft Working Paper (revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2437
#define N2437 (CXX11)

/// \brief A name for the null pointer: nullptr (revision 4)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2431
#define N2431 (CXX11)

/// \brief C++ Atomic Types and Operations
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2427
#define N2427 (CXX11)

/// \brief Strongly Typed Enums (revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2347
#define N2347 (CXX11)

/// \brief Defaulted and Deleted Functions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2346
#define N2346 (CXX11)

/// \brief Decltype (revision 7): proposed wording
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2343
#define N2343 (CXX11)

/// \brief Adding Alignment Support to the C++ Programming Language / Wording
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2341
#define N2341 (CXX11)

/// \brief Templates Aliases (Revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2258
#define N2258 (CXX11)

/// \brief New Character Types in C++
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2249
#define N2249 (CXX11)

/// \brief Proposed Wording for Variadic Templates (Revision 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2242
#define N2242 (CXX11)

/// \brief Generalized Constant Expressions — Revision 5
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2235
#define N2235 (CXX11)

/// \brief A Proposal to Add an Rvalue Reference to the C++ Language
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2118
#define N2118 (CXX11)

/// \brief Iostream manipulators for convenient extraction and insertion of monetary values
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2072
#define N2072 (CXX11)

/// \brief Iostream manipulators for convenient extraction and insertion of struct tm objects
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2071
#define N2071 (CXX11)

/// \brief Adding "extern template" (version 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1987
#define N1987 (CXX11)

/// \brief Delegating Constructors (revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1986
#define N1986 (CXX11)

/// \brief Deducing the type of variable from its initializer expression
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1984
#define N1984 (CXX11 || MKVER(4,4,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief Draft Technical Report on C++ Library Extensions
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1836
#define N1836 (CXX11)

/// \brief Adding the long long type to C++ (Revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1811
#define N1811 (CXX11)

/// \brief Extended friend Declarations (Rev. 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1791
#define N1791 (CXX11)

/// \brief Right Angle Brackets (Revision 2)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1757
#define N1757 (CXX11)

/// \brief A Proposal to Restore Multi-declarator auto Declarations
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1737
#define N1737 (MKVER(4,4,0)<=GNUC)

/// \brief Proposal to Add Static Assertions to the Core Language (Revision 3)
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1720
#define N1720 (CXX11)

/// \brief Working draft changes for C99 preprocessor synchronization
/// \sa http://open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1653
#define N1653 (CXX11)

#endif//RRCXX_CXX_VERSIONS_HXX_
