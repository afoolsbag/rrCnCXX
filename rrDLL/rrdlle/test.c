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
    struct rrdllx_version_t v;
    ck_assert(rrdllx_get_version(&v) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_zstring)
{
    static const rrdllx_zstring_t val = "wahyayayah";

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    rrdllx_zstring_t ztr;
    ck_assert(rrdllx_alloc_zstring(hdl, val, &ztr) == rrdllx_success);
    ck_assert_str_eq(ztr, val);
    ck_assert(rrdllx_free_zstring(hdl, ztr) == rrdllx_success);

    ck_assert(rrdllx_destruct(hdl) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_zstring_array)
{
    static const rrdllx_zstring_t val[] = {"str1", "str2", "str3"};
    static const size_t cnt = sizeof val / sizeof *val;

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    struct rrdllx_zstring_sarray_t ztrarr;
    ck_assert(rrdllx_alloc_zstring_array(hdl, val, cnt, &ztrarr) == rrdllx_success);
    ck_assert(rrdllx_free_zstring_array(hdl, ztrarr.data) == rrdllx_success);

    ck_assert(rrdllx_destruct(hdl) == rrdllx_success);
}
END_TEST;

START_TEST(tf_rrdllx_byte8_array)
{
    static const uint8_t val[] = "The binary value.";
    static const size_t siz = sizeof val;

    rrdllx_handle_t hdl = NULL;
    ck_assert(rrdllx_construct(&hdl) == rrdllx_success);

    struct rrdllx_byte8_sarray_t byte8arr;
    ck_assert(rrdllx_alloc_byte8_array(hdl, val, siz, &byte8arr) == rrdllx_success);
    ck_assert(rrdllx_free_byte8_array(hdl, byte8arr.data) == rrdllx_success);

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
    tcase_add_test(tc, tf_rrdllx_byte8_array);
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
