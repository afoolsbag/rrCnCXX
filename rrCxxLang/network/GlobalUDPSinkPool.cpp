/** \copyright The MIT License */
#include "GlobalUDPSinkPool.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

GlobalUDPSinkPool &GlobalUDPSinkPool::
Instance()
{
#if (201103L <= __cplusplus) || \
    (defined __GNUC__ && (4 < __GNUC__ || 4 == __GNUC__ && 3 <= __GNUC_MINOR__)) || \
    (defined _MSC_VER && 1900<=_MSC_VER)
    static GlobalUDPSinkPool inst;  // instance
    return inst;
#else
    static ThreadSafeLazySingleton *instPtr {};
    if (!instPtr) {
        static std::mutex mutex;
        mutex.lock();
        if (!instPtr)
            instPtr = new ThreadSafeLazySingleton;
        mutex.unlock();
    }
    return *instPtr;
#endif
}

GlobalUDPSinkPool::
~GlobalUDPSinkPool()
{
    mapMutex.lock(); {
        for (auto pair : map) {
            if (!pair.second->processorSet.empty())
                /*ignore*/continue;
            map.erase(pair.first);
            delete pair.second;
        }
    } mapMutex.unlock();
}

UDPSink *GlobalUDPSinkPool::
allocate(const uint16_t port)
{
    if (map.end() == map.find(port)) {
        auto sink = new UDPSink(port);
        mapMutex.lock(); {
            map.insert(std::make_pair(port, sink));
        } mapMutex.unlock();
    }
    return map[port];
}

bool GlobalUDPSinkPool::
free(const uint16_t port)
{
    if (map.end() == map.find(port))
        return true;
    if (!map[port]->processorSet.empty())
        return false;
    auto sink = map[port];
    mapMutex.lock(); {
        map.erase(port);
    } mapMutex.unlock();
    delete sink;
    return true;
}

UDPSink *GlobalUDPSinkPool::
find(const uint16_t port)
{
    if (map.end() == map.find(port))
        return nullptr;
    return map[port];
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
