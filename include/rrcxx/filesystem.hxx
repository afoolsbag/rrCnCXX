//===-- Filesystem ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 寻找 `<filesystem>` 头文件。
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
#ifndef FILESYSTEM_HXX_
#define FILESYSTEM_HXX_

#if defined(__cpp_lib_filesystem) \
 || defined(__has_include) && __has_include(<filesystem>)

#include <filesystem>

#elif defined(__cpp_lib_experimental_filesystem) \
   || defined(__has_include) && __has_include(<experimental/filesystem>)

#include <experimental/filesystem>
namespace std {
namespace filesystem = experimental::filesystem;
}

#else

#include <boost/filesystem.hpp>
namespace std {
namespace filesystem = boost::filesystem;
}

#endif

#endif
