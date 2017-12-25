/** \copyright The MIT License */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__INL
#define RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__INL

#include "CircularBytesBuffer.hpp"

#include <cassert>
#include <cmath>
#include <cstring>

namespace rrdemo {
namespace cdom {
namespace cpp_library {

size_t CircularBytesBuffer::
getIdleLength() const
{
    return SIZE - length;
}

size_t CircularBytesBuffer::
copyDataInto(uint8_t * const dst, const size_t dstsize, const size_t dstlen) const
{
    assert(dstlen <= getLoadLength());
    const size_t actlen = fmin(dstlen, dstsize);  // actual length
    if (!haveInvertedPoint() || actlen <= SIZE - cursor) {
        memcpy_s(dst, dstsize, data + cursor, actlen);
    } else {
        const auto hlflen = SIZE - cursor;  // half length
        memcpy_s(dst, dstsize, data + cursor, hlflen);
        memcpy_s(dst + hlflen, dstsize - hlflen, data, actlen - hlflen);
    }
    return dstlen - actlen;
}

size_t CircularBytesBuffer::
addDataFrom(const uint8_t * const src, const size_t srclen)
{
    const size_t actlen = fmin(srclen, getIdleLength());
    if (haveInvertedPoint() || actlen <= SIZE - (cursor + length)) {
        memcpy_s(data + cursor + length, actlen, src, actlen);
        length += actlen;
    } else {
        const auto hlflen = SIZE - (cursor + length);
        memcpy_s(data + cursor + length, hlflen, src, hlflen);
        memcpy_s(data, actlen - hlflen, src + hlflen, actlen - hlflen);
        length += actlen;;
    }
    return srclen - actlen;
}

size_t CircularBytesBuffer::
cutDataInto(uint8_t * const dst, const size_t dstsize, const size_t dstlen)
{
    const auto dsclen = copyDataInto(dst, dstsize, dstlen);  // discarded length
    discardData(dstlen);
    return dsclen;
}

size_t CircularBytesBuffer::
discardData(const size_t len)
{
    const auto actlen = fmin(len, getLoadLength());
    if (!haveInvertedPoint() || actlen <= SIZE - cursor) {
        cursor = SIZE != cursor + len ? cursor + len : 0;
        length -= len;
    } else {
        const auto hlflen = SIZE - cursor;
        cursor = actlen - hlflen;
        length -= len;
    }
    return len - actlen;
}

bool CircularBytesBuffer::
haveInvertedPoint() const
{
    return SIZE < cursor + length;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__CIRCULAR_BYTES_BUFFER__INL
