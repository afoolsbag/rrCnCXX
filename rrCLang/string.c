/**
 * \file
 * \brief 字符串
 * \sa ["Null-terminated byte strings"](http://en.cppreference.com/w/c/string/byte). *cppreference.com*.
 * \author zhengrr
 * \date 2018-1-5 – 16
 * \copyright The MIT License
 */

#include <assert.h>
#include <string.h>

#include "c_standard_version.h"

/**
 * \brief 字符串复制
 * \sa ["strcpy"](http://cplusplus.com/reference/cstring/strcpy/). *C++ Reference*.
 * \sa ["strcpy, strcpy_s"](http://en.cppreference.com/w/c/string/byte/strcpy). *cppreference.com*.
 */
void string_copy(void)
{
	char dst[4] = {'\0'};
	const char src[4] = "abc";

	strcpy(dst, src);

#if CN1225
	strcpy_s(dst, sizeof(dst), src);
#endif/* CN1225*/

	assert(!strcmp(src, dst));
}

/**
 * \brief 字符串复制
 * \sa ["strncpy"](http://cplusplus.com/reference/cstring/strncpy/). *C++ Reference*.
 * \sa ["strncpy, strncpy_s"](http://en.cppreference.com/w/c/string/byte/strncpy). *cppreference.com*.
 */
void string_n_copy(void)
{
	char dst[4] = {'\0'};
	const char src[4] = "abc";

	strncpy(dst, src, 4);
	dst[sizeof(dst) - 1] = '\0';

	assert(!strcmp(src, dst));
}

/**
 * \brief 字符串拼接
 * \sa ["strcat"](http://cplusplus.com/reference/cstring/strcat/). *C++ Reference*.
 * \sa ["strcat, strcat_s"](http://en.cppreference.com/w/c/string/byte/strcat). *cppreference.com*.
 */
void string_concatenate(void)
{
	char dst[7] = "abc";
	const char src[4] = "def";

	strcat(dst, src);

	assert(!strcmp(dst, "abcdef"));
}

/**
 * \brief 字符串拼接
 * \sa ["strncat"](http://cplusplus.com/reference/cstring/strncat/). *C++ Reference*.
 * \sa ["strncat, strncat_s"](http://en.cppreference.com/w/c/string/byte/strncat). *cppreference.com*.
 */
void string_n_concatenate(void)
{
	char dst[7] = "abc";
	const char src[4] = "def";

	strncat(dst, src, sizeof(dst) - strlen(dst) - 1);

	assert(!strcmp(dst, "abcdef"));
}

/**
 * \brief 字符串长度
 * \sa ["strlen"](http://cplusplus.com/reference/cstring/strlen/). *C++ Reference*.
 * \sa ["strlen, strnlen_s"](http://en.cppreference.com/w/c/string/byte/strlen). *cppreference.com*.
 */
void string_length(void)
{
	const char src[4] = "abc";

	size_t len = strlen(src);

	assert(3 == len);
}

/**
 * \brief 字符串比较
 * \sa ["strcmp"](http://cplusplus.com/reference/cstring/strcmp/). *C++ Reference*.
 * \sa ["strcmp"](http://en.cppreference.com/w/c/string/byte/strcmp). *cppreference.com*.
 */
void string_compare(void)
{
	const char src[4] = "abc";
	const char dst[4] = "abc";

	assert(!strcmp(src, dst));
}

int main(void)
{
	/* Conversions to numeric formats */

	/* String manipulation */
	string_copy();
	string_n_copy();
	string_concatenate();
	string_n_concatenate();

	/* String examination */
	string_length();
	string_compare();

	/* Character array manipulation */

	/* Miscellaneous */
}
