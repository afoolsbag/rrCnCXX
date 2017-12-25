/** \file
 *  \sa <http://en.cppreference.com/w/c/numeric/random>
 *  \author zhengrr
 *  \date 2016-10-10 – 11-8
 *  \copyright The MIT License
 */
#include <stdlib.h>
#include <time.h>

/** \brief 依据当前时间生成伪随机数。
 *  \return 生成的伪随机数，范围在 [0, RAND_MAX]。
 */
static int generate_pseudo_random_number_by_current_time(void)
{
        srand((unsigned)time(NULL));
        return rand();
}
