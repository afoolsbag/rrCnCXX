/**
 * \copyright Unlicense
 */

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <check.h>

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable: 4200)
#endif
#include <hiredis/hiredis.h>
#ifdef _WIN32
#pragma warning(pop)
#endif

#include "ts.h"

static redisContext *tcc = NULL;  /**< Test Case Context */

static void setup(void)
{
    tcc = redisConnectWithTimeout(host_address, host_port, timeout);
    ck_assert(tcc);
    ck_assert_int_eq(tcc->err, REDIS_OK);
}

static void teardown(void)
{
    redisFree(tcc);
}

/**
 * \brief 链表。
 *
 * \sa [`RPUSH`](https://redis.io/commands/rpush)
 * \sa [`LRANGE`](https://redis.io/commands/lrange)
 *
 */
START_TEST(tf_list)
{
    static const char key[] = "rrRedis:list";
    static const char val[][5] = {"val1", "val2", "val3"};

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    freeReplyObject(redisCommand(tcc, "RPUSH %s %s %s %s", key, val[0], val[1], val[2]));
    r = redisCommand(tcc, "LRANGE %s 0 -1", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_ARRAY);
    for (size_t i = 0; i < r->elements; ++i) {
        ck_assert_int_eq(r->element[i]->type, REDIS_REPLY_STRING);
        ck_assert_str_eq(r->element[i]->str, val[i]);
    }
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "LRANGE %s 0 -1", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_ARRAY);
    ck_assert_int_eq(r->elements, 0);
    freeReplyObject(r);
}
END_TEST;

TCase *tc_list(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_list);
    return tc;
}
