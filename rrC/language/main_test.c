/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gMain 主函数
 * \ingroup gLang
 *
 * \version 2018-11-27
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "algorithms/_test.h"
#include "atomic_operations/_test.h"
#include "date_and_time_utilities/_test.h"
#include "dynamic_memory_management/_test.h"
#include "input_output_support/_test.h"
#include "language/_test.h"
#include "numerics/_test.h"
#include "strings/_test.h"
#include "type_support/_test.h"

/**
 * \brief 主函数。
 *
 * \returns 退出状态（exit status）。
 *
 * \sa <https://zh.cppreference.com/w/c/language/main_function>
 */
int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_add_suite(tr, ts_algorithms());
    srunner_add_suite(tr, ts_atomic_operations());
    srunner_add_suite(tr, ts_date_and_time_utilities());
    srunner_add_suite(tr, ts_dynamic_memory_management());
    srunner_add_suite(tr, ts_input_output_support());
    srunner_add_suite(tr, ts_language());
    srunner_add_suite(tr, ts_numerics());
    srunner_add_suite(tr, ts_strings());
    srunner_add_suite(tr, ts_type_support());
    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}

/** @} */
