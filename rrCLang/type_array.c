/** \file
 *  \brief 类型系统：数组类型
 *  \sa ["Array declaration"](http://en.cppreference.com/w/c/language/array). *cppreference.com*.
 *  \sa ["Array initialization"](http://en.cppreference.com/w/c/language/array_initialization). *cppreference.com*.
 *  \sa ["string literals"](http://en.cppreference.com/w/c/language/string_literal). *cppreference.com*.
 *  \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-10-9 – 2018-1-6
 *  \copyright The MIT License */

#include "c_standard_version.h"

#include <assert.h>

int main()
{
	/* 匿名数组（复合字面量） */
#if CSTD99
	int *p_compound_literals = (int[]) {0, 1, 2};
	assert(p_compound_literals[0] == 0);
	assert(p_compound_literals[1] == 1);
	assert(p_compound_literals[2] == 2);
#endif// CSTD99
}
