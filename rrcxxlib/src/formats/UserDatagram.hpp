/** \file
 *  \brief 用户数据报（User Datagram）格式。
 *  \sa [RFC 768](http://tools.ietf.org/html/rfc768)
 *  \sa [RFC 2460](http://tools.ietf.org/html/rfc2460)
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-13
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__USER_DATAGRAM__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__USER_DATAGRAM__HPP

#include <cstdint>

#include "api.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 用户数据报。
struct RRDEMO__CDOM__CPP_LIBRARY__API UserDatagram final {
    static const size_t MINIMUM_SIZE {8/*bytes*/};
    static const size_t DATA_MAXIMUM_SIZE {UINT16_MAX/*bytes*/};

    uint16_t sourcePort : 16;
    uint16_t destinationPort : 16;
    uint16_t length : 16;
    uint16_t checksum : 16;
    uint8_t data[DATA_MAXIMUM_SIZE];
};

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif //RRDEMO__CDOM__CPP_LIBRARY__USER_DATAGRAM__HPP
