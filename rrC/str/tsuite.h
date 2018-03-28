#pragma once
#ifndef STR_TSUITE_H_
#define STR_TSUITE_H_

#include <check.h>

TCase *tcase_str_cnv(void);
TCase *tcase_str_man(void);

Suite *tsuite_str(void);

#endif/*STR_TSUITE_H_*/
