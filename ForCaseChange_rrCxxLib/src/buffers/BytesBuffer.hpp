/** \file
 *  \author zhengrr
 *  \date 2016-12-30 – 2017-1-16
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__HPP

#include <cstdint>

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 字节缓存。
/** \warning 为确保效率而全面使用内联，舍弃了虚函数和多态，允许继承仅为代码复用。
 */
class BytesBuffer {
    explicit BytesBuffer(const BytesBuffer &) = delete;
    explicit BytesBuffer(BytesBuffer &&) = delete;
    BytesBuffer &operator=(const BytesBuffer &) = delete;
    BytesBuffer &operator=(BytesBuffer &&) = delete;

public:
    /// 构造函数。
    /** \param bufferSize 缓存尺寸，默认为百兆网 25FPS 帧最大尺寸，500000 字节。
     */
    inline explicit BytesBuffer(const size_t bufferSize = 500000);

    /// 析构函数。
    inline ~BytesBuffer();

    /// 检查缓存负载是否为空。
    inline bool isEmpty() const;

    /// 获取缓存负载量。
    inline size_t getLoadLength() const;

    /// 获取缓存闲置量。
    inline size_t getIdleLength() const;

    /// 从…复制数据。
    /** \param source 来源地；
     *  \param length 欲复制的数据量。
     *  \return 超限而丢弃的数据量。
     */
    inline size_t copyDataFrom(const uint8_t * const source, const size_t length);

    /// 复制数据到…。
    /** \param destination 目的地；
     *  \param size        目的地可用尺寸；
     *  \param length      欲复制的数据量。
     *  \return 超限的数据量。
     *  \pre length <= getLoadLength()。
     */
    inline size_t copyDataInto(uint8_t * const destination, const size_t size, const size_t length) const;

    /// 从…追加数据（到头部）。
    /** \param source 来源地；
     *  \param length 欲追加的数据量。
     *  \return 超限而丢弃的数据量。
     */
    inline size_t addDataFrom(const uint8_t * const source, const size_t length);

    /// （从尾部）剪切数据到…。
    /** \param destination 目的地；
     *  \param size        目的地可用尺寸；
     *  \param length      欲剪切的数据量。
     *  \return 超限而丢弃的数据量。
     *  \pre length <= getLoadLength()。
     */
    inline size_t cutDataInto(uint8_t * const destination, const size_t size, const size_t length);

    /// （从尾部）丢弃数据。
    /** \param length 欲丢弃的数据量。
     *  \return 超限的数据量。
     */
    inline size_t discardData(const size_t length);

    /// 重置。
    inline void reset();

protected:
    const size_t SIZE;  ///< 缓存尺寸
    uint8_t *data {};   ///< 缓存数据
    size_t cursor {};   ///< 起始游标偏移量
    size_t length {};   ///< 负载量

};// class BytesBuffer

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#include "BytesBuffer.inl"

#endif// RRDEMO__CDOM__CPP_LIBRARY__BYTES_BUFFER__HPP
