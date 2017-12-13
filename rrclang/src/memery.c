/** \file
 *  \brief 内存。
 *  \author zhengrr
 *  \date 2016-12-2
 *  \copyright The MIT License
 */
#include <stdlib.h>

/** \brief Memory ALLOCation / FREE
 *  \sa <http://en.cppreference.com/w/c/memory/malloc>
 *  \sa <http://en.cppreference.com/w/c/memory/free>
 */
static int mallocfree(void)
{
        int *ptr = NULL;
        if (NULL == (ptr = malloc(10 * sizeof *ptr))) return EXIT_FAILURE;
        free(ptr);  ptr = NULL;

        return EXIT_SUCCESS;
}
#ifdef ENTRY_SWITCH
int main(void) { return mallocfree(); }
#endif// ENTRY SWITCH

/** \brief C ALLOCation / FREE
 *  \sa <http://en.cppreference.com/w/c/memory/calloc>
 *  \sa <http://en.cppreference.com/w/c/memory/free>
 */
static int callocfree(void)
{
        struct point { int x; int y; } *ptr = NULL;
        if (NULL == (ptr = calloc(1, sizeof *ptr))) return EXIT_FAILURE;
        free(ptr);  ptr = NULL;

        return EXIT_SUCCESS;
}

/** \brief RE-ALLOCation
 *  \sa <http://en.cppreference.com/w/c/memory/realloc>
 */
static int reallocfunc(void)
{
        int *ptr = NULL;
        if (NULL == (ptr = realloc(ptr, 10 * sizeof *ptr))) return EXIT_FAILURE;
        if (NULL == (ptr = realloc(ptr, 20 * sizeof *ptr))) return EXIT_FAILURE;
        realloc(ptr, 0);  ptr = NULL;

        return EXIT_SUCCESS;
}
