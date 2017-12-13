/** \copyright The MIT License */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__INL
#define RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__INL

#include "BytesBuffer.hpp"

#include <cassert>
#include <cmath>
#include <cstring>

namespace rrdemo {
namespace cdom {
namespace cpp_library {

BytesBuffer::
BytesBuffer(const size_t bufferSize) :
SIZE {bufferSize}
{
    data = new uint8_t[SIZE];
}

BytesBuffer::
~BytesBuffer()
{
    delete[] data;
}

bool BytesBuffer::
isEmpty() const
{
    return 0 == getLoadLength();
}

size_t BytesBuffer::
getLoadLength() const
{
    return length;
}

size_t BytesBuffer::
getIdleLength() const
{
    return SIZE - (cursor + length);
}

size_t BytesBuffer::
copyDataFrom(const uint8_t * const src, const size_t srclen)
{
    const size_t actlen = fmin(srclen, SIZE);  // actual length
    memcpy_s(data, SIZE, src, actlen);
    cursor = 0;
    length = actlen;
    return srclen - actlen;
}

size_t BytesBuffer::
copyDataInto(uint8_t * const dst, const size_t dstsize, const size_t dstlen) const
{
    assert(dstlen <= getLoadLength());
    const size_t actlen = fmin(dstlen, dstsize);
    memcpy_s(dst, dstsize, data + cursor, actlen);
    return dstlen - actlen;
}

size_t BytesBuffer::
addDataFrom(const uint8_t * const src, const size_t srclen)
{
    const size_t actlen = fmin(srclen, getIdleLength());
    memcpy_s(data + cursor + length, getIdleLength(), src, actlen);
    length += actlen;
    return srclen - actlen;
}

size_t BytesBuffer::
discardData(const size_t len)
{
    const size_t actlen = fmin(len, getLoadLength());
    cursor += len;
    length -= len;
    return len - actlen;
}

size_t BytesBuffer::
cutDataInto(uint8_t * const dst, const size_t dstsize, const size_t dstlen)
{
    const auto dsclen = copyDataInto(dst, dstsize, dstlen);  // discarded length
    discardData(dstlen);
    return dsclen;
}

void BytesBuffer::
reset()
{
    cursor = 0;
    length = 0;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__INL
