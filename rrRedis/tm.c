/**
 * \copyright Unlicense
 */

#include <stdlib.h>

#include <check.h>

#include "ts.h"

int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_set_fork_status(tr, CK_NOFORK);
    srunner_add_suite(tr, ts());
    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
