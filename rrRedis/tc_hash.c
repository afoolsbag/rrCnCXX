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
 * \brief 散列。
 * \details 映射、字典、哈希。
 *
 * \sa [`HSET`](https://redis.io/commands/hset)
 * \sa [`HGET`](https://redis.io/commands/hget)
 * \sa [`HVALS`](https://redis.io/commands/hvals)
 */
START_TEST(tf_hash)
{
    static const char key[] = "rrRedis:hash";
    static const char hkey[][5] = {"key1", "key2", "key3"};
    static const char hval[][5] = {"val1", "val2", "val3"};

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    freeReplyObject(redisCommand(tcc, "HMSET %s %s %s %s %s %s %s", key, hkey[0], hval[0], hkey[1], hval[1], hkey[2], hval[2]));
    r = redisCommand(tcc, "HVALS %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_ARRAY);
    for (size_t i = 0; i < r->elements; ++i) {
        ck_assert_int_eq(r->element[i]->type, REDIS_REPLY_STRING);
        ck_assert_str_eq(r->element[i]->str, hval[i]);
    }
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "HVALS %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_ARRAY);
    ck_assert_int_eq(r->elements, 0);
    freeReplyObject(r);
}
END_TEST;

TCase *tc_hash(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_hash);
    return tc;
}
