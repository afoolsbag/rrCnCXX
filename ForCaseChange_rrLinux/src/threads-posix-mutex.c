/** \file
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread1/>
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread2/>
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread3/>
 *  \author zhengrr
 *  \date 2016-10-11 – 27
 *  \copyright The MIT License
 */
#ifdef __GNUC__

#include <stdbool.h>
#include <pthread.h>

static struct {
        int value;
        pthread_mutex_t mutex;
} money;

static void *make_money(void *arg)
{
        bool mutex_done = false;

        if (!mutex_done &&
            !pthread_mutex_trylock(&money.mutex)) {
                ++money.value;
                mutex_done = true;
                pthread_mutex_unlock(&money.mutex);
        }

        if (!mutex_done) {
                pthread_mutex_lock(&money.mutex);
                ++money.value;
                mutex_done = true;
                pthread_mutex_unlock(&money.mutex);
        }

        return NULL;
}

static void master(void)
{
        pthread_t woodcutter;
        pthread_t miner;

        if (pthread_create(&woodcutter, NULL, make_money, NULL)) {
                abort();
        }

        if (pthread_create(&miner, NULL, make_money, NULL)) {
                abort();
        }

        if (pthread_join(woodcutter, NULL)) {
                abort();
        }

        if (pthread_join(miner, NULL)) {
                abort();
        }
}

#endif// GCC
