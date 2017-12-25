/** \copyright The MIT License */
#include "NetworkAbstractLayerUnit.hpp"

#include "../../prj-clib/src/parse_bit_stream.h"

namespace rrdemo {
namespace cdom {
namespace cpp_library {

bool NetworkAbstractLayerUnit::
Validate(const uint8_t * const data, const size_t size)
{
    if (3 <= size &&
        1 == zrr_parse32bits(data, size, 0, 3 * 8)) return true;
    if (4 <= size &&
        1 == zrr_parse32bits(data, size, 0, 4 * 8)) return true;
    return false;
}

}// namespace cpp_library
}// namespace cdom
}// namespace rrdemo
