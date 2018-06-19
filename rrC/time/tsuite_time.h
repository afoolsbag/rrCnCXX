#pragma once
#ifndef RRC_TIME_TSUITETIME_H_
#define RRC_TIME_TSUITETIME_H_

#include <check/check.h>

Suite *tsuite_time(void);

TCase *tcase_caltm(void);
TCase *tcase_clktm(void);
TCase *tcase_epotm(void);
TCase *tcase_spectm(void);

#endif/*RRC_TIME_TSUITETIME_H_*/
