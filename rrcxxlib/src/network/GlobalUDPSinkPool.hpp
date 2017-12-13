/** \file
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__GLOBAL_UDP_SINK_POOL__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__GLOBAL_UDP_SINK_POOL__HPP

#include <map>
#include <mutex>

#include "UDPSink.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 全局用户数据报协议接收器池。
class GlobalUDPSinkPool final {
    explicit GlobalUDPSinkPool(const GlobalUDPSinkPool &) = delete;
    explicit GlobalUDPSinkPool(GlobalUDPSinkPool &&) = delete;
    GlobalUDPSinkPool &operator=(const GlobalUDPSinkPool &) = delete;
    GlobalUDPSinkPool &operator=(GlobalUDPSinkPool &&) = delete;

public:
    /// 获取全局单例。
    static GlobalUDPSinkPool &Instance();

private:
    /// 构造函数。
    explicit GlobalUDPSinkPool() = default;

    /// 析构函数。
    ~GlobalUDPSinkPool();

    /// 分配接收器。
    UDPSink *allocate(const uint16_t port);

    /// 释放接收器。
    bool free(const uint16_t port);

    /// 查找接收器。
    UDPSink *find(const uint16_t port);

private:
    std::map<uint16_t, UDPSink *> map;  ///< 接收器映射集
    std::mutex mapMutex;                ///< 接收器映射集锁

};// class GlobalUDPSinkPool

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__GLOBAL_UDP_SINK_POOL__HPP
