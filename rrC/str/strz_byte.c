/**
 * \file
 * \brief 空终止字节字符串
 * \sa ["Null-terminated byte strings (空终止字节字符串)"](http://en.cppreference.com/w/c/string/byte). *cppreference.com*.
 * \sa \ref p_strs_lib
 * \author zhengrr
 * \date 2018-1-5 – 23
 * \copyright The MIT License
 */

#include <assert.h>
#include <string.h>

#include "c_std_ver.h"




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

/** \brief main */
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
