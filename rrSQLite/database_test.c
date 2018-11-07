#include <check/check.h>
#include <sqlite3.h>

#include "_test.h"

/**
 * \remarks 不论成功与否，在句柄打开后，都应将其关闭。
 * \sa <https://sqlite.org/c3ref/open.html>
 * \sa <https://sqlite.org/c3ref/close.html>
 */
START_TEST(tf_open_and_close)
{
    sqlite3 *db = NULL;
    if (sqlite3_open("test.sqlite", &db) != SQLITE_OK)
        ck_abort_msg("sqlite3_open failed: %s\n", sqlite3_errmsg(db));

    if (sqlite3_close(db) != SQLITE_OK)
        ck_abort_msg("sqlite3_close failed: %s\n", sqlite3_errmsg(db));
    db = NULL;
}
END_TEST

TCase *tc_database(void)
{
    TCase *const tc = tcase_create("database");
    tcase_add_test(tc, tf_open_and_close);
    return tc;
}
