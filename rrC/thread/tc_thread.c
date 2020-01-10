#include <check.h>

#include "c_versions.h"
#include "ts_thread.h"

#if FEATURE_THREADS
#include <threads.h>
#endif

/**
 * \addtogroup groupThread
 * @{
 */

START_TEST(tf_thread)
{
#if FEATURE_THREADS
#endif
}
END_TEST;

/**
 * @}
 */

TCase *tc_thread(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_thread);
    return tc;
}
