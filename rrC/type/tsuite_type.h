#pragma once
#ifndef RRC_STR_TSUITETYPE_H_
#define RRC_STR_TSUITETYPE_H_

#include <check/check.h>

Suite *tsuite_type(void);

TCase *tcase_array(void);
TCase *tcase_char(void);
TCase *tcase_struct(void);

#endif/*RRC_STR_TSUITETYPE_H_*/
