//===-- Builder -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBuilder 生成器
/// \ingroup gDzn
///
/// 生成器设计模式：
///
/// 意图将一个复杂对象的构建与它的的表示分离，使得同样的构建过程可以创建不同的表示。
///
/// > + 它使你可以改变一个产品的内部表示
/// > + 它将构造代码和表示代码分开
/// > + 它使你可对构造过程进行更精细的控制
///
/// \version 2018-09-27
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

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
    virtual std::unique_ptr<product> get_product() { return std::make_unique<product>(current_product); }
private:
    product current_product;
};

/// \brief 导向器。
class director {
public:
    std::unique_ptr<product> create_product(std::unique_ptr<builder> &builder)
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
    std::unique_ptr<builder> builder {std::make_unique<concrete_builder>().release()};
    std::unique_ptr<director> director {std::make_unique<class director>()};
    auto product = director->create_product(builder);
}

/// @}

}//namespace rrcxx::test
