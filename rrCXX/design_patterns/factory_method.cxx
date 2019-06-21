//===-- Factory Method ------------------------------------------*- C++ -*-===//
///
/// \defgroup gFactoryMethod 工厂方法
/// \ingroup gDesignPatterns
///
/// 工厂方法设计模式：
///
/// 意图定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。
///
/// > + 为子类提供挂钩
/// > + 连接平行的类层次
///
/// \startuml
///   interface "按钮工厂" as button_factory {
///     + {abstract} create_button() : button
///   }
///   interface "按钮" as button
///
///   class "Win 风格按钮工厂" as win_button_factory {
///     + create_button() : button
///   }
///   class "Win 风格按钮" as win_button
///
///   class "Mac 风格按钮工厂" as mac_button_factory {
///     + create_button() : button
///   }
///   class "Mac 风格按钮" as mac_button
///
///   button_factory .> button : create_button()
///
///   win_button_factory .u.|> button_factory
///   win_button .u.|> button
///   win_button_factory .> win_button
///
///   mac_button_factory .u..|> button_factory
///   mac_button .u..|> button
///   mac_button_factory .> mac_button
/// \enduml
///
/// \version 2018-11-27
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

/// \addtogroup gFactoryMethod
/// @{

/// \brief 产品（接口）。
class product {};

/// \brief 创建者（接口）。
class creator {
public:
    virtual ~creator() = default;
    virtual unique_ptr<product> create_product() = 0;
};

/// \brief 具体产品。
class concrete_product: public product {};

/// \brief 具体创建者。
class concrete_creator: public creator {
public:
    unique_ptr<product> create_product() final
    {
        return make_unique<concrete_product>();
    }
};

/// \brief 生成器。
TEST(design_patterns, factory_method)
{
    unique_ptr<creator> creator {make_unique<concrete_creator>()};
    auto product {creator->create_product()};
}

/// @}

}
