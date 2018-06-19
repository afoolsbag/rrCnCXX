/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gMain 主函数
 * \ingroup gLang
 *
 * \version 2018-06-19
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "cdef.h"
#include "algo/tsuite_algo.h"
#include "time/tsuite_time.h"

/**
 * \brief 主函数。
 *
 * \param argc 参数计数（argument count）。
 * \param argv 参数矢量（argument vector）。
 * \returns 退出状态（exit status）。
 *
 * \sa ["Main function"](http://en.cppreference.com/w/c/language/main_function). *cppreference.com*.
 */
int main(int argc, char *argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	SRunner *runner = srunner_create(NULL);

	srunner_add_suite(runner, tsuite_algo());
	srunner_add_suite(runner, tsuite_time());

	srunner_run_all(runner, CK_NORMAL);
	const int ec = srunner_ntests_failed(runner);

	srunner_free(runner);
	return ec;
}

/** @} */
