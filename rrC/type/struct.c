/**
 * \file
 * \brief 结构体
 * \sa ["Struct declaration"](http://en.cppreference.com/w/c/language/struct). *cppreference.com*.
 * \sa ["Struct and union initialization"](http://en.cppreference.com/w/c/language/struct_initialization). *cppreference.com*.
 * \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*.
 * \author zhengrr
 * \date 2016-12-2 – 2018-1-15
 * \copyright The MIT License
 */

#include <assert.h>

#include "std.h"

/** \brief point */
static struct point {
	double x, y;
};

/** \brief main */
int main(void)
{
	/* 匿名结构体（复合字面量） */
#if C_STD_99
	struct point p_compound_literals = (struct point) {.x = 0, .y = 0};
	assert(p_compound_literals.x == 0);
	assert(p_compound_literals.y == 0);
#endif/* C_STD_99*/
}
