/** \copyright Unlicense */

#include <errno.h>
#include <stdio.h>

#include <zookeeper/zookeeper.h>

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
