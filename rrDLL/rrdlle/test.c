/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-05-13
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <rrdllc/lib.h>
#include <rrdllx/rrdllx.h>

START_TEST(tf_rrdllc_version)
{
    rrdllc_version_t v;
    ck_assert(rrdllc_get_version(&v) == rrdllc_success);
}
END_TEST;

START_TEST(tf_rrdllx_version)
{
    rrdllx_version_t v;
    ck_assert(rrdllx_get_version(&v) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_zstring)
{
    rrdllx_handle_t h = NULL;
    ck_assert(rrdllx_construct(&h) == rrdllx_success);

    rrdllx_zstring_t z;
    ck_assert(rrdllx_alloc_zstring(h, &z) == rrdllx_invalid_argument_reference_to_notnull);

    z = NULL;
    ck_assert(rrdllx_alloc_zstring(h, &z) == rrdllx_success);
    ck_assert(rrdllx_free_zstring(h, z) == rrdllx_success);

    ck_assert(rrdllx_free_zstring(h, z) == rrdllx_out_of_range_instance_zstring);

    ck_assert(rrdllx_destruct(h) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_zstring_array)
{
    rrdllx_handle_t h = NULL;
    ck_assert(rrdllx_construct(&h) == rrdllx_success);

    rrdllx_zstring_array_t za;
    ck_assert(rrdllx_alloc_zstring_array(h, &za) == rrdllx_invalid_argument_reference_to_notnull);

    za = NULL;
    ck_assert(rrdllx_alloc_zstring_array(h, &za) == rrdllx_success);
    ck_assert(rrdllx_free_zstring_array(h, za) == rrdllx_success);

    ck_assert(rrdllx_free_zstring_array(h, za) == rrdllx_out_of_range_instance_zstring_array);

    ck_assert(rrdllx_destruct(h) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_binary)
{
    rrdllx_handle_t h = NULL;
    ck_assert(rrdllx_construct(&h) == rrdllx_success);

    rrdllx_binary_t b;
    ck_assert(rrdllx_alloc_binary(h, &b) == rrdllx_invalid_argument_reference_to_notnull);

    b = NULL;
    ck_assert(rrdllx_alloc_binary(h, &b) == rrdllx_success);
    ck_assert(rrdllx_free_binary(h, b) == rrdllx_success);

    ck_assert(rrdllx_free_binary(h, b) == rrdllx_out_of_range_instance_binary);

    ck_assert(rrdllx_destruct(h) == rrdllx_success);
}
END_TEST;

TCase *tc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_set_timeout(tc, 0);
    tcase_add_test(tc, tf_rrdllc_version);
    tcase_add_test(tc, tf_rrdllx_version);
    tcase_add_test(tc, tf_rrdllx_zstring);
    tcase_add_test(tc, tf_rrdllx_zstring_array);
    tcase_add_test(tc, tf_rrdllx_binary);
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
