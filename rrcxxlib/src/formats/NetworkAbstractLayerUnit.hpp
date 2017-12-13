/** \file
 *  \brief 网络抽象层单元（NALU，Network Abstract Layer Unit）格式。
 *  \sa [ISO/IEC 14496-10:2014(en)](
 *          http://iso.org/obp/ui/#iso:std:iso-iec:14496:-10:ed-8:v1:en)
 *  \author zhengrr
 *  \date 2016-12-22 – 2017-1-14
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__NETWORK_ABSTRACT_LAYER__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__NETWORK_ABSTRACT_LAYER__HPP

#include <cstdint>

#include "api.hpp"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 网络抽象层单元－辅助增强信息。
/** nal_unit_type = 6。
 */
struct RRDEMO__CDOM__CPP_LIBRARY__API NALUSupplementalEnhancementInformation {};

/// 网络抽象层单元－序列参数集。
/** nal_unit_type = 7。
 */
struct RRDEMO__CDOM__CPP_LIBRARY__API NALUSequenceParameterSet {
    uint8_t profile_idc : 8;
    uint8_t constraint_set0_flag : 1;
    uint8_t constraint_set1_flag : 1;
    uint8_t constraint_set2_flag : 1;
    uint8_t constraint_set3_flag : 1;
    uint8_t reserved_zero_4bits : 4;
    uint8_t level_idc : 8;
};

/// 网络抽象层单元－图片参数集。
/** nal_unit_type = 8。
 */
struct RRDEMO__CDOM__CPP_LIBRARY__API NALUPictureParameterSet {};

/// 网络抽象层单元。
struct RRDEMO__CDOM__CPP_LIBRARY__API NetworkAbstractLayerUnit {
    union {
        uint32_t start_codes_4bytes : 32;  ///< 起始码 4 字节变种，恒为 00000001(16)
        uint32_t start_codes_3bytes : 24;  ///< 起始码 3 字节变种，恒为 000001(16)
    };
    uint8_t forbidden_zero_bit : 1;        ///< 禁止位，固为 0
    uint8_t nal_ref_idc : 2;               ///< 参考重要度
    uint8_t nal_unit_type : 5;             ///< 单元类型

    /// 检验数据是否符合格式。
    static bool Validate(const uint8_t * const data, const size_t size);
};

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__NETWORK_ABSTRACT_LAYER__HPP
