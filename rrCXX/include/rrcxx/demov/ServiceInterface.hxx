//===-- Service Interface ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 服务接口。
///
/// \version 2018-09-12
/// \since 2018-09-12
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_SERVICE_INTERFACE_HXX_
#define RRCXX_SERVICE_INTERFACE_HXX_

#include <memory>
#include <thread>

namespace rrcxx {
namespace demov {

///
/// \brief 服务接口。
///
class ServiceInterface
{
public:
    /// \brief 启动服务。
    void startService();

    /// \brief 停止服务并会和。
    void stopServiceAndJoin();

    /// \brief 停止服务并分离。
    void stopServiceAndDetach();

    /// \brief 虚析构函数。
    virtual ~ServiceInterface() = default;

protected:
    std::unique_ptr<std::thread> threadManager;  ///< 线程管理者。
    bool threadLoopFlag {false};                 ///< 线程循环标志。
    virtual void threadFunction() = 0;           ///< 纯虚线程函数。
};

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_SERVICE_INTERFACE_HXX_
