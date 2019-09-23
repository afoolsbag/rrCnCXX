/// \copyright Unlicense

#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

using namespace std;

namespace rrspdlog {

TEST(test, gft)
{
    constexpr char json[] {R"({"string":"this is a string","number":1337,"true":true,"false":false,"null":null,"array":[1,2,3,4,5,6,7],"object":{"k1":"v1","k2":"v2","k3":"v3"}})"};

    auto j = nlohmann::json::parse(json);

    ASSERT_TRUE(j.contains("string"));
    ASSERT_FALSE(j.contains("not-exists"));

    ASSERT_TRUE(j["number"].is_number());
    ASSERT_FALSE(j["number"].is_string());

    ASSERT_TRUE(j["true"].get<bool>());
    ASSERT_FALSE(j["false"].get<bool>());

    cout << j.dump(2) << '\n';
}

}
