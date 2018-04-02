//===-- Program Options -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost Program Options
/// \sa ["Boost.Program_options"](https://boost.org/doc/libs/1_66_0/doc/html/program_options.html). *Boost 1.66.0*.
///
/// \version 2018-04-02
/// \since 2018-04-02
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

int main(int argc, char *argv[])
{
    try {
        bpo::options_description opt_grp1_desc("Group1 options");
        opt_grp1_desc.add_options()
            ("help,h", "This message.")
            ("compression", bpo::value<double>(), "set compression level")
            ;

        bpo::variables_map var_map;
        bpo::store(bpo::parse_command_line(argc, argv, opt_grp1_desc), var_map);
        bpo::notify(var_map);

        if (var_map.count("help")) {
            std::cout << opt_grp1_desc << std::endl;
            return EXIT_SUCCESS;
        }

        if (var_map.count("compression")) {
            std::cout << "Compression level was set to " << var_map["compression"].as<double>() << std::endl;
        } else {
            std::cout << "Compression level was not set." << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;

    } catch (...) {
        std::cerr << "Exception of unknown type!" << std::endl;
    }
    return EXIT_SUCCESS;
}
