//===-- Locale --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Locale
/// \sa <https://boost.org/doc/libs/master/libs/locale/>
///
/// \version 2019-11-27
/// \since 2019-11-25
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <string>

#include <boost/locale.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace {

string narrow_to_utf8(const string &narrow)
{
    boost::locale::generator gen;
    gen.locale_cache_enabled(true);
    return boost::locale::conv::to_utf<char>(narrow, gen(boost::locale::util::get_system_locale()));
}

string utf8_to_narrow(const string &utf8)
{
    boost::locale::generator gen;
    gen.locale_cache_enabled(true);
    return boost::locale::conv::from_utf<char>(utf8, gen(boost::locale::util::get_system_locale()));
}

}

namespace rrboost {

TEST(locale, system_locale)
{
    cout << boost::locale::util::get_system_locale() << '\n';
}

// Unicode | UTF-8    | UTF-16BE | UTF-16LE | UTF-32BE | UTF-32LE | CP936 | 字形
// --------+----------+----------+----------+----------+----------+-------+-----
// U+4F60  | E4 BD A0 | 4F60     | 604F     | 00004F60 | 604F0000 | C4 E3 | 你
// U+597D  | E5 A5 BD | 597D     | 7D59     | 0000597D | 7D590000 | BA C3 | 好
// U+FF0C  | EF BC 8C | FF0C     | FCF0     | 0000FF0C | 0CFF0000 | A3 AC | ，
// U+4E16  | E4 B8 96 | 4E16     | 164E     | 00004E16 | 164E0000 | CA C0 | 世
// U+754C  | E7 95 8C | 754C     | 4C75     | 0000754C | 4C750000 | BD E7 | 界

#ifdef _MSC_VER
TEST(locale, cp936)
{
    constexpr auto utf8 = u8"你好，世界";
    const auto cp936 = utf8_to_narrow(reinterpret_cast<const char *>(utf8));
    const byte *const p {reinterpret_cast<const byte *>(cp936.c_str())};
    size_t i {};
    ASSERT_EQ(p[i++], static_cast<byte>(0xC4));
    ASSERT_EQ(p[i++], static_cast<byte>(0xE3));
    ASSERT_EQ(p[i++], static_cast<byte>(0xBA));
    ASSERT_EQ(p[i++], static_cast<byte>(0xC3));
    ASSERT_EQ(p[i++], static_cast<byte>(0xA3));
    ASSERT_EQ(p[i++], static_cast<byte>(0xAC));
    ASSERT_EQ(p[i++], static_cast<byte>(0xCA));
    ASSERT_EQ(p[i++], static_cast<byte>(0xC0));
    ASSERT_EQ(p[i++], static_cast<byte>(0xBD));
    ASSERT_EQ(p[i++], static_cast<byte>(0xE7));
    ASSERT_EQ(p[i++], static_cast<byte>(0x00));
}
#endif

}
