/*===-- rrExeC -------------------------------------------------*- C -*-===*//**
 *
 * \version 2019-06-20
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <rrlibc/rrlibc.h>
#include <rrlibx/rrlibx.h>

START_TEST(tf_rrlibc_version)
{
    ck_assert_int_eq(rrlibc_success, rrlibc_get_version(NULL, NULL, NULL, NULL));
}
END_TEST;

static TCase *tc_rrlibc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_rrlibc_version);
    return tc;
}

static rrlibx_handle_t tc_rrlibx_handle = NULL;

static void tc_rrlibx_setup(void)
{
    ck_assert_ptr_eq(NULL, tc_rrlibx_handle);
    ck_assert_int_eq(rrlibx_success, rrlibx_construct(&tc_rrlibx_handle));
    ck_assert_ptr_ne(NULL, tc_rrlibx_handle);
}

static void tc_rrlibx_teardown(void)
{
    ck_assert_ptr_ne(NULL, tc_rrlibx_handle);
    ck_assert_int_eq(rrlibx_success, rrlibx_destruct(tc_rrlibx_handle));
}

START_TEST(tf_rrlibx_version)
{
    ck_assert_int_eq(rrlibx_success, rrlibx_get_version(NULL, NULL, NULL, NULL));
}
END_TEST;

START_TEST(tf_rrlibx_basic)
{
    static const int invalue = 1337;
    ck_assert_int_eq(rrlibx_success, rrlibx_set_basic(tc_rrlibx_handle, invalue));

    int outvalue = 0;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_basic(tc_rrlibx_handle, &outvalue));

    ck_assert_int_eq(invalue, outvalue);
}
END_TEST;

START_TEST(tf_rrlibx_array)
{
    static const uint8_t indata[] = "wahyayayah";
    static const size_t insize = sizeof indata;
    ck_assert_int_eq(rrlibx_success, rrlibx_set_array(tc_rrlibx_handle, indata, insize));

    size_t outsize = 0;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_array(tc_rrlibx_handle, NULL, &outsize));
    ck_assert_int_eq(insize, outsize);

    uint8_t *outdata = malloc(outsize);
    ck_assert_ptr_ne(NULL, outdata);
    ck_assert_int_eq(rrlibx_success, rrlibx_get_array(tc_rrlibx_handle, outdata, &outsize));

    ck_assert_mem_eq(indata, outdata, insize);
    free(outdata);
}
END_TEST;

START_TEST(tf_rrlibx_string)
{
    static const char instring[] = "wahyayayah";
    ck_assert_int_eq(rrlibx_success, rrlibx_set_string(tc_rrlibx_handle, instring));

    char outstring[rrlibx_string_fixed_size] = "\0";
    ck_assert_int_eq(rrlibx_success, rrlibx_get_string_fixed_size(tc_rrlibx_handle, outstring));

    ck_assert_str_eq(instring, outstring);
}
END_TEST;

static TCase *tc_rrlibx(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, tc_rrlibx_setup, tc_rrlibx_teardown);
    tcase_add_test(tc, tf_rrlibx_version);
    tcase_add_test(tc, tf_rrlibx_basic);
    tcase_add_test(tc, tf_rrlibx_array);
    tcase_add_test(tc, tf_rrlibx_string);
    return tc;
}

static Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_rrlibc());
    suite_add_tcase(ts, tc_rrlibx());
    return ts;
}

int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_set_fork_status(tr, CK_NOFORK);
    srunner_add_suite(tr, ts());
    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
