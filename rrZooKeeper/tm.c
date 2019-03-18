#include <stddef.h>

#include <check.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)
#endif
#include <zookeeper/zookeeper.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "ts.h"

int main(void)
{
    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);

    SRunner *const tr = srunner_create(NULL);
    srunner_set_fork_status(tr, CK_NOFORK);
    srunner_add_suite(tr, ts());

    srunner_run_all(tr, CK_NORMAL);
    const int err = srunner_ntests_failed(tr);
    srunner_free(tr);
    return err;
}
