/**
 * \file
 * \brief C 内存管理库
 * \sa ["C memory management library (C 内存管理库)"](http://en.cppreference.com/w/c/memory). *cppreference.com*.
 * \sa \ref index
 * \author zhengrr
 * \date 2016-12-2 – 2018-1-23
 * \copyright The MIT License
 */

#include <stdlib.h>

/**
 * \brief 内存分配
 * \sa ["malloc"](http://en.cppreference.com/w/c/memory/malloc). *cppreference.com*.
 * \sa ["free"](http://en.cppreference.com/w/c/memory/free). *cppreference.com*.
 */
void memory_allocation(void)
{
	void *pInt = malloc(sizeof(int));
	if (NULL == pInt)
		return;

	free(pInt);
	pInt = NULL;
}

/**
 * \brief 内存分配
 * \sa ["calloc"](http://en.cppreference.com/w/c/memory/calloc). *cppreference.com*.
 */
void clear_allocation(void)
{
	void *p7Int = calloc(7, sizeof(int));
	if (NULL == p7Int)
		return;

	free(p7Int);
	p7Int = NULL;
}

/** \brief 内存重新分配
 * \sa ["realloc"](http://en.cppreference.com/w/c/memory/realloc). *cppreference.com*.
 */
void reallocation(void)
{
	void *int_array_ptr = realloc(NULL, 2 * sizeof(int));
	if (NULL == int_array_ptr)
		return;

	void *temp_ptr = int_array_ptr;
	int_array_ptr = realloc(temp_ptr, 4 * sizeof(int));
	if (NULL == int_array_ptr) {
		free(temp_ptr);
		return;
	}
	temp_ptr = NULL;

	realloc(int_array_ptr, 0);
	int_array_ptr = NULL;
}

/** \brief main */
int main(void)
{
	memory_allocation();
	clear_allocation();
	reallocation();
}
