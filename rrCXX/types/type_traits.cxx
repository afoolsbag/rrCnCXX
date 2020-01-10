//===-- Type Traits ---------------------------------------------*- C++ -*-===//
///
/// \defgroup groupTypeTraits 类型特性
/// \ingroup groupTypes
///
/// \sa <https://zh.cppreference.com/w/cpp/types>
///
/// \version 2020-01-09
/// \since 2019-07-26
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <type_traits>
#include <typeinfo>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroup groupTypeTraits
/// @{

/// \brief 编译期常量：`integral_constant`（完整常量）
/// \details 标准库通过构造一个具有 `static constexpr T value = V;` 成员的模板类，
///          以类的公有静态成员常量的形式存储一个编译期常量。
///
///          标准库还提供了以下编译期常量特化：
///          
///          *   `T=bool` 的部分特化：`bool_constant`
///          *   `T=bool, V=true` 的完全特化：`true_type`
///          *   `T=bool, V=false` 的完全特化：`false_type`
TEST(type_traits, compile_time_constant)
{
    using int_1337_type = integral_constant<int, 1337>;
    static_assert(1337 == int_1337_type::value);

    static_assert(true == true_type::value);

    static_assert(false == false_type::value);
}

/// \brief 基础类型类别
/// \details 标准库通过构造模板类，使该模板类的一般形式继承自 `false_type`，
///          并使该模板类的指定特化形式继承自 `true_type`，实现编译器对模板形参的判别。
///
///          值得注意的是，基础类别如 `void`，对应有四个类型形参：
///
///          *   `void`
///          *   `const void`
///          *   `volatile void`
///          *   `const volatile void`
///
///          指针类别如 `void *` 对应为：
///
///          *   `void *`
///          *   `void * const`
///          *   `void * volatile`
///          *   `void * const volatile`
///
///          函数类别对应有 240 个（Visual Studio 2017 15.9.12）类型形参，正交分解为：
///
///          *   函数的调用约定：`__cdecl`、`__clrcall`、`__fastcall`、`__stdcall` 或 `__vectorcall`（×5）
///          *   函数的参数类型：常规函数 `Ret(Args...)` 或变参函数 `Ret(Args......)`（×2）
///          *   函数的 cv 限定：（无）、`const`、`volatile` 或 `const volatile`（×4）
///          *   函数的引用限定：（无）、左值引用 `&` 或右值引用 `&&`（×3）
///          *   函数的异常声明：（无）或无异常声明 `noexcept`（×2）
///
///          非静态成员函数类别对应 288 个（同上）类型形参，相较于其它函数，其调用约定另增一项 `__thiscall`
TEST(type_traits, primary_type_categories)
{
    // `void`
    static_assert(is_void_v<void>);

    // `std::nullptr_t`
    static_assert(is_null_pointer_v<std::nullptr_t>);

    // 整型
    static_assert(is_integral_v<bool>);
    static_assert(is_integral_v<char>);
    static_assert(is_integral_v<signed char>);
    static_assert(is_integral_v<unsigned char>);
    //static_assert(is_integral_v<char8_t>);
    static_assert(is_integral_v<char16_t>);
    static_assert(is_integral_v<char32_t>);
    static_assert(is_integral_v<wchar_t>);
    static_assert(is_integral_v<short>);
    static_assert(is_integral_v<unsigned short>);
    static_assert(is_integral_v<int>);
    static_assert(is_integral_v<unsigned>);
    static_assert(is_integral_v<long>);
    static_assert(is_integral_v<unsigned long>);
    static_assert(is_integral_v<long long>);
    static_assert(is_integral_v<unsigned long long>);

    // 浮点型
    static_assert(is_floating_point_v<float>);
    static_assert(is_floating_point_v<double>);
    static_assert(is_floating_point_v<long double>);

    // 原生数组
    static_assert(is_array_v<int[1337]>);
    static_assert(is_array_v<int[]>);

    // 枚举、联合、结构体和类，is_enum、is_union 和 is_class 依赖于实现
#ifdef _MSC_VER
    static_assert(is_enum_v<enum enum_t : int>);
#endif
    static_assert(is_union_v<union union_t>);
    static_assert(is_class_v<class class_t>);
    static_assert(is_class_v<struct struct_t>);

    // 函数，不包括成员函数
    static_assert(is_function_v<void()>);

    // 指针，不包括指向成员的指针
    static_assert(is_pointer_v<void *>);

    // 左值引用
    static_assert(is_lvalue_reference_v<int &>);

    // 右值引用
    static_assert(is_rvalue_reference_v<int &&>);

    // 非静态成员对象指针
    static_assert(is_member_object_pointer_v<int(class_t::*)>);

    // 非静态成员函数指针
    static_assert(is_member_function_pointer_v<int(class_t::*)()>);
}

/// \brief 复合类型类别
TEST(type_traits, composite_type_categories)
{
    // 基础类型：算术类型、`void` 和 `nullptr_t`
    static_assert(is_fundamental_v<int>);

    // 算术类型：整型或浮点型
    static_assert(is_arithmetic_v<int>);

    // 标量类型：算术类型、`enum`、原生指针类型和 `nullptr_t`
    static_assert(is_scalar_v<nullptr_t>);

    // 对象类型：除函数、引用、`void` 外的所有类型
    static_assert(!is_object_v<void>);

    // 复合类型：所有非基础类型
    static_assert(is_compound_v<class class_t>);

    // 引用类型：左值引用或右值引用
    static_assert(is_reference_v<int &>);

    // 成员指针：非静态成员对象指针或非静态成员函数指针
    static_assert(is_member_pointer_v<int(class_t::*)>);
}

/// \brief 类型属性
TEST(type_traits, type_properties)
{
    struct struct_t {};
    struct interface_t { virtual void func() = 0; };
    struct implement_t final : interface_t { void func() override {} };

    // `const`
    static_assert(is_const_v<const void>);

    // `volatile`
    static_assert(is_volatile_v<volatile void>);

    // 平凡和平凡可复制，`is_trivial` 和 `is_trivially_copyable` 依赖于实现
    static_assert(is_trivial_v<struct_t>);
    static_assert(is_trivially_copyable_v<struct_t>);

    // 标准布局，`is_standard_layout` 依赖于实现
    static_assert(is_standard_layout_v<struct_t>);

    // 空类，`is_empty` 依赖于实现
    static_assert(is_empty_v<struct_t>);

    // 多态类，`is_polymorphic` 依赖于实现
    static_assert(is_polymorphic_v<implement_t>);

    // 抽象类，`is_abstract` 依赖于实现
    static_assert(is_abstract_v<interface_t>);

    // `final` 类，`is_final` 依赖于实现
    static_assert(is_final_v<implement_t>);

    // 聚合类，`is_aggregate` 依赖于实现
    static_assert(is_aggregate_v<struct_t>);

    // 有符号算术类型，`is_signed`
    static_assert(is_signed_v<signed char>);

    // 无符号算术类型，`is_unsigned`
    static_assert(is_unsigned_v<unsigned char>);
}

/// @}
}
