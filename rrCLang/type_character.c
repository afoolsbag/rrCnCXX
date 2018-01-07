/** \file
 *  \brief 类型系统：字符类型
 *  \author zhengrr
 *  \date 2016-10-9 – 2018-1-6
 *  \copyright The MIT License */

/** \brief 一种巧妙的个位十六进制数到其字符编码的转换
 *  \param hexint 个位十六进制数（0x0 ~ 0xF）
 *  \return 对应的字符编码（'0' ~ 'F'） */
char hex_int_to_char(const int hexint)
{
	return "0123456789ABCDEF"[hexint % 16];
}
