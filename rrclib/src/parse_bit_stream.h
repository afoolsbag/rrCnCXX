/** \file
 *  \brief 解析位流（bit stream）。
 *  \author zhengrr
 *  \date 2017-1-6 – 7-14
 *  \copyright The MIT License
 */
#ifndef RRC__LIBRARY__PARSE_BIT_STREAM__H
#define RRC__LIBRARY__PARSE_BIT_STREAM__H

#include <stdint.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

        /** \brief 解析最长 8 个位（bit(s)）。
         *  \param data   数据源；
         *  \param size   byte(s)，数据源尺寸；
         *  \param offset bit(s)，解析偏移量；
         *  \param length bit(s)，解析长度。
         *  \return 解析结果。
         */
        RRC__LIBRARY__API uint8_t zrr_parse8bits(
                const uint8_t * const data, const size_t size,
                const size_t offset, const size_t length);

        /** \brief 解析最长 16 个位（bit(s)）。
         *  \param data   数据源；
         *  \param size   byte(s)，数据源尺寸；
         *  \param offset bit(s)，解析偏移量；
         *  \param length bit(s)，解析长度。
         *  \return 解析结果。
         */
        RRC__LIBRARY__API uint16_t zrr_parse16bits(
                const uint8_t * const data, const size_t size,
                const size_t offset, const size_t length);

        /** \brief 解析最长 32 个位（bit(s)）。
         *  \param data   数据源；
         *  \param size   byte(s)，数据源尺寸；
         *  \param offset bit(s)，解析偏移量；
         *  \param length bit(s)，解析长度。
         *  \return 解析结果。
         */
        RRC__LIBRARY__API uint32_t zrr_parse32bits(
                const uint8_t * const data, const size_t size,
                const size_t offset, const size_t length);

        /** \brief 解析最长 64 个位（bit(s)）。
         *  \param data   数据源；
         *  \param size   byte(s)，数据源尺寸；
         *  \param offset bit(s)，解析偏移量；
         *  \param length bit(s)，解析长度。
         *  \return 解析结果。
         */
        RRC__LIBRARY__API uint64_t zrr_parse64bits(
                const uint8_t * const data, const size_t size,
                const size_t offset, const size_t length);

#ifdef __cplusplus
}
#endif

#endif// RRC__LIBRARY__PARSE_BIT_STREAM__H
