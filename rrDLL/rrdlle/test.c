/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-05-10
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <rrdllc/lib.h>
#include <rrdllx/lib.h>

START_TEST(tf_rrdllc_version)
{
    rrdllc_version_t v;
    ck_assert(rrdllc_version(&v) == rrdllc_success);
}
END_TEST;

START_TEST(tf_rrdllx_version)
{
    rrdllx_version_t v;
    ck_assert(rrdllx_version(&v) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_string)
{
    rrdllx_handle_t h = NULL;
    ck_assert(rrdllx_construct(&h) == rrdllx_success);

    rrdllx_string_t s;
    ck_assert(rrdllx_alloc_string(h, NULL, &s) == rrdllx_invalid_argument);

    s = NULL;
    ck_assert(rrdllx_alloc_string(h, NULL, &s) == rrdllx_success);
    ck_assert(rrdllx_free_string(h, s) == rrdllx_success);

    ck_assert(rrdllx_free_string(h, s) == rrdllx_out_of_range);

    rrdllx_destruct(h);
}
END_TEST;

START_TEST(tf_rrdllx_string_array)
{
    rrdllx_handle_t h = NULL;
    ck_assert(rrdllx_construct(&h) == rrdllx_success);

    rrdllx_string_array_t a;
    ck_assert(rrdllx_alloc_string_array(h, 20, &a) == rrdllx_invalid_argument);

    a = NULL;
    ck_assert(rrdllx_alloc_string_array(h, 20, &a) == rrdllx_success);
    ck_assert(rrdllx_free_string_array(h, a) == rrdllx_success);

    ck_assert(rrdllx_free_string_array(h, a) == rrdllx_out_of_range);

    rrdllx_destruct(h);
}
END_TEST;

TCase *tc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_set_timeout(tc, 0);
    tcase_add_test(tc, tf_rrdllc_version);
    tcase_add_test(tc, tf_rrdllx_version);
    tcase_add_test(tc, tf_rrdllx_string);
    tcase_add_test(tc, tf_rrdllx_string_array);
    return tc;
}

static Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc());
    return ts;
}

int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_add_suite(tr, ts());
    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
