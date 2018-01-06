/** \file
 *  \brief 类型系统：字符串
 *  \author zhengrr
 *  \date 2018-1-5
 *  \copyright The MIT License */

#include "c_standard_version.h"

#include <string.h>

/** \brief 字符串操作
 *  \sa ["String manipulation"](http://en.cppreference.com/w/c/string/byte#String_manipulation). *cppreference.com*.
 */
void string_manipulation()
{
	char *src = "abc";
	char dst[4];

	/* 字符串复制 String copy */
	strcpy(dst, src);
#if CN1225
	strcpy_s(dst, sizeof(dst), src);
#endif// CN1225
}

int main()
{
	string_manipulation();
}
