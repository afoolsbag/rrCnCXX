/** \file
 *  \brief 类的成员。
 *  \author zhengrr
 *  \date 2017-1-6
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP__CLASS_MEMBER__HPP
#define RRDEMO__CDOM__CPP__CLASS_MEMBER__HPP

#include <set>

namespace rrdemo {
namespace cdom {
namespace cpp {

class ClassMember {
    /*
     * 静态成员使用 Pascal 命名法，非静态成员使用 Camel 命名法，禁止使用 Hungarian 命名法；
     * 成员命名应确切且禁止使用缩写，在应用时方善用引用等以简化书写。
     */

public:
    static bool PourIntoGlobalPool(ClassMember *object);
    static ClassMember *ScoopFromGlobalPool();

private:
    static std::set<ClassMember *> GlobalPool;

};// class ClassMember

}// namespace cpp
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP__CLASS_MEMBER__HPP