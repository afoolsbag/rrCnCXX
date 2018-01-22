/** \file
 *  \brief 禁用类构造函数的隐式转换和复制初始化。
 *  \sa <http://en.cppreference.com/w/cpp/language/explicit>
 *  \author zhengrr
 *  \date 2017-12-28 – 2018-1-2
 *  \copyright The MIT License */

#include <gtest/gtest.h>

namespace {

struct Class {
    Class(int) {}
    operator bool() const { return true; }
};// struct ClazzWithoutExplicit

struct Clazz {
    explicit Clazz(int) {}
    explicit operator bool() const { return true; }
};// struct ClazzWithExplicit

}// namespace

TEST(class_explicit, class_explicit)
{
    Class a1(1);                       // ✓ 直接初始化
    Class a2 = 2;                      // ✓ 复制初始化
    Class a3{3};                       // ✓ 直接列表初始化
    Class a4 = {4};                    // ✓ 复制列表初始化
    Class a5 = static_cast<Class>(5);  // ✓ 显式转换直接初始化
    if (a1);                           // ✓ 用户自定义转换
    bool na2 = a2;                     // ✓ 复制初始化
    bool na3 = static_cast<bool>(a3);  // ✓ 显式转换直接初始化

    Clazz b1(1);                       // ✓ 直接初始化
//  Clazz b2 = 2;                      // ✗ 复制初始化
    Clazz b3{3};                       // ✓ 直接列表初始化
//  Clazz b4 = {4};                    // ✗ 复制列表初始化
    Clazz b5 = static_cast<Clazz>(5);  // ✓ 显式转换直接初始化
    if (b1);                           // ✓ 用户自定义转换
//  bool nb2 = b2;                     // ✗ 复制初始化
    bool nb3 = static_cast<bool>(b3);  // ✓ 显式转换直接初始化

    SUCCEED();
}
