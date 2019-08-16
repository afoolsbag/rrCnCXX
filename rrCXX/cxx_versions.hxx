//===-- C++ Version ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief C++ 版本。
///
/// \sa [*Pre-defined Compiler Macros*](https://sourceforge.net/p/predef/wiki/)
/// \sa ["C++ 编译器支持情况表"](https://zh.cppreference.com/w/cpp/compiler_support). *cppreference.com*.
///
/// \version 2019-08-16
/// \since 2017-12-13
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_CXX_VERSIONS_HXX_
#define RRCXX_CXX_VERSIONS_HXX_

//----- Compilers --------------------------------------------------------------

/// \brief 一般化版本号（Normalized Version）
/// \details 形如 `0xVVRRPPPP`。
/// \param v 主版本号（version）
/// \param r 次版本号（revision)
/// \param p 补丁版本号（patch）
#define NORMALIZED_VERSION(v, r, p) (((v) << 24) + ((r) << 16) + (p))

/// \def NORMALIZED_CLANG_VERSION
/// \brief 一般化 clang 版本号
#ifdef __clang__
#define NORMALIZED_CLANG_VERSION    NORMALIZED_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#else
#define NORMALIZED_CLANG_VERSION    0
#endif

/// \def NORMALIZED_GNUC_VERSION
/// \brief 一般化 NORMALIZED_GNUC_VERSION 版本号
#ifdef __GNUC__
#ifdef __GNUC_PATCHLEVEL__
#define NORMALIZED_GNUC_VERSION     NORMALIZED_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#else
#define NORMALIZED_GNUC_VERSION     NORMALIZED_VERSION(__GNUC__, __GNUC_MINOR__, 0)
#endif
#else
#define NORMALIZED_GNUC_VERSION     0
#endif

/// \def NORMALIZED_MSC_VERSION
/// \brief 一般化 NORMALIZED_MSC_VERSION 版本号
#ifdef _MSC_VER
#if 1400 <= _MSC_VER
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, _MSC_FULL_VER % 100000)
#elif 1200 <= _MSC_VER
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
#else
#define NORMALIZED_MSC_VERSION      NORMALIZED_VERSION(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif
#else
#define NORMALIZED_MSC_VERSION      0
#endif

//----- Standards --------------------------------------------------------------

#ifndef __cplusplus
#error A C++ compiler is required.
#endif

/// \brief C++20
/// \sa <https://isocpp.org/std/status>
#define STANDARD_CXX20              (201703L<__cplusplus)

/// \brief ISO/IEC 14882:2017
/// \sa <https://iso.org/standard/68564.html>
#define STANDARD_CXX17              (201703L<=__cplusplus)

/// \brief ISO/IEC 14882:2014
/// \sa <https://iso.org/standard/64029.html>
#define STANDARD_CXX14              (201402L<=__cplusplus)

/// \brief ISO/IEC 14882:2011
/// \sa <https://iso.org/standard/50372.html>
#define STANDARD_CXX11              (201103L<=__cplusplus)

/// \brief ISO/IEC 14882:2003
/// \sa <https://iso.org/standard/38110.html>
#define STANDARD_CXX03              (199711L<=__cplusplus)

/// \brief ISO/IEC 14882:1998
/// \sa <https://iso.org/standard/25845.html>
#define STANDARD_CXX98              (199711L<=__cplusplus)

//----- Features ---------------------------------------------------------------

/// \brief 一致容器擦除
/// \sa <https://wg21.link/p1209r0>
#define FEATURE_P1209R0             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 嵌套内联命名空间
/// \sa <https://wg21.link/p1094r2>
#define FEATURE_P1094R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `constexpr` 虚函数
/// \sa <https://wg21.link/p1064r0>
#define FEATURE_P1064R0             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 禁止聚合体有用户声明的构造函数
/// \sa <https://wg21.link/p1008r1>
#define FEATURE_P1008R1             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 整合特性测试宏
/// \sa <https://wg21.link/p0941r2>
#define FEATURE_P0941R2             (STANDARD_CXX20 || NORMALIZED_VERSION(5,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,15,0)<=NORMALIZED_MSC_VERSION)

/// \brief 概念库
/// \sa <https://wg21.link/p0898r3>
#define FEATURE_P0898R3             STANDARD_CXX20

/// \brief 令 `constexpr` 函数的实例化较不贪婪
/// \sa <https://wg21.link/p0895r0>
#define FEATURE_P0895R0             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `explicit(bool)`
/// \sa <https://wg21.link/p0892r2>
#define FEATURE_P0892R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 不可见的 ADL 及函数模板
/// \sa <https://wg21.link/p0846r0>
#define FEATURE_P0846R0             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 属性 `[[no_unique_address]]`
/// \sa <https://wg21.link/p0840r2>
#define FEATURE_P0840R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `Lambda` 初始化捕获中的包展开
/// \sa <https://wg21.link/p0780r2>
#define FEATURE_P0780R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `<version>`
/// \sa <https://wg21.link/p0754r2>
#define FEATURE_P0754R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 概念
/// \sa <https://wg21.link/p0734r0>
#define FEATURE_P0734R0             STANDARD_CXX20

/// \brief 非类型模板形参中的类类型
/// \sa <https://wg21.link/p0732r2>
#define FEATURE_P0732R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 销毁的 `operator delete`
/// \sa <https://wg21.link/p0722r3>
#define FEATURE_P0722R3             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 原子 `shared_ptr` 与 `weak_ptr`
/// \sa <https://wg21.link/p0718r2>
#define FEATURE_P0718R2             STANDARD_CXX20

/// \brief `const &` 限定的指向成员指针
/// \sa <https://wg21.link/p0704r1>
#define FEATURE_P0704R1             STANDARD_CXX20

/// \brief 类模板实参推导中的 `initializer_list` 构造函数
/// \sa <https://wg21.link/p0702r1>
#define FEATURE_P0702R1             STANDARD_CXX20

/// \brief 特化上的访问检查
/// \sa <https://wg21.link/p0692r1>
#define FEATURE_P0692R1             (STANDARD_CXX20 || NORMALIZED_GNUC_VERSION)

/// \brief 位域的默认成员初始化器
/// \sa <https://wg21.link/p0683r1>
#define FEATURE_P0683R1             STANDARD_CXX20

/// \brief 扩展 `std::make_shared` 以支持数组
/// \sa <https://wg21.link/p0674r1>
#define FEATURE_P0674R1             STANDARD_CXX20

/// \brief 转换指针为裸指针的工具
/// \sa <https://wg21.link/p0653r2>
#define FEATURE_P0653R2             (STANDARD_CXX20 || NORMALIZED_VERSION(8,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 默认化复制构造函数的 `const` 不匹配
/// \sa <https://wg21.link/p0641r2>
#define FEATURE_P0641R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 使 `typename` 更可选
/// \sa <https://wg21.link/p0634r3>
#define FEATURE_P0634R3             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 可默认构造且可赋值的无状态 `lambda`
/// \sa <https://wg21.link/p0624r2>
#define FEATURE_P0624R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 基于范围的 `for` 的初始化语句
/// \sa <https://wg21.link/p0614r1>
#define FEATURE_P0614R1             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `std::is_constant_evaluated()`
/// \sa <https://wg21.link/p0595r2>
#define FEATURE_P0595R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 简化隐式 `lambda` 捕获
/// \sa <https://2g21.link/p0588r1>
#define FEATURE_P0588R1             (STANDARD_CXX20 || NORMALIZED_VERSION(8,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 整数的 2 的幂的运算
/// \sa <https://wg21.link/p0556r3>
#define FEATURE_P0556R3             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `std::remove_cvref`
/// \sa <https://wg21.link/p0550r2>
#define FEATURE_P0550R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 契约
/// \sa <https://wg21.link/p0542r5>
#define FEATURE_P0542R5             STANDARD_CXX20

/// \brief DR：模板模板实参的匹配排除兼容的模板
/// \sa <https://wg21.link/p0522r0>
#define FEATURE_P0522R0             (STANDARD_CXX17 || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION)

/// \brief 三路比较运算符
/// \sa <https://wg21.link/p0515r3>
#define FEATURE_P0515R3             (STANDARD_CXX20 || NORMALIZED_VERSION(19,20,0)<=NORMALIZED_MSC_VERSION)

/// \brief `char8_t`
/// \sa <https://wg21.link/p0482r6>
#define FEATURE_P0482R6             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 属性 `[[likely]]` 与 `[[unlikely]]`
/// \sa <https://wg21.link/p0479r5>
#define FEATURE_P0479R5             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `std::bit_cast()`
/// \sa <https://wg21.link/p0476r2>
#define FEATURE_P0476R2             STANDARD_CXX20

/// \brief `std::endian`
/// \sa <https://wg21.link/p0463r1>
#define FEATURE_P0463R1             (STANDARD_CXX20 || NORMALIZED_VERSION(8,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 字符串前缀与后缀检查
/// \sa <https://wg21.link/p0457r2>
#define FEATURE_P0457R2             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 泛型 `lambda` 的模板形参列表
/// \sa <https://wg21.link/p0428r2>
#define FEATURE_P0428R2             STANDARD_CXX20

/// \brief `<complex>` 的更多 `constexpr`
/// \sa <https://wg21.link/p0415r1>
#define FEATURE_P0415R1             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief 允许 `lambda` 捕获 `[=, this]`
/// \sa <https://wg21.link/p0409r2>
#define FEATURE_P0409R2             STANDARD_CXX20

/// \brief `inline` 变量
/// \sa <https://wg21.link/p0386r2>
#define FEATURE_P0386R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION)

/// \brief 日历与时区
/// \sa <https://wg21.link/p0355r7>
#define FEATURE_P0355R7             STANDARD_CXX20

/// \brief 指代初始化器
/// \sa <https://wg21.link/p0329r4>
#define FEATURE_P0329R4             STANDARD_CXX20

/// \brief `__VA_OPT__`
/// \sa <https://wg21.link/p0306r4>
#define FEATURE_P0306R4             STANDARD_CXX20

/// \brief `if` 和 `switch` 的初始化语句
/// \sa <https://wg21.link/p0305r1>
#define FEATURE_P0305R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 不求值语境中的 `lambda`
/// \sa <https://wg21.link/p0315r4>
#define FEATURE_P0315R4             (STANDARD_CXX20 || NORMALIZED_VERSION(9,0,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `std::byte`
/// \sa <https://wg21.link/p0298r3>
#define FEATURE_P0298R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `constexpr if` 语句
/// \sa <https://wg21.link/p0292r2>
#define FEATURE_P0292R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 忽略未知属性
/// \sa <https://wg21.link/p0283r2>
#define FEATURE_P0283R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 十六进制浮点字面量
/// \sa <https://wg21.link/p0245r1>
#define FEATURE_P0245R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::any` 和 `std::optional`
/// \sa <https://wg21.link/p0220r1>
#define FEATURE_P0220R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::filesystem`
/// \sa <https://wg21.link/p0218r1>
#define FEATURE_P0218R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 结构化绑定
/// \sa <https://wg21.link/p0217r3>
#define FEATURE_P0217R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `[[maybe_unused]]` 属性
/// \sa <https://wg21.link/p0212r1>
#define FEATURE_P0212R1             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<algorithm>` 与 `<utility>` 的 `constexpr`
/// \sa <https://wg21.link/p0202r3>
#define FEATURE_P0202R3             STANDARD_CXX20

/// \brief `using` 声明中的包展开
/// \sa <https://wg21.link/p0195r2>
#define FEATURE_P0195R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief `[[nodiscard]]` 属性
/// \sa <https://wg21.link/p0189r1>
#define FEATURE_P0189R1             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `[[fallthrough]]` 属性
/// \sa <https://wg21.link/p0188r1>
#define FEATURE_P0188R1             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 基于范围 `for` 的相异 `begin` 和 `end` 类型
/// \sa <https://wg21.link/p0184r0>
#define FEATURE_P0184R0             (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION || 201603<=__cpp_range_based_for)

/// \brief `constexpr` lambda 表达式
/// \sa <https://wg21.link/p0170r1>
#define FEATURE_P0170R1             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION || 201603<=__cpp_constexpr)

/// \brief 硬件干涉大小
/// \sa <https://wg21.link/p0154r1>
#define FEATURE_P0154R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 更严格的表达式求值顺序
/// \sa <https://wg21.link/p0145r3>
#define FEATURE_P0145R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 枚举的直接列表初始化
/// \sa <https://wg21.link/p0138r2>
#define FEATURE_P0138R2             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 替换含引用成员的类对象
/// \sa <https://wg21.link/p0137r1>
#define FEATURE_P0137R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 继承构造函数的新规定（DR1941 等）
/// \sa <https://wg21.link/p0136r1>
#define FEATURE_P0136R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 受保证的复制消除
/// \sa <https://wg21.link/p0135r1>
#define FEATURE_P0135R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,13,0)<=NORMALIZED_MSC_VERSION)

/// \brief 拥有 `auto` 类型的非类型模板形参
/// \sa <https://wg21.link/p0127r2>
#define FEATURE_P0127R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::span`
/// \sa <https://wg21.link/p0122r7>
#define FEATURE_P0122R7             STANDARD_CXX20

/// \brief 类模板的模板实参推导
/// \sa <https://wg21.link/p0091r3>
#define FEATURE_P0091R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::variant`
/// \sa <https://wg21.link/p0088r3>
#define FEATURE_P0088R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 接合 `map` 和 `set`
/// \sa <https://wg21.link/p0083r3>
#define FEATURE_P0083R3             (STANDARD_CXX17 || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION)

/// \brief 初等字符串转换
/// \sa <https://wg21.link/p0067r5>
#define FEATURE_P0067R5             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 预处理器条件中的 `__has_include`
/// \sa <https://wg21.link/p0061r1>
#define FEATURE_P0061R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 同步缓冲的 `ostream`
/// \sa <https://wg21.link/p0053r7>
#define FEATURE_P0053R7             STANDARD_CXX20

/// \brief 一元折叠表达式和空形参包
/// \sa <https://wg21.link/p0036r0>
#define FEATURE_P0036R0             (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION || 201603<=__cpp_fold_expressions)

/// \brief 过对齐数据的动态内存分配
/// \sa <https://wg21.link/p0035r4>
#define FEATURE_P0035R4             (STANDARD_CXX17 || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION)

/// \brief 使用属性命名空间而不重复
/// \sa <https://wg21.link/p0028r4>
#define FEATURE_P0028R4             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 并行 TS 的标准化
/// \sa <https://wg21.link/p0024r2>
#define FEATURE_P0024R2             (STANDARD_CXX17 || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION)

/// \brief 浮点原子算术
/// \sa <https://wg21.link/p0020r6>
#define FEATURE_P0020R6             STANDARD_CXX20

/// \brief `std::atomic_ref`
/// \sa <https://wg21.link/p0019r8>
#define FEATURE_P0019R8             STANDARD_CXX20

/// \brief `*this` 的 lambda 捕获
/// \sa <https://wg21.link/p0018r3?
#define FEATURE_P0018R3             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION || 201603<=__cpp_capture_star_this)

/// \brief 有基类的类的聚合初始化
/// \sa <https://wg21.link/p0017r1>
#define FEATURE_P0017R1             (STANDARD_CXX17 || NORMALIZED_VERSION(7,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,14,0)<=NORMALIZED_MSC_VERSION || 201603<=__cpp_aggregate_bases)

/// \brief 令异常规定为类型系统的一部分
/// \sa <https://wg21.link/p0012r1>
#define FEATURE_P0012R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION)

/// \brief 从 C++17 移除弃用的异常规定
/// \sa <https://wg21.link/p0003r5>
#define FEATURE_P0003R5             (STANDARD_CXX17 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 移除弃用的 `operator++(bool)`
/// \sa <https://wg21.link/p0002r1>
#define FEATURE_P0002R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief 移除 `register` 关键字的已弃用使用
/// \sa <https://wg21.link/p0001r1>
#define FEATURE_P0001R1             (STANDARD_CXX17 || NORMALIZED_VERSION(19,11,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::shared_mutex`（无时限）
/// \sa <https://wg21.link/n4508>
#define FEATURE_N4508               (STANDARD_CXX17 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 改进 `std::pair` 和 `std::tuple`
/// \sa <https://wg21.link/n4387>
#define FEATURE_N4387               (STANDARD_CXX17 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 折叠表达式
/// \sa <https://wg21.link/n4295>
#define FEATURE_N4295               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION || 201411<=__cpp_fold_expressions)

/// \brief 允许所有非类型模板实参的常量求值
/// \sa <https://wg21.link/n4268>
#define FEATURE_N4268               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,12,0)<=NORMALIZED_MSC_VERSION || 201411<=__cpp_nontype_template_args)

/// \brief u8 字符字面量
/// \sa <https://wg21.link/n4267>
#define FEATURE_N4267               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION || 201411<=__cpp_unicode_characters)

/// \brief 命名空间和枚举项的属性
/// \sa <https://wg21.link/n4266>
#define FEATURE_N4266               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION || (201411<=__cpp_namespace_attributes&&201411<=__cpp_enumerator_attributes))

/// \brief `std::uncaught_exceptions()`
/// \sa <https://wg21.link/n4259>
#define FEATURE_N4259               (STANDARD_CXX17 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 嵌套命名空间定义
/// \sa <https://wg21.link/n4230>
#define FEATURE_N4230               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || 201411<=__cpp_nested_namespace_definitions)

/// \brief 移除三标符
/// \sa <https://wg21.link/n4086>
#define FEATURE_N4086               (STANDARD_CXX17 || NORMALIZED_VERSION(5,1,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 模板模板形参中的 `typename`
/// \sa <https://wg21.link/n4051>
#define FEATURE_N4051               (STANDARD_CXX17 || NORMALIZED_VERSION(5,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 无消息的 `static_assert`
/// \sa <https://wg21.link/n3928>
#define FEATURE_N3928               (STANDARD_CXX17 || NORMALIZED_VERSION(6,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION || 201411<=__cpp_static_assert)

/// \brief 直接列表初始化的新 `auto` 规则
/// \sa <https://wg21.link/n3922>
#define FEATURE_N3922               (STANDARD_CXX17 || NORMALIZED_VERSION(5,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::string_view`
/// \sa <https://wg21.link/n3921>
#define FEATURE_N3921               (STANDARD_CXX17 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 单引号作为数位分隔符
/// \sa <https://wg21.link/n3781>
#define FEATURE_N3781               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 具大小解分配
/// \sa <https://wg21.link/n3778>
#define FEATURE_N3778               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `[[deprecated]]` 属性
/// \sa <https://wg21.link/n3760>
#define FEATURE_N3760               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 双范围的 `std::equal`、`std::is_permutation`、`std::mismatch`
/// \sa <https://wg21.link/n3671>
#define FEATURE_N3671               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::get<T>()`
/// \sa <https://wg21.link/n3670>
#define FEATURE_N3670               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 修正无 `const` 的 `constexpr` 成员函数
/// \sa <https://wg21.link/n3669>
#define FEATURE_N3669               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::exchange`
/// \sa <https://wg21.link/n3668>
#define FEATURE_N3668               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 清晰化内存分配（避免、融合分配）
/// \sa <https://wg21.link/n3664>
#define FEATURE_N3664               (STANDARD_CXX14)

/// \brief `std::shared_timed_mutex`
/// \sa <https://wg21.link/n3659>
#define FEATURE_N3659               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::integer_sequence`
/// \sa <https://wg21.link/n3658>
#define FEATURE_N3658               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 异相关联查找
/// \sa <https://wg21.link/n3657>
#define FEATURE_N3657               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::quoted`
/// \sa <https://wg21.link/n3654>
#define FEATURE_N3654               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 成员初始化器与聚合体（NSDMI）
/// \sa <https://wg21.link/n3653>
#define FEATURE_N3653               (STANDARD_CXX14 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 扩展的 `constexpr`
/// \sa <https://wg21.link/n3652>
#define FEATURE_N3652               (STANDARD_CXX14 || NORMALIZED_VERSION(19,10,0)<=NORMALIZED_MSC_VERSION)

/// \brief 变量模板
/// \sa <https://wg21.link/n3651>
#define FEATURE_N3651               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 泛型（多态）lambda 表达式
/// \sa <https://wg21.link/n3649>
#define FEATURE_N3649               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 初始化、泛化 lambda 捕获（init-capture）
/// \sa <https://wg21.link/n3648>
#define FEATURE_N3648               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 空向前迭代器
/// \sa <https://wg21.link/n3644>
#define FEATURE_N3644               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<chrono>` 和 `<string>` 的用户定义字面量
/// \sa <https://wg21.link/n3642>
#define FEATURE_N3642               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `decltype(auto)`，正常函数的返回类型推导
/// \sa <https://wg21.link/n3638>
#define FEATURE_N3638               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 改进的 `std::integral_constant`
/// \sa <https://wg21.link/n3545>
#define FEATURE_N3545               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 二进制字面量
/// \sa <https://wg21.link/n3472>
#define FEATURE_N3472               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<initializer_list>`、`<utility>` 和 `<tuple>` 的 `constexpr`
/// \sa <https://wg21.link/n3471>
#define FEATURE_N3471               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<array>` 的 `constexpr`
/// \sa <https://wg21.link/n3470>
#define FEATURE_N3470               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<chrono>` 的 `constexpr`
/// \sa <https://wg21.link/n3469>
#define FEATURE_N3469               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `std::result_of` 及 `SFINAE`
/// \sa <https://wg21.link/n3462>
#define FEATURE_N3462               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 语境转换的遣词调整
/// \sa <https://wg21.link/n3323>
#define FEATURE_N3323               (STANDARD_CXX14 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `<complex>` 的 `constexpr`
/// \sa <https://wg21.link/n3302>
#define FEATURE_N3302               (STANDARD_CXX14 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `decltype` v1.1
/// \sa <https://wg21.link/n3276>
#define FEATURE_N3276               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `override` 与 `final` v1.0
/// \sa <https://wg21.link/n3272>
#define FEATURE_N3272               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `override` 与 `final` v0.9
/// \sa <https://wg21.link/n3206>
#define FEATURE_N3206               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 右值引用 v3.0
/// \sa <https://wg21.link/n3053>
#define FEATURE_N3053               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `noexcept`
/// \sa <https://wg21.link/n3050>
#define FEATURE_N3050               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 范围 `for` 循环
/// \sa <https://wg21.link/n2930>
#define FEATURE_N2930               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `override` 与 `final` v0.8
/// \sa <https://wg21.link/n2928>
#define FEATURE_N2928               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief Lambda 表达式 v1.1
/// \sa <https://wg21.link/n2927>
#define FEATURE_N2927               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 右值引用 v2.0
/// \sa <https://wg21.link/n2844>
#define FEATURE_N2844               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 用户定义字面量
/// \sa <https://wg22.link/n2765>
#define FEATURE_N2765               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 前置 `enum` 声明
/// \sa <https://wg21.link/n2764>
#define FEATURE_N2764               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 属性
/// \sa <https://wg21.link/n2761>
#define FEATURE_N2761               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 非静态数据成员初始化器
/// \sa <https://wg21.link/n2756>
#define FEATURE_N2756               (STANDARD_CXX11 || NORMALIZED_VERSION(4,7,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION || 200809<=__cpp_nsdmi)

/// \brief 初始化器列表
/// \sa <https://wg21.link/n2672>
#define FEATURE_N2672               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 动态指针安全性（GC 接口）
/// \sa <https://wg21.link/n2670>
#define FEATURE_N2670               STANDARD_CXX11

/// \brief 有并发的动态初始化及析构
/// \sa <https://wg21.link/n2660>
#define FEATURE_N2660               (STANDARD_CXX11 || NORMALIZED_VERSION(4,3,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION || 200806<=__cpp_threadsafe_static_init)

/// \brief 线程局域存储
/// \sa <https://wg21.link/n2659>
#define FEATURE_N2659               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief Lambda 表达式 v1.0
/// \sa <https://wg21.link/n2658>
#define FEATURE_N2658               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 局部及无名类型作为模板形参
/// \sa <https://wg21.link/n2657>
#define FEATURE_N2657               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 变长模板 v1.0
/// \sa <https://wg21.link/n2555>
#define FEATURE_N2555               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief Lambda 表达式 v0.9
/// \sa <https://wg21.link/n2550>
#define FEATURE_N2550               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 无限制的联合体
/// \sa <https://wg21.link/n2544>
#define FEATURE_N2544               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 尾随的函数返回类型
/// \sa <https://wg21.link/n2541>
#define FEATURE_N2541               (STANDARD_CXX11 || NORMALIZED_VERSION(4,4,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 继承的构造函数
/// \sa <https://wg21.link/n2540>
#define FEATURE_N2540               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 内联命名空间
/// \sa <https://wg21.link/n2535>
#define FEATURE_N2535               (STANDARD_CXX11 || NORMALIZED_VERSION(4,3,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief Thread Library Working Draft
/// \sa <https://wg21.link/n2497>
#define FEATURE_N2497               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 原始和 Unicode 字符串字面量
/// \sa <https://wg21.link/n2442>
#define FEATURE_N2442               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 引用限定符
/// \sa <https://wg21.link/n2439>
#define FEATURE_N2439               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 显式转换运算符
/// \sa <https://wg21.link/n2437>
#define FEATURE_N2437               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `nullptr`
/// \sa <https://wg21.link/n2431>
#define FEATURE_N2431               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 原子操作
/// \sa <https://wg21.link/n2427>
#define FEATURE_N2427               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 强类型 `enum`
/// \sa <https://wg21.link/n2347>
#define FEATURE_N2347               (STANDARD_CXX11 || NORMALIZED_VERSION(17,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 默认化和被删除的函数
/// \sa <https://wg21.link/n2346>
#define FEATURE_N2346               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `decltype` v1.0
/// \sa <https://wg21.link/n2343>
#define FEATURE_N2343               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `alignas` 和 `alignof`
/// \sa <https://wg21.link/n2341>
#define FEATURE_N2341               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 模板别名
/// \sa <https://wg21.link/n2258>
#define FEATURE_N2258               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 新字符类型
/// \sa <https://wg21.link/n2249>
#define FEATURE_N2249               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 变长模板 v0.9
/// \sa <https://wg21.link/n2242>
#define FEATURE_N2242               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `constexpr`
/// \sa <https://wg21.link/n2235>
#define FEATURE_N2235               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 右值引用 v1.0
/// \sa <https://wg21.link/n2118>
#define FEATURE_N2118               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 金额、时间及十六进制浮点 I/O 操纵符：金额
/// \sa <https://wg21.link/n2072>
#define FEATURE_N2072               (STANDARD_CXX11 || NORMALIZED_VERSION(3,8,0)<=NORMALIZED_CLANG_VERSION || NORMALIZED_VERSION(5,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 金额、时间及十六进制浮点 I/O 操纵符：时间
/// \sa <https://wg21.link/n2071>
#define FEATURE_N2071               (STANDARD_CXX11 || NORMALIZED_VERSION(3,8,0)<=NORMALIZED_CLANG_VERSION || NORMALIZED_VERSION(5,0,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `extern template`
/// \sa <https://wg21.link/n1987>
#define FEATURE_N1987               (STANDARD_CXX11 || NORMALIZED_VERSION(12,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 委托构造函数
/// \sa <https://wg21.link/n1986>
#define FEATURE_N1986               (STANDARD_CXX11 || NORMALIZED_VERSION(18,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `auto` v1.0
/// \sa <https://wg21.link/n1984>
#define FEATURE_N1984               (STANDARD_CXX11 || NORMALIZED_VERSION(4,4,0)<=NORMALIZED_GNUC_VERSION || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 类型特性
/// \sa <https://wg21.link/n1836>
#define FEATURE_N1836               (STANDARD_CXX11 || NORMALIZED_VERSION(14,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief `long long`
/// \sa <https://wg21.link/n1811>
#define FEATURE_N1811               (STANDARD_CXX11 || NORMALIZED_VERSION(14,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 扩展的 `friend` 声明
/// \sa <https://wg21.link/n1791>
#define FEATURE_N1791               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief 右角括号
/// \sa <https://wg21.link/n1757>
#define FEATURE_N1757               (STANDARD_CXX11 || NORMALIZED_VERSION(14,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief A Proposal to Restore Multi-declarator Declarations
/// \sa <https://wg21.link/n1737>
#define FEATURE_N1737               (NORMALIZED_VERSION(4,4,0)<=NORMALIZED_GNUC_VERSION)

/// \brief `static_assert`
/// \sa <https://wg21.link/n1720>
#define FEATURE_N1720               (STANDARD_CXX11 || NORMALIZED_VERSION(16,0,0)<=NORMALIZED_MSC_VERSION)

/// \brief C99 预处理器
/// \sa <https://wg21.link/n1653>
#define FEATURE_N1653               (STANDARD_CXX11 || NORMALIZED_VERSION(19,0,0)<=NORMALIZED_MSC_VERSION)

#endif
