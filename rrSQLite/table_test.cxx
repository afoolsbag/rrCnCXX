//===-- Table Test ----------------------------------------------*- C++ -*-===//
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

class TableTest :public testing::Test {
protected:
    static void SetUpTestCase()
    {
        sqlite3 *db {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_open("test.sqlite3", &db)) << sqlite3_errmsg(db);
        up_db.reset(db);
    }

    static void TearDownTestCase()
    {
        sqlite3 *db {up_db.release()};
        ASSERT_EQ(SQLITE_OK, sqlite3_close(db)) << sqlite3_errmsg(db);
    }

    static unique_ptr<sqlite3, decltype(&sqlite3_close)> up_db;
};
unique_ptr<sqlite3, decltype(&sqlite3_close)> TableTest::up_db {nullptr, &sqlite3_close};

/// \sa <https://sqlite.org/lang_createtable.html>
/// \sa <https://sqlite.org/lang_droptable.html>
TEST_F(TableTest, create_and_drop)
{
    {
        constexpr char stat_text[] {
            "CREATE TABLE test ( "
            "    uuid BLOB PRIMARY KEY "
            "); "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());
    }
    {
        constexpr char stat_text[] {
            "DROP TABLE test; "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());
    }
}

/// \sa <https://sqlite.org/autoinc.html>
TEST_F(TableTest, autoincrement)
{
    {
        constexpr char stat_text[] {
            "CREATE TABLE test ( "
            "    id INTEGER PRIMARY KEY AUTOINCREMENT "
            "); "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());
    }
    {
        constexpr char stat_text[] {
            "DROP TABLE test; "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());
    }
}

}
