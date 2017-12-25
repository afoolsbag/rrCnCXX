/** \file
 *  \brief 友元。
 *  \sa <http://en.cppreference.com/w/cpp/language/classes>
 *  \author zhengrr
 *  \date 2016-10-25 – 31
 *  \copyright The MIT License
 */
namespace {

class Class {
    int privateData = 0;

    /// 友元函数。
    /** 友元函数声明于类中，但不是成员函数，不被继承。
     */
    friend int GetClassPrivateData(const Class& object);

    /// 友元类。
    /** 友元类声明于类中，但不是嵌套类，不被继承。
     *  友元类的所有成员函数都是友元函数。
     */
    friend class Clazz;
};

int GetClassPrivateData(const Class& object)
{
    return object.privateData;
}

class Clazz {
    int privateData = 0;
    void copyFromClassPrivateData(const Class& object)
    {
        privateData = object.privateData;
    }
};

}// namespace
