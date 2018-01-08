/** \file
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__HPP

#include <mutex>
#include <queue>

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 双队列资源池。
template <typename ResourceType> class DoubleQueuePool final {
    explicit DoubleQueuePool(const DoubleQueuePool &) = delete;
    explicit DoubleQueuePool(DoubleQueuePool &&) = delete;
    DoubleQueuePool &operator=(const DoubleQueuePool &) = delete;
    DoubleQueuePool &operator=(DoubleQueuePool &&) = delete;

public:
    /// 构造函数。
    /** \param poolSize 资源池初始尺寸，默认为 3。
     */
    explicit DoubleQueuePool(const size_t poolSize = 3);

    /// 析构函数。
    ~DoubleQueuePool();

    /// 获取负载资源数目。
    size_t getLoadBufferCount() const;

    /// 获取闲置缓资源目。
    size_t getIdleBufferCount() const;

    /// 压入负载资源。
    void push(ResourceType * const loadBuffer);

    /// 弹出负载资源。
    ResourceType *pop();

    /// 回收闲置资源。
    void recycle(ResourceType * const idleBuffer);

    /// 分配闲置资源。
    ResourceType *allocate();

    /// 强制分配资源。
    /** 若闲置资源已空，则尝试释放负载资源并将其分配。
     */
    ResourceType *allocateForce();

private:
    std::queue<ResourceType * const> loadQueue;  ///< 负载资源队列
    std::queue<ResourceType * const> idleQueue;  ///< 闲置资源队列
    std::mutex queueMutex;                       ///< 资源队列锁

};// class DoubleQueuePool

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#include "DoubleQueuePool.inl"

#endif// RRDEMO__CDOM__CPP_LIBRARY__DOUBLE_QUEUE_POOL__HPP
