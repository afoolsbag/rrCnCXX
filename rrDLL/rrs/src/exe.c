/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \version 2019-02-27
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#include "rrc/lib.h"
#include "rrx/lib.h"

int main(void)
{
    {
        struct rrc_version_t v;
        if (rrc_version(&v) != rrc_success)
            return EXIT_FAILURE;
        printf("rrc version %d.%d.%d.%d\n", v.major, v.minor, v.patch, v.tweak);
    }

    {
        struct rrx_version_t v;
        if (rrx_version(&v) != rrx_success)
            return EXIT_FAILURE;
        printf("rrx version %d.%d.%d.%d\n", v.major, v.minor, v.patch, v.tweak);
    }

    {
        rrx_handle_t h;
        rrx_construct(&h);
        rrx_plus(h, 5);
        rrx_minus(h, 2);
        int r;
        rrx_equals(h, &r);
        rrx_destruct(h);
        printf("rrx result: %d\n", r);
    }

    return EXIT_SUCCESS;
}
