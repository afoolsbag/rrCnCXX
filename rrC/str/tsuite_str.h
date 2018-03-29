#pragma once
#ifndef STR_TSUITESTR_H_
#define STR_TSUITESTR_H_

#include <check.h>

TCase *tcase_bstr_cnv(void);
TCase *tcase_bstr_exam(void);
TCase *tcase_bstr_man(void);

Suite *tsuite_str(void);

#endif/*STR_TSUITESTR_H_*/
