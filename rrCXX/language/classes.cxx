//===-- Classes -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gClasses 类
/// \ingroup gLanguage
///
/// \sa gMemory
/// \sa [类](https://zh.cppreference.com/w/cpp/language/classes)
///
/// \version 2019-08-06
/// \since 2018-10-09
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

namespace {
/// \brief 特殊成员函数（special member functions）类。
/// \remarks C.20: 只要可能，请避免定义任何的默认操作\n
///          C.21: 如果对任何默认操作提供了定义或者 `=delete`，请为所有默认操作都提供定义或者 `=delete`\n
///          C.22: 使默认操作之间保持一致\n
///          C.80: 当需要明确使用缺省语义时，使用 `=default`\n
///          C.81: 当需要关闭缺省行为（且不需要替代的行为）时，使用 `=delete`\n
///          C.82: 不要在构造函数和析构函数中调用虚函数\n
///          C.83: 考虑为值类型提供 `noexcept` 的 `swap` 函数\n
///          C.84: `swap` 不应当失败\n
///          C.85: 使 `swap` 函数 `noexcept`\n
///          C.86: 使 `==` 对操作数的类型对称，并使之 `noexcept`\n
///          C.87: 请当心基类的 `==`\n
///          C.89: 使 `hash` 函数 `noexcept`
class smfc {
public:
    /// \brief 默认构造函数。
    /// \remarks C.40: 如果类具有不变式，请为其定义构造函数\n
    ///          C.41: 构造函数应当创建经过完整初始化的对象\n
    ///          C.42: 当构造函数无法构造有效对象时，应当抛出异常\n
    ///          C.43: 保证可复制（值类型）类带有默认构造函数\n
    ///          C.44: 尽量让默认构造函数简单且不抛出异常\n
    ///          C.45: 不要定义仅对数据成员进行初始化的默认构造函数；应当使用成员初始化式\n
    ///          C.46: 默认情况下，把单参数的构造函数声明为 `explicit`\n
    ///          C.47: 按成员声明的顺序对成员变量进行定义和初始化\n
    ///          C.48: 对于常量初始化式来说，优先采用类中的初始化式而不是构造函数中的成员初始化式\n
    ///          C.49: 优先进行初始化而不是在构造函数中赋值\n
    ///          C.50: 当初始化过程中需要体现“虚函数行为”时，请使用工厂函数\n
    ///          C.51: 用委派构造函数来表示类中所有构造函数的共同行为\n
    ///          C.52: 使用继承构造函数来把构造函数引入到无须进行其他的明确初始化操作的派生类之中\n
    ///          NR.5: 请勿如此：不要在构造函数中进行实际工作；代之以采用两阶段初始化
    explicit smfc() = default;

    /// \brief 复制构造函数。
    /// \details 明确的（`explicit`）复制构造函数只允许形如 `smfc object {other};` 的调用方式；\n
    ///          而不允许形如 `smfc object = other;` 的调用方式。
    explicit smfc(const smfc &) = default;

    /// \brief 移动构造函数。
    /// \details 对 `explicit` 关键字的行为同复制构造函数。
    explicit smfc(smfc &&) noexcept = default;

    /// \brief 析构函数。
    /// \remarks C.30: 如果一个类需要在对象销毁时执行明确的操作，请为其定义析构函数\n
    ///          C.31: 类所获取的所有资源，必须都在类的析构函数中进行释放\n
    ///          C.32: 如果类中带有原始指针（`T*`）或者引用（`T&`），请考虑它是否是所有者\n
    ///          C.33: 如果类中带有所有权的指针成员，请定义析构函数或使之为 `=delete`\n
    ///          C.35: 带有虚函数的基类应当有虚析构函数\n
    ///          C.36: 析构函数不能失败\n
    ///          C.37: 使析构函数 `noexcept`
    virtual ~smfc() noexcept = default;

    /// \brief 复制赋值操作。
    /// \remarks C.60: 使复制赋值非 `virtual`，接受 `const&` 的参数，并返回非 `const` 的引用\n
    ///          C.61: 复制操作应当进行复制\n
    ///          C.62: 使复制赋值可以安全进行自赋值\n
    ///          C.67: 多态类应当抑制复制操作
    smfc &operator=(const smfc &) = default;

    /// \brief 移动赋值操作。
    /// \remarks C.63: 使移动赋值非 `virtual`，接受 `&&` 的参数，并返回非 `const` 的引用\n
    ///          C.64: 移动操作应当进行移动，并使原对象处于有效状态\n
    ///          C.65: 使移动赋值可以安全进行自赋值\n
    ///          C.66: 使移动操作 `noexcept`
    smfc &operator=(smfc &&) noexcept = default;
};
}

namespace rrcxx {
/// \addtogroup gClasses
/// @{

/// \details 通过 `{}` 调用构造函数，以与可能的 `()` 操作符区分
TEST(classes, constructor)
{
    [[maybe_unused]] const smfc obj {};
}

/// @}
}

//==============================================================================
// 复制省略 COPY ELISION
//
// 长求总：建议返回左值，且尽可能触发优化。
//
// *   若声明返回左值
//     1) 尽可能采用“构造并立即返回”，这将触发返回值优化（return value optimization）
//     2) 否则，尽可能保证返回对象可移动为返回类型，并在返回时直接返回对象，这将触发右值引用优化
//     3) 否则，将采用复制构造和析构
//
// *   若声明返回右值引用
//     1) 存储返回值的变量必须带有引用记号，不可缺漏；若缺漏不会被语法解析器检查出，但在运行时会造成内存泄露
//     2) 总会触发返回值优化

namespace {
class clazz {
public:
    explicit clazz() : sn_ {++global_serial_number_} { cout << "object-" << sn_ << ": default constructor" << endl; }
    clazz(const clazz &other) : sn_ {++global_serial_number_} { cout << "object-" << sn_ << ": copy constructor from object-" << other.sn_ << endl; }
    clazz(clazz &&other) noexcept : sn_ {++global_serial_number_}
    {
        cout << "object-" << sn_ << ": move constructor from object-" << other.sn_ << endl;
    }
    virtual ~clazz() noexcept { cout << "object-" << sn_ << ": destructor" << endl; }
    clazz &operator=(const clazz &other) = delete;
    clazz &operator=(clazz &&other) = delete;
private:
    const std::size_t sn_;
    static std::size_t global_serial_number_;
};
std::size_t clazz::global_serial_number_ {};
}

namespace rrcxx {
/// \addtogroup gClasses
/// @{

/// \brief 构造并立即返回左值（Lvalue）
/// \details 若编译器支持，将执行返回值优化，避免冗余的构造和析构。
TEST(classes, lvalue_rvo)
{
    const auto &get_by_lvalue_rvo = []() -> clazz {
        return clazz {};
    };

    [[maybe_unused]] const auto obj = get_by_lvalue_rvo();
}

/// \brief 构造左值但推迟返回
/// \details 编译器将尝试采用移动构造，若不行则采用复制构造。\n
///          若要采用移动构造，对象类型需要可移动到返回类型，且返回时直接返回对象。
TEST(classes, lvalue_move)
{
    const auto &get_by_lvalue_move = []() -> clazz {
        clazz object;
        return object;
    };
    {
        [[maybe_unused]] const auto obj = get_by_lvalue_move();
    }

    // 对象无法移动到返回类型，采用复制构造
    const auto &get_by_lvalue_copy_1 = []() -> clazz {
        const clazz object;
        return object;
    };
    {
        [[maybe_unused]] const auto obj = get_by_lvalue_copy_1();
    }

    // 返回表达式而非直接返回对象，采用复制构造
    const auto &get_by_lvalue_copy_2 = [](bool cond = true) -> clazz {
        clazz object;
        return cond ? object : ((void)0, object);
    };
    {
        [[maybe_unused]] const auto obj = get_by_lvalue_copy_2();
    }
}

/// \brief 构造并返回右值引用（Lvalue reference）
/// \details 若编译器支持，将执行返回值优化，避免冗余的构造和析构。
/// \warning 注意，存储返回的右值引用的变量，如 `&obj` 前的引用记号不可缺漏。
TEST(classes, rvalue_rvo)
{
    const auto &get_by_rvalue_rvo = []() -> clazz && {
        clazz object;
        return move(object);
    };
    [[maybe_unused]] const auto &obj = get_by_rvalue_rvo();
    //                          ^
    //                          |
    //               注意这个引用记号，不可缺漏
}

/// @}
}
