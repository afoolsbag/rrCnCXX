/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupMain 主函数
 * \ingroup groupLanguage
 *
 * \version 2020-01-09
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include "algorithm/ts_algorithm.h"
#include "atomic/ts_atomic.h"
#include "chrono/ts_chrono.h"
#include "error/ts_error.h"
#include "io/ts_io.h"
#include "language/ts_language.h"
#include "locale/ts_locale.h"
#include "memory/ts_memory.h"
#include "numeric/ts_numeric.h"
#include "string/ts_string.h"
#include "types/ts_types.h"

/**
 * \brief 主函数。
 *
 * \returns 退出状态（exit status）。
 *
 * \sa <https://zh.cppreference.com/w/c/language/main_function>
 */
int main(void)
{
    if (!setlocale(LC_ALL, ".UTF-8"))
        if (!setlocale(LC_ALL, "C.UTF-8"))
            fputs("Set locale with UTF-8 failed.\n", stderr);

    SRunner *const tr = srunner_create(NULL);
    srunner_add_suite(tr, ts_algorithm());
    srunner_add_suite(tr, ts_atomic());
    srunner_add_suite(tr, ts_chrono());
    srunner_add_suite(tr, ts_error());
    srunner_add_suite(tr, ts_io());
    srunner_add_suite(tr, ts_language());
    srunner_add_suite(tr, ts_locale());
    srunner_add_suite(tr, ts_memory());
    srunner_add_suite(tr, ts_numeric());
    srunner_add_suite(tr, ts_string());
    srunner_add_suite(tr, ts_types());

    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}

/**
 * @}
 */
