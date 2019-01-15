/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-01-15
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include "lwic/library.h"
#include "lwicxx/library.hxx"

int main(int argc, char *argv[])
{
    rrdll_lwicxx_handle_t lwicxxHdl = NULL;
    rrdll_lwicxx_construct(&lwicxxHdl);
    rrdll_lwicxx_plus(lwicxxHdl, 5);
    rrdll_lwicxx_minus(lwicxxHdl, 2);
    int result;
    rrdll_lwicxx_equals(lwicxxHdl, &result);
    rrdll_lwicxx_destruct(lwicxxHdl);
    printf("lwicxx result: %d\n", result);

    return EXIT_SUCCESS;
}
