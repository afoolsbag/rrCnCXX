/**
 * \addtogroup gChrono
 * @{
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

#include <check.h>

#include "ts_chrono.h"

/**
 * \brief POSIX 时间
 * \remark 虽然实现通常使用 POSIX 时间实现 `time_t`，但实际上 C 标准没有限定其实现方式。
 *
 * \sa ["Unix time"](https://wikipedia.org/wiki/Unix_time). *Wikipedia*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 */
START_TEST(tf_time_t)
{
    /* 获取当前系统时间 */
    const time_t t1 = time(NULL);
    ck_assert(t1 != -1);

    /* 另一种书写风格 */
    time_t t2;
    ck_assert(time(&t2) != -1);

    /* 俩时间之差，以秒为单位 */
    const double inr = difftime(t2, t1);
    (void)inr;
}
END_TEST;

/**
 * \brief 时间结构体
 * \details 可读的时间结构体。
 */
START_TEST(tf_struct_tm)
{
    /* 设置时间结构体，将其重整并返回对应的 POSIX 时间 */
    time_t t0;
    {
        struct tm t0s;
        memset(&t0s, 0x00, sizeof t0s);
        t0s.tm_year = 1992 - 1900;
        t0s.tm_mon = 6 - 1;
        t0s.tm_mday = 25;

        t0 = mktime(&t0s);
        ck_assert(t0 != -1);
    }

    /* 获取当前时间，并转换为对应的时间结构体，值为协调世界时 */
    struct tm t1s;
    {
        const time_t t1 = time(NULL);
        ck_assert(t1 != -1);

        const struct tm *const tmp = gmtime(&t1);
        ck_assert(tmp);

        t1s = *tmp;
    }

    /* 获取当前时间，并转换为对应的时间结构体，值为本地时 */
    struct tm t2s;
    {
        const time_t t2 = time(NULL);
        ck_assert(t2 != -1);

        const struct tm *const tmp = localtime(&t2);
        ck_assert(tmp);

        t2s = *tmp;
    }

    /* 时间结构体转换为字符串 */
    {
        char buf[20];
        ck_assert(0 < strftime(buf, sizeof buf, "%Y-%m-%dT%H:%M:%S", &t1s));
        ck_assert(0 < printf("t1: %s\n", buf));
    }

    /* 或者简单地使用默认格式 */
    {
        char buf[26];

        char *tmp = asctime(&t2s);
        ck_assert(strlen(tmp) + 1 <= sizeof buf);
        strcpy(buf, tmp);

        ck_assert(0 < printf("t2: %s", buf));
    }

    /* 又或直接从 POSIX 时间转换为默认格式 */
    {
        char buf[26];

        char *tmp = ctime(&t0);
        ck_assert(strlen(tmp) + 1 <= sizeof buf);
        strcpy(buf, tmp);

        ck_assert(0 < printf("t0: %s", buf));
    }
}
END_TEST;

/**
 * \brief 时钟时间
 */
START_TEST(tf_clock_t)
{
    const clock_t start = clock();
    /* do something */
    const clock_t end = clock();
    const double costs_in_seconds = (start - end) / (double)CLOCKS_PER_SEC;

    (void)costs_in_seconds;
}
END_TEST;

/**
 * \brief 纳秒时间
 */
START_TEST(tf_timespec)
{
    struct timespec spec;
    ck_assert(0 < timespec_get(&spec, TIME_UTC));
}
END_TEST;

/**
 * @}
 */

TCase *tc_chrono(void)
{
    TCase *const tc = tcase_create("chrono");
    tcase_add_test(tc, tf_struct_tm);
    tcase_add_test(tc, tf_time_t);
    tcase_add_test(tc, tf_clock_t);
    tcase_add_test(tc, tf_timespec);
    return tc;
}
