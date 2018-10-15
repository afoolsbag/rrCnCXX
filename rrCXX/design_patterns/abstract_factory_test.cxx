//===-- Abstract Factory ----------------------------------------*- C++ -*-===//
///
/// \defgroup gAbstractFactory 抽象工厂
/// \ingroup gDzn
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
/// \version 2018-10-10
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>
using namespace std;

#include <gtest/gtest.h>

namespace rrcxx::test {

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
    unique_ptr<abstract_factory> factory {make_unique<concrete_factory>().release()};
    auto product_a {factory->create_product()};
}

/// @}

}//namespace rrcxx::test
