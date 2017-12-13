/** \copyright The MIT License */
#include "FlashVideo.hpp"

#include "../../prj-clib/src/parse_bit_stream.h"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

bool FLVTagDataAudio::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    if (size < 1) return false;
    soundFormat = zrr_parse8bits(data, size, cursor, 4); cursor += 4;
    if (0x9u == soundFormat || 0xCu == soundFormat || 0xDu == soundFormat) return false;
    soundRate = zrr_parse8bits(data, size, cursor, 2); cursor += 2;
    soundSize = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    soundType = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (isAAC()) {
        if (size < 1 + 1)return false;
        aacPacketType = zrr_parse8bits(data, size, cursor, 8);
        if (1 < aacPacketType) return false;
    }
    return true;
}

bool FLVTagDataVideo::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    if (size < 1) return false;
    frameType = zrr_parse8bits(data, size, cursor, 4); cursor += 4;
    if (frameType < 1 || 5 < frameType) return false;
    codecID = zrr_parse8bits(data, size, cursor, 4); cursor += 4;
    if (codecID < 1 || 7 < codecID) return false;
    if (isAVC()) {
        if (size < 5) return false;
        avcPacketType = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
        if (2 < avcPacketType) return false;
        auto tmp = zrr_parse32bits(data, size, cursor, 24);
        if (1 == (tmp & 0x80000000)) tmp = ~tmp + 1;
        avcCompositionTime = static_cast<int32_t>(tmp);
        if (!isAVCNALU() && 0 != getCompositionTime()) return false;
    }
    return true;
}

bool FLVTag::
Validate(const uint8_t * const data, const size_t size)
{
    FLVTag tmp;
    return tmp.parse(data, size);
}

bool FLVTag::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    // Tag Header
    if (size < 11) return false;
    reserved2 = zrr_parse8bits(data, size, cursor, 2); cursor += 2;
    if (0 != reserved2) return false;
    filter = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    tagType = zrr_parse8bits(data, size, cursor, 5); cursor += 5;
    if (!isAudio() && !isVideo() && !isScript()) return false;
    dataSize = zrr_parse32bits(data, size, cursor, 24); cursor += 24;
    timestamp = zrr_parse32bits(data, size, cursor, 24); cursor += 24;
    timestampExtended = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    streamID = zrr_parse32bits(data, size, cursor, 24); cursor += 24;
    if (0 != streamID) return false;
    // Tag Data
    cursor += dataSize * 8;
    // Tag Size
    if (size < 11 + dataSize + 4) return false;
    previousTagSize = zrr_parse32bits(data, size, cursor, 32);
    return true;
}

bool FLV::
Validate(const uint8_t * const data, const size_t size)
{
    FLV tmp;
    return tmp.parse(data, size);
}

bool FLV::
parse(const uint8_t * const data, const size_t size)
{
    size_t cursor {};
    // Header
    if (size < 9) return false;
    signature = zrr_parse32bits(data, size, cursor, 24); cursor += 24;
    if ('FLV' != signature) return false;
    version = zrr_parse8bits(data, size, cursor, 8); cursor += 8;
    typeFlagsReserved1 = zrr_parse8bits(data, size, cursor, 5); cursor += 5;
    if (0 != typeFlagsReserved5) return false;
    typeFlagsAudio = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    typeFlagsReserved1 = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    if (0 != typeFlagsReserved1) return false;
    typeFlagsVideo = zrr_parse8bits(data, size, cursor, 1); cursor += 1;
    dataOffset = zrr_parse32bits(data, size, cursor, 32);
    // Header Size
    if (size < dataOffset + 4) return false;
    previousTagSize0 = zrr_parse32bits(data, size, dataOffset * 8, 32);
    if (0 != previousTagSize0) return false;
    return true;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
