/** \copyright The MIT License */

#include <check/check.h>

#include "rrc/lseg1d.h"
#include "tsuite_numr.h"

START_TEST(test_lseg1d_and)
	struct rrc_lseg1d_t l = {{7}, {5}};
	struct rrc_lseg1d_t n = {{3}, {6}};
	struct rrc_lseg1d_t r = rrc_lseg1d_and(l, n);
	ck_assert(5 == r.a.x && 6 == r.b.x);
END_TEST

TCase *tcase_lseg1d(void)
{
	TCase *tcase = tcase_create("lseg1d");
	tcase_add_test(tcase, test_lseg1d_and);
	return tcase;
}
