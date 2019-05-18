/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-05-18
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
    static const rrdllx_zstring_t val = "wahyayayah";

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    rrdllx_zstring_t ztr;
    ck_assert(rrdllx_alloc_zstring(hdl, val, &ztr) == rrdllx_dereference_not_initialized);
    ztr = NULL;
    ck_assert(rrdllx_alloc_zstring(hdl, val, &ztr) == rrdllx_success);

    ck_assert(rrdllx_free_zstring(hdl, ztr) == rrdllx_success);
    ck_assert(rrdllx_free_zstring(hdl, ztr) == rrdllx_instance_zstring_not_found);

    ck_assert(rrdllx_destruct(hdl) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_zstring_array)
{
    static const rrdllx_zstring_t val[] = {"str1", "str2", "str3"};
    static const size_t cnt = sizeof val / sizeof *val;

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    rrdllx_zstring_array_t ztr_arr;
    ck_assert(rrdllx_alloc_zstring_array(hdl, val, cnt, &ztr_arr) == rrdllx_dereference_not_initialized);
    ztr_arr = NULL;
    ck_assert(rrdllx_alloc_zstring_array(hdl, val, cnt, &ztr_arr) == rrdllx_success);

    ck_assert(rrdllx_free_zstring_array(hdl, ztr_arr) == rrdllx_success);
    ck_assert(rrdllx_free_zstring_array(hdl, ztr_arr) == rrdllx_instance_zstring_array_not_found);

    ck_assert(rrdllx_destruct(hdl) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_binary)
{
    static const uint8_t val[] = "The binary value.";
    static const size_t siz = sizeof val;

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    rrdllx_binary_t bin;
    ck_assert(rrdllx_alloc_binary(hdl, val, siz, &bin) == rrdllx_dereference_not_initialized);
    bin = NULL;
    ck_assert(rrdllx_alloc_binary(hdl, val, siz, &bin) == rrdllx_success);

    ck_assert(rrdllx_free_binary(hdl, bin) == rrdllx_success);
    ck_assert(rrdllx_free_binary(hdl, bin) == rrdllx_instance_binary_not_found);

    ck_assert(rrdllx_destruct(hdl) == rrdllx_success);
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
