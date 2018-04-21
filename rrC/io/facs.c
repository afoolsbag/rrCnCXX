/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gFAcs 文件访问
 * \ingroup gIo
 *
 * \sa ["File access"](http://en.cppreference.com/w/c/io#File_access). *cppreference.com*.
 *
 * \version 2018-04-21
 * \date 2016-11-14
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdio.h>

#include "io/tsuite_io.h"

/**
 * \brief 打开文件。
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
