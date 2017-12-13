/** \file
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__UDP_SINK__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__UDP_SINK__HPP

#include <mutex>
#include <set>
#include <thread>

#include "UDPProcessor.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 用户数据报协议接收器。
class UDPSink final {
    explicit UDPSink() = delete;
    explicit UDPSink(const UDPSink &) = delete;
    explicit UDPSink(UDPSink &&) = delete;
    UDPSink &operator=(const UDPSink &) = delete;
    UDPSink &operator=(UDPSink &&) = delete;

public:
    /// 构造函数。
    explicit UDPSink(const uint16_t port);

    /// 析构函数。
    ~UDPSink();

    /// 插入处理器。
    void insertProcessor(UDPProcessor * const processor);

    /// 移除处理器。
    void eraseProcessor(UDPProcessor * const processor);

    uint16_t port;                          ///< 端口
    std::thread *receiverThread {};         ///< 收流线程
    bool receiverThreadLoopFlag;            ///< 收流线程循环标志位
    std::set<UDPProcessor *> processorSet;  ///< 处理器集
    std::mutex processorSetMutex;           ///< 处理器集锁

};// class UDPSink

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__UDP_SINK__HPP
