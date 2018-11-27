//===-- Prototype -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gPrototype 原型
/// \ingroup gDesignPatterns
///
/// 原型设计模式：
///
/// 意图用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
///
/// > + 运行时刻增加和删除产品
/// > + 改变值以指定新对象
/// > + 改变结构以指定新对象
/// > + 减少子类的构造
/// > + 用类动态配置应用
///
/// \startuml
///   interface prototype {
///     + {abstract} clone()
///   }
///
///   class concrete_propttype {
///     + clone()
///   }
///
///   prototype <|.. concrete_propttype
/// \enduml
///
/// \version 2018-11-27
/// \since 2018-09-27
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

/// \addtogroup gPrototype
/// @{

/// \brief 原型（接口）。
class prototype {
public:
    virtual ~prototype() = default;
    virtual unique_ptr<prototype> clone() const = 0;
};

/// \brief 具体原型。
class concrete_prototype: public prototype {
public:
    unique_ptr<prototype> clone() const final
    {
        return make_unique<concrete_prototype>();
    }
};

/// \brief 生成器。
TEST(design_patterns, prototype)
{
    const unique_ptr<prototype> prototype {make_unique<concrete_prototype>()};
    auto clone {prototype->clone()};
}

/// @}

}//namespace rrcxx
