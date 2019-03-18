/*===-- Ephemeral & Sequence -----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 临时和顺序。
 *
 * \version 2019-03-18
 * \since 2018-12-30
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef __GNUC__
#include <unistd.h>
#endif

#include <check.h>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)
#endif
#include <zookeeper/zookeeper.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "ts.h"

/*------------------------------------------------------------------------------
 * Constant
 */

static const char root1[] = "/rrzookeeper";
static const char root2[] = "/rrzookeeper/eph_seq";
static const char eph_node_path[] = "/rrzookeeper/eph_seq/eph";
static const char seq_node_path[] = "/rrzookeeper/eph_seq/seq";
static const char both_node_path[] = "/rrzookeeper/eph_seq/eph_seq";

/*------------------------------------------------------------------------------
 * Test Case
 */

static zhandle_t *tczh = NULL;  ///< Test Case ZooKeeper Handle

static void setup(void)
{
    puts(__FILE__);

    tczh = zookeeper_init(host, NULL, timeout, NULL, NULL, 0);
    ck_assert_msg(tczh, "zookeeper_init failed: %s\n", zerror(errno));

    int rc = ZOK;

    rc = zoo_create(tczh, root1, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK || rc == ZNODEEXISTS, "zoo_create failed: %s\n", zerror(rc));
    rc = zoo_create(tczh, root2, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK || rc == ZNODEEXISTS, "zoo_create failed: %s\n", zerror(rc));
}

static void teardown(void)
{
    const int rc = zookeeper_close(tczh);
    ck_assert_msg(rc == ZOK, "zookeeper_close failed: %s\n", zerror(errno));
    tczh = NULL;

    puts("");
}

/*------------------------------------------------------------------------------
 * Test Functions
 */

START_TEST(tf_eph)
{
    int rc = ZOK;

    rc = zoo_create(tczh, eph_node_path, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));

    rc = zoo_exists(tczh, eph_node_path, false, NULL);
    ck_assert_msg(rc == ZOK, "zoo_exists failed: %s\n", zerror(rc));
}
END_TEST;

START_TEST(tf_seq)
{
    int rc = ZOK;

    char buf[256];
    rc = zoo_create(tczh, seq_node_path, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_SEQUENCE, buf, sizeof buf);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));

    rc = zoo_exists(tczh, buf, false, NULL);
    ck_assert_msg(rc == ZOK, "zoo_exists failed: %s\n", zerror(rc));
}
END_TEST;

START_TEST(tf_eph_seq)
{
    int rc = ZOK;
    char buf[256];

    rc = zoo_create(tczh, both_node_path, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL | ZOO_SEQUENCE, buf, sizeof buf);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));

    rc = zoo_exists(tczh, buf, false, NULL);
    ck_assert_msg(rc == ZOK, "zoo_exists failed: %s\n", zerror(rc));
}
END_TEST;

TCase *tc_eph_seq(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_eph);
    tcase_add_test(tc, tf_seq);
    tcase_add_test(tc, tf_eph_seq);
    return tc;
}
