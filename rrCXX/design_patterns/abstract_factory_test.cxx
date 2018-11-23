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
///   interface "文档创建器" as document_creator {
///     + {abstract} create_letter() : letter
///     + {abstract} create_resume() : resume
///   }
///   interface "信件" as letter
///   interface "简历" as resume
///
///   class "花哨风文档创建器" as fancy_document_creator {
///     + create_letter() : letter
///     + create_resume() : resume
///   }
///   class "花哨风信件" as fancy_letter
///   class "花哨风简历" as fancy_resume
///
///   class "现代风文档创建器" as modern_document_creator {
///     + create_letter() : letter
///     + create_resume() : resume
///   }
///   class "现代风信件" as modern_letter
///   class "现代风简历" as modern_resume
///
///   document_creator .l> letter : create_letter()
///   document_creator .r> resume : create_resume()
///
///   fancy_document_creator .u.|> document_creator
///   fancy_letter .u.|> letter
///   fancy_resume .u.|> resume
///   fancy_document_creator .l> fancy_letter : create_letter()
///   fancy_document_creator .r> fancy_resume : create_resume()
///
///   modern_document_creator .u..|> document_creator
///   modern_letter .u..|> letter
///   modern_resume .u..|> resume
///   modern_document_creator .l> modern_letter : create_letter()
///   modern_document_creator .r> modern_resume : create_resume()
/// \enduml
///
/// \version 2018-11-23
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
