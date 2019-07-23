//===-- WebSocketPP Test ----------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-23
/// \since 2018-04-22
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#ifdef _MSC_VER
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif

#include <thread>

#include <gtest/gtest.h>

#include "client.hpp"
#include "server.hpp"

using namespace std;

namespace rrwebsocketpp {

TEST(case, test)
{
    thread svr_thrd {[] {
        try {
            server svr;
            svr.start();

        } catch (const websocketpp::exception &e) {
            cerr << "A exception occurred on the server thread function: " << e.what() << endl;

        } catch (const exception &e) {
            cerr << "A exception occurred on the server thread function: " << e.what() << endl;

        } catch (...) {
            cerr << "A exception occurred on the server thread function." << endl;

        }
    }};

    thread clt_thrd {[] {
        try {
            client clt;
            clt.start();

        } catch (const websocketpp::exception &e) {
            cerr << "A exception occurred on the client thread function: " << e.what() << endl;

        } catch (const exception &e) {
            cerr << "A exception occurred on the client thread function: " << e.what() << endl;

        } catch (...) {
            cerr << "A exception occurred on the client thread function." << endl;

        }
    }};

    clt_thrd.join();
    svr_thrd.join();
}

}
