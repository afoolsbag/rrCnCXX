/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include <check/check.h>
#include "rrWindows/rrWindows.h"

#include "test.h"

START_TEST(TestGenUuid)
{
    CONST size_t len = StringCchLengthS(GenerateUuid());
    ck_assert_int_eq(len, 36);
}
END_TEST

TCase *TCaseGenUuid(VOID)
{
    TCase *tcase = tcase_create("GenUuid");
    tcase_add_test(tcase, TestGenUuid);
    return tcase;
}
