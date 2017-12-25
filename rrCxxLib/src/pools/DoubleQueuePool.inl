/** \copyright The MIT License */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__INL
#define RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__INL

#include "DoubleQueuePool.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

template <typename ResourceType> DoubleQueuePool<ResourceType>::
DoubleQueuePool(const size_t size)
{
    queueMutex.lock(); {
        for (auto i = 0; i < size; ++i) {
            idleQueue.push(new ResourceType);
        }
    } queueMutex.unlock();
}

template <typename ResourceType> DoubleQueuePool<ResourceType>::
~DoubleQueuePool()
{
    queueMutex.lock(); {
        while (!loadQueue.empty()) {
            delete loadQueue.front();
            loadQueue.pop();
        }
        while (!idleQueue.empty()) {
            delete idleQueue.front();
            idleQueue.pop();
        }
    } queueMutex.unlock();
}

template <typename ResourceType> size_t DoubleQueuePool<ResourceType>::
getLoadBufferCount() const
{
    return loadQueue.size();
}

template <typename ResourceType> size_t DoubleQueuePool<ResourceType>::
getIdleBufferCount() const
{
    return idleQueue.size();
}

template <typename ResourceType> void DoubleQueuePool<ResourceType>::
push(ResourceType * const buf)
{
    queueMutex.lock(); {
        loadQueue.push(buf);
    } queueMutex.unlock();
}

template <typename ResourceType> ResourceType *DoubleQueuePool<ResourceType>::
pop()
{
    ResourceType *buf;
    queueMutex.lock(); {
        if (loadQueue.empty())
            buf = nullptr;
        else {
            buf = loadQueue.front();
            loadQueue.pop();
        }
    } queueMutex.unlock();
    return buf;
}

template <typename ResourceType> void DoubleQueuePool<ResourceType>::
recycle(ResourceType * const buf)
{
    queueMutex.lock(); {
        idleQueue.push(buf);
    } queueMutex.unlock();
}

template <typename ResourceType> ResourceType *DoubleQueuePool<ResourceType>::
allocate()
{
    ResourceType *buf;
    queueMutex.lock(); {
        if (idleQueue.empty())
            buf = nullptr;
        else {
            buf = idleQueue.front();
            idleQueue.pop();
        }
    } queueMutex.unlock();
    return const_cast<ResourceType * const>(buf);
}

template <typename ResourceType> ResourceType *DoubleQueuePool<ResourceType>::
allocateForce()
{
    ResourceType *buf;
    queueMutex.lock(); {
        if (idleQueue.empty()) {
            if (loadQueue.empty()) {
                buf = nullptr;
            } else {
                buf = loadQueue.front();
                loadQueue.pop();
            }
        } else {
            buf = idleQueue.front();
            idleQueue.pop();
        }
    } queueMutex.unlock();
    return buf;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__INL
