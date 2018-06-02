//===-- Special Member Functions --------------------------------*- C++ -*-===//
///
/// \file
/// \brief 特殊成员函数。
///
/// \version 2018-06-02
/// \since 2016-10-19
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

namespace {

/// \brief 带默认构造函数的类。
class DefCtorCl {
public:
  /// \brief 隐式声明的默认构造函数
  /// \sa <http://en.cppreference.com/w/cpp/language/default_constructor>
  inline DefCtorCl() = default;
};

/// \brief 带默认复制构造函数的类。
class DefCpyCtorCl {
public:
  /// \brief 隐式声明的复制构造函数
  /// \sa <http://en.cppreference.com/w/cpp/language/copy_constructor>
  inline DefCpyCtorCl(const DefCpyCtorCl &) = default;
};

/// \brief 带默认移动构造函数的类。
class DefMovCtorCl {
public:
  /// \brief 隐式声明的移动构造函数
  /// \sa <http://en.cppreference.com/w/cpp/language/move_constructor>
  inline DefMovCtorCl(DefMovCtorCl &&) = default;
};

/// \brief 带默认复制运算的类。
class DefCpyAsgmt {
public:
  /// \brief 隐式声明的复制运算。
  /// \sa <http://en.cppreference.com/w/cpp/language/copy_assignment>
  inline DefCpyAsgmt &operator=(const DefCpyAsgmt &) = default;
};

/// \brief 带默认移动运算的类。
class DefMovAsgmt {
public:
  /// \brief 隐式声明的移动赋值运算
  /// \sa <http://en.cppreference.com/w/cpp/language/move_assignment>
  inline DefMovAsgmt &operator=(DefMovAsgmt &&) = default;
};

/// \brief 带默认析构函数的类。
class DefDtorCl {
public:
  /// \brief 隐式声明的析构函数
  /// \sa <http://en.cppreference.com/w/cpp/language/destructor>
  inline ~DefDtorCl() = delete;
};

}// namespace

TEST(SpMemFunc, Ignore) {
  SUCCEED();
}
