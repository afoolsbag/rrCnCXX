/// \copyright Unlicense

#include <iostream>

#include <gtest/gtest.h>

#include "rrwindows/rrwindows.hxx"

using namespace std;

namespace rrwindows {

TEST(dynamic_link_library, executable_path)
{
    cout << "executable_path: " << executable_path() << '\n';
}

TEST(dynamic_link_library, alloc_executable_directory_path)
{
    cout << "rrwindows_path: " << rrwindows_path() << '\n';
}

}
