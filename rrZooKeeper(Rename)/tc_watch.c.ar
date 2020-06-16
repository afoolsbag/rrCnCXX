/*===-- Watch --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 监视。
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
#include <string.h>

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

static const char *ztype(int type)
{
    if (type == ZOO_CREATED_EVENT)     return "CREATED_EVENT";
    if (type == ZOO_DELETED_EVENT)     return "DELETED_EVENT";
    if (type == ZOO_CHANGED_EVENT)     return "CHANGED_EVENT";
    if (type == ZOO_CHILD_EVENT)       return "CHILD_EVENT";
    if (type == ZOO_SESSION_EVENT)     return "SESSION_EVENT";
    if (type == ZOO_NOTWATCHING_EVENT) return "NOTWATCHING_EVENT";
    return "UNKNOWN_EVENT_TYPE";
}

static const char *zstate(const int stat)
{
    if (stat == 0)                         return "CLOSED_STATE";
    if (stat == ZOO_CONNECTING_STATE)      return "CONNECTING_STATE";
    if (stat == ZOO_ASSOCIATING_STATE)     return "ASSOCIATING_STATE";
    if (stat == ZOO_CONNECTED_STATE)       return "CONNECTED_STATE";
    if (stat == ZOO_EXPIRED_SESSION_STATE) return "EXPIRED_SESSION_STATE";
    if (stat == ZOO_AUTH_FAILED_STATE)     return "AUTH_FAILED_STATE";
    return "INVALID_STATE";
}

static const char *zpath(const char *path)
{
    if (!path)         return "<null>";
    if (!strlen(path)) return "<empty>";
    return path;
}

/*------------------------------------------------------------------------------
 * Constant
 */

static const char root1[] = "/rrzookeeper";
static const char root2[] = "/rrzookeeper/watch";
static const char *root = root2;
static const char node_path[] = "/rrzookeeper/watch/node";
static const char node_value[] = "value";
static const char node_eulav[] = "eulav";

static const bool rewatch = false;

/*------------------------------------------------------------------------------
 * Test Case
 */

static zhandle_t *tczh = NULL;  ///< Test Case ZooKeeper Handle

void init_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx)
{
    (void)zh;
    (void)ctx;

    printf("%s: type=%s, state=%s, path=%s.\n", __func__, ztype(type), zstate(stat), zpath(path));
}

static void setup(void)
{
    puts(__FILE__);

    tczh = zookeeper_init(host, init_watcher, timeout, NULL, NULL, 0);
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
 * Exists Watcher
 */

static void on_awexists_completion(int rc, const struct Stat *stat, const void *data)
{
    (void)stat;
    (void)data;

    if (rc != ZOK && rc != ZNONODE)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));
}

static void exists_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx)
{
    printf("%s: type=%s, state=%s, path=%s.\n", __func__, ztype(type), zstate(stat), zpath(path));

    if (rewatch) {
        const int rc = zoo_wexists(zh, path, exists_watcher, ctx, NULL);
        if (rc != ZOK && rc != ZNONODE)
            fprintf(stderr, "%s: zoo_wexists failed: %s\n", __func__, zerror(rc));
    }
}

/**
 * \brief exists 监视。
 * \details 监视 `CREATED_EVENT` 和 `DELETED_EVENT`
 */
START_TEST(tf_exists_watch)
{
    int rc = ZOK;


    rc = zoo_awexists(tczh, node_path, exists_watcher, NULL, on_awexists_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awexists failed: %s\n", zerror(rc));

    rc = zoo_create(tczh, node_path, node_value, sizeof node_value, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));


    rc = zoo_awexists(tczh, node_path, exists_watcher, NULL, on_awexists_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awexists failed: %s\n", zerror(rc));

    rc = zoo_delete(tczh, node_path, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
}
END_TEST;

/*------------------------------------------------------------------------------
 * Get Watcher
 */

void on_awget_completion(int rc, const char *val, int len, const struct Stat *stat, const void *data)
{
    (void)val;
    (void)len;
    (void)stat;
    (void)data;

    if (rc != ZOK && rc != ZNONODE)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));
}

void get_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx)
{
    printf("%s: type=%s, state=%s, path=%s.\n", __func__, ztype(type), zstate(stat), zpath(path));

    if (rewatch) {
        const int rc = zoo_awget(zh, path, get_watcher, ctx, on_awget_completion, NULL);
        if (rc != ZOK && rc != ZNONODE)
            fprintf(stderr, "%s: zoo_awget failed: %s\n", __func__, zerror(rc));
    }
}

/**
 * \brief get 监视。
 * \details 监视 `CHANGED_EVENT` 和 `DELETED_EVENT`
 */
START_TEST(tf_get_watch)
{
    int rc = ZOK;


    rc = zoo_create(tczh, node_path, node_value, sizeof node_value, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));


    rc = zoo_awget(tczh, node_path, get_watcher, NULL, on_awget_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awget failed: %s\n", zerror(rc));

    rc = zoo_set(tczh, node_path, node_eulav, sizeof node_eulav, -1);
    ck_assert_msg(rc == ZOK, "zoo_set failed: %s\n", zerror(rc));


    rc = zoo_awget(tczh, node_path, get_watcher, NULL, on_awget_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awget failed: %s\n", zerror(rc));

    rc = zoo_delete(tczh, node_path, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
}
END_TEST;

/*------------------------------------------------------------------------------
 * Get Children Watcher
 */

void on_awget_children_completion(int rc, const struct String_vector *strs, const void *data)
{
    (void)rc;
    (void)strs;
    (void)data;

    if (rc != ZOK && rc != ZNONODE)
        fprintf(stderr, "%s error: %s\n", __func__, zerror(rc));
}

void get_children_watcher(zhandle_t *zh, int type, int stat, const char *path, void *ctx)
{
    printf("%s: type=%s, state=%s, path=%s.\n", __func__, ztype(type), zstate(stat), zpath(path));

    if (rewatch) {
        const int rc = zoo_awget_children(zh, path, get_children_watcher, ctx, on_awget_children_completion, NULL);
        if (rc != ZOK && rc != ZNONODE)
            fprintf(stderr, "%s: zoo_wget_children failed: %s\n", __func__, zerror(rc));
    }
}

/**
 * \brief get_children 监视。
 * \details 监视 `CHILD_EVENT`
 */
START_TEST(tf_get_children_watch)
{
    int rc = ZOK;


    rc = zoo_awget_children(tczh, root, get_children_watcher, NULL, on_awget_children_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awget_children failed: %s\n", zerror(rc));

    rc = zoo_create(tczh, node_path, node_value, sizeof node_value, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    ck_assert_msg(rc == ZOK, "zoo_create failed: %s\n", zerror(rc));


    rc = zoo_awget_children(tczh, root, get_children_watcher, NULL, on_awget_children_completion, NULL);
    ck_assert_msg(rc == ZOK, "zoo_awget_children failed: %s\n", zerror(rc));

    rc = zoo_delete(tczh, node_path, -1);
    ck_assert_msg(rc == ZOK, "zoo_delete failed: %s\n", zerror(rc));
}
END_TEST;

TCase *tc_watch(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, tf_exists_watch);
    tcase_add_test(tc, tf_get_watch);
    tcase_add_test(tc, tf_get_children_watch);
    return tc;
}
