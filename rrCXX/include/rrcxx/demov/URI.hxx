//===-- Uniform Resource Identifier -----------------------------*- C++ -*-===//
///
/// \file
/// \brief 统一资源标识符。
///
/// \version 2018-09-10
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_URI_HXX_
#define RRCXX_URI_HXX_

#include <string>

namespace rrcxx {
namespace demov {

///
/// \brief 统一资源标识符。
///
using URI = std::string;

///
/// \brief 统一资源命名符。
///
using URN = std::string;

///
/// \brief 统一资源定位符。
///
using URL = std::string;

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_URI_HXX_
