//===-- Noob ----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gNoob 菜鸟
/// \ingroup gRegex
///
/// \version 2019-11-26
/// \since 2019-06-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <regex>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

namespace rrcxx {

TEST(regex, noob)
{
    constexpr char data[] {"file_2019_04_08_10_14_08_id_0000000040_ri_0000_angle_000.0000_rect_0947_0208_0996_0288_key_score_0.578215"};

    const string str {data};
    smatch mat;
    const regex reg {R"(^file_(\d{4})_(\d{2})_(\d{2})_(\d{2})_(\d{2})_(\d{2})_id_(\d+)_ri_(\d+)_angle_([\d]+\.?[\d]*)_rect_(\d+)_(\d+)_(\d+)_(\d+)_key_score_([\d]+\.?[\d]*)$)"};
    regex_match(str, mat, reg);

    ASSERT_EQ("2019", mat[1]);
    ASSERT_EQ("04", mat[2]);
    ASSERT_EQ("08", mat[3]);
    ASSERT_EQ("10", mat[4]);
    ASSERT_EQ("14", mat[5]);
    ASSERT_EQ("08", mat[6]);
    ASSERT_EQ("0000000040", mat[7]);
    ASSERT_EQ("0000", mat[8]);
    ASSERT_EQ("000.0000", mat[9]);
    ASSERT_EQ("0947", mat[10]);
    ASSERT_EQ("0208", mat[11]);
    ASSERT_EQ("0996", mat[12]);
    ASSERT_EQ("0288", mat[13]);
    ASSERT_EQ("0.578215", mat[14]);
}

}
