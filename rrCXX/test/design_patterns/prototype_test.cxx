//===-- Prototype -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gPrototype 原型
/// \ingroup gDzn
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
/// \version 2018-09-27
/// \since 2018-09-27
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gPrototype
/// @{

/// \brief 原型（接口）。
class prototype {
public:
    virtual ~prototype() = default;
    virtual std::unique_ptr<prototype> clone() const = 0;
};

/// \brief 具体原型。
class concrete_prototype: public prototype {
public:
    std::unique_ptr<prototype> clone() const final
    {
        return std::make_unique<concrete_prototype>();
    }
};

/// \brief 生成器。
TEST(design_patterns, prototype)
{
    const std::unique_ptr<prototype> prototype {std::make_unique<concrete_prototype>()};
    auto clone {prototype->clone()};
}

/// @}

}//namespace rrcxx::test
