/// \copyright Unlicense

#include <gtest/gtest.h>

#include "rrwindows/rrwindows.hxx"

namespace rrwindows {

constexpr char utf8[] = "你好，世界";
constexpr wchar_t unicode[] = L"你好，世界";
constexpr char gb2312[] = "\xC4\xE3\xBA\xC3\xA3\xAC\xCA\xC0\xBD\xE7";

TEST(unicode_and_character_sets, multi_byte_to_wide_char)
{
    ASSERT_EQ(unicode, multi_byte_to_wide_char(utf8, CP_UTF8));
}

TEST(unicode_and_character_sets, wide_char_to_multi_byte)
{
    ASSERT_EQ(utf8, wide_char_to_multi_byte(unicode, CP_UTF8));
}

TEST(unicode_and_character_sets, multi_byte_to_multi_byte)
{
    ASSERT_EQ(gb2312, multi_byte_to_multi_byte(utf8, CP_UTF8, CP_GB2312));
}

}
