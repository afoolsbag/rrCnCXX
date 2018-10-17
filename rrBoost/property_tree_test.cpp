//===-- Property Tree -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Property Tree
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/property_tree.html>
///
/// \version 2018-10-17
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <set>
#include <string>
using namespace std;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <gtest/gtest.h>

namespace rrboost::test {

TEST(property_tree, with_xml)
{
    struct log_settings {
        string      file {"log.txt"s};
        int         level {0};
        set<string> modules {"m1"s, "m2"s, "m3"s};
        void load(const string &config_file)
        {
            boost::property_tree::ptree tree;
            boost::property_tree::read_xml(config_file, tree);
            file = tree.get("log.file", "log.txt");
            level = tree.get("log.level", 0);
            for (const auto &pair : tree.get_child("log.modules"))
                modules.insert(pair.second.data());
        }
        void save(const string &config_file)
        {
            boost::property_tree::ptree tree;
            tree.put("log.file", file);
            tree.put("log.level", level);
            for (const auto &module : modules)
                tree.add("log.modules.module", module);
            boost::property_tree::write_xml(config_file, tree);
        }
    };

    log_settings settings;
    settings.save("config.xml");
    settings.load("config.xml");
}

}//namespace rrboost::test
