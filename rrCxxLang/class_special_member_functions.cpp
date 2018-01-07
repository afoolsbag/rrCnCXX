/** \file
 *  \brief 类的特殊成员函数。
 *  \author zhengrr
 *  \date 2016-10-19 – 2017-12-28
 *  \copyright The MIT License */

namespace {

class Class {
public:
    /// 隐式声明的默认构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/default_constructor> */
    explicit Class() = delete;

    /// 隐式声明的复制构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/copy_constructor> */
    explicit Class(const Class&) = delete;

    /// 隐式声明的移动构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/move_constructor> */
    explicit Class(Class&&) = delete;

    /// 隐式声明的析构函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/destructor> */
    ~Class() = delete;

    /// 隐式声明的复制赋值操作符。
    /** \sa <http://en.cppreference.com/w/cpp/language/copy_assignment> */
    Class& operator=(const Class&) = delete;

    /// 隐式声明的移动赋值操作符。
    /** \sa <http://en.cppreference.com/w/cpp/language/move_assignment> */
    Class& operator=(Class&&) = delete;

};// class Class

}// namespace
