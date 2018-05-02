/** \copyright The MIT License */

#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/genuuid.h"

START_TEST(TestGenUuid)
{
    size_t len = 0;
    StringCchLength(GenerateUuid(), STRSAFE_MAX_CCH, &len);
    ck_assert_int_eq(len, 36);
}
END_TEST

TCase *TCaseGenUuid(VOID)
{
    TCase *tcase = tcase_create("GenUuid");
    tcase_add_test(tcase, TestGenUuid);
    return tcase;
}
