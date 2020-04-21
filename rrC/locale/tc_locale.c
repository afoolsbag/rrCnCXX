#include <locale.h>
#include <stdio.h>

#include <check.h>

#include "ts_locale.h"

/**
 * \addtogroup groupLocale
 * @{
 */

/**
 * \brief 打印当前本地化配置名
 *
 * \sa <https://zh.cppreference.com/w/c/locale/setlocale>
 */
START_TEST(tf_print_locale)
{
    const int cnt = printf("locale: %s\n", setlocale(LC_ALL, NULL));
    if (cnt < 0)
        perror("printf");
}
END_TEST;

/**
 * @}
 */

TCase *tc_locale(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_print_locale);
    return tc;
}
