//===-- Database Test -------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-22
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
/// \sa <https://sqlite.org/c3ref/open.html>
/// \sa <https://sqlite.org/c3ref/close.html>
TEST(database, open_and_close)
{
    unique_ptr<sqlite3, decltype(&sqlite3_close)> up_db {nullptr, &sqlite3_close};

    {
        sqlite3 *db {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_open("test.sqlite3", &db)) << sqlite3_errmsg(db);
        up_db.reset(db);
    }

    {
        sqlite3 *db {up_db.release()};
        ASSERT_EQ(SQLITE_OK, sqlite3_close(db)) << sqlite3_errmsg(db);
    }
}

}
