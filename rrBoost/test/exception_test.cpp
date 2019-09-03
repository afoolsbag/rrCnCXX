//===-- Exception -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Exception
/// \sa <https://boost.org/doc/libs/1_71_0/libs/exception/doc/boost-exception.html>
///
/// \version 2019-09-03
/// \since 2019-09-03
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cerrno>
#include <csignal>
#include <iostream>

#include <boost/exception/exception.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <gtest/gtest.h>

namespace {
class base_exception : virtual public std::exception, virtual public boost::exception {};

typedef boost::error_info<struct tag_errno_code, int>        errno_code;
typedef boost::error_info<struct tag_file_name, std::string> file_name;
}

using namespace std;

namespace rrboost {

TEST(exception, gft)
{
    try {
        throw runtime_error {"666"};

    } catch (const base_exception &e) {
        if (const auto ei = boost::get_error_info<file_name>(e))
            cerr << "file name: " << *ei << '\n';
        if (const auto ei = boost::get_error_info<errno_code>(e))
            cerr << "errno code: " << *ei << '\n';

    } catch (...) {
        cerr << boost::current_exception_diagnostic_information();
    }
}

}
