//===-- Database Test -------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-08-01
/// \since 2018-05-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>

#include <gtest/gtest.h>
#include <sqlite3.h>

using namespace std;

namespace rrsqlite {

/// \remarks 不论成功与否，在句柄打开后，都应将其关闭。
/// \sa [Opening A New Database Connection](https://sqlite.org/c3ref/open.html)
/// \sa [Closing A Database Connection](https://sqlite.org/c3ref/close.html)
TEST(database, open_and_close)
{
    unique_ptr<sqlite3, decltype(&sqlite3_close)> db {nullptr, &sqlite3_close};

    {
        sqlite3 *p {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_open("test.sqlite3", &p)) << sqlite3_errmsg(p);
        db.reset(p);
    }

    {
        sqlite3 *p {db.release()};
        ASSERT_EQ(SQLITE_OK, sqlite3_close(p)) << sqlite3_errmsg(p);
    }
}

}
