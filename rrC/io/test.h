#ifndef IO_TEST_H_
#define IO_TEST_H_

#include <check.h>

TCase *dirio_test_case(void);
TCase *errio_test_case(void);
TCase *facs_test_case(void);
TCase *fmtio_test_case(void);
TCase *fop_test_case(void);
TCase *fpos_test_case(void);
TCase *unfmtio_test_case(void);

Suite *io_test_suite(void);

#endif/* IO_TEST_H_*/
