//===-- Builder -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBuilder 生成器
/// \ingroup gDesignPatterns
///
/// 生成器设计模式：
///
/// 意图将一个复杂对象的构建与它的的表示分离，使得同样的构建过程可以创建不同的表示。
///
/// > + 它使你可以改变一个产品的内部表示
/// > + 它将构造代码和表示代码分开
/// > + 它使你可对构造过程进行更精细的控制
///
/// \startuml
///   class "服务员" as waiter
///   abstract "披萨生成器" as pizza_builder {
///     + {abstract} build_dough()
///     + {abstract} build_sauce()
///     + {abstract} build_topping()
///     + get_pizza()
///   }
///   class "披萨" as pizza {
///     + dough
///     + sauce
///     + topping 
///   }
///
///   class "夏威夷披萨生成器" as hawaiian_pizza_builder {
///     + build_dough()
///     + build_sauce()
///     + build_topping()
///   }
///
///   class "辣披萨生成器" as spicy_pizza_builder {
///     + build_dough()
///     + build_sauce()
///     + build_topping()
///   }
///
///   waiter -> pizza_builder
///   pizza_builder .> pizza
///   hawaiian_pizza_builder -u-|> pizza_builder
///   spicy_pizza_builder -u-|> pizza_builder
///
/// \enduml
///
/// \version 2018-12-29
/// \since 2018-09-26
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

namespace rrcxx::test {

/// \addtogroup gBuilder
/// @{

/// \brief 产品。
class product {};

/// \brief 生成器（接口）。
class builder {
public:
    virtual ~builder() = default;
    virtual void build_part() {}
    virtual unique_ptr<product> get_product() { return make_unique<product>(current_product); }
private:
    product current_product;
	byte paddings[3] {};
};

/// \brief 导向器。
class director {
public:
    unique_ptr<product> create_product(unique_ptr<builder> &builder)
    {
        builder->build_part();
        return builder->get_product();
    }
};

/// \brief 具体生成器。
class concrete_builder: public builder {
    void build_part() final {}
};

/// \brief 生成器。
TEST(design_patterns, builder)
{
    unique_ptr<builder> builder {make_unique<concrete_builder>()};
    unique_ptr<director> director {make_unique<class director>()};
    auto product = director->create_product(builder);
}

/// @}

}//namespace rrcxx
