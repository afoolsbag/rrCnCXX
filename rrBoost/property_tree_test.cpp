//===-- Property Tree -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Property Tree
/// \sa <https://boost.org/doc/libs/1_68_0/doc/html/property_tree.html>
///
/// \version 2019-01-23
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <boost/dll.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(property_tree, with_ini)
{
    const auto ini_path {[] {
        auto tmp {boost::dll::program_location()};
        return tmp.replace_extension(".ini"); }()};

    // write
    {
        boost::property_tree::ptree pt;
        pt.put("Section.Key", "Value");
        pt.put("TypeValues.int", 123);
        pt.put("TypeValues.float", 4.5);
        pt.put("TypeValues.string", "666");
        boost::property_tree::write_ini(ini_path.string(), pt);
    }

    // read
    {
        boost::property_tree::ptree pt;
        boost::property_tree::read_ini(ini_path.string(), pt);
        cout << "TypeValues.int=" << pt.get<int>("TypeValues.int") << "\n";
        cout << "TypeValues.float=" << pt.get<float>("TypeValues.float") << "\n";
        cout << "TypeValues.string=" << pt.get<string>("TypeValues.string") << "\n";
    }
}

TEST(property_tree, with_xml)
{
    const auto xml_path {[] {
        auto tmp {boost::dll::program_location()};
        return tmp.replace_extension(".xml"); }()};

    // write
    {
        boost::property_tree::ptree pt;
        pt.put("TypeValues.int", 123);
        pt.put("TypeValues.float", 4.5);
        pt.put("TypeValues.string", "666");
        boost::property_tree::write_xml(xml_path.string(), pt);
    }

    // read
    {
        boost::property_tree::ptree pt;
        boost::property_tree::read_xml(xml_path.string(), pt);
        cout << "TypeValues.int=" << pt.get<int>("TypeValues.int") << "\n";
        cout << "TypeValues.float=" << pt.get<float>("TypeValues.float") << "\n";
        cout << "TypeValues.string=" << pt.get<string>("TypeValues.string") << "\n";
    }
}

}//namespace rrboost
