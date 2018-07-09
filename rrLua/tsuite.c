#include "tsuite.h"

Suite *tsuite(void)
{
    Suite *tsuite = suite_create("suite");
    suite_add_tcase(tsuite, tcase());
    return tsuite;
}
