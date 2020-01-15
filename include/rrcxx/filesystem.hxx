//===-- Filesystem ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 寻找可用的 `<filesystem>` 头文件。
///
/// \sa <https://stackoverflow.com/questions/53365538>
///
/// \version 2020-01-13
/// \since 2019-08-16
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_FILESYSTEM_HXX_
#define RRCXX_FILESYSTEM_HXX_

#if defined(__cpp_lib_filesystem) \
 || defined(__has_include) && __has_include(<filesystem>)

#include <filesystem>
namespace rrcxx { namespace filesystem = std::filesystem; }

#elif defined(__cpp_lib_experimental_filesystem) \
   || defined(__has_include) && __has_include(<experimental/filesystem>)

#include <experimental/filesystem>
namespace rrcxx { namespace filesystem = std::experimental::filesystem; }

#else

#include <boost/filesystem.hpp>
namespace rrcxx { namespace filesystem = boost::filesystem; }

#endif

#endif
