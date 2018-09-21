//===-- Uniform Resource Identifier -----------------------------*- C++ -*-===//
///
/// \file
/// \brief 统一资源标识符。
///
/// \version 2018-09-21
/// \since 2018-09-21
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_URI_HXX_
#define RRCXX_URI_HXX_

#include <string>

namespace rrcxx::prototypes::igcf2 {

/// \brief 统一资源标识符。
using uri = std::string;

/// \brief 统一资源命名符。
using urn = uri;

/// \brief 统一资源定位符。
using url = uri;

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_URI_HXX_
