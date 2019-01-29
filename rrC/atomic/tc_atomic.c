/**
 * \addtogroup gAtomic
 * @{
 */

#include "c_versions.h"
#if ATOMICS
#include <stdatomic.h>
#endif

#include <check/check.h>

#include "ts_atomic.h"

START_TEST(tf_atomic_int)
{
#if ATOMICS
    atomic_int aint;
#endif
}
END_TEST;

/**
 * @}
 */

TCase *tc_atomic(void)
{
    TCase *const tc = tcase_create("atomic");
    tcase_add_test(tc, tf_atomic_int);
    return tc;
}
