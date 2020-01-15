//===-- Filesystem ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Filesystem
/// \sa <https://boost.org/doc/libs/master/libs/filesystem/>
///
/// \version 2020-01-13
/// \since 2019-11-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <fstream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/locale.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace {

inline string utf16_to_utf8(const wstring &utf16)
{
    return boost::locale::conv::utf_to_utf<char, wchar_t>(forward<const wstring &>(utf16));
}

inline wstring utf8_to_utf16(const string &utf8)
{
    return boost::locale::conv::utf_to_utf<wchar_t, char>(forward<const string &>(utf8));
}

}

namespace rrboost {

TEST(filesystem, chmod)
{
    const auto temp_path = boost::filesystem::temp_directory_path() / boost::filesystem::unique_path();

    ofstream temp_file {temp_path.c_str()};
    temp_file << "hello, world\n";
    if (!temp_file.is_open())
        FAIL() << "Failed to create temporary file: " << temp_path << '\n';

    permissions(temp_path, boost::filesystem::all_all);
    cout << "Succeed to create temporary file: " << temp_path << '\n';
}

}
