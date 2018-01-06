/** \file
 *  \brief 类型系统：结构体类型
 *  \sa ["Struct declaration"](http://en.cppreference.com/w/c/language/struct). *cppreference.com*.
 *  \sa ["Struct and union initialization"](http://en.cppreference.com/w/c/language/struct_initialization). *cppreference.com*.
 *  \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-12-2 – 2018-1-6
 *  \copyright The MIT License */

#include "c_standard_version.h"

#include <assert.h>

static struct point {
	double x, y;
};

int main()
{
	/* 匿名结构体（复合字面量） */
#if CSTD99
	struct point p_compound_literals = (struct point) {.x = 0, .y = 0};
	assert(p_compound_literals.x == 0);
	assert(p_compound_literals.y == 1);
#endif// CSTD99
}
