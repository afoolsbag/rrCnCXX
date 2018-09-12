//===-- Studio --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 工作室。
///
/// \version 2018-09-12
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_STUDIO_HXX_
#define RRCXX_STUDIO_HXX_

#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

#include "Order.hxx"
#include "ServiceInterface.hxx"
#include "URI.hxx"
#include "UUID.hxx"

namespace rrcxx {
namespace demov {

///
/// \brief 工作室。
///
class Studio : public ServiceInterface {
public:
    /// \brief 下订单。
    UUID placeOrder(const URI &rawItemUri, const std::string &username = "", const std::string &password = "");

    /// \brief 暂停订单。
    void pauseOrder(const UUID &orderId) = delete;

    /// \brief 恢复订单。
    void resumeOrder(const UUID &orderId) = delete;

    /// \brief 取消订单。
    void cancelOrder(const UUID &orderId) = delete;

    /// \brief 重试订单。
    void retryOrder(const UUID &orderId) = delete;

    /// \brief 查询订单。
    void queryOrder(const UUID &orderId);

private:
    std::map<UUID, Order> ordersInventory;  ///< 订单清单。
    std::list<UUID>       pendingList;      ///< 未完成列表。
    std::mutex            ordersMutex;      ///< 订单互斥量。

    /// \brief 线程函数。
    void threadFunction() final;

    std::shared_ptr<Service> downloadService;   ///< 下载服务。
    void downloadCallback();                    ///< 下载回调。

    std::shared_ptr<Service> transcodeService;  ///< 转码服务。
    void transcodeCallback();                   ///< 转码回调。

    std::shared_ptr<Service> recognizeService;  ///< 识别服务。
    void recognizeCallback();                   ///< 识别回调。
};

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_STUDIO_HXX_
