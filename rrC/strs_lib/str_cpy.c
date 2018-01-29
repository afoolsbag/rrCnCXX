/**
 * \defgroup g_str_cpy 字符串复制
 * \ingroup g_strs_lib
 *
 * \author zhengrr
 * \date 2018-1-5 – 25
 * \copyright The MIT License
 *
 * @{
 */

#include <assert.h>
#include <string.h>

#include "c_std_ver.h"

/**
 * \brief 字符串复制
 * \sa ["strcpy, strcpy_s"](http://en.cppreference.com/w/c/string/byte/strcpy). *cppreference.com*.
 */
void string_copy(void)
{
	char dst[4] = "";
	const char src[4] = "abc";

	strcpy(dst, src);

#if C_N1225
	strcpy_s(dst, sizeof(dst), src);
#endif/* C_N1225*/

	assert(!strcmp(src, dst));
}

/**
 * \brief 字符串复制
 * \sa ["strncpy, strncpy_s"](http://en.cppreference.com/w/c/string/byte/strncpy). *cppreference.com*.
 */
void string_n_copy(void)
{
	char dst[4] = "";
	const char src[4] = "abc";

	strncpy(dst, src, sizeof(dst) - 1);
	dst[sizeof(dst) - 1] = '\0';

	assert(!strcmp(src, dst));
}

/** \brief main */
int main(void)
{
	string_copy();
	string_n_copy();
}

/** @} */
