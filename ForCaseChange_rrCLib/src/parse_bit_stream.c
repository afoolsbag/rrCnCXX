/** \copyright The MIT License */
#include "parse_bit_stream.h"

#include <assert.h>
#include <math.h>

static const size_t BYTE_BITS = 8;

static const uint8_t BITS_MASK_TABLE[8][8] = {
        {0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF},
        {0x00, 0x40, 0x60, 0x70, 0x78, 0x7C, 0x7E, 0x7F},
        {0x00, 0x00, 0x20, 0x30, 0x38, 0x3C, 0x3E, 0x3F},
        {0x00, 0x00, 0x00, 0x10, 0x18, 0x1C, 0x1E, 0x1F},
        {0x00, 0x00, 0x00, 0x00, 0x08, 0x0C, 0x0E, 0x0F},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x07},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01}
};

uintmax_t parse_bits(const uint8_t * const data, const size_t size,
                     const size_t offset, const size_t length)
{
        assert(length <= sizeof(uintmax_t) * BYTE_BITS);
        assert(offset + length <= size * BYTE_BITS);
        uintmax_t result = 0;
        size_t bytec = offset / BYTE_BITS;                      // byte cursor
        size_t bitc = (size_t)fmax(offset, bytec * BYTE_BITS);  // bit cursor
        size_t splitc;                                          // split (bit) cursor
        do {
                splitc = (size_t)fmin(bytec * BYTE_BITS + 7, offset + length);
                result |= (data[bytec] & BITS_MASK_TABLE[bitc % BYTE_BITS][splitc % BYTE_BITS]) << (offset + length - splitc);
                bitc = ++bytec * BYTE_BITS;
        } while (bitc + 7 < offset + length);
        return result;
}

uint8_t zrr_parse8bits(const uint8_t * const data, const size_t size,
                       const size_t offset, const size_t length)
{
        assert(length <= sizeof(uint8_t) * BYTE_BITS);
        return (uint8_t)parse_bits(data, size, offset, length);
}

uint16_t zrr_parse16bits(const uint8_t * const data, const size_t size,
                         const size_t offset, const size_t length)
{
        assert(length <= sizeof(uint16_t) * BYTE_BITS);
        return (uint16_t)parse_bits(data, size, offset, length);
}

uint32_t zrr_parse32bits(const uint8_t * const data, const size_t size,
                         const size_t offset, const size_t length)
{
        assert(length <= sizeof(uint32_t) * BYTE_BITS);
        return (uint32_t)parse_bits(data, size, offset, length);
}

uint64_t zrr_parse64bits(const uint8_t * const data, const size_t size,
                         const size_t offset, const size_t length)
{
        assert(length <= sizeof(uint64_t) * BYTE_BITS);
        return (uint64_t)parse_bits(data, size, offset, length);
}
