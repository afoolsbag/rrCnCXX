/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup g_main 主函数
 * \ingroup g_lang
 *
 * \version 2018-03-28
 * \date 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include "mem/tsuite_mem.h"
#include "str/tsuite_str.h"
#include "time/tsuite_time.h"

/**
 * \brief 主函数
 *
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \returns 退出状态（exit status）
 *
 * \sa ["Main function"](http://en.cppreference.com/w/c/language/main_function). *cppreference.com*.
 */
int main(int argc, char *argv[])
{
	SRunner *runner = srunner_create(NULL);

	srunner_add_suite(runner, tsuite_mem());
	srunner_add_suite(runner, tsuite_str());
	srunner_add_suite(runner, tsuite_time());

	srunner_run_all(runner, CK_NORMAL);
	int failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failed;
}

/** @} */
