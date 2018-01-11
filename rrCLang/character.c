/** \file
 *  \brief 字符
 *  \sa ["character constant"](http://en.cppreference.com/w/c/language/character_constant)<sub> [*cmn-Hans*](http://zh.cppreference.com/w/c/language/character_constant)</sub>. *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-10-9 – 2018-1-11
 *  \copyright The MIT License */

#include "c_standard_version.h"

#include <assert.h>
#if CSTD95
# include <wchar.h>
#endif/* CSTD95*/
#if CN1040
# include <uchar.h>
#endif/* CN1040*/

/** \brief 一种巧妙的个位十六进制数到其字符编码的转换
 *  \param hexint 个位十六进制数（0x0 ~ 0xF）
 *  \return 对应的字符编码（'0' ~ 'F'） */
char hex_int_to_char(const int hexint)
{
	return "0123456789ABCDEF"[hexint % 16];
}

int main()
{
	char ascii = 'a';  /* U+0061 */
	assert('\141' == ascii);
	assert('\x61' == ascii);

	wchar_t utf16 = L'喵';  /* U+55B5 */

#if CSTD99
	assert(L'\u55B5' == utf16);

	wchar_t utf32 = U'𝌀';
#endif/* CSTD99*/

#ifdef CSTD11

#endif/* CSTD11*/
}
