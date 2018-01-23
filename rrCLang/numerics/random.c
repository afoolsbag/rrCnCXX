/**
 * \file
 * \brief 伪随机数生成
 * \sa ["Pseudo-random number generation (伪随机数生成)"](http://en.cppreference.com/w/c/numeric/random). *cppreference.com*.
 * \sa \ref p_numerics
 * \author zhengrr
 * \date 2016-10-10 – 2018-1-23
 * \copyright The MIT License
 */

#include <stdlib.h>
#include <time.h>

/**
 * \brief 依据当前时间生成伪随机数。
 * \return 生成的伪随机数，范围在 [0, RAND_MAX]。
 */
static int generate_pseudo_random_number_by_current_time(void)
{
	srand((unsigned)time(NULL));
	return rand();
}
