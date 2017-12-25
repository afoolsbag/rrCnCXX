/** \file
 *  \author zhengrr
 *  \date 2017-1-6 – 16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__HPP

#include "BytesBuffer.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 循环字节缓存。
class CircularBytesBuffer final : public BytesBuffer {
    explicit CircularBytesBuffer(const CircularBytesBuffer &) = delete;
    explicit CircularBytesBuffer(CircularBytesBuffer &&) = delete;
    CircularBytesBuffer &operator=(const CircularBytesBuffer &) = delete;
    CircularBytesBuffer &operator=(CircularBytesBuffer &&) = delete;

public:
    explicit CircularBytesBuffer(const size_t bufferSize = 500000) :
        BytesBuffer(bufferSize)
    {}

    ~CircularBytesBuffer()
    {}

    inline size_t getIdleLength() const /*override*/;

    inline size_t copyDataInto(uint8_t * const destination, const size_t size, const size_t length) const /*override*/;

    inline size_t addDataFrom(const uint8_t * const source, const size_t length) /*override*/;

    inline size_t cutDataInto(uint8_t * const destination, const size_t size, const size_t length) /*override*/;

    inline size_t discardData(const size_t length) /*override*/;

private:
    /// 检查缓存负载受否含有“颠倒点”。
    /*  HAVE NOT INVERTED POINT    HAVE THE INVERTED POINT
     *     start      end                  end  start
     *       v > > > o v              > > o v     v >
     *  |?|_|B|B|B|B|B|_|_|?|?|    |?|B|B|B|_|_|_|B|B|?|?|
     *     ^               ^          ^               ^
     *     0 <-- SIZE --> MAX         0 <-- SIZE --> MAX
     */
    inline bool haveInvertedPoint() const;

};// class CircularBytesBuffer

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#include "CircularBytesBuffer.inl"

#endif// RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__HPP
