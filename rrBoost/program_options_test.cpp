//===-- Program Options -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Program Options
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/program_options.html>
///
/// \version 2018-10-17
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

#include <boost/program_options.hpp>
#include <gtest/gtest.h>

namespace rrboost::test {

TEST(program_options, first_step)
{
    const char *const argv[] {"siii", "xiaa", "yiii", "--help", "--compression", "1.1"};
    span<const czstring<>> args {argv};

    try {
        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "this message")
            ("compression", boost::program_options::value<double>(), "set compression level");

        boost::program_options::variables_map vars;
        boost::program_options::store(parse_command_line(args.size(), argv, desc), vars);
        boost::program_options::notify(vars);

        if (vars.count("help")) {
            cout << desc << "\n";
        }

        if (vars.count("compression")) {
            cout << "Compression level was set to " << vars["compression"].as<double>() << "\n";
        } else {
            cout << "Compression level was not set.\n";
        }

    } catch (const exception &e) {
        FAIL() << e.what();

    } catch (...) {
        FAIL() << "Exception of unknown type.";

    }
}

}//namespace rrboost::test
