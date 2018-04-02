#pragma once
#ifndef STR_TSUITETYPE_H_
#define STR_TSUITETYPE_H_

#include <check/check.h>

TCase *tcase_array(void);
TCase *tcase_char(void);
TCase *tcase_struct(void);

Suite *tsuite_type(void);

#endif/*STR_TSUITETYPE_H_*/
