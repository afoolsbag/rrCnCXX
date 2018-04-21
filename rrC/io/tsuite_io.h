#pragma once
#ifndef IO_TSUITEIO_H_
#define IO_TSUITEIO_H_

#include <check/check.h>

Suite *tsuite_io(void);

TCase *tcase_dirio(void);
TCase *tcase_errio(void);
TCase *tcase_facs(void);
TCase *tcase_fmtio(void);
TCase *tcase_fop(void);
TCase *tcase_fpos(void);
TCase *tcase_unfmtio(void);

#endif/*IO_TSUITEIO_H_*/
