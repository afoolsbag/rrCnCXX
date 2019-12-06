/// \copyright Unlicense

#include <iostream>
#include <thread>

#include <boost/asio.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

/// \brief 线程池
TEST(asio, thread_pool)
{
    boost::asio::thread_pool thread_pool{ 3 };

    const auto t = clock();

    const auto just_sleep = [&t]() {
        cout << this_thread::get_id() << " entry at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
        this_thread::sleep_for(100ms);
        cout << this_thread::get_id() << " leave at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    };

    cout << "main invoke at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    boost::asio::post(thread_pool, just_sleep);

    this_thread::sleep_for(10ms);
    cout << "main invoke at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    boost::asio::post(thread_pool, just_sleep);

    this_thread::sleep_for(10ms);
    cout << "main invoke at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    boost::asio::post(thread_pool, just_sleep);

    this_thread::sleep_for(10ms);
    cout << "main invoke at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    boost::asio::post(thread_pool, just_sleep);

    cout << "main wait at " << (clock() - t) / static_cast<double>(CLOCKS_PER_SEC) << '\n';
    thread_pool.join();
}

}
