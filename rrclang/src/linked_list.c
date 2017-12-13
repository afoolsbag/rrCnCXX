/** \file
 *  \brief 链表。
 *  \sa <http://sglib.sourceforge.net/doc/index.html#list_api0>
 *  \author zhengrr
 *  \date 2016-11-11 – 14
 *  \copyright The MIT License
 */
#ifdef SGLIB

#include <stdio.h>
#include <stdlib.h>

#include "sglib/sglib.h"

typedef struct ilistelem {
        int i;                   //< value
        struct ilistelem *nptr;  //< next pointer
} ilistelem, *ilist;
#define ILISTELEM_COMPARATOR(e1, e2) (e1->i - e2->i)

#define SIZE 10
static int INPUT[SIZE] = {1, 7, 5, 3, 9, 0, 6, 4, 2, 8};

#if ENTRY_SWITCH || 0
int main(void)
{
        ilist list = NULL;
        ilistelem *cur;
        for (int i = 0; i < SIZE; ++i) {
                cur = malloc(sizeof(ilistelem));
                cur->i = INPUT[i];
                SGLIB_LIST_ADD(ilistelem, list, cur, nptr);
        }

        SGLIB_LIST_SORT(ilistelem, list, ILISTELEM_COMPARATOR, nptr);

        SGLIB_LIST_MAP_ON_ELEMENTS(ilistelem, list, cur, nptr, {
                printf("%d ", cur->i);
        });
        printf("\n");

        SGLIB_LIST_MAP_ON_ELEMENTS(ilistelem, list, cur, nptr, {
                free(cur);
        });
        system("pause");
        return EXIT_SUCCESS;
}
#endif// ENTRY SWICH

#endif// SGLIB
