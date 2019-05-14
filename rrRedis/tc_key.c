/**
 * \copyright Unlicense
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
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
 * \brief 键。
 * \details 最大长度 512 MiB。
 */
START_TEST(tf_key)
{}
END_TEST;

/**
 * \sa [`EXISTS`](https://redis.io/commands/set)
 */
START_TEST(tf_EXISTS)
{
    static const char key[] = "rrRedis:key";

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "SET %s %s", key, "placeholder"));
    r = redisCommand(tcc, "EXISTS %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, true);
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "EXISTS %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, false);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 有效期。
 *
 * \sa [`EXPIRE`](https://redis.io/commands/expire)
 * \sa [`PEXPIRE`](https://redis.io/commands/pexpire)
 * \sa [`EXPIREAT`](https://redis.io/commands/expireat)
 * \sa [`PERSIST`](https://redis.io/commands/persist)
 * \sa [`TTL`](https://redis.io/commands/ttl)
 */
START_TEST(tf_expire)
{}
END_TEST;

TCase *tc_key(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_key);
    tcase_add_test(tc, tf_EXISTS);
    tcase_add_test(tc, tf_expire);
    return tc;
}
