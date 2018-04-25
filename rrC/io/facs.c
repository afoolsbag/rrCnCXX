/*===-- File Access --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gFAcs 文件访问
 * \ingroup gIo
 *
 * \sa ["File access"](http://en.cppreference.com/w/c/io#File_access). *cppreference.com*.
 *
 * \version 2018-04-25
 * \since 2016-11-14
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#include <check/check.h>

#include "cver.h"
#include "io/tsuite_io.h"

/**
 * \brief 打开文件（file open）。
 * \sa http://en.cppreference.com/w/c/io/fopen
 */
START_TEST(test_fopen)
	FILE *fp = fopen("hello.txt", "a+");
	if (NULL == fp) {
		fprintf(stderr, "file open failed.\n");
		return;
	}
	fclose(fp);
END_TEST

START_TEST(test_fopen_s)
#if LIB_EXT1
#endif/*LIB_EXT1*/
END_TEST

/**
 * \brief 以不同名称打开既存的文件流（file re-open）。
 * \sa http://en.cppreference.com/w/c/io/freopen
 */
START_TEST(test_freopen)
END_TEST

START_TEST(test_freopen_s)
#if LIB_EXT1
#endif/*LIB_EXT1*/
END_TEST

/** @} */

TCase *tcase_facs(void)
{
	TCase *tcase = tcase_create("facs");
	tcase_add_test(tcase, test_fopen);
	tcase_add_test(tcase, test_fopen_s);
	tcase_add_test(tcase, test_freopen);
	tcase_add_test(tcase, test_freopen_s);
	return tcase;
}
