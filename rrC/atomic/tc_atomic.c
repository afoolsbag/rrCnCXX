/**
 * \addtogroup gAtomic
 * @{
 */

#include "c_versions.h"

#if FEATURE_ATOMICS
#include <stdatomic.h>
#endif

#include <check.h>

#include "ts_atomic.h"

START_TEST(tf_atomic_int)
{
#if FEATURE_ATOMICS
    atomic_int aint = 0;
    ++aint;
    (void)aint;
#endif
}
END_TEST;

/**
 * @}
 */

TCase *tc_atomic(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_atomic_int);
    return tc;
}
