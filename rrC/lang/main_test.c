/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gMain 主函数
 * \ingroup gLang
 *
 * \version 2018-08-07
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>

#include <check/check.h>

#include "algo/test.h"
#include "atom/test.h"

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

    srunner_run_all(runner, CK_NORMAL);
    const int ec = srunner_ntests_failed(runner);
    srunner_free(runner);

    system("TIMEOUT /T 15");
    return ec;
}

/** @} */
