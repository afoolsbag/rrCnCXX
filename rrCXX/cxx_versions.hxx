//===-- C++ Versiosn---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 版本。
///
/// \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
/// \sa ["C++ 编译器支持情况表"](https://zh.cppreference.com/w/cpp/compiler_support). *cppreference.com*.
///
/// \version 2018-10-15
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

/// \brief ISO/IEC 14882:2003
/// \sa <https://iso.org/standard/38110.html>
#define CXX03 CXX98

/// \brief ISO/IEC 14882:1998
/// \sa <https://iso.org/standard/25845.html>
#define CXX98 (199711L<=__cplusplus)

//-Language-Features------------------------------------------------------------

/// \brief 概念
/// \sa <http://wg21.link/p0734r0>
#define P0734R0 (CXX20)

/// \brief Fixing const-qualified pointers to members
/// \sa <http://wg21.link/p0704r1>
#define P0704R1 (CXX20)

/// \brief Language support for Constructor Template Argument Deduction
/// \sa <http://wg21.link/p0702r1>
#define P0702R1 (CXX20)

/// \brief Default member initializers for bit-fields (revision 1)
/// \sa <http://wg21.link/p0683r1>
#define P0683R1 (CXX20)

/// \brief Extending make_shared to Support Arrays
/// \sa <http://wg21.link/p0674r1>
#define P0674R1 (CXX20)

/// \brief Utility to convert a pointer to a raw pointer
/// \sa <http://wg21.link/p0653r2>
#define P0653R2 (CXX20)

/// \brief Range-based for statements with initializer
/// \sa <http://wg21.link/p0614r1>
#define P0614R1 (CXX20)

/// \brief Transformation Trait remove_cvref
/// \sa <http://wg21.link/p0550r2>
#define P0550R2 (CXX20)

/// \brief 契约
/// \sa <http://wg21.link/p0542r5>
#define P0542R5 (CXX20)

/// \brief DR：模板模板实参的匹配排除兼容的模板
/// \sa <http://wg21.link/p0522r0>
#define P0522R0 (CXX17 || MKVER(19,12,0)<=MSC)

/// \brief Consistent comparison
/// \sa <http://wg21.link/p0515r3>
#define P0515R3 (CXX20)

/// \brief endian, Just endian
/// \sa <http://wg21.link/p0463r1>
#define P0463R1 (CXX20)

/// \brief String Prefix and Suffix Checking
/// \sa <http://wg21.link/p0457r2>
#define P0457R2 (CXX20)

/// \brief Familiar template syntax for generic lambdas
/// \sa <http://wg21.link/p0428r2>
#define P0428R2 (CXX20)

/// \brief Constexpr for std::complex
/// \sa <http://wg21.link/p0415r1>
#define P0415R1 (CXX20)

/// \brief Allow lambda capture [=, this]
/// \sa <http://wg21.link/p0409r2>
#define P0409R2 (CXX20)

/// \brief `inline` 变量
/// \sa <http://wg21.link/p0386r2>
#define P0386R2 (CXX17 || MKVER(19,12,0)<=MSC)

/// \brief Designated Initialization Wording
/// \sa <http://wg21.link/p0329r4>
#define P0329R4 (CXX20)

/// \brief Comma omission and comma deletion
/// \sa <http://wg21.link/p0306r4>
#define P0306R4 (CXX20)

/// \brief `if` 和 `switch` 的初始化语句
/// \sa <http://wg21.link/p0305r1>
#define P0305R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief `std::byte`
/// \sa <http://wg21.link/p0298r3>
#define P0298R3 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief `constexpr if` 语句
/// \sa <http://wg21.link/p0292r2>
#define P0292R2 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief 忽略未知属性
/// \sa <http://wg21.link/p0283r2>
#define P0283R2 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief 十六进制浮点字面量
/// \sa <http://wg21.link/p0245r1>
#define P0245R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief `std::any` 和 `std::optional`
/// \sa <http://wg21.link/p0220r1>
#define P0220R1 (CXX17 || MKVER(19,10,0)<=MSC)

/// \brief `std::filesystem`
/// \sa <http://wg21.link/p0218r1>
#define P0218R1 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 结构化绑定
/// \sa <http://wg21.link/p0217r3>
#define P0217R3 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief `[[maybe_unused]]` 属性
/// \sa <http://wg21.link/p0212r1>
#define P0212R1 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,11,0)<=MSC)

/// \brief Add Constexpr Modifiers to Functions in <algorithm> and <utility> Headers
/// \sa <http://wg21.link/p0202r3>
#define P0202R3 (CXX20)

/// \brief `using` 声明中的包展开
/// \sa <http://wg21.link/p0195r2>
#define P0195R2 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief `[[nodiscard]]` 属性
/// \sa <http://wg21.link/p0189r1>
#define P0189R1 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,11,0)<=MSC)

/// \brief `[[fallthrough]]` 属性
/// \sa <http://wg21.link/p0188r1>
#define P0188R1 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,10,0)<=MSC)

/// \brief 基于范围 `for` 的相异 `begin` 和 `end` 类型
/// \sa <http://wg21.link/p0184r0>
#define P0184R0 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,10,0)<=MSC || 201603<=__cpp_range_based_for)

/// \brief `constexpr` lambda 表达式
/// \sa <http://wg21.link/p0170r1>
#define P0170R1 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,11,0)<=MSC || 201603<=__cpp_constexpr)

/// \brief 硬件干涉大小
/// \sa <http://wg21.link/p0154r1>
#define P0154R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief 更严格的表达式求值顺序
/// \sa <http://wg21.link/p0145r3>
#define P0145R3 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 枚举的直接列表初始化
/// \sa <http://wg21.link/p0138r2>
#define P0138R2 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,11,0)<=MSC)

/// \brief 替换含引用成员的类对象
/// \sa <http://wg21.link/p0137r1>
#define P0137R1 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 继承构造函数的新规定（DR1941 等）
/// \sa <http://wg21.link/p0136r1>
#define P0136R1 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 受保证的复制消除
/// \sa <http://wg21.link/p0135r1>
#define P0135R1 (CXX17 || MKVER(19,13,0)<=MSC)

/// \brief 拥有 `auto` 类型的非类型模板形参
/// \sa <http://wg21.link/p0127r2>
#define P0127R2 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 类模板的模板实参推导
/// \sa <http://wg21.link/p0091r3>
#define P0091R3 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief `std::variant`
/// \sa <http://wg21.link/p0088r3>
#define P0088R3 (CXX17 || MKVER(19,10,0)<=MSC)

/// \brief 接合 `map` 和 `set`
/// \sa <http://wg21.link/p0083r3>
#define P0083R3 (CXX17 || MKVER(19,12,0)<=MSC)

/// \brief 初等字符串转换
/// \sa <http://wg21.link/p0067r5>
#define P0067R5 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief 预处理器条件中的 `__has_include`
/// \sa <http://wg21.link/p0061r1>
#define P0061R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief C++ Synchronized Buffered Ostream
/// \sa <http://wg21.link/p0053r7>
#define P0053R7 (CXX20)

/// \brief 一元折叠表达式和空形参包
/// \sa <http://wg21.link/p0036r0>
#define P0036R0 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,12,0)<=MSC || 201603<=__cpp_fold_expressions)

/// \brief 过对齐数据的动态内存分配
/// \sa <http://wg21.link/p0035r4>
#define P0035R4 (CXX17 || MKVER(19,12,0)<=MSC)

/// \brief 使用属性命名空间而不重复
/// \sa <http://wg21.link/p0028r4>
#define P0028R4 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief 并行 TS 的标准化
/// \sa <http://wg21.link/p0024r2>
#define P0024R2 (CXX17 || MKVER(19,14,0)<=MSC)

/// \brief Floating Point Atomic
/// \sa <http://wg21.link/p0020r6>
#define P0020R6 (CXX20)

/// \brief `*this` 的 lambda 捕获
/// \sa <http://wg21.link/p0018r3?
#define P0018R3 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,11,0)<=MSC || 201603<=__cpp_capture_star_this)

/// \brief 有基类的类的聚合初始化
/// \sa <http://wg21.link/p0017r1>
#define P0017R1 (CXX17 || MKVER(7,0,0)<=GNUC || MKVER(19,14,0)<=MSC || 201603<=__cpp_aggregate_bases)

/// \brief 令异常规定为类型系统的一部分
/// \sa <http://wg21.link/p0012r1>
#define P0012R1 (CXX17 || MKVER(19,12,0)<=MSC)

/// \brief 从 C++17 移除弃用的异常规定
/// \sa <http://wg21.link/p0003r5>
#define P0003R5 (CXX17 || MKVER(19,10,0)<=MSC)

/// \brief 移除弃用的 `operator++(bool)`
/// \sa <http://wg21.link/p0002r1>
#define P0002R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief 移除 `register` 关键字的已弃用使用
/// \sa <http://wg21.link/p0001r1>
#define P0001R1 (CXX17 || MKVER(19,11,0)<=MSC)

/// \brief `std::shared_mutex`（无时限）
/// \sa <http://wg21.link/n4508>
#define N4508 (CXX17 || MKVER(19,0,0)<=MSC)

/// \brief 改进 `std::pair` 和 `std::tuple`
/// \sa <http://wg21.link/n4387>
#define N4387 (CXX17 || MKVER(19,0,0)<=MSC)

/// \brief 折叠表达式
/// \sa <http://wg21.link/n4295>
#define N4295 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,12,0)<=MSC || 201411<=__cpp_fold_expressions)

/// \brief 允许所有非类型模板实参的常量求值
/// \sa <http://wg21.link/n4268>
#define N4268 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,12,0)<=MSC || 201411<=__cpp_nontype_template_args)

/// \brief u8 字符字面量
/// \sa <http://wg21.link/n4267>
#define N4267 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,0,0)<=MSC || 201411<=__cpp_unicode_characters)

/// \brief 命名空间和枚举项的属性
/// \sa <http://wg21.link/n4266>
#define N4266 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,0,0)<=MSC || (201411<=__cpp_namespace_attributes&&201411<=__cpp_enumerator_attributes))

/// \brief `std::uncaught_exceptions()`
/// \sa <http://wg21.link/n4259>
#define N4259 (CXX17 || MKVER(19,0,0)<=MSC)

/// \brief 嵌套命名空间定义
/// \sa <http://wg21.link/n4230>
#define N4230 (CXX17 || MKVER(6,0,0)<=GNUC || 201411<=__cpp_nested_namespace_definitions)

/// \brief 移除三标符
/// \sa <http://wg21.link/n4086>
#define N4086 (CXX17 || MKVER(5,1,0)<=GNUC || MKVER(16,0,0)<=MSC)

/// \brief 模板模板形参中的 `typename`
/// \sa <http://wg21.link/n4051>
#define N4051 (CXX17 || MKVER(5,0,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief 无消息的 `static_assert`
/// \sa <http://wg21.link/n3928>
#define N3928 (CXX17 || MKVER(6,0,0)<=GNUC || MKVER(19,10,0)<=MSC || 201411<=__cpp_static_assert)

/// \brief 直接列表初始化的新 `auto` 规则
/// \sa <http://wg21.link/n3922>
#define N3922 (CXX17 || MKVER(5,0,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief `std::string_view`
/// \sa <http://wg21.link/n3921>
#define N3921 (CXX17 || MKVER(19,10,0)<=MSC)

/// \brief 单引号作为数位分隔符
/// \sa <http://wg21.link/n3781>
#define N3781 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 具大小解分配
/// \sa <http://wg21.link/n3778>
#define N3778 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `[[deprecated]]` 属性
/// \sa <http://wg21.link/n3760>
#define N3760 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 双范围的 `std::equal`、`std::is_permutation`、`std::mismatch`
/// \sa <http://wg21.link/n3671>
#define N3671 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `std::get<T>()`
/// \sa <http://wg21.link/n3670>
#define N3670 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 修正无 `const` 的 `constexpr` 成员函数
/// \sa <http://wg21.link/n3669>
#define N3669 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `std::exchange`
/// \sa <http://wg21.link/n3668>
#define N3668 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 清晰化内存分配（避免、融合分配）
/// \sa <http://wg21.link/n3664>
#define N3664 (CXX14)

/// \brief `std::shared_timed_mutex`
/// \sa <http://wg21.link/n3659>
#define N3659 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `std::integer_sequence`
/// \sa <http://wg21.link/n3658>
#define N3658 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 异相关联查找
/// \sa <http://wg21.link/n3657>
#define N3657 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `std::quoted`
/// \sa <http://wg21.link/n3654>
#define N3654 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 成员初始化器与聚合体（NSDMI）
/// \sa <http://wg21.link/n3653>
#define N3653 (CXX14 || MKVER(19,10,0)<=MSC)

/// \brief 扩展的 `constexpr`
/// \sa <http://wg21.link/n3652>
#define N3652 (CXX14 || MKVER(19,10,0)<=MSC)

/// \brief 变量模板
/// \sa <http://wg21.link/n3651>
#define N3651 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 泛型（多态）lambda 表达式
/// \sa <http://wg21.link/n3649>
#define N3649 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 初始化、泛化 lambda 捕获（init-capture）
/// \sa <http://wg21.link/n3648>
#define N3648 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 空向前迭代器
/// \sa <http://wg21.link/n3644>
#define N3644 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `<chrono>` 和 `<string>` 的用户定义字面量
/// \sa <http://wg21.link/n3642>
#define N3642 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `decltype(auto)`，正常函数的返回类型推导
/// \sa <http://wg21.link/n3638>
#define N3638 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 改进的 `std::integral_constant`
/// \sa <http://wg21.link/n3545>
#define N3545 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 二进制字面量
/// \sa <http://wg21.link/n3472>
#define N3472 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `<initializer_list>`、`<utility>` 和 `<tuple>` 的 `constexpr`
/// \sa <http://wg21.link/n3471>
#define N3471 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `<array>` 的 `constexpr`
/// \sa <http://wg21.link/n3470>
#define N3470 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `<chrono>` 的 `constexpr`
/// \sa <http://wg21.link/n3469>
#define N3469 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `std::result_of` 及 `SFINAE`
/// \sa <http://wg21.link/n3462>
#define N3462 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief 语境转换的遣词调整
/// \sa <http://wg21.link/n3323>
#define N3323 (CXX14 || MKVER(18,0,0)<=MSC)

/// \brief `<complex>` 的 `constexpr`
/// \sa <http://wg21.link/n3302>
#define N3302 (CXX14 || MKVER(19,0,0)<=MSC)

/// \brief `decltype` v1.1
/// \sa <http://wg21.link/n3276>
#define N3276 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief `override` 与 `final` v1.0
/// \sa <http://wg21.link/n3272>
#define N3272 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief `override` 与 `final` v0.9
/// \sa <http://wg21.link/n3206>
#define N3206 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 右值引用 v3.0
/// \sa <http://wg21.link/n3053>
#define N3053 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief `noexcept`
/// \sa <http://wg21.link/n3050>
#define N3050 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 范围 `for` 循环
/// \sa <http://wg21.link/n2930>
#define N2930 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief `override` 与 `final` v0.8
/// \sa <http://wg21.link/n2928>
#define N2928 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief Lambda 表达式 v1.1
/// \sa <http://wg21.link/n2927>
#define N2927 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 右值引用 v2.0
/// \sa <http://wg21.link/n2844>
#define N2844 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 用户定义字面量
/// \sa <http://wg22.link/n2765>
#define N2765 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 前置 `enum` 声明
/// \sa <http://wg21.link/n2764>
#define N2764 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 属性
/// \sa <http://wg21.link/n2761>
#define N2761 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 非静态数据成员初始化器
/// \sa <http://wg21.link/n2756>
#define N2756 (CXX11 || MKVER(4,7,0)<=GNUC || MKVER(18,0,0)<=MSC || 200809<=__cpp_nsdmi)

/// \brief 初始化器列表
/// \sa <http://wg21.link/n2672>
#define N2672 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief 动态指针安全性（GC 接口）
/// \sa <http://wg21.link/n2670>
#define N2670 (CXX11)

/// \brief 有并发的动态初始化及析构
/// \sa <http://wg21.link/n2660>
#define N2660 (CXX11 || MKVER(4,3,0)<=GNUC || MKVER(19,0,0)<=MSC || 200806<=__cpp_threadsafe_static_init)

/// \brief 线程局域存储
/// \sa <http://wg21.link/n2659>
#define N2659 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief Lambda 表达式 v1.0
/// \sa <http://wg21.link/n2658>
#define N2658 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 局部及无名类型作为模板形参
/// \sa <http://wg21.link/n2657>
#define N2657 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 变长模板 v1.0
/// \sa <http://wg21.link/n2555>
#define N2555 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief Lambda 表达式 v0.9
/// \sa <http://wg21.link/n2550>
#define N2550 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 无限制的联合体
/// \sa <http://wg21.link/n2544>
#define N2544 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 尾随的函数返回类型
/// \sa <http://wg21.link/n2541>
#define N2541 (CXX11 || MKVER(4,4,0)<=GNUC || MKVER(16,0,0)<=MSC)

/// \brief 继承的构造函数
/// \sa <http://wg21.link/n2540>
#define N2540 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 内联命名空间
/// \sa <http://wg21.link/n2535>
#define N2535 (CXX11 || MKVER(4,3,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief Thread Library Working Draft
/// \sa <http://wg21.link/n2497>
#define N2497 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 原始和 Unicode 字符串字面量
/// \sa <http://wg21.link/n2442>
#define N2442 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 引用限定符
/// \sa <http://wg21.link/n2439>
#define N2439 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 显式转换运算符
/// \sa <http://wg21.link/n2437>
#define N2437 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief `nullptr`
/// \sa <http://wg21.link/n2431>
#define N2431 (CXX11 || MKVER(16.0.0)<=MSC)

/// \brief 原子操作
/// \sa <http://wg21.link/n2427>
#define N2427 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 强类型 `enum`
/// \sa <http://wg21.link/n2347>
#define N2347 (CXX11 || MKVER(17,0,0)<=MSC)

/// \brief 默认化和被删除的函数
/// \sa <http://wg21.link/n2346>
#define N2346 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief `decltype` v1.0
/// \sa <http://wg21.link/n2343>
#define N2343 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief `alignas` 和 `alignof`
/// \sa <http://wg21.link/n2341>
#define N2341 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 模板别名
/// \sa <http://wg21.link/n2258>
#define N2258 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief 新字符类型
/// \sa <http://wg21.link/n2249>
#define N2249 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 变长模板 v0.9
/// \sa <http://wg21.link/n2242>
#define N2242 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief `constexpr`
/// \sa <http://wg21.link/n2235>
#define N2235 (CXX11 || MKVER(19,0,0)<=MSC)

/// \brief 右值引用 v1.0
/// \sa <http://wg21.link/n2118>
#define N2118 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 金额、时间及十六进制浮点 I/O 操纵符：金额
/// \sa <http://wg21.link/n2072>
#define N2072 (CXX11 || MKVER(3,8,0)<=CLANG || MKVER(5,0,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief 金额、时间及十六进制浮点 I/O 操纵符：时间
/// \sa <http://wg21.link/n2071>
#define N2071 (CXX11 || MKVER(3,8,0)<=CLANG || MKVER(5,0,0)<=GNUC || MKVER(19,0,0)<=MSC)

/// \brief `extern template`
/// \sa <http://wg21.link/n1987>
#define N1987 (CXX11 || MKVER(12,0,0)<=MSC)

/// \brief 委托构造函数
/// \sa <http://wg21.link/n1986>
#define N1986 (CXX11 || MKVER(18,0,0)<=MSC)

/// \brief `auto` v1.0
/// \sa <http://wg21.link/n1984>
#define N1984 (CXX11 || MKVER(4,4,0)<=GNUC || MKVER(16,0,0)<=MSC)

/// \brief 类型特性
/// \sa <http://wg21.link/n1836>
#define N1836 (CXX11 || MKVER(14,0,0)<=MSC)

/// \brief `long long`
/// \sa <http://wg21.link/n1811>
#define N1811 (CXX11 || MKVER(14,0,0)<=MSC)

/// \brief 扩展的 `friend` 声明
/// \sa <http://wg21.link/n1791>
#define N1791 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief 右角括号
/// \sa <http://wg21.link/n1757>
#define N1757 (CXX11 || MKVER(14,0,0)<=MSC)

/// \brief A Proposal to Restore Multi-declarator Declarations
/// \sa <http://wg21.link/n1737>
#define N1737 (MKVER(4,4,0)<=GNUC)

/// \brief `static_assert`
/// \sa <http://wg21.link/n1720>
#define N1720 (CXX11 || MKVER(16,0,0)<=MSC)

/// \brief C99 预处理器
/// \sa <http://wg21.link/n1653>
#define N1653 (CXX11 || MKVER(19,0,0)<=MSC)

#endif//RRCXX_CXX_VERSIONS_HXX_
