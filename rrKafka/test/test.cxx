//===-- Kafka Test ----------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-08-02
/// \since 2019-08-02
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <fstream>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "kafka.hxx"

using namespace std;

namespace rrkafka {

constexpr char broker_list[] {"172.16.0.27:9092, 172.16.0.28:9092, 172.16.0.29:9092"};
constexpr char topic[] {"test-cpp-1"};

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
    prod.produce({str.cbegin(), str.cend()});
}

TEST_F(kafka_test, consume)
{
    const auto[key, value] = cons.consume();
    cout << "consume:\n"
        "key=" << key.value_or("<null>") << "\n"
        "value=" << string {reinterpret_cast<const char *>(value.data()), value.size()} << '\n';
}

}
