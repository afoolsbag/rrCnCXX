/// \copyright Unlicense

#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

using namespace std;

namespace rrspdlog {

TEST(test, gft)
{
    constexpr char json[] {R"({"string":"this is a string","number":1337,"true":true,"false":false,"null":null,"array":[1,2,3,4,5,6,7],"object":{"k1":"v1","k2":"v2","k3":"v3"}})"};

    rapidjson::Document document;
    document.Parse(json);

    ASSERT_TRUE(document.HasMember("string"));
    ASSERT_FALSE(document.HasMember("not-exists"));

    ASSERT_TRUE(document["number"].IsNumber());
    ASSERT_FALSE(document["number"].IsString());

    ASSERT_TRUE(document["true"].GetBool());
    ASSERT_FALSE(document["false"].GetBool());

    ASSERT_TRUE(document.FindMember("null") != document.MemberEnd());

    rapidjson::StringBuffer buffer;
    //rapidjson::Writer writer {buffer};
    rapidjson::PrettyWriter writer {buffer};
    document.Accept(writer);

    cout << buffer.GetString() << '\n';
}

}
