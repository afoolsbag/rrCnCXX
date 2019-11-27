//===-- Row -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 行
///
/// \version 2019-11-27
/// \since 2018-05-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdio>
#include <cstdint>
#include <gsl/gsl>

#include <gtest/gtest.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

using namespace std;
using namespace gsl;

namespace rrsqlite {

static const struct data_t {
    int64_t id {-1};
    int64_t integer_column {666};
    double  real_column {2.7182818};
    char    text_column[255] {"SMT ZL JT"};
    uint8_t blob_column[4] {1, 3, 3, 7};
} data;

class row_test :public testing::Test {
protected:
    static void SetUpTestCase()
    {
        constexpr char stmt_text[] {
            "DROP TABLE IF EXISTS row_test_table; "
            " "
            "CREATE TABLE row_test_table ( "
            "    id             INTEGER PRIMARY KEY, "
            "    integer_column INTEGER, "
            "    real_column    REAL, "
            "    text_column    TEXT, "
            "    blob_column    BLOB "
            "); "};

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
unique_ptr<sqlite3, decltype(&sqlite3_close)> row_test::sqlite3_db {nullptr, &sqlite3_close};
unique_ptr<SQLite::Database> row_test::sqlitecpp_db {nullptr};

/// \sa [INSERT](https://sqlite.org/lang_insert.html)
TEST_F(row_test, insert)
{
    constexpr char stmt_text[] {
        "INSERT INTO row_test_table (integer_column, real_column, text_column, blob_column) "
        "VALUES (?1, ?2, ?3, ?4); "};

    /*sqlite3*/ {
        sqlite3_stmt *stmt {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(sqlite3_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(sqlite3_db.get());

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, data.integer_column)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_double(stmt, 2, data.real_column)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_text(stmt, 3, data.text_column, -1, SQLITE_TRANSIENT)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_blob(stmt, 4, data.blob_column, sizeof(data.blob_column), SQLITE_TRANSIENT)) << sqlite3_errmsg(sqlite3_db.get());

            ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(sqlite3_db.get());

            ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(sqlite3_db.get());
        }

        ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(sqlite3_db.get());
    }

    /*sqlitecpp*/ {
        SQLite::Statement stmt(*sqlitecpp_db, stmt_text);

        for (index i = 0; i < 5; ++i) {
            stmt.bind(1, data.integer_column);
            stmt.bind(2, data.real_column);
            stmt.bind(3, data.text_column);
            stmt.bind(4, data.blob_column, sizeof(data.blob_column));
            stmt.exec();
            stmt.reset();
        }
    }
}

/// \sa [SELECT](https://sqlite.org/lang_select.html)
TEST_F(row_test, select)
{
    constexpr char stmt_text[] {
        "SELECT id, integer_column, real_column, text_column, blob_column "
        "  FROM row_test_table; "};

    /*sqlite3*/ {
        sqlite3_stmt *stmt {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(sqlite3_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(sqlite3_db.get());

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            data_t row {};

            //row.id = sqlite3_column_int64(stmt, 0);

            row.integer_column = sqlite3_column_int64(stmt, 1);
            ASSERT_EQ(data.integer_column, row.integer_column);

            row.real_column = sqlite3_column_double(stmt, 2);
            ASSERT_DOUBLE_EQ(data.real_column, row.real_column);

            memcpy(row.text_column, sqlite3_column_text(stmt, 3), sqlite3_column_bytes(stmt, 3));
            row.text_column[sqlite3_column_bytes(stmt, 3)] = '\0';
            ASSERT_STREQ(data.text_column, row.text_column);

            memcpy(row.blob_column, sqlite3_column_blob(stmt, 4), sqlite3_column_bytes(stmt, 4));
        }

        ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(sqlite3_db.get());
    }

    /*sqlitecpp*/ {
        SQLite::Statement stmt(*sqlitecpp_db, stmt_text);

        while (stmt.executeStep()) {
            data_t row {};

            //row.id = sqlite3_column_int64(stmt, 0);

            row.integer_column = stmt.getColumn(1);
            ASSERT_EQ(data.integer_column, row.integer_column);

            row.real_column = stmt.getColumn(2);
            ASSERT_DOUBLE_EQ(data.real_column, row.real_column);

            memcpy(row.text_column, stmt.getColumn(3).getText(), stmt.getColumn(3).getBytes());
            row.text_column[stmt.getColumn(3).getBytes()] = '\0';
            ASSERT_STREQ(data.text_column, row.text_column);

            memcpy(row.blob_column, stmt.getColumn(4).getBlob(), stmt.getColumn(4).getBytes());
        }
    }

}

/// \sa [UPDATE](https://sqlite.org/lang_update.html)
TEST_F(row_test, update)
{
    constexpr char stmt_text[] {
        "UPDATE row_test_table "
        "   SET integer_column = ?1, "
        "       real_column = ?2, "
        "       text_column = ?3, "
        "       blob_column = ?4 "
        " WHERE id = ?5; "};

    /*sqlite3*/ {
        sqlite3_stmt *stmt {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(sqlite3_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
        for (int i = 0; i < 1; ++i) {
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, data.integer_column)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_double(stmt, 2, data.real_column)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_text(stmt, 3, data.text_column, -1, SQLITE_TRANSIENT)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_blob(stmt, 4, data.blob_column, sizeof(data.blob_column), SQLITE_TRANSIENT)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 5, 1)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(sqlite3_db.get());
        }
        ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(sqlite3_db.get());
    }

    /*sqlitecpp*/ {
        SQLite::Statement stmt(*sqlitecpp_db, stmt_text);
        for (index i = 0; i < 1; ++i) {
            stmt.bind(1, data.integer_column);
            stmt.bind(2, data.real_column);
            stmt.bind(3, data.text_column);
            stmt.bind(4, data.blob_column, sizeof(data.blob_column));
            stmt.bind(5, 1);
            stmt.exec();
            stmt.reset();
        }
    }
}

/// \sa [DELETE](https://sqlite.org/lang_delete.html)
TEST_F(row_test, delete)
{
    constexpr char stmt_text[] {
        "DELETE FROM row_test_table "
        " WHERE id = ?1; "};

    /*sqlite3*/ {
        sqlite3_stmt *stmt {nullptr};
        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(sqlite3_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(sqlite3_db.get());
        for (int i = 0; i < 1; ++i) {
            ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, 1)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(sqlite3_db.get());
            ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(sqlite3_db.get());
        }
        ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(sqlite3_db.get());
    }

    /*sqlitecpp*/ {
        SQLite::Statement stmt(*sqlitecpp_db, stmt_text);
        for (index i = 0; i < 1; ++i) {
            stmt.bind(1, 1);
            stmt.exec();
            stmt.reset();
        }
    }
}

}
