/** \file
 *  \brief 内存
 *  \sa ["C memory management library"](http://en.cppreference.com/w/c/memory). *cppreference.com*.
 *  \author zhengrr
 *  \date 2016-12-2 – 2018-1-15
 *  \copyright The MIT License
 */
#include <stdlib.h>

/**
 * \brief 内存分配
 * \sa ["malloc"](http://cplusplus.com/reference/cstdlib/malloc/). *C++ Reference*.
 * \sa ["free"](http://cplusplus.com/reference/cstdlib/free/). *C++ Reference*.
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
 * \sa ["calloc"](http://cplusplus.com/reference/cstdlib/calloc/). *C++ Reference*.
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
 * \sa ["realloc"](http://cplusplus.com/reference/cstdlib/realloc/). *C++ Reference*.
 * \sa ["realloc"](http://en.cppreference.com/w/c/memory/realloc). *cppreference.com*.
 */
void reallocation(void)
{
	void *pIntArray = realloc(NULL, 2 * sizeof(int));
	if (NULL == pIntArray)
		return;

	void *pTemp = pIntArray;
	pIntArray = realloc(pTemp, 4 * sizeof(int);
	if (NULL == pIntArray) {
		free(pTemp);
		return;
	}
	pTemp = NULL;

	realloc(pIntArray, 0);
	pIntArray = NULL;
}

int main(void)
{
	memory_allocation();
	clear_allocation();
	reallocation();
}
