//===-- Property Tree -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Property Tree
/// \sa <https://boost.org/doc/libs/master/doc/html/property_tree.html>
///
/// \version 2019-02-25
/// \since 2018-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <climits>
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
    constexpr auto kn {"section.name"};  ///< key name
    constexpr auto kv {"value"};         ///< key value
    constexpr auto in {"type.int"};      ///< int (key) name
    constexpr auto iv {INT_MAX};         ///< int (key) value
    constexpr auto rn {"type.real"};     ///< real (key) name
    constexpr auto rv {DBL_MAX};         ///< real (key) value
    constexpr auto sn {"type.string"};   ///< string (key) name
    constexpr auto sv {"the quick brown fox jumps over the lazy dog"};  ///< string (key) value

    const auto ini_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".ini"); }()};

    /* write */ {
        property_tree::ptree pt;

        pt.put(kn, kv);

        pt.put(in, iv);
        pt.put(rn, rv);
        pt.put(sn, sv);

        write_ini(ini_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_ini(ini_path.string(), pt);

        ASSERT_EQ(pt.get<string>(kn), kv);

        ASSERT_EQ(pt.get<int>(in), iv);
        ASSERT_EQ(pt.get<double>(rn), rv);
        ASSERT_EQ(pt.get<string>(sn), sv);
    }
}

TEST(property_tree, with_json)
{
    constexpr auto pn {"object.name"};  ///< pair name
    constexpr auto pv {"value"};        ///< pair value
    constexpr auto in {"type.int"};     ///< int (pair) name
    constexpr auto iv {INT_MAX};        ///< int (pair) value
    constexpr auto rn {"type.real"};    ///< real (pair) name
    constexpr auto rv {DBL_MAX};        ///< real (pair) value
    constexpr auto sn {"type.string"};  ///< string (pair) name
    constexpr auto sv {"the quick brown fox jumps over the lazy dog"};  ///< string (pair) value
    constexpr auto an {"array"};        ///< array name
    constexpr auto avn {"value n"};     ///< array value n

    const auto json_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".json"); }()};

    /* write */ {
        property_tree::ptree pt;

        pt.put(pn, pv);

        pt.put(in, iv);
        pt.put(rn, rv);
        pt.put(sn, sv);

        property_tree::ptree avt, avnt;
        avnt.put("", avn);
        avt.push_back(make_pair("", avnt));
        pt.put_child(an, avt);

        write_json(json_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_json(json_path.string(), pt);

        ASSERT_EQ(pt.get<string>(pn), pv);

        ASSERT_EQ(pt.get<int>(in), iv);
        ASSERT_EQ(pt.get<double>(rn), rv);
        ASSERT_EQ(pt.get<string>(sn), sv);

        ASSERT_EQ(pt.get_child(an).front().second.get_value<string>(), avn);
    }
}

TEST(property_tree, with_xml)
{
    constexpr auto et {"root.tag"};                          ///< element tag
    constexpr auto ec {"content"};                           ///< element content
    constexpr auto it {"root.type.int"};                     ///< int (element) tag
    constexpr auto ic {INT_MAX};                             ///< int (element) content
    constexpr auto rt {"root.type.real"};                    ///< real (element) tag
    constexpr auto rc {DBL_MAX};                             ///< real (element) content
    constexpr auto st {"root.type.string"};                  ///< string (element) tag
    constexpr auto sc {"the quick brown fox jumps over the lazy dog"};  ///< string (element) content
    constexpr auto at {"root.array"};                        ///< array (element) tag
    constexpr auto ait {"root.array.item"};                  ///< array item (element) tag
    constexpr auto aicn {"content n"};                       ///< array item (element) content n
    constexpr auto ct {"root.comment.<xmlcomment>"};         ///< comment (element) tag
    constexpr auto cc {"comment"};                           ///< comment (element) comment
    constexpr auto ain {"root.attribute.<xmlattr>.int"};     ///< attribute (element) int name
    constexpr auto aiv {INT_MAX};                            ///< attribute (element) int value
    constexpr auto arn {"root.attribute.<xmlattr>.real"};    ///< attribute (element) real name
    constexpr auto arv {DBL_MAX};                            ///< attribute (element) real value
    constexpr auto asn {"root.attribute.<xmlattr>.string"};  ///< attribute (element) string name
    constexpr auto asv {"the quick brown fox jumps over the lazy dog"};  ///< attribute (element) string value

    const auto xml_path {[] {
        auto tmp {dll::program_location()};
        return tmp.replace_extension(".xml"); }()};

    /* write */ {
        property_tree::ptree pt;

        pt.put(et, ec);

        pt.put(it, ic);
        pt.put(rt, rc);
        pt.put(st, sc);

        pt.add(ait, aicn);

        pt.put(ct, cc);

        pt.put(ain, aiv);
        pt.put(arn, arv);
        pt.put(asn, asv);

        write_xml(xml_path.string(), pt);
    }

    /* read */ {
        property_tree::ptree pt;
        read_xml(xml_path.string(), pt);

        ASSERT_EQ(pt.get<string>(et), ec);

        ASSERT_EQ(pt.get<int>(it), ic);
        ASSERT_EQ(pt.get<double>(rt), rc);
        ASSERT_EQ(pt.get<string>(st), sc);

        ASSERT_EQ(pt.get_child(at).front().second.get_value<string>(), aicn);

        ASSERT_EQ(pt.get<string>(ct), cc);

        ASSERT_EQ(pt.get<int>(ain), aiv);
        ASSERT_EQ(pt.get<double>(arn), arv);
        ASSERT_EQ(pt.get<string>(asn), asv);
    }
}

}//namespace rrboost
