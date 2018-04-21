#pragma once
#ifndef STR_TSUITESTR_H_
#define STR_TSUITESTR_H_

#include <check/check.h>

Suite *tsuite_str(void);

TCase *tcase_bstr_cnv(void);
TCase *tcase_bstr_exam(void);
TCase *tcase_bstr_man(void);

#endif/*STR_TSUITESTR_H_*/
