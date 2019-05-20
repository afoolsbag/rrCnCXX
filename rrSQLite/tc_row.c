/**
 * \copyright Unlicense
 */

#include <stdio.h>
#include <stdint.h>

#include <check.h>
#include <sqlite3.h>

#include "ts.h"

static sqlite3 *db = NULL;

static void setup(void)
{
    if (sqlite3_open("test.sqlite3", &db) != SQLITE_OK)
        fprintf(stderr, "sqlite3_open failed: %s\n", sqlite3_errmsg(db));

    const char sql[] =
        "DROP TABLE IF EXISTS test;"
        "CREATE TABLE test ("
        "    id     INTEGER PRIMARY KEY,"
        "    texval TEXT,"
        "    numval NUMERIC,"
        "    reaval REAL,"
        "    intval INTEGER,"
        "    bloval BLOB"
        ");";
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
        fprintf(stderr, "sqlite3_exec failed: %s\n", sqlite3_errmsg(db));
}

struct data {
    char    texval[5];
    char    numval[5];
    double  reaval;
    int64_t intval;
    uint8_t bloval[5];
};

/**
 * \sa <https://sqlite.org/lang_insert.html>
 */
START_TEST(tf_insert)
{
    sqlite3_stmt *stmt = NULL;
    const char sql[] =
        "INSERT INTO test (texval, numval, reaval, intval, bloval)"
        "VALUES (?1, ?2, ?3, ?4, ?5);";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        ck_abort_msg("sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));

    for (int i = 0; i < 1; ++i) {
        struct data data;
        memcpy(data.texval, "test", 5);
        memcpy(data.numval, "1337", 5);
        data.reaval = 2.7182818;
        data.intval = 1337;
        memset(data.bloval, 0, 5);

        if (sqlite3_bind_text(stmt, 1, data.texval, -1, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_text(stmt, 2, data.numval, -1, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_double(stmt, 3, data.reaval) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_double failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_int64(stmt, 4, data.intval) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_int64 failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_blob(stmt, 5, data.bloval, 5, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_blob failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_step(stmt) != SQLITE_DONE)
            ck_abort_msg("sqlite3_step failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_reset(stmt) != SQLITE_OK)
            ck_abort_msg("sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
    }

    if (sqlite3_finalize(stmt) != SQLITE_OK)
        ck_abort_msg("sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
    stmt = NULL;
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_select.html>
 */
START_TEST(tf_select)
{
    sqlite3_stmt *stmt = NULL;
    const char sql[] =
        "SELECT id, texval, numval, reaval, intval, bloval"
        "  FROM test;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        ck_abort_msg("sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const int64_t id = sqlite3_column_int64(stmt, 0);
        ck_assert_int_eq(id, 1);

        struct data data;
        memcpy(data.texval, sqlite3_column_text(stmt, 1), sqlite3_column_bytes(stmt, 1));
        data.texval[4] = '\0';
        memcpy(data.numval, sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2));
        data.numval[4] = '\0';
        data.reaval = sqlite3_column_double(stmt, 3);
        data.intval = sqlite3_column_int64(stmt, 4);
        memcpy(data.bloval, sqlite3_column_blob(stmt, 5), sqlite3_column_bytes(stmt, 5));

        ck_assert_str_eq(data.texval, "test");
        ck_assert_str_eq(data.numval, "1337");
        ck_assert_double_eq(data.reaval, 2.7182818);
        ck_assert_int_eq(data.intval, 1337);
    }

    if (sqlite3_finalize(stmt) != SQLITE_OK)
        ck_abort_msg("sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
    stmt = NULL;
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_update.html>
 */
START_TEST(tf_update)
{
    sqlite3_stmt *stmt = NULL;
    const char sql[] =
        "UPDATE test"
        "   SET texval = ?1,"
        "       numval = ?2,"
        "       reaval = ?3,"
        "       intval = ?4,"
        "       bloval = ?5"
        " WHERE id = ?6;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        ck_abort_msg("sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));

    for (int i = 0; i < 1; ++i) {
        struct data data;
        memcpy(data.texval, "test", 5);
        memcpy(data.numval, "1337", 5);
        data.reaval = 2.7182818;
        data.intval = 1337;
        memset(data.bloval, 0, 5);

        if (sqlite3_bind_text(stmt, 1, data.texval, -1, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_text(stmt, 2, data.numval, -1, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_double(stmt, 3, data.reaval) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_double failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_int64(stmt, 4, data.intval) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_int64 failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_blob(stmt, 5, data.bloval, 5, SQLITE_TRANSIENT) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_blob failed: %s\n", sqlite3_errmsg(db));
        if (sqlite3_bind_int64(stmt, 6, 1) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_int64 failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_step(stmt) != SQLITE_DONE)
            ck_abort_msg("sqlite3_step failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_reset(stmt) != SQLITE_OK)
            ck_abort_msg("sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
    }

    if (sqlite3_finalize(stmt) != SQLITE_OK)
        ck_abort_msg("sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
    stmt = NULL;
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_delete.html>
 */
START_TEST(tf_delete)
{
    sqlite3_stmt *stmt = NULL;
    const char sql[] =
        "DELETE FROM test"
        " WHERE id = ?1;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        ck_abort_msg("sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));

    for (int i = 0; i < 1; ++i) {
        if (sqlite3_bind_int64(stmt, 1, 1) != SQLITE_OK)
            ck_abort_msg("sqlite3_bind_int64 failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_step(stmt) != SQLITE_DONE)
            ck_abort_msg("sqlite3_step failed: %s\n", sqlite3_errmsg(db));

        if (sqlite3_reset(stmt) != SQLITE_OK)
            ck_abort_msg("sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
    }

    if (sqlite3_finalize(stmt) != SQLITE_OK)
        ck_abort_msg("sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
    stmt = NULL;
}
END_TEST;

static void teardown(void)
{
    const char sql[] =
        "DROP TABLE IF EXISTS test;";
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
        fprintf(stderr, "sqlite3_exec failed: %s\n", sqlite3_errmsg(db));

    if (sqlite3_close(db) != SQLITE_OK)
        fprintf(stderr, "sqlite3_close failed: %s\n", sqlite3_errmsg(db));
    db = NULL;
}

TCase *tc_row(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_insert);
    tcase_add_test(tc, tf_select);
    tcase_add_test(tc, tf_update);
    tcase_add_test(tc, tf_delete);
    return tc;
}
