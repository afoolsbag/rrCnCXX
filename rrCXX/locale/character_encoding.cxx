//===-- Character Encoding --------------------------------------*- C++ -*-===//
///
/// \defgroup gCharacterEncoding 字符编码
/// \ingroup gLocale
///
/// \sa [“你”](https://unicode-table.com/4F60/). *Unicode®字符百科*.
/// \sa [“好”](https://unicode-table.com/597D/). *Unicode®字符百科*.
/// \sa [“，”](https://unicode-table.com/FF0C/). *Unicode®字符百科*.
/// \sa [“世”](https://unicode-table.com/4E16/). *Unicode®字符百科*.
/// \sa [“界”](https://unicode-table.com/754C/). *Unicode®字符百科*.
///
/// \version 2019-11-27
/// \since 2019-11-26
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdint>
#include <string>

#include <gtest/gtest.h>

using namespace std;

namespace {
/// \brief 字节序
enum class endian {
    big,     ///< 大尾序
    little,  ///< 小尾序
    unexpected
};
/// \brief 检查字节序
endian check_endian()
{
    union {
        uint32_t byte4;
        uint8_t  byte1[4];
    } data = {0x01020304};
    if (data.byte1[0] == 0x01 && data.byte1[1] == 0x02 && data.byte1[2] == 0x03 && data.byte1[3] == 0x04)
        return endian::big;
    else if (data.byte1[0] == 0x04 && data.byte1[1] == 0x03 && data.byte1[2] == 0x02 && data.byte1[3] == 0x01)
        return endian::little;
    else
        return endian::unexpected;
}
}

namespace rrcxx {
/// \addtogroupg gCharacterEncoding
/// @{

// Unicode | UTF-8    | UTF-16BE | UTF-16LE | UTF-32BE | UTF-32LE | CP936 | 字形
// --------+----------+----------+----------+----------+----------+-------+-----
// U+4F60  | E4 BD A0 | 4F60     | 604F     | 00004F60 | 604F0000 | C4 E3 | 你
// U+597D  | E5 A5 BD | 597D     | 7D59     | 0000597D | 7D590000 | BA C3 | 好
// U+FF0C  | EF BC 8C | FF0C     | FCF0     | 0000FF0C | 0CFF0000 | A3 AC | ，
// U+4E16  | E4 B8 96 | 4E16     | 164E     | 00004E16 | 164E0000 | CA C0 | 世
// U+754C  | E7 95 8C | 754C     | 4C75     | 0000754C | 4C750000 | BD E7 | 界

TEST(character_encoding, utf8)
{
    constexpr auto utf8 = u8"你好，世界";
    const byte *const p {reinterpret_cast<const byte *>(utf8)};
    size_t i {};
    ASSERT_EQ(p[i++], byte {0xE4});
    ASSERT_EQ(p[i++], byte {0xBD});
    ASSERT_EQ(p[i++], byte {0xA0});
    ASSERT_EQ(p[i++], byte {0xE5});
    ASSERT_EQ(p[i++], byte {0xA5});
    ASSERT_EQ(p[i++], byte {0xBD});
    ASSERT_EQ(p[i++], byte {0xEF});
    ASSERT_EQ(p[i++], byte {0xBC});
    ASSERT_EQ(p[i++], byte {0x8C});
    ASSERT_EQ(p[i++], byte {0xE4});
    ASSERT_EQ(p[i++], byte {0xB8});
    ASSERT_EQ(p[i++], byte {0x96});
    ASSERT_EQ(p[i++], byte {0xE7});
    ASSERT_EQ(p[i++], byte {0x95});
    ASSERT_EQ(p[i++], byte {0x8C});
    ASSERT_EQ(p[i++], byte {0x00});
}

TEST(character_encoding, utf16)
{
    constexpr auto utf16 = u"你好，世界";
    const byte *const p {reinterpret_cast<const byte *>(utf16)};
    size_t i {};
    if (check_endian() == endian::big) {
        ASSERT_EQ(p[i++], byte {0x4F});
        ASSERT_EQ(p[i++], byte {0x60});
        ASSERT_EQ(p[i++], byte {0x59});
        ASSERT_EQ(p[i++], byte {0x7D});
        ASSERT_EQ(p[i++], byte {0xFF});
        ASSERT_EQ(p[i++], byte {0x0C});
        ASSERT_EQ(p[i++], byte {0x4E});
        ASSERT_EQ(p[i++], byte {0x16});
        ASSERT_EQ(p[i++], byte {0x75});
        ASSERT_EQ(p[i++], byte {0x4C});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
    } else if (check_endian() == endian::little) {
        ASSERT_EQ(p[i++], byte {0x60});
        ASSERT_EQ(p[i++], byte {0x4F});
        ASSERT_EQ(p[i++], byte {0x7D});
        ASSERT_EQ(p[i++], byte {0x59});
        ASSERT_EQ(p[i++], byte {0x0C});
        ASSERT_EQ(p[i++], byte {0xFF});
        ASSERT_EQ(p[i++], byte {0x16});
        ASSERT_EQ(p[i++], byte {0x4E});
        ASSERT_EQ(p[i++], byte {0x4C});
        ASSERT_EQ(p[i++], byte {0x75});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
    } else {
        FAIL() << "Unexpected endian.";
    }
}

TEST(character_encoding, utf32)
{
    //constexpr auto wide = L"你好，世界";
    constexpr auto utf32 = U"你好，世界";
    const byte *const p {reinterpret_cast<const byte *>(utf32)};
    size_t i {};
    if (check_endian() == endian::big) {
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x4F});
        ASSERT_EQ(p[i++], byte {0x60});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x59});
        ASSERT_EQ(p[i++], byte {0x7D});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0xFF});
        ASSERT_EQ(p[i++], byte {0x0C});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x4E});
        ASSERT_EQ(p[i++], byte {0x16});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x75});
        ASSERT_EQ(p[i++], byte {0x4C});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
    } else if (check_endian() == endian::little) {
        ASSERT_EQ(p[i++], byte {0x60});
        ASSERT_EQ(p[i++], byte {0x4F});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x7D});
        ASSERT_EQ(p[i++], byte {0x59});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x0C});
        ASSERT_EQ(p[i++], byte {0xFF});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x16});
        ASSERT_EQ(p[i++], byte {0x4E});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x4C});
        ASSERT_EQ(p[i++], byte {0x75});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
        ASSERT_EQ(p[i++], byte {0x00});
    } else {
        FAIL() << "Unexpected endian.";
    }
}

/// @}
}
