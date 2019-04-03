/**
 * \copyright Unlicense
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <WinSock2.h>

#include <check.h>

#pragma warning(push)
#pragma warning(disable: 4200)
#include <hiredis/hiredis.h>
#pragma warning(pop)

#include "ts.h"

static redisContext *tcc = NULL;  /**< Test Case Context */

static void setup(void)
{
    tcc = redisConnectWithTimeout(host_addr, host_port, timeout);
    if (!tcc)
        ck_abort_msg("Connect failed: can't allocate redis context.");
    if (tcc->err) {
        fprintf(stderr, "Connect failed: %s\n", tcc->errstr);
        redisFree(tcc);
        ck_abort();
    }
}

static void teardown(void)
{
    redisFree(tcc);
}

/**
 * \brief 乒乓。
 *
 * \sa [`PING`](https://redis.io/commands/ping)
 */
START_TEST(tf_ping)
{
    redisReply *r = redisCommand(tcc, "PING");
    ck_assert_str_eq(r->str, "PONG");
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 字符串。
 *
 * \sa [`SET`](https://redis.io/commands/set)
 * \sa [`GET`](https://redis.io/commands/get)
 * \sa [`EXISTS`](https://redis.io/commands/exists)
 * \sa [`DEL`](https://redis.io/commands/del)
 */
START_TEST(tf_string)
{
    const char key[] = "rrRedis:string";
    const char val[] = "The quick brown fox jumps over the lazy dog.";

    redisReply *r = NULL;

    r = redisCommand(tcc, "SET %s %s", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);

    r = redisCommand(tcc, "GET %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_STRING);
    ck_assert_str_eq(r->str, val);
    freeReplyObject(r);
}
END_TEST;

/**
 * \brief 二进制。
 * \details 最大长度 512 MiB。
 *
 * \sa [`TYPE`](https://redis.io/commands/type)
 * \sa [`GETBIT`](https://redis.io/commands/getbit)
 * \sa [`SETBIT`](https://redis.io/commands/setbit)
 * \sa [`BITCOUNT`](https://redis.io/commands/bitcount)
 */
START_TEST(tf_binary)
{
    const char key[] = "rrRedis:binary";
    const char bin[] = "The quick brown fox jumps over the lazy dog.";
    const size_t siz = sizeof bin;

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
    const char key[] = "rrRedis:integer";
    int val = 0;

    redisReply *r = NULL;

    r = redisCommand(tcc, "SET %s %d", key, val);
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "OK");
    freeReplyObject(r);

    r = redisCommand(tcc, "INCR %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, ++val);
    freeReplyObject(r);

    r = redisCommand(tcc, "DECR %s", key);
    ck_assert_int_eq(r->type, REDIS_REPLY_INTEGER);
    ck_assert_int_eq(r->integer, --val);
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
{
    
}
END_TEST;

/**
 * \brief 链表。
 *
 * \sa [`LPUSH`](https://redis.io/commands/lpush)
 * \sa [`LPOP`](https://redis.io/commands/lpop)
 * \sa [`RPUSH`](https://redis.io/commands/rpush)
 * \sa [`RPOP`](https://redis.io/commands/rpop)
 * \sa [`RPOPLPUSH`](https://redis.io/commands/rpoplpush)
 * \sa [`LRANGE`](https://redis.io/commands/lrange)
 *
 */
START_TEST(tf_list)
{
    
}
END_TEST;

/**
 * \brief 散列。
 * \details 映射、字典、哈希。
 *
 * \sa [`HSET`](https://redis.io/commands/hset)
 * \sa [`HMSET`](https://redis.io/commands/hmset)
 * \sa [`HGET`](https://redis.io/commands/hget)
 * \sa [`HGETALL`](https://redis.io/commands/hgetall)
 */
START_TEST(tf_hash)
{
    
}
END_TEST;

/**
 * \brief 集合。
 *
 * \sa [`SADD`](https://redis.io/commands/sadd)
 * \sa [`SMEMBERS`](https://redis.io/commands/smembers)
 * \sa [`SPOP`](https://redis.io/commands/spop)
 *
 * \sa [`SINTER`](https://redis.io/commands/sinter)
 * \sa [`SUNION`](https://redis.io/commands/sunion)
 */
START_TEST(tf_set)
{
    
}
END_TEST;

/**
 * \brief 有序集合。
 *
 * \sa [`ZADD](https://redis.io/commands/ZADD)
 */
START_TEST(tf_sorted_set)
{
    
}
END_TEST;

TCase *tc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_ping);
    tcase_add_test(tc, tf_string);
    tcase_add_test(tc, tf_binary);
    tcase_add_test(tc, tf_atomic);
    tcase_add_test(tc, tf_batch);
    tcase_add_test(tc, tf_expire);
    tcase_add_test(tc, tf_list);
    tcase_add_test(tc, tf_hash);
    tcase_add_test(tc, tf_set);
    tcase_add_test(tc, tf_sorted_set);
    return tc;
}
