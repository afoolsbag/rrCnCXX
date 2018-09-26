//===-- Factory Method ------------------------------------------*- C++ -*-===//
///
/// \defgroup gFactoryMethod 工厂方法
/// \ingroup gDzn
///
/// 工厂方法设计模式：
///
/// 意图定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。
///
/// > + 为子类提供挂钩
/// > + 连接平行的类层次
///
/// \version 2018-09-26
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gFactoryMethod
/// @{

// abstract

/// \brief 产品（接口）。
class product {};

/// \brief 创建者（接口）。
class creator {
public:
    virtual ~creator() = default;
    virtual std::unique_ptr<product> create_product() = 0;
};

// concrete

/// \brief 具体产品类别 1。
class concrete_product_type_1: public product {};

/// \brief 具体创建者类别 1。
class concrete_creator_type_1: public creator {
public:
    std::unique_ptr<product> create_product() final
    {
        std::unique_ptr<product> product {std::make_unique<concrete_product_type_1>()};
        return product;
    }
};

/// \brief 生成器。
TEST(factory_method, test)
{
    std::unique_ptr<creator> creator {std::make_unique<concrete_creator_type_1>()};
    auto product {creator->create_product()};
}

/// @}

}//namespace rrcxx::test
