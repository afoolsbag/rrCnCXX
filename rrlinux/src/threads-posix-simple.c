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

static void *task(void *arg)
{
        return NULL;
}

static void master(void)
{
        pthread_t worker;

        if (pthread_create(&worker, NULL, task, NULL)) {
                abort();
        }

        if (pthread_join(worker, NULL)) {
                abort();
        }
}

#endif// GCC
