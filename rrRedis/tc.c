/**
 * \copyright Unlicense
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <WinSock2.h>
#endif

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

/**
 * \brief 超时。
 */
START_TEST(tf_timeout)
{
    redisContext *c = redisConnectWithTimeout(host_address, 65535, timeout);
    ck_assert(c);
    ck_assert(c->err == REDIS_ERR_IO);
    redisFree(c);
}
END_TEST;

static redisContext *tcc = NULL;  /**< Test Case Context */

static void setup(void)
{
    tcc = redisConnectWithTimeout(host_address, host_port, timeout);
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
    ck_assert_int_eq(r->type, REDIS_REPLY_STATUS);
    ck_assert_str_eq(r->str, "PONG");
    freeReplyObject(r);
}
END_TEST;

TCase *tc(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_timeout);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_ping);
    return tc;
}
