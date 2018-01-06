/** \file
 *  \brief 标记
 *  \sa [Alternative operators and tokens](http://en.cppreference.com/w/c/language/operator_alternative). *cppreference.com*.
 *  \author zhengrr
 *  \data 2016-11-7 – 2018-1-6
 *  \copyright The MIT License */

#include "c_standard_version.h"

#if CSTD95
# include <iso646.h>
#endif// CSTD95
#include <stdio.h>

int main()
{
	/* 三标符 Trigraphs */
	printf("??<\n");  /* { */
	printf("??<\n");  /* } */
	printf("??(\n");  /* [ */
	printf("??)\n");  /* ] */
	printf("??=\n");  /* # */
	printf("??/\n");  /* \ */
	printf("??'\n");  /* ^ */
	printf("??!\n");  /* | */
	printf("??-\n");  /* ~ */


	/* 替用记号 Alternative tokens */
#if CSTD95
	/* <%  {  */
	/* %>  }  */
	/* <:  [  */
	/* :>  ]  */
	/* %:  #  */
	/* %:: ## */
#endif// CSTD95


	/* 操作符宏 Operator macros */
#if CSTD95
	/* and    && */
	/* or     || */
	/* not    !  */
	/* and_eq &= */
	/* or_eq  |= */
	/* not_eq != */
	/* bitand &  */
	/* bitor  |  */
	/* compl  ~  */
	/* xor    ^  */
	/* xor_eq ^= */
#endif// CSTD95
}
