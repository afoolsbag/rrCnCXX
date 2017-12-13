/** \file
 *  \brief 单例模式。
 *  \author zhengrr
 *  \date 2016-10-18 – 2017-12-13
 *  \copyright The MIT License
 */
#include "cxx_standard_version.hpp"

#if !(   CXX_STD_11    <= CXX_STD_VER \
      || CXX_GCC_4_4_3 <= CXX_GCC_VER \
      || CXX_MVC_2015  <= CXX_MVC_VER  )
#include <mutex>
#endif

/// 线程安全的惰性单例类。
class ThreadSafeLazySingleton {
public:
    explicit ThreadSafeLazySingleton(const ThreadSafeLazySingleton &) = delete;
    ThreadSafeLazySingleton &operator=(const ThreadSafeLazySingleton &) = delete;

    static ThreadSafeLazySingleton &Instance();

private:
    explicit ThreadSafeLazySingleton() = default;

};// class ThreadSafeLazySingleton

ThreadSafeLazySingleton &ThreadSafeLazySingleton::Instance()
{
#if    CXX_STD_11    <= CXX_STD_VER \
    || CXX_GCC_4_4_3 <= CXX_GCC_VER \
    || CXX_MVC_2015  <= CXX_MVC_VER
    static ThreadSafeLazySingleton instance;
    return instance;
#else
    static ThreadSafeLazySingleton *instance_pointer {};
    if (!instance_pointer) {
        static std::mutex mutex;
        mutex.lock();
        if (!instance_pointer)
            instance_pointer = new ThreadSafeLazySingleton;
        mutex.unlock();
    }
    return *instPtr;
#endif
};
