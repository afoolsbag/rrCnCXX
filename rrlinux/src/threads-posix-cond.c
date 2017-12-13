/** \file
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread1/>
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread2/>
 *  \sa <http://ibm.com/developerworks/cn/linux/thread/posix_thread3/>
 *  \author zhengrr
 *  \date 2016-10-11 – 27
 *  \copyright The MIT License
 */
#ifdef __GNUC__

#include <pthread.h>

static struct {
        int value;
        pthread_mutex_t mutex;
        pthread_cond_t cond;
} money;

static void *print_money(void *arg)
{
        pthread_mutex_lock(&money.mutex);
        ++money.value;
        pthread_mutex_unlock(&money.mutex);
        if (0 < money.value) pthread_cond_broadcast(&money.cond);
        return NULL;
}

static void *splurge(void *arg)
{
        pthread_mutex_lock(&money.mutex);
        if (money.value <= 0) pthread_cond_wait(&money.cond, &money.mutex);
        --money.value;
        pthread_mutex_unlock(&money.mutex);
        return NULL;
}

static void master(void)
{
        money.value = 0;
        pthread_mutex_init(&money.mutex, NULL);
        pthread_cond_init(&money.cond, NULL);

        pthread_t gambler;
        pthread_t black_sheep;

        if (pthread_create(&gambler, NULL, print_money, NULL)) {
                abort();
        }

        if (pthread_create(&black_sheep, NULL, splurge, NULL)) {
                abort();
        }

        if (pthread_join(print_money, NULL)) {
                abort();
        }

        if (pthread_join(splurge, NULL)) {
                abort();
        }
}

#endif// GCC
