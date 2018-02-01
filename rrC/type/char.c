/**
 * \file
 * \brief 字符
 * \sa ["Character types"](http://en.cppreference.com/w/c/language/arithmetic_types#Character_types). *cppreference.com*.
 * \sa ["character constant"](http://en.cppreference.com/w/c/language/character_constant). *cppreference.com*.
 * \sa ["Escape sequences"](http://en.cppreference.com/w/c/language/escape). *cppreference.com*.
 * \author zhengrr
 * \date 2016-10-9 – 2018-1-15
 * \copyright The MIT License
 */

#include "std.h"

#include <assert.h>
#if C_STD_95
# include <wchar.h>
#endif/* CSTD95*/
#if C_N1040
# include <uchar.h>
#endif/* CN1040*/

/** \brief 一种巧妙的个位十六进制数到其字符编码的转换
 *  \param hexint 个位十六进制数（0x0 ~ 0xF）
 *  \return 对应的字符编码（'0' ~ 'F'） */
char hex_int_to_char(const int hexint)
{
	return "0123456789ABCDEF"[hexint % 16];
}

/** \brief main */
int main(void)
{
	char ascii = 'a';  /* U+0061 */
	assert('\141' == ascii);
	assert('\x61' == ascii);

	wchar_t utf16 = L'喵';  /* U+55B5 */

#if C_STD_99
	assert(L'\u55B5' == utf16);

	wchar_t utf32 = U'𝌀';
#endif/* C_STD_99*/

#ifdef C_STD_11

#endif/* C_STD_11*/
}
