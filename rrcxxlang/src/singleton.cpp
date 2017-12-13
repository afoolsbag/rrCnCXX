/** \file
 *  \brief 单例模式。
 *  \author zhengrr
 *  \date 2016-10-18 – 2017-1-16
 *  \copyright The MIT License
 */
#include <mutex>

namespace {

/// 线程安全的惰性单例模式类。
class ThreadSafeLazySingleton {
public:
    explicit ThreadSafeLazySingleton(const ThreadSafeLazySingleton &) = delete;
    ThreadSafeLazySingleton &operator=(const ThreadSafeLazySingleton &) = delete;

    static ThreadSafeLazySingleton &Instance();

private:
    explicit ThreadSafeLazySingleton() = default;

};// class ThreadSafeLazySingleton

ThreadSafeLazySingleton &ThreadSafeLazySingleton::
Instance()
{
#if (201103L <= __cplusplus) || \
    (defined __GNUC__ && (4 < __GNUC__ || 4 == __GNUC__ && 3 <= __GNUC_MINOR__)) || \
    (defined _MSC_VER && 1900<=_MSC_VER)
    static ThreadSafeLazySingleton inst;  // instance
    return inst;
#else
    static ThreadSafeLazySingleton *instPtr {};  // instance pointer
    if (!instPtr) {
        static std::mutex mutex;
        mutex.lock();
        if (!instPtr)
            instPtr = new ThreadSafeLazySingleton;
        mutex.unlock();
    }
    return *instPtr;
#endif
};

}// namespace
