#include <stdlib.h>

#include <check/check.h>

#include "tsuite.h"

int main(int argc, char *argv[])
{
    SRunner *runner = srunner_create(NULL);

    srunner_add_suite(runner, tsuite());

    srunner_run_all(runner, CK_NORMAL);
    const int errco = srunner_ntests_failed(runner);
    srunner_free(runner);

    system("TIMEOUT /T 15");

    return errco;
}
