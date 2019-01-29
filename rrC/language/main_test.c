/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gMain 主函数
 * \ingroup gLang
 *
 * \version 2019-01-28
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "algorithm/_test.h"
#include "atomic/_test.h"
#include "chrono/_test.h"

#include "io/_test.h"
#include "language/_test.h"
#include "memory/_test.h"
#include "numeric/_test.h"
#include "string/_test.h"
#include "types/_test.h"

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
    srunner_add_suite(tr, ts_algorithm());
    srunner_add_suite(tr, ts_atomic());
    srunner_add_suite(tr, ts_chrono());

    //TODO: 等待重构
    srunner_add_suite(tr, ts_io());
    srunner_add_suite(tr, ts_language());
    srunner_add_suite(tr, ts_memory());
    srunner_add_suite(tr, ts_numerics());
    srunner_add_suite(tr, ts_strings());
    srunner_add_suite(tr, ts_type_support());

    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}

/** @} */
