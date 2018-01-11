/** \file
 *  \brief 函数
 *  \sa [Functions](http://en.cppreference.com/w/c/language/functions). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-10-17 – 2018-1-11
 *  \copyright The MIT License */

#include <stdio.h>
#include <stdlib.h>

/** \page page_function
 *  \section sec_char_array_vs_char_pointer 字符数组与字符指针
 *
 *  二者功能等同。
 *
 *  对于应用访问接口函数：
 *  定长只读字符串采用字符数组，以显式地提醒用户注意输入参数的尺寸；
 *  其它字符串采用字符指针，且推荐显式指定尺寸，以强制用户检查安全性；
 *  入口做安全检查。
 *
 *  对于一般函数：
 *  定长字符串采用字符数组，变长字符串采用字符指针，便于理解其限定条件；
 *  入口、出口做断言，假定输入输出合规。
 *
 *  \sa ["Char array vs char pointer in C"](https://stackoverflow.com/questions/10186765). *Stack Overflow*. */

/** \brief （显式指定）丢弃返回值。
 */
static int discard_return_value(void)
{
	(void) printf("This function returns number of output character.");
	return EXIT_SUCCESS;
}

#if (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__ /*C99*/) || \
    (defined(__GNUC__) && (0 < __GNUC__ || 0 == __GNUC__ && 9 <= __GNUC_MINOR__) /*GCC0.9*/)
/** \brief 变长数组作为形式参数。
 */
static int vla_as_param(int length, int array[ *])
{
}
#endif

#if (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__ /*C99*/)
/** \brief static 声明形式参数数组最小长度。
 */
static int static_array_param(int array[static 3])
{
}
#endif

/* 关于函数参数采用字符数组或字符指针
 *
 * 对于形式参数
 *
 * 若有定长限制，采用字符数组，如 char langcode[LANG_CODE_SIZE]，以提醒用户注意输入尺寸，且函数内做越界检查。
 *
 * 若不定长限制，采用字符指针，如 char *str, size_t strsize，以提醒用户预防越界。
 *
 * 对于实际参数
 *
 * 一律采用字符指针，C 不作越界检查，不应预设参数是正确的 */
