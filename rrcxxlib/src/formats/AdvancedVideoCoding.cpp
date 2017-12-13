/** \copyright The MIT License */
#include "AdvancedVideoCoding.hpp"

#include "../../prj-clib/src/parse_bit_stream.h"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

bool AVCSequenceHeader::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    if (size < 7) return false;
    configurationVersion = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    if (1 != configurationVersion) return false;
    avcProfileIndication = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    profileCompatibility = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    avcLevelIndication = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    reserver6 = zrr_parse8bits(data, size, cursor, 6); cursor += 6;
    if (0x3F != reserver6) return false;
    lengthSizeMinusOne = zrr_parse8bits(data, size, cursor, 2); cursor += 2;
    reserver3 = zrr_parse8bits(data, size, cursor, 3); cursor += 3;
    if (7 != reserver3) return false;
    numOfSequenceParameterSets = zrr_parse8bits(data, size, cursor, 5); cursor += 5;
    for (auto i = 0; i < getNumOfSPSs(); ++i) {
        if (size * 8 < cursor + 16) return false;
        cursor += 16 + 8 * zrr_parse16bits(data, size, cursor, 16);
    }
    if (size * 8 < cursor + 8) return false;
    numOfPictureParameterSets = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    for (auto i = 0; i < getNumOfPPSs(); ++i) {
        if (size * 8 < cursor + 16) return false;
        cursor += 16 + 8 * zrr_parse16bits(data, size, cursor, 16);
    }
    if (size * 8 < cursor) return false;
    return true;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
