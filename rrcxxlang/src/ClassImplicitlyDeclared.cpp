/** \file
 *  \brief 类的隐式声明的（成员函数）。
 *  \author zhengrr
 *  \date 2016-10-19 – 2017-1-6
 *  \copyright The MIT License
 */
namespace {

class ClassImplicitlyDeclared {
public:
    /// 隐式声明的默认构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/default_constructor>
     */
    explicit ClassImplicitlyDeclared() = delete;

    /// 隐式声明的复制构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/copy_constructor>
     */
    explicit ClassImplicitlyDeclared(const ClassImplicitlyDeclared &) = delete;

    /// 隐式声明的移动构造函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/move_constructor>
     */
    explicit ClassImplicitlyDeclared(ClassImplicitlyDeclared &&) = delete;

    /// 隐式声明的析构函数。
    /** \sa <http://en.cppreference.com/w/cpp/language/destructor>
     */
    ~ClassImplicitlyDeclared() = delete;

    /// 隐式声明的复制赋值操作符。
    /** \sa <http://en.cppreference.com/w/cpp/language/copy_assignment>
     */
    ClassImplicitlyDeclared &operator=(const ClassImplicitlyDeclared &) = delete;

    /// 隐式声明的移动赋值操作符。
    /** \sa <http://en.cppreference.com/w/cpp/language/move_assignment>
     */
    ClassImplicitlyDeclared &operator=(ClassImplicitlyDeclared &&) = delete;

};// class ClassImplicitlyDeclared

}// namespace
