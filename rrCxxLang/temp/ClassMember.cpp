/** \copyright The MIT License */
#include "ClassMember.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp {

/* 静态数据成员初始化 */
std::set<ClassMember *> ClassMember::GlobalPool {};

bool ClassMember::
PourIntoGlobalPool(ClassMember *object)
{
    return true;
}

ClassMember *ClassMember::
ScoopFromGlobalPool()
{
    return nullptr;
}


}// namespace cpp
}// namespace cdom
}// namespace rrdemo
