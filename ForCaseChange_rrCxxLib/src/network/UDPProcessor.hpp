/** \file
 *  \brief UDP 处理器接口。
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__UDP_PROCESSOR__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__UDP_PROCESSOR__HPP

#include <WinSock2.h>

#include "formats/UserDatagram.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 用户数据报协议处理器（接口）。
struct UDPProcessor {
    virtual ~UDPProcessor()
    {}

    /// 当新的用户数据报被接收时（的回调函数）。
    /** \param userDatagram    用户数据报；
     *  \param receiverAddress 接收者地址；
     *  \param senderAddress   发送者地址。
     */
    virtual void whenNewUserDatagramReceived(const UserDatagram &userDatagram,
                                             const SOCKADDR_IN &receiverAddress,
                                             const SOCKADDR_IN &senderAddress)
    {}

};// struct UDPProcessor

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__UDP_PROCESSOR__HPP
