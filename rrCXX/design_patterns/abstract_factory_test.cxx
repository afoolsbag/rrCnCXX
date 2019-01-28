//===-- Abstract Factory ----------------------------------------*- C++ -*-===//
///
/// \defgroup gAbstractFactory 抽象工厂
/// \ingroup gDesignPatterns
///
/// 为一个产品族提供了统一的创建接口。当需要这个产品族的某一系列的时候，可以从抽象工厂中选出相应的系列创建一个具体的工厂类。
///
/// \startuml
///   title 抽象工厂模式（Abstract Factory Pattern）
///
///   class "客户" as client
///
///   interface "图形界面工厂" as gui_factory {
///     + {abstract} create_button() : button
///     + {abstract} create_border() : border
///   }
///   interface "按钮" as button {
///     + {abstract} paint() : void
///   }
///   interface "边框" as border {
///     + {abstract} paint() : void
///   }
///
///   class "Windows 工厂" as windows_factory {
///     + create_button() : button
///     + create_border() : border
///   }
///   class "Windows 按钮" as windows_button {
///     + paint() : void
///   }
///   class "Windows 边框" as windows_border {
///     + paint() : void
///   }
///
///   class "MacOSX 工厂" as macosx_factory {
///     + create_button() : button
///     + create_border() : border
///   }
///   class "MacOSX 按钮" as macosx_button {
///     + paint() : void
///   }
///   class "MacOSX 边框" as macosx_border {
///     + paint() : void
///   }
///
///   client --> gui_factory
///   client --> button
///   client --> border
///
///   gui_factory <|.. windows_factory
///   button <|.. windows_button
///   border <|.. windows_border
///   windows_factory .> windows_button : create_button()
///   windows_factory .l> windows_border : create_border()
///
///   gui_factory <|... macosx_factory
///   button <|... macosx_button
///   border <|... macosx_border
///   macosx_factory .> macosx_button : create_button()
///   macosx_factory .l> macosx_border : create_border()
///
///   legend
///     抽象工厂（AbstractFactory）：图形界面工厂
///     抽象产品（AbstractProduct）：按钮、边框
///     具体工厂（ConcreteFactory）：Windows 工厂、MacOSX 工厂
///     具体产品（ConcreteProduct）：Windows 按钮、Windows 边框、MacOSX 按钮、MacOSX 边框
///   endlegend
/// \enduml
///
/// \version 2018-11-28
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
namespace abstract_factory {

/// \addtogroup gAbstractFactory
/// @{

/// \brief 按钮。
class button {
public:
    explicit button() = default;
    explicit button(const button &) = default;
    explicit button(button &&) noexcept = default;
    virtual ~button() = default;
    button &operator=(const button &) = default;
    button &operator=(button &&) noexcept = default;

    virtual void paint() const = 0;
};

/// \brief 边框。
class border {
public:
    explicit border() = default;
    explicit border(const border &) = default;
    explicit border(border &&) noexcept = default;
    virtual ~border() = default;
    border &operator=(const border &) = default;
    border &operator=(border &&) noexcept = default;

    virtual void paint() const = 0;
};

/// \brief 图形界面工厂。
class gui_factory {
public:
    explicit gui_factory() = default;
    explicit gui_factory(const gui_factory &) = default;
    explicit gui_factory(gui_factory &&) noexcept = default;
    virtual ~gui_factory() = default;
    gui_factory &operator=(const gui_factory &) = default;
    gui_factory &operator=(gui_factory &&) noexcept = default;

    virtual unique_ptr<button> create_button() const = 0;
    virtual unique_ptr<border> create_border() const = 0;
};

/// \brief Windows 按钮。
class windows_button: public button {
public:
    void paint() const override
    {
        cout << "Windows Button\n";
    }
};

/// \brief Windows 边框。
class windows_border: public border {
public:
    void paint() const override
    {
        cout << "Windows Border\n";
    }
};

/// \brief Windows 工厂。
class windows_factory: public gui_factory {
public:
    unique_ptr<button> create_button() const override
    {
        return make_unique<windows_button>();
    }

    unique_ptr<border> create_border() const override
    {
        return make_unique<windows_border>();
    }
};

/// \brief MacOSX 按钮。
class macosx_button: public button {
public:
    void paint() const override
    {
        cout << "MacOSX Button\n";
    }
};

/// \brief MacOSX 边框。
class macosx_border: public border {
public:
    void paint() const override
    {
        cout << "MacOSX Border\n";
    }
};

/// \brief MacOSX 工厂。
class macosx_factory: public gui_factory {
public:
    unique_ptr<button> create_button() const override
    {
        return make_unique<macosx_button>();
    }

    unique_ptr<border> create_border() const override
    {
        return make_unique<macosx_border>();
    }
};

/// @}

}//namespace abstract_factory

/// \addtogroup gAbstractFactory
/// @{

/// \brief 抽象工厂。
TEST(design_patterns, abstract_factory)
{
    using namespace abstract_factory;

    {
        const unique_ptr<gui_factory> factory {make_unique<windows_factory>()};
        const auto button {factory->create_button()};
        const auto border {factory->create_border()};
        button->paint();
        border->paint();
    }
    {
        const unique_ptr<gui_factory> factory {make_unique<macosx_factory>()};
        const auto button {factory->create_button()};
        const auto border {factory->create_border()};
        button->paint();
        border->paint();
    }
}

/// @}

}//namespace rrcxx
