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
 * \brief `create`
 *
 * \sa [`SET`](https://redis.io/commands/set)
 * \sa [`SETNX`](https://redis.io/commands/setnx)
 */
START_TEST(tf_SETNX)
{
    static const char key[] = "rrRedis:string";
    static const char val[] = "The quick brown fox jumps over the lazy dog.";

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "SET %s %s", key, "placeholder"));
    r = redisCommand(tcc, "SET %s %s NX", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_NIL);
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "SET %s %s NX", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief `update`
 *
 * \sa [`SET`](https://redis.io/commands/set)
 * \sa [`SETXX`](https://redis.io/commands/setxx)
 */
START_TEST(tf_SETXX)
{
    static const char key[] = "rrRedis:string";
    static const char val[] = "The quick brown fox jumps over the lazy dog.";

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "SET %s %s", key, "placeholder"));
    r = redisCommand(tcc, "SET %s %s XX", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "SET %s %s XX", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_NIL);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief `query`
 *
 * \sa [`GET`](https://redis.io/commands/get)
 */
START_TEST(tf_GET)
{
    static const char key[] = "rrRedis:string";
    static const char val[] = "The quick brown fox jumps over the lazy dog.";

    redisReply *r = NULL;

    freeReplyObject(redisCommand(tcc, "SET %s %s", key, val));
    r = redisCommand(tcc, "GET %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_STRING);
    ck_assert_str_eq(r->str, val);
    freeReplyObject(r);

    freeReplyObject(redisCommand(tcc, "DEL %s", key));
    r = redisCommand(tcc, "GET %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_NIL);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 二进制数据。
 * \details 最大长度 512 MiB。
 */
START_TEST(tf_binary)
{
    static const char key[] = "rrRedis:binary";
    static const char bin[] = "The quick brown fox jumps over the lazy dog.";
    static const size_t siz = sizeof bin;

    redisReply *r = NULL;

    r = redisCommand(tcc, "SET %s %b", key, bin, siz);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);

    r = redisCommand(tcc, "GET %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_STRING);
    ck_assert_mem_eq(r->str, bin, r->len);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 原子操作。
 *
 * \sa [`INCR`](https://redis.io/commands/incr)
 * \sa [`DECR`](https://redis.io/commands/decr)
 * \sa [`INCRBY`](https://redis.io/commands/incrby)
 * \sa [`DECRBY`](https://redis.io/commands/decrby)
 * \sa [`GETSET`](https://redis.io/commands/getset)
 */
START_TEST(tf_atomic)
{
    static const char key[] = "rrRedis:integer";

    redisReply *r = NULL;
    int num = 0;

    freeReplyObject(redisCommand(tcc, "SET %s %d", key, num));

    r = redisCommand(tcc, "INCR %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, ++num);
    freeReplyObject(r);

    r = redisCommand(tcc, "DECR %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, --num);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 批量操作。
 *
 * \sa [`MSET`](https://redis.io/commands/mset)
 * \sa [`MGET`](https://redis.io/commands/mget)
 */
START_TEST(tf_batch)
{
    const char key1[] = "rrRedis:multi:1";
    const char val1[] = "Shao Mengting";
    const char key2[] = "rrRedis:multi:2";
    const char val2[] = "Zhu Lu";
    const char key3[] = "rrRedis:multi:3";
    const char val3[] = "Jiang Ting";

    redisReply *r = NULL;

    r = redisCommand(tcc, "MSET %s %s %s %s %s %s", key1, val1, key2, val2, key3, val3);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);

    r = redisCommand(tcc, "MGET %s %s %s", key1, key2, key3);
    ck_assert_int_eq(r->type, REDIS_REPLY_ARRAY);
    ck_assert_str_eq(r->element[0]->str, val1);
    ck_assert_str_eq(r->element[1]->str, val2);
    ck_assert_str_eq(r->element[2]->str, val3);
    freeReplyObject(r);
}
END_TEST;

TCase *tc_string(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_SETNX);
    tcase_add_test(tc, tf_SETXX);
    tcase_add_test(tc, tf_GET);
    tcase_add_test(tc, tf_binary);
    tcase_add_test(tc, tf_atomic);
    tcase_add_test(tc, tf_batch);
    return tc;
}
