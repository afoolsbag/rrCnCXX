/*===-- Synchronous CRUD ---------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 同步增删改查。
 *
 * \version 2019-03-18
 * \since 2018-12-30
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>

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
static const char root2[] = "/rrzookeeper/sync_curd";
static const char *root = root2;
static const char null_node_path[] = "/rrzookeeper/sync_curd/null_node";
static const char value_node_path[] = "/rrzookeeper/sync_curd/value_node";
static const char value_node_value[] = "value";
static const char value_node_eulav[] = "eulav";
static const char dangling_node_path[] = "/rrzookeeper/sync_curd/nonexistent/dangling_node";

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
    rc = zoo_delete(tczh, null_node_path, -1);
    ck_assert_msg(rc == ZOK || rc == ZNONODE, "zoo_delete failed: %s\n", zerror(rc));
    rc = zoo_delete(tczh, value_node_path, -1);
    ck_assert_msg(rc == ZOK || rc == ZNONODE, "zoo_delete failed: %s\n", zerror(rc));
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

/**
 * \brief 同步创建节点。
 */
START_TEST(tf_create)
{
    int rc = ZOK;

    /* 创建空节点 */
    rc = zoo_create(tczh, null_node_path, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));

    /* 创建值节点 */
    rc = zoo_create(tczh, value_node_path, value_node_value, sizeof value_node_value, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));

    /* 不允许跨级创建节点 */
    rc = zoo_create(tczh, dangling_node_path, NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZNONODE, "zoo_create failed: %s\n", zerror(rc));
}
END_TEST;

/**
 * \brief 同步读取节点。
 */
START_TEST(tf_read)
{
    int rc = ZOK;

    /* 检查节点存在 */
    rc = zoo_exists(tczh, null_node_path, false, NULL);
    ck_assert_msg(rc == ZOK, "zoo_exists failed: %s\n", zerror(rc));

    /* 检查节点不存在 */
    rc = zoo_exists(tczh, dangling_node_path, false, NULL);
    ck_assert_msg(rc == ZNONODE, "zoo_exists failed: %s\n", zerror(rc));

    /* 读取节点值 */
    char buf[256];
    int len = sizeof(buf);
    rc = zoo_get(tczh, value_node_path, false, buf, &len, NULL);
    ck_assert_msg(rc == ZOK, "zoo_get failed: %s\n", zerror(rc));
    ck_assert_str_eq(buf, value_node_value);

    /* 获取子节点 */
    struct String_vector strs = {0};
    rc = zoo_get_children(tczh, root, false, &strs);
    ck_assert_msg(rc == ZOK, "zoo_get_children failed: %s\n", zerror(rc));
    for (int i = 0; i < strs.count; ++i)
        printf("%s's sub-node: %s\n", root, strs.data[i]);
    if (strs.count)
        deallocate_String_vector(&strs);
}
END_TEST;

/**
 * \brief 同步变更节点。
 */
START_TEST(tf_update)
{
    /* 变更节点 */
    const int rc = zoo_set(tczh, value_node_path, value_node_eulav, sizeof value_node_eulav, -1);
    ck_assert_msg(rc == ZOK, "zoo_set failed: %s\n", zerror(rc));
}
END_TEST;

/**
 * \brief 同步删除节点。
 */
START_TEST(tf_delete)
{
    int rc = ZOK;

    /* 不允许跨级删除节点 */
    rc = zoo_delete(tczh, root, -1);
    ck_assert_msg(rc == ZNOTEMPTY, "zoo_delete failed: %s\n", zerror(rc));

    /* 删除节点 */
    rc = zoo_delete(tczh, null_node_path, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
    rc = zoo_delete(tczh, value_node_path, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
    rc = zoo_delete(tczh, root, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));

}
END_TEST;

TCase *tc_sync_crud(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_create);
    tcase_add_test(tc, tf_read);
    tcase_add_test(tc, tf_update);
    tcase_add_test(tc, tf_delete);
    return tc;
}
