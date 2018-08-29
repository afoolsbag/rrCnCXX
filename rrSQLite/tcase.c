#include <stdio.h>

#include <check/check.h>
#include <sqlite3/sqlite3.h>

#include "tsuite.h"

#define RAWSCOUNT 5
char uuids[RAWSCOUNT][37] = {
    "61ac05cb-0e56-4061-a938-cc327306c5ad",
    "b5f2cb91-554f-4f72-8c96-f79da287f805",
    "49b46d77-0cd5-4ec0-b35b-e1a1481b0f97",
    "1f53b67f-2e06-4283-96bb-610e164b91bb",
    "3afcbdae-79c8-4d4f-9a57-6be7812597b3"
};
char paths[RAWSCOUNT][14] = {
    "path/to/file1",
    "path/to/file2",
    "path/to/file3",
    "path/to/file4",
    "path/to/file5"
};

static sqlite3 *db;

/**
 * \remarks 不论成功与否，在句柄打开后，都应将其关闭。
 * \sa <https://sqlite.org/c3ref/open.html>
 */
START_TEST(test_open)
{
    if (SQLITE_OK != sqlite3_open("test.sqlite", &db)) {
        fprintf(stderr, "sqlite3_open failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/c3ref/exec.html>
 */
START_TEST(test_create_table)
{
    const char sql[] =
        "CREATE TABLE IF NOT EXISTS processing ("
        "    uuid TEXT PRIMARY KEY,"
        "    path TEXT NOT NULL"
        ");";

    char *msg;
    if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &msg)) {
        fprintf(stderr, "sqlite3_exec failed: %s\n", msg);
        sqlite3_free(msg);
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_insert.html>
 */
START_TEST(test_insert)
{
    sqlite3_stmt *stmt;

    const char sql[] =
        "INSERT OR IGNORE INTO processing(uuid, path)"
        "VALUES (?1, ?2);";
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fprintf(stderr, "sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }

    for (int i = 0; i < RAWSCOUNT; ++i) {
        if (SQLITE_OK != sqlite3_bind_text(stmt, 1, uuids[i], -1, SQLITE_TRANSIENT)) {
            fprintf(stderr, "sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }
        if (SQLITE_OK != sqlite3_bind_text(stmt, 2, paths[i], -1, SQLITE_TRANSIENT)) {
            fprintf(stderr, "sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        if (SQLITE_DONE != sqlite3_step(stmt)) {
            fprintf(stderr, "sqlite3_step failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        if (SQLITE_OK != sqlite3_reset(stmt)) {
            fprintf(stderr, "sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }
    }

    if (SQLITE_OK != sqlite3_finalize(stmt)) {
        fprintf(stderr, "sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_select.html>
 */
START_TEST(test_select_while)
{
    sqlite3_stmt *stmt;

    const char sql[] =
        "SELECT uuid, path"
        "  FROM processing"
        " WHERE uuid = ?1;";
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fprintf(stderr, "sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }

    for (int i = 0; i < RAWSCOUNT; ++i) {
        if (SQLITE_OK != sqlite3_bind_text(stmt, 1, uuids[i], -1, SQLITE_TRANSIENT)) {
            fprintf(stderr, "sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        if (SQLITE_ROW != sqlite3_step(stmt)) {
            fprintf(stderr, "sqlite3_step failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        const char *path = (char *)sqlite3_column_text(stmt, 1);
        ck_assert_str_eq(path, paths[i]);

        if (SQLITE_OK != sqlite3_reset(stmt)) {
            fprintf(stderr, "sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }
    }

    if (SQLITE_OK != sqlite3_finalize(stmt)) {
        fprintf(stderr, "sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_select.html>
 */
START_TEST(test_select)
{
    sqlite3_stmt *stmt;

    const char sql[] =
        "SELECT uuid, path"
        "  FROM processing;";
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fprintf(stderr, "sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }

    while (SQLITE_ROW == sqlite3_step(stmt)) {
        const char *uuid = (char *)sqlite3_column_text(stmt, 0);
        const char *path = (char *)sqlite3_column_text(stmt, 1);
        ((void)uuid);
        ((void)path);
    }

    if (SQLITE_OK != sqlite3_finalize(stmt)) {
        fprintf(stderr, "sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/lang_delete.html>
 */
START_TEST(test_delete_while)
{
    sqlite3_stmt *stmt;

    const char sql[] =
        "DELETE FROM processing"
        " WHERE uuid = ?1;";
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fprintf(stderr, "sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }

    for (int i = 0; i < RAWSCOUNT; ++i) {
        if (SQLITE_OK != sqlite3_bind_text(stmt, 1, uuids[i], -1, SQLITE_TRANSIENT)) {
            fprintf(stderr, "sqlite3_bind_text failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        if (SQLITE_DONE != sqlite3_step(stmt)) {
            fprintf(stderr, "sqlite3_step failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }

        if (SQLITE_OK != sqlite3_reset(stmt)) {
            fprintf(stderr, "sqlite3_reset failed: %s\n", sqlite3_errmsg(db));
            ck_abort();
        }
    }

    if (SQLITE_OK != sqlite3_finalize(stmt)) {
        fprintf(stderr, "sqlite3_finalize failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST;

/**
 * \sa <https://sqlite.org/c3ref/close.html>
 */
START_TEST(test_close)
{
    if (SQLITE_OK != sqlite3_close(db)) {
        fprintf(stderr, "sqlite3_close failed: %s\n", sqlite3_errmsg(db));
        ck_abort();
    }
}
END_TEST

TCase *tcase(void)
{
    TCase *tcase = tcase_create("tcase");
    tcase_add_test(tcase, test_open);
    tcase_add_test(tcase, test_create_table);
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_select_while);
    tcase_add_test(tcase, test_select);
    tcase_add_test(tcase, test_delete_while);
    tcase_add_test(tcase, test_close);
    return tcase;
}
