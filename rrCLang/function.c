/** \file
 *  \brief 函数
 *  \sa \ref page_function
 *  \sa [Functions](http://en.cppreference.com/w/c/language/functions). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-10-17 – 2018-1-12
 *  \copyright The MIT License */

#include <stdio.h>
#include <stdlib.h>

/** \page page_function
 *  \section sec_char_array_vs_char_pointer_in_function_prototype 函数原型里的字符数组与字符指针
 *
 *  二者功能等同（在函数原型里，字符数组会退化为字符指针）。
 *
 *  对于应用访问接口函数：
 *  只读定长字符串采用字符数组，以显式地提醒用户注意输入参数的尺寸；
 *  其它字符串采用字符指针，且推荐要求输入尺寸，以强制用户检查安全性；
 *  入口做安全检查。
 *
 *  对于一般函数：
 *  一律采用字符指针；
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
static int vla_as_param(int length, int array[*])
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
