/**
 * \file
 * \brief 字符串链接
 * \sa \ref p_strs_lib
 * \author zhengrr
 * \date 2018-1-5 – 23
 * \copyright The MIT License
 */

#include <assert.h>
#include <string.h>

#include "c_std_ver.h"

/**
 * \brief 字符串链接
 * \sa ["strcat, strcat_s"](http://en.cppreference.com/w/c/string/byte/strcat). *cppreference.com*.
 */
void string_catenate(void)
{
	char dst[7] = "abc";
	const char src[4] = "def";

	strcat(dst, src);

	assert(!strcmp(dst, "abcdef"));
}

/**
 * \brief 字符串链接
 * \sa ["strncat, strncat_s"](http://en.cppreference.com/w/c/string/byte/strncat). *cppreference.com*.
 */
void string_n_catenate(void)
{
	char dst[7] = "abc";
	const char src[4] = "def";

	strncat(dst, src, sizeof(dst) - strlen(dst) - 1);

	assert(!strcmp(dst, "abcdef"));
}

/** \brief main */
int main(void)
{
	string_catenate();
	string_n_catenate();
}
