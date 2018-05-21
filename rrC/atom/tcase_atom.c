/*===-- Atomic Operations Library ------------------------------*- C -*-===*//**
 *
 * \defgroup gAtom 原子操作库
 * \ingroup gRef
 *
 * \sa ["Atomic operations library"](http://en.cppreference.com/w/c/atomic). *cppreference.com*.
 *
 * \version 2018-04-25
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <check/check.h>

#include "cver.h"
#include "atom/tsuite_atom.h"

#if ATOMICS
# include <stdatomic.h>
#endif

#include "cdef.h"

START_TEST(test_atom)
#if ATOMICS
	atomic_int aint;
	UNUSED(aint);
#endif/*ATOMICS*/
END_TEST

/** @} */

TCase *tcase_atom(void)
{
	TCase *tcase = tcase_create("atom");

	tcase_add_test(tcase, test_atom);

	return tcase;
}
