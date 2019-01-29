#include <stdlib.h>

#include <check/check.h>

#include "_test.h"

/**
 * \addtogroup gMemory
 * @{
 */

/**
 * \brief 内存分配（Memory Allocate）
 */
START_TEST(tf_malloc)
{
    char *p = malloc(666 * sizeof(char));
    if (!p) {
        ck_abort_msg("Not enough memory");
        return;
    }

    /* 使用分配到的空间 */

    free(p);
    p = NULL;
}
END_TEST;

/**
 * \brief 干净分配（Clean Allocate）
 */
START_TEST(tf_calloc)
{
    char *p = calloc(666, sizeof(char));
    if (!p) {
        ck_abort_msg("Not enough memory");
        return;
    }

    ck_assert_int_eq(*p, 0);
    /* 使用分配到的空间 */

    free(p);
    p = NULL;
}
END_TEST;

/**
 * \brief 重新分配（Re-Allocate）
 * \details 变更分配的尺寸。
 */
START_TEST(tf_realloc)
{
    /* 第一次请求分配 233 字节的空间 */
    char *p = realloc(NULL, 233 * sizeof(char));
    if (!p) {
        ck_abort_msg("Not enough memory");
        return;
    }

    /* 并指定前四个字节 */
    p[0] = '2';
    p[1] = '3';
    p[2] = '3';
    p[3] = '\0';
    ck_assert_str_eq(p, "233");

    /* 第二次请求将空间扩大至 666 字节 */
    char *bak = p;
    p = realloc(bak, 666 * sizeof(uint8_t));
    if (!p) {
        free(bak);
        ck_abort_msg("Not enough memory");
        return;
    }
    bak = NULL;

    /* 之前的数据依然有效 */
    ck_assert_str_eq(p, "233");

    /* 从 C11 开始弃用 realloc(p, 0) 用法 */
    free(p);
    p = NULL;
}
END_TEST;

/**
 * @}
 */

TCase *tc_memory(void)
{
    TCase *const tc = tcase_create("memory");
    tcase_add_test(tc, tf_malloc);
    tcase_add_test(tc, tf_calloc);
    tcase_add_test(tc, tf_realloc);
    return tc;
}
