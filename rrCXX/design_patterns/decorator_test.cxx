//===-- Decorator -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gDecorator 修饰器
/// \ingroup gDesignPatterns
///
/// 向某个对象动态地添加更多的功能。修饰模式是除类继承外另一种扩展功能的方法。
///
/// \startuml
///   interface "智械" as omnic {
///     + {abstract} self_introduction()
///     + {abstract} attack()
///     + {abstract} defense()
///   }
///
///   class "小不点儿" as little_one {
///     + self_introduction()
///     + attack()
///     + defense()
///   }
///
///   abstract "模块" as module {
///     - base : omnic
///     + constructor(omnic)
///     + self_introduction()
///     + attack()
///     + defense()
///   }
///   class "机炮模块" as cannon_module {
///     + self_introduction()
///     + attack()
///   }
///   class "护盾模块" as shield_module {
///     + self_introduction()
///     + defense()
///   }
///
///   omnic <|.. little_one
///   omnic <|.. module
///   module o-- omnic
///   module <|-- cannon_module
///   module <|-- shield_module
/// \enduml
///
/// \version 2018-11-27
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

#pragma warning(pop)

using namespace std;

namespace rrcxx {
namespace decorator {

/// \addtogroup gDecorator
/// @{

/// \brief 智械。
class omnic {
public:
    explicit omnic() = default;
    explicit omnic(const omnic &) = default;
    explicit omnic(omnic &&) noexcept = default;
    virtual ~omnic() = default;
    omnic &operator=(const omnic &) = default;
    omnic &operator=(omnic &&) noexcept = default;

    virtual void self_introduction() const = 0;
    virtual void attack() const = 0;
    virtual void defense() const = 0;
};

/// \brief 模块。
class module: public omnic {
private:
    unique_ptr<omnic> base;
public:
    explicit module() = delete;
    explicit module(const module &) = delete;
    explicit module(module &&) noexcept = default;
    virtual ~module() = default;
    module &operator=(const module &) = delete;
    module &operator=(module &&) noexcept = default;

    explicit module(unique_ptr<omnic> &&base) :
        base {move(base)}
    {}

    void self_introduction() const override
    {
        base->self_introduction();
    }

    void attack() const override
    {
        base->attack();
    }

    void defense() const override
    {
        base->defense();
    }
};

/// \brief 小不点儿。
class little_one: public omnic {
public:
    void self_introduction() const override
    {
        cout << "littleone self introduction...\n";
    }

    void attack() const override
    {
        cout << "littleone attack...\n";
    }

    void defense() const override
    {
        cout << "littleone defense...\n";
    }
};

/// \brief 机炮模块。
class cannon_module: public module {
public:
    explicit cannon_module() = delete;
    explicit cannon_module(const cannon_module &) = delete;
    explicit cannon_module(cannon_module &&) noexcept = default;
    virtual ~cannon_module() = default;
    cannon_module &operator=(const cannon_module &) = delete;
    cannon_module &operator=(cannon_module &&) noexcept = default;

    explicit cannon_module(unique_ptr<omnic> &&base):
        module(move(base))
    {}

    void self_introduction() const override
    {
        module::self_introduction();
        cout << "  equipped with cannon module\n";
    }

    void attack() const override
    {
        module::attack();
        cout << "  cannon attack\n";
    }
};

/// \brief 护盾模块。
class shield_module: public module {
public:
    explicit shield_module() = delete;
    explicit shield_module(const shield_module &) = delete;
    explicit shield_module(shield_module &&) noexcept = default;
    virtual ~shield_module() = default;
    shield_module &operator=(const shield_module &) = delete;
    shield_module &operator=(shield_module &&) noexcept = default;

    explicit shield_module(unique_ptr<omnic> &&base):
        module(move(base))
    {}

    void self_introduction() const override
    {
        module::self_introduction();
        cout << "  equipped with shield module\n";
    }

    void defense() const override
    {
        module::defense();
        cout << "  shield defense\n";
    }
};

/// @}

}//namespace decorator

/// \addtogroup gDecorator
/// @{

/// \brief 修饰器。
TEST(design_patterns, decorator)
{
    using namespace decorator;
    const auto the_little_one {
        make_unique<shield_module>(
            make_unique<cannon_module>(
                make_unique<cannon_module>(
                    make_unique<little_one>())))};
    the_little_one->self_introduction();
    the_little_one->attack();
    the_little_one->defense();
}

/// @}

}//namespace rrcxx
