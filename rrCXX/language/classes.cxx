//===-- Classes -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gClasses 类
/// \ingroup gLanguage
///
/// \sa gMemory
///
/// \version 2019-01-28
/// \since 2018-10-09
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gClasses
/// @{

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
class smf_class {
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
    explicit smf_class() = default;

    /// \brief 复制构造函数。
    explicit smf_class(const smf_class &) = default;

    /// \brief 移动构造函数。
    explicit smf_class(smf_class &&) noexcept = default;

    /// \brief 析构函数。
    /// \remarks C.30: 如果一个类需要在对象销毁时执行明确的操作，请为其定义析构函数\n
    ///          C.31: 类所获取的所有资源，必须都在类的析构函数中进行释放\n
    ///          C.32: 如果类中带有原始指针（`T*`）或者引用（`T&`），请考虑它是否是所有者\n
    ///          C.33: 如果类中带有所有权的指针成员，请定义析构函数或使之为 `=delete`\n
    ///          C.35: 带有虚函数的基类应当有虚析构函数\n
    ///          C.36: 析构函数不能失败\n
    ///          C.37: 使析构函数 `noexcept`
    virtual ~smf_class() noexcept = default;

    /// \brief 复制赋值操作。
    /// \remarks C.60: 使复制赋值非 `virtual`，接受 `const&` 的参数，并返回非 `const` 的引用\n
    ///          C.61: 复制操作应当进行复制\n
    ///          C.62: 使复制赋值可以安全进行自赋值\n
    ///          C.67: 多态类应当抑制复制操作
    smf_class &operator=(const smf_class &) = default;

    /// \brief 移动赋值操作。
    /// \remarks C.63: 使移动赋值非 `virtual`，接受 `&&` 的参数，并返回非 `const` 的引用\n
    ///          C.64: 移动操作应当进行移动，并使原对象处于有效状态\n
    ///          C.65: 使移动赋值可以安全进行自赋值\n
    ///          C.66: 使移动操作 `noexcept`
    smf_class &operator=(smf_class &&) noexcept = default;
};

/// @}

}//namespace rrcxx
