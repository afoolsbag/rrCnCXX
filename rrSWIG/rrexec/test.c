/*===-- rrexec -------------------------------------------------*- C -*-===*//**
 *
 * \version 2020-04-30
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <rrlibc/rrlibc.h>
#include <rrlibx/rrlibx.h>

/*==============================================================================
 * rrlibc
 *----------------------------------------------------------------------------*/

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

/*==============================================================================
 * rrlibx
 *----------------------------------------------------------------------------*/

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
    static const int in_value = 1337;
    ck_assert_int_eq(rrlibx_success, rrlibx_set_basic(tc_rrlibx_handle, in_value));

    int out_value = 0;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_basic(tc_rrlibx_handle, &out_value));

    ck_assert_int_eq(in_value, out_value);
}
END_TEST;

START_TEST(tf_rrlibx_array)
{
    static const uint8_t in_data[] = "SMT ZL JT";
    static const size_t in_size = sizeof in_data;
    ck_assert_int_eq(rrlibx_success, rrlibx_set_array(tc_rrlibx_handle, in_data, in_size));

    size_t out_size = 0;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_array(tc_rrlibx_handle, NULL, &out_size));
    ck_assert_int_eq(in_size, out_size);
    uint8_t *out_data = malloc(out_size);
    ck_assert_ptr_ne(NULL, out_data);
    ck_assert_int_eq(rrlibx_success, rrlibx_get_array(tc_rrlibx_handle, out_data, &out_size));
    ck_assert_mem_eq(in_data, out_data, min(in_size, out_size));
    free(out_data);

    const uint8_t *ref_data;
    size_t ref_size;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_array_cvr(tc_rrlibx_handle, &ref_data, &ref_size));
    ck_assert_mem_eq(in_data, ref_data, min(in_size, ref_size));
}
END_TEST;

START_TEST(tf_rrlibx_string)
{
    static const char in_string[] = "SMT ZL JT";
    ck_assert_int_eq(rrlibx_success, rrlibx_set_string(tc_rrlibx_handle, in_string));

    char out_string[rrlibx_string_fsb_size] = "\0";
    ck_assert_int_eq(rrlibx_success, rrlibx_get_string_fsb(tc_rrlibx_handle, out_string));
    ck_assert_str_eq(in_string, out_string);

    const char *ref_string;
    ck_assert_int_eq(rrlibx_success, rrlibx_get_string_cvr(tc_rrlibx_handle, &ref_string));
    ck_assert_str_eq(in_string, ref_string);
}
END_TEST;

static void CDECL callback(void *p_user_data)
{
    *(bool *)p_user_data = true;
}

START_TEST(tf_rrlx_callback)
{
    bool pass = false;
    rrlibx_set_callback(tc_rrlibx_handle, callback, &pass);
    rrlibx_invoke_callback(tc_rrlibx_handle);
    while (!pass)
        continue;
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
    tcase_add_test(tc, tf_rrlx_callback);
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
