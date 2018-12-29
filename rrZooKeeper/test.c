#include <stdbool.h>
#include <stdio.h>

#define USE_STATIC_LIB

#include <zookeeper/zookeeper.h>

//#pragma comment(lib, "WS2_32.Lib")

static bool connected = false;
static bool expired = false;

void my_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    printf("Event type %d.\n", type);
}

int main(void)
{
    zhandle_t *zh = zookeeper_init("127.0.0.1:2181", my_watcher, 15000, NULL, NULL, 0);

    const static char testRootValue[] = "testRootValue";
    zoo_create(zh, "/testRoot", testRootValue, sizeof(testRootValue), &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);

    const static char testChildValue[] = "testChildValue";
    zoo_create(zh, "/testRoot/testChild", testChildValue, sizeof(testChildValue), &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);

    zookeeper_close(zh);
}
