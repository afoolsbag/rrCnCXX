/** \copyright Unlicense */

#include <stdbool.h>
#include <stdio.h>

#include <zookeeper/zookeeper.h>

void on_acreate_completion(int rc, const char *value, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_acreate failed: %s\n", zerror(rc));
}

void on_aexists_completion(int rc, const struct Stat *stat, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aexists failed: %s\n", zerror(rc));
}

void on_aget_completion(int rc, const char *value, int value_len, const struct Stat *stat, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aget failed: %s\n", zerror(rc));
}

void on_aget_children_completion(int rc, const struct String_vector *strings, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aget_children failed: %s\n", zerror(rc));
}

void on_aset_completion(int rc, const struct Stat *stat, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aset failed: %s\n", zerror(rc));
}

void on_adelete_completion(int rc, const void *data)
{
    printf("%s\n", __func__);
    if (rc != ZOK)
        fprintf(stderr, "zoo_adelete failed: %s\n", zerror(rc));
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

    /* 节点创建（Create） */
    rc = zoo_acreate(zh, "/anode", NULL, -1, &ZOO_OPEN_ACL_UNSAFE, 0, on_acreate_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_acreate failed: %s\n", zerror(rc));

    /* 节点读取（Read） */
    rc = zoo_aexists(zh, "/anode", false, on_aexists_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aexists failed: %s\n", zerror(rc));

    rc = zoo_aget(zh, "/anode", false, on_aget_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aget failed: %s\n", zerror(rc));

    rc = zoo_aget_children(zh, "/anode", false, on_aget_children_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aget_children failed: %s\n", zerror(rc));

    /* 节点变更（Update） */
    rc = zoo_aset(zh, "/anode", "12345", sizeof("12345"), -1, on_aset_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_aset failed: %s\n", zerror(rc));

    /* 节点删除（Delete） */
    rc = zoo_adelete(zh, "/anode", -1, on_adelete_completion, NULL);
    if (rc != ZOK)
        fprintf(stderr, "zoo_adelete failed: %s\n", zerror(rc));

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
