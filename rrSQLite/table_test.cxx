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

class table_test :public testing::Test {
protected:
    static void SetUpTestCase()
    {
        {
            sqlite3 *p {nullptr};
            ASSERT_EQ(SQLITE_OK, sqlite3_open("test.sqlite3", &p)) << sqlite3_errmsg(p);
            db.reset(p);
        }

        constexpr char stat_text[] {"DROP TABLE IF EXISTS table_test_table; "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(db.get());
    }

    static void TearDownTestCase()
    {
        {
            sqlite3 *p {db.release()};
            ASSERT_EQ(SQLITE_OK, sqlite3_close(p)) << sqlite3_errmsg(p);
        }
    }

    static unique_ptr<sqlite3, decltype(&sqlite3_close)> db;
};
unique_ptr<sqlite3, decltype(&sqlite3_close)> table_test::db {nullptr, &sqlite3_close};

/// \sa [`CREATE TABLE`](https://sqlite.org/lang_createtable.html)
/// \sa [`DROP TABLE`](https://sqlite.org/lang_droptable.html)
TEST_F(table_test, create_and_drop)
{
    {
        constexpr char stat_text[] {
            "CREATE TABLE table_test_table ( "
            "    uuid BLOB PRIMARY KEY "
            "); "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(db.get());
    }

    {
        constexpr char stat_text[] {
            "DROP TABLE table_test_table; "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(db.get());
    }
}

/// \sa [SQLite Autoincrement](https://sqlite.org/autoinc.html)
/// \sa [Datatypes In SQLite Version 3](https://sqlite.org/datatype3.html)
TEST_F(table_test, autoincrement)
{
    {
        constexpr char stat_text[] {
            "CREATE TABLE table_test_table ( "
            "    id INTEGER PRIMARY KEY AUTOINCREMENT "
            "); "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(db.get());
    }
}

}
