/**
 * \file
 * \brief 数组
 * \sa ["Array declaration"](http://en.cppreference.com/w/c/language/array). *cppreference.com*.
 * \sa ["Array initialization"](http://en.cppreference.com/w/c/language/array_initialization). *cppreference.com*.
 * \author zhengrr
 * \date 2016-10-9 – 2018-1-15
 * \copyright The MIT License
 */

#include "c_standard_version.h"

#include <assert.h>

/**
 * \brief （匿名数组）复合字面量
 * \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*.
 */
void compound_literals()
{
#if CSTD99
	int *p_compound_literals = (int[]) {0, 1, 2};
	assert(p_compound_literals[0] == 0);
	assert(p_compound_literals[1] == 1);
	assert(p_compound_literals[2] == 2);
#endif/* CSTD99*/
}

// C99 变长数组

int main(void)
{
}

// 13.7
// char d[][8]
// char *d[8]