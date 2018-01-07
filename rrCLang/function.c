/** \file
 *  \brief 函数。
 *  \sa <http://en.cppreference.com/w/c/language/functions>
 *  \author zhengrr
 *  \date 2016-10-17 – 12-2
 *  \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

/** \brief （显式指定）丢弃返回值。
 */
static int discard_return_value(void)
{
        (void)printf("This function returns number of output character.");
        return EXIT_SUCCESS;
}

#if (defined(__STDC_VERSION__) && 199901L<=__STDC_VERSION__ /*C99*/) || \
    (defined(__GNUC__) && (0<__GNUC__ || 0==__GNUC__ && 9<=__GNUC_MINOR__) /*GCC0.9*/)
/** \brief 变长数组作为形式参数。
 */
static int vla_as_param(int length, int array[*])
{      
}
#endif

#if (defined(__STDC_VERSION__) && 199901L<=__STDC_VERSION__ /*C99*/)
/** \brief static 声明形式参数数组最小长度。
 */
static int static_array_param(int array[static 3])
{
}
#endif
