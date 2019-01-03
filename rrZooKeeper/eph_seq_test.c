/** \copyright Unlicense */

#include <stdio.h>

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
    zh = zookeeper_init(host, NULL, timeout, NULL, NULL, 0);
    if (!zh) {
        fprintf(stderr, "zookeeper_init failed: %s\n", zerror(errno));
        return EXIT_FAILURE;
    }

    /* 前置 */
    rc = zoo_create(zh, "/eph_nodes", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
    rc = zoo_create(zh, "/seq_nodes", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
    rc = zoo_create(zh, "/eph_seq_nodes", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));

    /* 等待命令 */
    int ch;
    while ((ch = getchar()) != 'q') {
        switch (ch) {
        case 'e':
        {
            rc = zoo_create(zh, "/eph_nodes/eph_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, NULL, 0);
            if (rc != ZOK)
                fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
            break;
        }
        case 's':
        {
            char buf[256];
            const int len = sizeof(buf);
            rc = zoo_create(zh, "/seq_nodes/seq_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_SEQUENCE, buf, len);
            if (rc != ZOK)
                fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
            break;
        }
        case 'b':
        {
            char buf[256];
            const int len = sizeof(buf);
            rc = zoo_create(zh, "/eph_seq_nodes/eph_seq_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL | ZOO_SEQUENCE, buf, len);
            if (rc != ZOK)
                fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
            break;
        }
        default:
            break;
        }
    }

    /* 连接销毁 */
    rc = zookeeper_close(zh);
    if (rc != ZOK) {
        fprintf(stderr, "zookeeper_close failed: %s\n", zerror(rc));
        return EXIT_FAILURE;
    }
    zh = NULL;

    return EXIT_SUCCESS;
}
