//===-- Property Tree -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Property Tree
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/property_tree.html>
///
/// \version 2019-02-25
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <boost/dll.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace dll = boost::dll;
namespace property_tree = boost::property_tree;

namespace rrboost {

TEST(property_tree, with_ini)
{
    const auto ini_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".ini"); }()};

    /* write */ {
        property_tree::ptree pt;
        pt.put("Section.Key", "Value");
        pt.put("TypeValues.int", 123);
        pt.put("TypeValues.float", 4.5);
        pt.put("TypeValues.string", "666");
        write_ini(ini_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_ini(ini_path.string(), pt);
        cout << "TypeValues.int=" << pt.get<int>("TypeValues.int") << "\n";
        cout << "TypeValues.float=" << pt.get<float>("TypeValues.float") << "\n";
        cout << "TypeValues.string=" << pt.get<string>("TypeValues.string") << "\n";
    }
}

TEST(property_tree, with_json)
{
    const auto json_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".json"); }()};

    /* write */ {
        property_tree::ptree pt;
        pt.put("TypeValues.int", 123);
        pt.put("TypeValues.float", 4.5);
        pt.put("TypeValues.string", "666");
        write_json(json_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_json(json_path.string(), pt);
        cout << "TypeValues.int=" << pt.get<int>("TypeValues.int") << "\n";
        cout << "TypeValues.float=" << pt.get<float>("TypeValues.float") << "\n";
        cout << "TypeValues.string=" << pt.get<string>("TypeValues.string") << "\n";
    }
}

TEST(property_tree, with_xml)
{
    const auto xml_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".xml"); }()};

    /* write */ {
        property_tree::ptree pt;

        pt.put("root.<xmlattr>.int", 123);
        pt.put("root.<xmlattr>.float", .456);
        pt.put("root.<xmlattr>.string", "789");

        pt.put("root.<xmlcomment>", "comment");

        pt.put("root.int", 123);
        pt.put("root.float", 0.456);
        pt.put("root.string", "789");

        pt.add("root.item", "item1");
        pt.add("root.item", "item2");
        pt.add("root.item", "item3");

        write_xml(xml_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_xml(xml_path.string(), pt);

        ASSERT_EQ(pt.get<int>("root.<xmlattr>.int"), 123);
        ASSERT_EQ(pt.get<int>("root.int"), 123);

        for (const auto &it : pt.get_child("root.item")) {
            ASSERT_EQ(it.second.get<string>("item"), "item1");
            break;
        }
    }
}

}//namespace rrboost
