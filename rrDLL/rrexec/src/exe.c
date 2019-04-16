/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-04-16
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include "rrdllc/lib.h"
#include "rrdllcxx/lib.h"

int main(void)
{
    {
        struct rrdllc_version_t v;
        if (rrdllc_version(&v) != rrdllc_success)
            return EXIT_FAILURE;
        printf("rrDLLc version %d.%d.%d.%d\n", v.major, v.minor, v.patch, v.tweak);
    }

    {
        struct rrdllcxx_version_t v;
        if (rrdllcxx_version(&v) != rrdllcxx_success)
            return EXIT_FAILURE;
        printf("rrDLLcxx version %d.%d.%d.%d\n", v.major, v.minor, v.patch, v.tweak);
    }

    {
        rrdllcxx_handle_t h;
        rrdllcxx_construct(&h);
        rrdllcxx_plus(h, 5);
        rrdllcxx_minus(h, 2);
        int r;
        rrdllcxx_equals(h, &r);
        rrdllcxx_destruct(h);
        printf("rrDLLcxx result: %d\n", r);
    }

    return EXIT_SUCCESS;
}
