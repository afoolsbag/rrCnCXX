//===-- Row Test ------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-22
/// \since 2018-05-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <stdint.h>

#include <gtest/gtest.h>
#include <sqlite3.h>

using namespace std;

namespace rrsqlite {

struct test_row {
    int64_t id;
    int64_t integer_column;
    double  real_column;
    char    text_column[255];
    uint8_t blob_column[4];
};

class RowTest :public testing::Test {
protected:
    static void SetUpTestCase()
    {
        {
            sqlite3 *db {nullptr};
            ASSERT_EQ(SQLITE_OK, sqlite3_open("test.sqlite3", &db)) << sqlite3_errmsg(db);
            up_db.reset(db);
        }

        constexpr char stat_text[] {
            "DROP TABLE IF EXISTS test; "
            "CREATE TABLE test ( "
            "    id             INTEGER PRIMARY KEY, "
            "    integer_column INTEGER, "
            "    real_column    REAL, "
            "    text_column    TEXT, "
            "    blob_column    BLOB "
            "); "};
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());
    }

    static void TearDownTestCase()
    {
        constexpr char stat_text[] =
            "DROP TABLE IF EXISTS test; ";
        ASSERT_EQ(SQLITE_OK, sqlite3_exec(up_db.get(), stat_text, nullptr, nullptr, nullptr)) << sqlite3_errmsg(up_db.get());

        {
            sqlite3 *db {up_db.release()};
            ASSERT_EQ(SQLITE_OK, sqlite3_close(db)) << sqlite3_errmsg(db);
        }
    }

    static unique_ptr<sqlite3, decltype(&sqlite3_close)> up_db;
    const static test_row td_row;
};
unique_ptr<sqlite3, decltype(&sqlite3_close)> RowTest::up_db {nullptr, &sqlite3_close};
const test_row RowTest::td_row {-1, 666, 2.7182818, "SMT ZL JT", {1, 3, 3, 7}};

/// \sa <https://sqlite.org/lang_insert.html>
TEST_F(RowTest, insert)
{
    constexpr char stmt_text[] {
        "INSERT INTO test (integer_column, real_column, text_column, blob_column) "
        "VALUES (?1, ?2, ?3, ?4); "};
    sqlite3_stmt *stmt {nullptr};
    ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(up_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(up_db.get());

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, td_row.integer_column)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_double(stmt, 2, td_row.real_column)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_text(stmt, 3, td_row.text_column, -1, SQLITE_TRANSIENT)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_blob(stmt, 4, td_row.blob_column, sizeof(td_row.blob_column), SQLITE_TRANSIENT)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(up_db.get());
    }

    ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(up_db.get());
}

/// \sa <https://sqlite.org/lang_select.html>
TEST_F(RowTest, select)
{
    constexpr char stmt_text[] {
        "SELECT id, integer_column, real_column, text_column, blob_column "
        "  FROM test; "};
    sqlite3_stmt *stmt {nullptr};
    ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(up_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(up_db.get());

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        test_row row;

        row.id = sqlite3_column_int64(stmt, 0);

        row.integer_column = sqlite3_column_int64(stmt, 1);
        ASSERT_EQ(td_row.integer_column, row.integer_column);

        row.real_column = sqlite3_column_double(stmt, 2);
        ASSERT_DOUBLE_EQ(td_row.real_column, row.real_column);

        memcpy(row.text_column, sqlite3_column_text(stmt, 3), sqlite3_column_bytes(stmt, 3));
        row.text_column[sqlite3_column_bytes(stmt, 3)] = '\0';
        ASSERT_STREQ(td_row.text_column, row.text_column);

        memcpy(row.blob_column, sqlite3_column_blob(stmt, 4), sqlite3_column_bytes(stmt, 4));
    }

    ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(up_db.get());
}

/// \sa <https://sqlite.org/lang_update.html>
TEST_F(RowTest, update)
{
    constexpr char stmt_text[] {
        "UPDATE test "
        "   SET integer_column = ?1, "
        "       real_column = ?2, "
        "       text_column = ?3, "
        "       blob_column = ?4 "
        " WHERE id = ?5; "};
    sqlite3_stmt *stmt {nullptr};
    ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(up_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(up_db.get());

    for (int i = 0; i < 1; ++i) {
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, td_row.integer_column)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_double(stmt, 2, td_row.real_column)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_text(stmt, 3, td_row.text_column, -1, SQLITE_TRANSIENT)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_blob(stmt, 4, td_row.blob_column, sizeof(td_row.blob_column), SQLITE_TRANSIENT)) << sqlite3_errmsg(up_db.get());
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 5, 1)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(up_db.get());
    }

    ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(up_db.get());
}

/// \sa <https://sqlite.org/lang_delete.html>
TEST_F(RowTest, tf_delete)
{
    constexpr char stmt_text[] {
        "DELETE FROM test "
        " WHERE id = ?1; "};
    sqlite3_stmt *stmt {nullptr};
    ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(up_db.get(), stmt_text, -1, &stmt, nullptr)) << sqlite3_errmsg(up_db.get());

    for (int i = 0; i < 1; ++i) {
        ASSERT_EQ(SQLITE_OK, sqlite3_bind_int64(stmt, 1, 1)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_DONE, sqlite3_step(stmt)) << sqlite3_errmsg(up_db.get());

        ASSERT_EQ(SQLITE_OK, sqlite3_reset(stmt)) << sqlite3_errmsg(up_db.get());
    }

    ASSERT_EQ(SQLITE_OK, sqlite3_finalize(stmt)) << sqlite3_errmsg(up_db.get());
}

}
