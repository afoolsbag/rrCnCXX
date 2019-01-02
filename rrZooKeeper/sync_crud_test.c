/** \copyright Unlicense */

#include <stdbool.h>
#include <stdio.h>

#define USE_STATIC_LIB
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

    /* 节点创建（Create） */
    rc = zoo_create(zh, "/null_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
    rc = zoo_create(zh, "/value_node", "value", sizeof("value"), &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));

    rc = zoo_create(zh, "/parent_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));
    rc = zoo_create(zh, "/parent_node/child_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));

    rc = zoo_create(zh, "/nonexistent/dangling_node", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc != ZOK)
        fprintf(stderr, "zoo_create failed: %s\n", zerror(rc));

    /* 节点读取（Read） */
    rc = zoo_exists(zh, "/zookeeper", false, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_exists failed: %s\n", zerror(rc));

    char buf[256];
    int len = sizeof(buf);
    rc = zoo_get(zh, "/value_node", false, buf, &len, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_get failed: %s\n", zerror(rc));

    struct String_vector strings = {0};
    rc = zoo_get_children(zh, "/parent_node2", false, &strings);
    if (strings.count)
        deallocate_String_vector(&strings);
    if (rc != ZOK)
        fprintf(stderr, "zoo_get_children failed: %s\n", zerror(rc));

    /* 节点变更（Update） */
    rc = zoo_set(zh, "/value_node", "12345", sizeof("12345"), -1);
    if (rc != ZOK)
        fprintf(stderr, "zoo_set failed: %s\n", zerror(rc));

    /* 节点删除（Delete） */
    rc = zoo_delete(zh, "/null_node", -1);
    if (rc != ZOK)
        fprintf(stderr, "zoo_delete failed: %s\n", zerror(rc));

    /* 连接销毁 */
    rc = zookeeper_close(zh);
    if (rc != ZOK) {
        fprintf(stderr, "zookeeper_close failed: %s\n", zerror(rc));
        return EXIT_FAILURE;
    }
    zh = NULL;

    return EXIT_SUCCESS;
}
