/** \file
 *  \brief 数组。
 *  \sa <http://en.cppreference.com/w/c/language/array>
 *  \sa <http://en.cppreference.com/w/c/language/array_initialization>
 *  \sa <http://sglib.sourceforge.net/doc/index.html#array_api0>
 *  \author zhengrr
 *  \date 2016-10-9 – 11-14
 *  \copyright The MIT License
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if (defined(__STDC_VERSION__) && 199901L<=__STDC_VERSION__ /*C99*/)
/** \brief 匿名数组（复合字面量）。
 */
static int anonymous_array(void)
{
        (int[]){1,2,3,4,5};
        return EXIT_SUCCESS;
}
#endif

/** \brief 矩阵。
 */
static int matrix(void)
{
        static const int8_t GOBLACK = (int8_t)INT8_MIN;
        static const int8_t GOSPACE = (int8_t)0;
        static const int8_t GOWHITE = (int8_t)INT8_MAX;

        int8_t goboard[19][19] = {0/*GOSPACE*/};
        goboard[3][3] = GOBLACK;
        goboard[5][2] = GOWHITE;

        return EXIT_SUCCESS;
}
#ifdef ENTRY_SWITCH
int main(void) { return matrix(); }
#endif// ENTRY SWITCH

#if (defined(__STDC_VERSION__) && 201112L<=__STDC_VERSION__ /*C11*/)
/** \brief 变长数组。
 */
static int variable_length_array(int argc, char *argv[])
{
        return EXIT_SUCCESS;
}
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return variable_length_array(argc, argv); }
#endif// ENTRY SWITCH
#endif

#ifdef SGLIB

#include <stdio.h>
#include <stdlib.h>

#include "sglib/sglib.h"

#define SIZE 10
static int INPUT[SIZE] = {1, 7, 5, 3, 9, 0, 6, 4, 2, 8};

#ifdef ENTRY_SWITCH
int main(void)
{
        int array[SIZE];
        for (int i = 0; i < SIZE; ++i) {
                array[i] = INPUT[i];
        }

        SGLIB_ARRAY_SINGLE_QUICK_SORT(int, array, SIZE, SGLIB_NUMERIC_COMPARATOR);

        for (int i = 0; i < SIZE; i++) {
                printf("%d ", array[i]);
        }
        printf("\n");
        return EXIT_SUCCESS;
}

#endif// ENTRY SWICH

#endif// SGLIB
