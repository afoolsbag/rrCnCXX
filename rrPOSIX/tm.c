#include <stdlib.h>

#include <check.h>

#include "ts.h"

int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_add_suite(tr, ts_all());

    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
