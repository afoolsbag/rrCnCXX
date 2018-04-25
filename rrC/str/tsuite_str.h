#pragma once
#ifndef RRC_STR_TSUITESTR_H_
#define RRC_STR_TSUITESTR_H_

#include <check/check.h>

Suite *tsuite_str(void);

TCase *tcase_bstr_cnv(void);
TCase *tcase_bstr_exam(void);
TCase *tcase_bstr_man(void);

#endif/*RRC_STR_TSUITESTR_H_*/
