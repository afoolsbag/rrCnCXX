/// \copyright Unlicense

#include <cfloat>
#include <climits>
#include <clocale>
#include <cstdio>
#include <thread>

#include <Ice/Ice.h>
#include <gtest/gtest.h>

#include "Service.h"
#include "ServiceImpl.h"

using namespace std;

namespace {
bool serverThreadFlag = true;
void serverThreadFunction(int argc, char *argv[])
{
    try {
        const auto clk = clock();

        // 通讯器
        Ice::CommunicatorHolder ich {argc, argv};

        // 适配器
        auto adapter = ich->createObjectAdapterWithEndpoints("LocalHost", "default -p 10000");

        // 侍从
        const auto servant = make_shared<rrIce::ServiceImpl>();
        adapter->add(servant, Ice::stringToIdentity(rrIce::Identifier));

        adapter->activate();

        printf("SERVER INITIALIZE COST %lfs\n", (clock() - clk) / static_cast<double>(CLOCKS_PER_SEC));

        while (serverThreadFlag)
            this_thread::sleep_for(1s);

    } catch (...) {

        throw;
    }
}
}

namespace rrIce {

class Test : public testing::Test {
protected:
    static void SetUpTestCase()
    {
        // SYSTEM
        setlocale(LC_ALL, ".UTF-8");
        system("CHCP 65001");

        // SERVER
        if (serverThread.joinable()) {
            serverThreadFlag = false;
            serverThread.join();
        }

        serverThreadFlag = true;
        serverThread = thread {serverThreadFunction, __argc, __argv};

        // CLIENT
        const auto clk = clock();
        // 通讯器
        ich = Ice::CommunicatorHolder {__argc, __argv};
        // 代理
        const auto proxy = ich->stringToProxy(Identifier + ":default -p 10000 -t 5000");
        // 服务
        service = Ice::checkedCast<ServicePrx>(proxy);
        if (!service)
            throw runtime_error("invalid proxy");
        printf("CLIENT INITIALIZE COST %lfs\n", (clock() - clk) / static_cast<double>(CLOCKS_PER_SEC));
    }

    static void TearDownTestCase()
    {
        if (serverThread.joinable()) {
            serverThreadFlag = false;
            serverThread.join();
        }
    }

    static thread serverThread;
    static Ice::CommunicatorHolder ich;
    static shared_ptr<ServicePrx> service;
};
thread Test::serverThread {};
Ice::CommunicatorHolder Test::ich {};
shared_ptr<ServicePrx> Test::service {};

TEST_F(Test, echoBool)
{
    constexpr bool expected {true};
    ASSERT_EQ(expected, service->echoBool(expected));
}

TEST_F(Test, echoByte)
{
    constexpr Ice::Byte expected {'x'};
    ASSERT_EQ(expected, service->echoByte(expected));
}

TEST_F(Test, echoShort)
{
    constexpr short expected {SHRT_MAX};
    ASSERT_EQ(expected, service->echoShort(expected));
}

TEST_F(Test, echoInt)
{
    constexpr int expected {INT_MAX};
    ASSERT_EQ(expected, service->echoInt(expected));
}

TEST_F(Test, echoLong)
{
    constexpr long long expected {LLONG_MAX};
    ASSERT_EQ(expected, service->echoLong(expected));
}

TEST_F(Test, echoFloat)
{
    constexpr float expected {FLT_MAX};
    ASSERT_EQ(expected, service->echoFloat(expected));
}

TEST_F(Test, echoDouble)
{
    constexpr double expected {DBL_MAX};
    ASSERT_EQ(expected, service->echoDouble(expected));
}

TEST_F(Test, echoString)
{
    constexpr char expected[] {"777"};
    ASSERT_EQ(expected, service->echoString(expected));
}

TEST_F(Test, echoEnum)
{
    constexpr CustomEnum expected {CustomEnum::ZL};
    ASSERT_EQ(expected, service->echoEnum(expected));
}

TEST_F(Test, echoStruct)
{
    constexpr CustomStruct expected {true, true, true};
    ASSERT_EQ(expected, service->echoStruct(expected));
}

TEST_F(Test, echoSequence)
{
    const CustomSequence expected {1, 2, 3, 4, 5, 6, 7};
    ASSERT_EQ(expected, service->echoSequence(expected));
}

TEST_F(Test, echoDictionary)
{
    const CustomDictionary expected {};
    ASSERT_EQ(expected, service->echoDictionary(expected));
}

TEST_F(Test, setNumber)
{
    constexpr int expected {INT_MAX};
    service->setNumber(expected);
}

TEST_F(Test, optNumber)
{
    constexpr int expected {INT_MAX};
    Ice::optional<int> outValue {Ice::nullopt};
    ASSERT_EQ(expected, service->optNumber(expected, outValue));
}

TEST_F(Test, getNumber)
{
    constexpr int expected {INT_MAX};
    int outValue;
    service->getNumber(outValue);
    ASSERT_EQ(expected, outValue);
}

TEST_F(Test, throwException)
{
    ASSERT_THROW(service->throwException(), Exception);
}

}
