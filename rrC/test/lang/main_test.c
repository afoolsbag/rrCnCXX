/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gMain 主函数
 * \ingroup gLang
 *
 * \version 2018-08-29
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "algo/_test.h"
#include "atom/_test.h"
#include "io/_test.h"
#include "mem/_test.h"
#include "numr/_test.h"
#include "str/_test.h"
#include "time/_test.h"
#include "type/_test.h"

/**
 * \brief 主函数。
 *
 * \returns 退出状态（exit status）。
 *
 * \sa <https://zh.cppreference.com/w/c/language/main_function>
 */
int main(void)
{
    SRunner *runner = srunner_create(NULL);
    srunner_add_suite(runner, tsuite_algo());
    srunner_add_suite(runner, tsuite_atom());
    srunner_add_suite(runner, tsuite_io());
    srunner_add_suite(runner, tsuite_mem());
    srunner_add_suite(runner, tsuite_numr());
    srunner_add_suite(runner, tsuite_str());
    srunner_add_suite(runner, tsuite_time());
    srunner_add_suite(runner, tsuite_type());
    srunner_run_all(runner, CK_NORMAL);
    const int err = srunner_ntests_failed(runner);
    srunner_free(runner);
    return err;
}

/** @} */
