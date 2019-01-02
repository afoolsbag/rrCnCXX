/** \copyright Unlicense */

#include <stdio.h>

#define USE_STATIC_LIB
#include <zookeeper/zookeeper.h>

static const char *ztype(int state)
{
    if (state == ZOO_CREATED_EVENT)
        return "CREATED_EVENT";
    if (state == ZOO_DELETED_EVENT)
        return "DELETED_EVENT";
    if (state == ZOO_CHANGED_EVENT)
        return "CHANGED_EVENT";
    if (state == ZOO_CHILD_EVENT)
        return "CHILD_EVENT";
    if (state == ZOO_SESSION_EVENT)
        return "SESSION_EVENT";
    if (state == ZOO_NOTWATCHING_EVENT)
        return "NOTWATCHING_EVENT";

    return "UNKNOWN_EVENT_TYPE";
}

static const char *zstate(const int state)
{
    if (state == 0)
        return "CLOSED_STATE";
    if (state == ZOO_CONNECTING_STATE)
        return "CONNECTING_STATE";
    if (state == ZOO_ASSOCIATING_STATE)
        return "ASSOCIATING_STATE";
    if (state == ZOO_CONNECTED_STATE)
        return "CONNECTED_STATE";
    if (state == ZOO_EXPIRED_SESSION_STATE)
        return "EXPIRED_SESSION_STATE";
    if (state == ZOO_AUTH_FAILED_STATE)
        return "AUTH_FAILED_STATE";

    return "INVALID_STATE";
}

const char *zpath(const char *const path)
{
    if (!path)
        return "<null>";
    if (!strlen(path))
        return "<empty>";
    return path;
}

void init_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    printf("init_watcher: type=%s, state=%s, path=%s.\n", ztype(type), zstate(state), zpath(path));
}

void exists_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    printf("exists_watcher: type=%s, state=%s, path=%s.\n", ztype(type), zstate(state), zpath(path));

    const int rc = zoo_wexists(zh, "/watch_node", exists_watcher, NULL, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wexists failed: %s\n", zerror(rc));
}

void get_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    printf("get_watcher: type=%s, state=%s, path=%s.\n", ztype(type), zstate(state), zpath(path));

    char buf[256];
    int len = sizeof(buf);
    const int rc = zoo_wget(zh, "/watch_node", get_watcher, NULL, buf, &len, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wget failed: %s\n", zerror(rc));
}

void get_children_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    printf("get_children_watcher: type=%s, state=%s, path=%s.\n", ztype(type), zstate(state), zpath(path));

    struct String_vector strings = {0};
    const int rc = zoo_wget_children(zh, "/watch_node", get_children_watcher, NULL, &strings);
    if (strings.count)
        deallocate_String_vector(&strings);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wget_children failed: %s\n", zerror(rc));
}

int main()
{
    const char host[] = "127.0.0.1:2181";
    const int timeout = 10 * 1000;

    zhandle_t *zh = NULL;
    int rc = ZOK;

    /* 日志配置 */
    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);
    zoo_set_log_stream(stderr);

    /* 连接初始化 */
    zh = zookeeper_init(host, init_watcher, timeout, NULL, NULL, 0);
    if (!zh) {
        fprintf(stderr, "zookeeper_init failed: %s\n", zerror(errno));
        return EXIT_FAILURE;
    }

    /* exists 监视 CREATED_EVENT 和 DELETED_EVENT */
    rc = zoo_wexists(zh, "/watch_node", exists_watcher, NULL, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wexists failed: %s\n", zerror(rc));

    /* get 监视 DELETED_EVENT 和 CHANGED_EVENT */
    char buf[256];
    int len = sizeof(buf);
    rc = zoo_wget(zh, "/watch_node", get_watcher, NULL, buf, &len, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wget failed: %s\n", zerror(rc));

    /* get_children 监视 CHILD_EVENT */
    struct String_vector strings = {0};
    rc = zoo_wget_children(zh, "/watch_node", get_children_watcher, NULL, &strings);
    if (strings.count)
        deallocate_String_vector(&strings);
    if (rc != ZOK)
        fprintf(stderr, "zoo_wget_children failed: %s\n", zerror(rc));

    /* 等待退出 */
    getchar();

    /* 连接销毁 */
    rc = zookeeper_close(zh);
    if (rc != ZOK) {
        fprintf(stderr, "zookeeper_close failed: %s\n", zerror(rc));
        return EXIT_FAILURE;
    }
    zh = NULL;

    return EXIT_SUCCESS;
}
