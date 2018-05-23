#include <check/check.h>
#include <sqlite3/sqlite3.h>

#include "tsuite.h"

START_TEST(test_create_database)
{

}
END_TEST

TCase *tcase(void)
{
    TCase *tcase = tcase_create("tcase");
    tcase_add_test(tcase, test_create_database);
    return tcase;
}
