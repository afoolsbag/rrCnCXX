/** \file
 *  \brief 单例模式。
 *  \author zhengrr
 *  \date 2016-10-18 – 2017-12-21
 *  \copyright The MIT License */

#include "../cxx_standard_version.hpp"

#include <cassert>

#if !CXXN2660
#else
#include <mutex>
#endif

namespace {

/* 结论：
 * 　若非必要，建议使用提前初始化单例模式，其无需互斥锁；
 * 　若有必要，延迟初始化应直接用锁，禁用双重检查锁，而在调用时善用变量缓存，减少访问。
 *
 * 议题：为什么禁止使用双重检查锁？
 * 　简言之，Ｃ＋＋抽象机是单线程的，编译器也依此优化，双重检查锁线程不安全。
 *
 * 参见：<http://blog.jobbole.com/86392> */

class ThreadSafeLazySingleton {
public:
    explicit ThreadSafeLazySingleton(const ThreadSafeLazySingleton &) = delete;
    ThreadSafeLazySingleton &operator=(const ThreadSafeLazySingleton &) = delete;

    static ThreadSafeLazySingleton &Instance();

private:
    explicit ThreadSafeLazySingleton() = default;

};

ThreadSafeLazySingleton &ThreadSafeLazySingleton::Instance()
{
#if CXXN2660
    static ThreadSafeLazySingleton instance;
    return instance;
#else// !CXXN2660
    // 为什么不用双重检查锁定
    // <http://blog.jobbole.com/86392/>
    static ThreadSafeLazySingleton *instance_pointer {};
    if (!instance_pointer) {
        static std::mutex mutex;
        mutex.lock();
        if (!instptr)
            instptr = new ThreadSafeLazySingleton;
        mutex.unlock();
    }
    return *instptr;
#endif// CXXN2660
};

}// namespace

int main()
{
    auto &inst1 = ThreadSafeLazySingleton::Instance();
    auto &inst2 = ThreadSafeLazySingleton::Instance();
    assert(&inst1 == &inst2);
}
