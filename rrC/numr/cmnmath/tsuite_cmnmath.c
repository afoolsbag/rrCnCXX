#include "tsuite_cmnmath.h"

Suite *tsuite_cmnmath(void)
{
    Suite *tsuite = suite_create("cmnmath");
    suite_add_tcase(tsuite, tcase_rnd());
    return tsuite;
}
