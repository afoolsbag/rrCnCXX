/*===-- Asynchronous CRUD --------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 异步增删改查。
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
 * Aux Functions
 */

static inline void sleep100ms(void)
{
#if defined(__GNUC__)
    usleep(100 * 1000);
#elif defined(_MSC_VER)
    Sleep(100);
#endif
}

static bool shoddy_mutex_locked = false;

static inline void shoddy_lock(void)
{
    shoddy_mutex_locked = true;
}

static inline void shoddy_unlock(void)
{
    shoddy_mutex_locked = false;
}

static inline void shoddy_wait(void)
{
    if (shoddy_mutex_locked)
        sleep100ms();
}

/*------------------------------------------------------------------------------
 * Constant
 */

static const char root1[] = "/rrzookeeper";
static const char root2[] = "/rrzookeeper/async_curd";
static const char *root = root2;
static const char node_path[] = "/rrzookeeper/async_curd/value_node";
static const char node_value[] = "value";
static const char node_eulav[] = "eulav";

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
    rc = zoo_delete(tczh, node_path, -1);
    ck_assert_msg(rc == ZOK || rc == ZNONODE, "zoo_delete failed: %s\n", zerror(rc));
}

static void teardown(void)
{
    const int rc = zookeeper_close(tczh);
    ck_assert_msg(rc == ZOK, "zookeeper_clost failed: %s\n", zerror(rc));
    tczh = NULL;

    puts("");
}

/*------------------------------------------------------------------------------
 * Create
 */

static void on_acreate_completion(int rc, const char *val, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    if (strcmp(val, node_path) != 0)
        fprintf(stderr, "%s error: val !=....\n", __func__);

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

/**
 * \brief 异步创建节点。
 */
START_TEST(tf_create)
{
    shoddy_lock();
    const int rc = zoo_acreate(tczh, node_path, node_value, sizeof node_value, &ZOO_OPEN_ACL_UNSAFE, 0, on_acreate_completion, NULL);
    ck_assert_msg(rc == ZOK, "zookeeper_acreate failed: %s\n", zerror(rc));
    shoddy_wait();
}
END_TEST;

/*------------------------------------------------------------------------------
 * Read
 */

static void on_aexists_completion(int rc, const struct Stat *stat, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    (void)stat;

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

static void on_aget_completion(int rc, const char *val, int len, const struct Stat *stat, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    if (len != sizeof node_value)
        fprintf(stderr, "%s error: len !=...\n", __func__);

    if (memcmp(val, node_value, (size_t)fmin(len, sizeof node_value)) != 0)
        fprintf(stderr, "%s error: val !=...\n", __func__);

    (void)stat;

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

static void on_aget_children_completion(int rc, const struct String_vector *strs, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    if (strs) {
        for (int i = 0; i < strs->count; ++i)
            printf("%s's sub-node: %s\n", root, strs->data[i]);
    } else {
        fprintf(stderr, "%s error: strs == null\n", __func__);
    }

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

/**
 * \brief 异步读取节点。
 */
START_TEST(tf_read)
{
    int rc = ZOK;

    /* 检查节点存在 */
    shoddy_lock();
    rc = zoo_aexists(tczh, node_path, false, on_aexists_completion, NULL);
    ck_assert_msg(rc == ZOK, "zookeeper_aexists failed: %s\n", zerror(rc));
    shoddy_wait();

    /* 读取节点值 */
    shoddy_lock();
    rc = zoo_aget(tczh, node_path, false, on_aget_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_aget failed: %s\n", zerror(rc));
    shoddy_wait();

    /* 获取子节点 */
    shoddy_lock();
    rc = zoo_aget_children(tczh, root, false, on_aget_children_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_aget_children failed: %s\n", zerror(rc));
    shoddy_wait();
}
END_TEST;

/*------------------------------------------------------------------------------
 * Update
 */

static void on_aset_completion(int rc, const struct Stat *stat, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    (void)stat;

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

/**
 * \brief 异步变更节点。
 */
START_TEST(tf_update)
{
    /* 变更节点 */
    shoddy_lock();
    const int rc = zoo_aset(tczh, node_path, node_eulav, sizeof node_eulav, -1, on_aset_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_aset failed: %s\n", zerror(rc));
    shoddy_wait();
}
END_TEST;

/*------------------------------------------------------------------------------
 * Delete
 */

static void on_adelete_completion(int rc, const void *data)
{
    if (rc != ZOK)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));

    if (data)
        fprintf(stderr, "%s error: data != null.\n", __func__);

    shoddy_unlock();
}

/**
 * \brief 异步删除节点。
 */
START_TEST(tf_delete)
{
    int rc = ZOK;

    /* 删除节点 */
    shoddy_lock();
    rc = zoo_adelete(tczh, node_path, -1, on_adelete_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
    shoddy_wait();

    shoddy_lock();
    rc = zoo_adelete(tczh, root, -1, on_adelete_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
    shoddy_wait();
}
END_TEST;

TCase *tc_async_crud(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_create);
    tcase_add_test(tc, tf_read);
    tcase_add_test(tc, tf_update);
    tcase_add_test(tc, tf_delete);
    return tc;
}
