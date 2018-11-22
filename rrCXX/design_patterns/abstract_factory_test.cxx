//===-- Abstract Factory ----------------------------------------*- C++ -*-===//
///
/// \defgroup gAbstractFactory 抽象工厂
/// \ingroup gDesignPatterns
///
/// 抽象工厂设计模式：
///
/// 意图提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
///
/// > + 它分离了具体的类
/// > + 它使得易于交换产品系列
/// > + 它有利于产品的一致性
/// > + 难以支持新种类的产品
///
/// \startuml
///   interface abstract_factory {
///     + {abstract} create_product1() : product1
///     + {abstract} create_product2() : product2
///   }
///   interface product1
///   interface product2
///
///   abstract_factory .left.> product1 : create_product1()
///   abstract_factory .right.> product2 : create_product2()
///
///   class concrete1_factory {
///     + create_product1() : product1
///     + create_product2() : product2
///   }
///   class concrete1_product1
///   class concrete1_product2
///
///   concrete1_factory .left.> concrete1_product1 : create_product1()
///   concrete1_factory .right.> concrete1_product2 : create_product2()
///
///   class concrete2_factory {
///     + create_product1() : product1
///     + create_product2() : product2
///   }
///   class concrete2_product1
///   class concrete2_product2
///
///   concrete2_factory .left.> concrete2_product1 : create_product1()
///   concrete2_factory .right.> concrete2_product2 : create_product2()
///
///   abstract_factory <|.. concrete1_factory
///   product1 <|.. concrete1_product1
///   product2 <|.. concrete1_product2
///
///   abstract_factory <|... concrete2_factory
///   product1 <|... concrete2_product1
///   product2 <|... concrete2_product2
/// \enduml
///
/// \version 2018-11-22
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

/// \addtogroup gAbstractFactory
/// @{

/// \brief 抽象产品。
class abstract_product {
public:
    virtual ~abstract_product() = default;
};

/// \brief 抽象工厂。
class abstract_factory {
public:
    virtual ~abstract_factory() = default;
    virtual unique_ptr<abstract_product> create_product() = 0;
};

/// \brief 具体产品。
class concrete_product: public abstract_product {};

/// \brief 具体工厂。
class concrete_factory: public abstract_factory {
public:
    unique_ptr<abstract_product> create_product() final
    {
        return make_unique<concrete_product>();
    }
};

/// \brief 抽象工厂。
TEST(design_patterns, abstract_factory)
{
    unique_ptr<abstract_factory> factory {make_unique<concrete_factory>()};
    auto product_a {factory->create_product()};
}

/// @}

}//namespace rrcxx
