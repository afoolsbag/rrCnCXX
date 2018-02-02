/*===-- Main Function ------------------------------------------*- C -*-===*//**
 *
 * \defgroup g_main 主函数
 * \ingroup g_lang
 *
 * \author zhengrr
 * \date 2016-10-9 – 2018-2-2
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check.h>

#include "str/test.h"

/**
 * \brief 主函数
 *
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \return 退出状态（exit status）
 *
 * \sa ["Main function"](http://en.cppreference.com/w/c/language/main_function). *cppreference.com*.
 */
int main(int argc, char *argv[])
{
	SRunner *runner = srunner_create(NULL);
	srunner_add_suite(runner, str_ste());

	srunner_run_all(runner, CK_NORMAL);
	int failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failed;
}

/** @} */
