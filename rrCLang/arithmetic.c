/** \file
 *  \brief 算术类型
 *  \sa ["Arithmetic types"](http://en.cppreference.com/w/c/language/arithmetic_types). *cppreference.com*.
 *  \sa ["Scalar initialization"](http://en.cppreference.com/w/c/language/scalar_initialization). *cppreference.com*.
 *  \sa ["integer constant"](http://en.cppreference.com/w/c/language/integer_constant). *cppreference.com*.
 *  \sa ["character constant"](http://en.cppreference.com/w/c/language/character_constant). *cppreference.com*.
 *  \sa ["floating constant"](http://en.cppreference.com/w/c/language/floating_constant). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-6-27 – 2018-1-5
 *  \copyright The MIT License */

/** \brief 一种巧妙的个位十六进制数到其字符编码的转换
 *  \param hexint 个位十六进制数（0x0 ~ 0xF）
 *  \return 对应的字符编码（'0' ~ 'F'） */
char hex_int_to_char(const int hexint)
{
	return "0123456789ABCDEF"[hexint % 16];
}
