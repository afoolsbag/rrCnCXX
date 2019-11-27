//===-- Table ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 表
///
/// \version 2019-10-21
/// \since 2018-05-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>

#include <gtest/gtest.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

using namespace std;

namespace rrsqlite {

class table_test : public testing::Test {
protected:
    static void SetUpTestCase()
    {
        constexpr char stmt_text[] {"DROP TABLE IF EXISTS table_test_table; "};

        /*sqlite3*/ {
            {
                sqlite3 *p {nullptr};
                ASSERT_EQ(SQLITE_OK, sqlite3_open("rrsqlite3.sqlite3", &p)) << sqlite3_errmsg(p);
                sqlite3_db.reset(p);
            }
            ASSERT_EQ(SQLITE_OK, sqlite3_exec(sqlite3_db.get(), stmt_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
        }

        /*sqlitecpp*/ {
            sqlitecpp_db = make_unique<SQLite::Database>("rrsqlitecpp.sqlite3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
            sqlitecpp_db->exec(stmt_text);
        }

    }
    static void TearDownTestCase()
    {
        /*sqlite3*/ {
            sqlite3 *p {sqlite3_db.release()};
            ASSERT_EQ(SQLITE_OK, sqlite3_close(p)) << sqlite3_errmsg(p);
        }

        /*sqlitecpp*/ {
            sqlitecpp_db.reset();
        }
    }
    static unique_ptr<sqlite3, decltype(&sqlite3_close)> sqlite3_db;
    static unique_ptr<SQLite::Database> sqlitecpp_db;
};
unique_ptr<sqlite3, decltype(&sqlite3_close)> table_test::sqlite3_db {nullptr, &sqlite3_close};
unique_ptr<SQLite::Database> table_test::sqlitecpp_db {nullptr};

/// \sa [`CREATE TABLE`](https://sqlite.org/lang_createtable.html)
/// \sa [`DROP TABLE`](https://sqlite.org/lang_droptable.html)
TEST_F(table_test, create_and_drop)
{
    {
        constexpr char stmt_text[] {
            "CREATE TABLE table_test_table ( "
            "    uuid BLOB PRIMARY KEY "
            "); "};

        /*sqlite3*/ {
            ASSERT_EQ(SQLITE_OK, sqlite3_exec(sqlite3_db.get(), stmt_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
        }

        /*sqlitecpp*/ {
            sqlitecpp_db->exec(stmt_text);
        }
    }

    {
        constexpr char stat_text[] {
            "DROP TABLE table_test_table; "};

        /*sqlite3*/ {
            ASSERT_EQ(SQLITE_OK, sqlite3_exec(sqlite3_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
        }

        /*sqlitecpp*/ {
            sqlitecpp_db->exec(stat_text);
        }
    }
}

/// \sa [SQLite Autoincrement](https://sqlite.org/autoinc.html)
/// \sa [Datatypes In SQLite Version 3](https://sqlite.org/datatype3.html)
TEST_F(table_test, autoincrement)
{
    constexpr char stmt_text[] {
        "CREATE TABLE table_test_table ( "
        "    id INTEGER PRIMARY KEY AUTOINCREMENT "
        "); "};

    /*sqlite3*/ {
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(sqlite3_db.get(), stmt_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
    }

    /*sqlitecpp*/ {
        sqlitecpp_db->exec(stmt_text);
    }
}

}
