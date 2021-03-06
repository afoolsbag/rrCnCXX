//===-- Kafka Test ----------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-11-25
/// \since 2019-08-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <fstream>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "rrkafka/rrkafka.hxx"

using namespace std;

namespace rrkafka {

constexpr char broker_list[] {"127.0.0.1:9092"};
constexpr char topic[] {"test-cpp"};

class kafka_test : public testing::Test {
protected:
    static producer prod;
    static kafka_consumer cons;
    static void SetUpTestCase()
    {}
    static void TearDownTestCase()
    {}
};
producer kafka_test::prod {broker_list, topic};
kafka_consumer kafka_test::cons {broker_list, topic};

TEST_F(kafka_test, produce)
{
    const auto str = "hello, world"s;
    prod.produce(str);
}

TEST_F(kafka_test, consume)
{
    for (; ; ) {
        const auto[key, value] = cons.consume();
        cout << "consume:\n";
        cout << "  key=" << key.value_or("<null>") << '\n';
        cout << "  value=" << string {reinterpret_cast<const char *>(value.data()), value.size()} << '\n';
    }
}

}
