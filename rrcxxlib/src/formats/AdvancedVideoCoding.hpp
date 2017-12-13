/** \file
 *  \brief 高级视频编码（AVC，Advanced Video Coding）格式。
 *  \sa [ISO/IEC 14496-10:2014(en)](
 *          http://iso.org/obp/ui/#iso:std:iso-iec:14496:-10:ed-8:v1:en)
 *  \author zhengrr
 *  \date 2017-1-11 – 14
 *  \copyright The MIT License
 */
#ifndef RRDEMO__CDOM__CPP_LIBRARY__ADVANCED_VIDEO_CODING__HPP
#define RRDEMO__CDOM__CPP_LIBRARY__ADVANCED_VIDEO_CODING__HPP

#include <cstdint>

namespace rrdemo {
namespace cdom {
namespace cpp_library {

/// 高级视频编码－序列头
struct AVCSequenceHeader {
    uint8_t configurationVersion : 8;  ///< 恒为 1
    uint8_t avcProfileIndication : 8;
    uint8_t profileCompatibility : 8;
    uint8_t avcLevelIndication : 8;
    uint8_t reserver6 : 6;             ///< 恒为 111111(2)
    uint8_t lengthSizeMinusOne : 2;
    uint8_t reserver3 : 3;             ///< 恒为 111(2)
    uint8_t numOfSequenceParameterSets : 5;
    struct SequenceParameterSet {
        uint16_t length : 16;
        uint8_t *nalUnit;
    } *sequenceParameterSets;
    uint8_t numOfPictureParameterSets : 8;
    struct PictureParameterSet {
        uint16_t length : 16;
        uint8_t *nalUnit;
    } *pictureParameterSets;

    uint8_t getNumOfSPSs() const { return numOfSequenceParameterSets; }
    uint8_t getNumOfPPSs() const { return numOfPictureParameterSets; }

    /// 解析数据。
    bool parse(const uint8_t * const data, const size_t size);

};// struct AVCSequenceHeader

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo

#endif// RRDEMO__CDOM__CPP_LIBRARY__ADVANCED_VIDEO_CODING__HPP