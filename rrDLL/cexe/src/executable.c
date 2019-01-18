/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-01-18
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include "clib/library.h"
#include "cxxlib/library.hxx"

int main(int argc, char *argv[])
{
    cxxlib_handle_t h = NULL;
    cxxlib_construct(&h);
    cxxlib_plus(h, 5);
    cxxlib_minus(h, 2);
    int result;
    cxxlib_equals(h, &result);
    cxxlib_destruct(h);
    printf("cxxlib result: %d\n", result);

    return EXIT_SUCCESS;
}
