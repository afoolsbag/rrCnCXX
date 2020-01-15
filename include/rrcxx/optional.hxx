//===-- Optional ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 寻找可用的 `<optional>` 头文件。
///
/// \version 2020-01-13
/// \since 2020-01-13
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_OPTIONAL_HXX_
#define RRCXX_OPTIONAL_HXX_

#if defined(__cpp_lib_optional) \
 || defined(__has_include) && __has_include(<optional>)

#include <optional>
namespace rrcxx = std;

#else

#include <boost/optional.hpp>
namespace rrcxx = boost;

#endif

#endif
