/**
 * \copyright Unlicense
 */

#include <stdlib.h>

#include <check.h>

#include "issue4/ts_issue4.h"
#include "issue5/ts_issue5.h"
#include "issue6/ts_issue6.h"

int main(void)
{
    SRunner *const tr = srunner_create(NULL);
    srunner_add_suite(tr, ts_issue4());
    srunner_add_suite(tr, ts_issue5());
    srunner_add_suite(tr, ts_issue6());
    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
