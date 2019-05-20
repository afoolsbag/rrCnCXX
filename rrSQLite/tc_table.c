/**
 * \copyright Unlicense
 */

#include <stdio.h>

#include <check.h>
#include <sqlite3.h>

#include "ts.h"

static sqlite3 *db = NULL;

static void setup(void)
{
    if (sqlite3_open("test.sqlite3", &db) != SQLITE_OK)
        fprintf(stderr, "sqlite3_open failed: %s\n", sqlite3_errmsg(db));
}

static void teardown(void)
{
    if (sqlite3_close(db) != SQLITE_OK)
        fprintf(stderr, "sqlite3_close failed: %s\n", sqlite3_errmsg(db));
    db = NULL;
}

/**
 * \sa <https://sqlite.org/lang_createtable.html>
 * \sa <https://sqlite.org/lang_droptable.html>
 */
START_TEST(tf_create_and_drop)
{
    {
        const char sql[] =
            "CREATE TABLE test ("
            "    uuid BLOB PRIMARY KEY"
            ");";
        if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
            ck_abort_msg("sqlite3_exec failed: %s\n", sqlite3_errmsg(db));
    }
    {
        const char sql[] =
            "DROP TABLE test;";
        if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
            ck_abort_msg("sqlite3_exec failed: %s\n", sqlite3_errmsg(db));
    }
}
END_TEST;

/*
 * \sa <https://sqlite.org/autoinc.html>
 */
START_TEST(tf_autoincrement)
{
    {
        const char sql[] =
            "CREATE TABLE test ("
            "    id INTEGER PRIMARY KEY AUTOINCREMENT"
            ");";
        if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
            ck_abort_msg("sqlite3_exec failed: %s\n", sqlite3_errmsg(db));
    }
    {
        const char sql[] =
            "DROP TABLE test;";
        if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK)
            ck_abort_msg("sqlite3_exec failed: %s\n", sqlite3_errmsg(db));
    }
}
END_TEST;

TCase *tc_table(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_create_and_drop);
    tcase_add_test(tc, tf_autoincrement);
    return tc;
}
