//===------------------------------------------------------------*- C++ -*-===//
///
/// \sa <https://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html>
///
/// \version 2018-11-01
/// \since 2018-10-31
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
using namespace cv;

namespace rrOpenCV::test {

TEST(mat, test)
{
    // 仅信息头
    const Mat matrix;

    // 二维矩阵
    const Mat matrix_2x2_8uc4 {2, 2, CV_8UC4, Scalar::all(0)};

    // 三维矩阵
    int sz[] {2, 2, 2};
    const Mat matrix_2x2x2_8uc5 {3, sz, CV_8UC(5), Scalar::all(0)};
}

TEST(mat, MATLAB)
{
    const Mat z = Mat::zeros(2, 2, CV_8UC1);
    ASSERT_EQ(z.at<uchar>(0, 0), 0u); ASSERT_EQ(z.at<uchar>(1, 0), 0u);
    ASSERT_EQ(z.at<uchar>(0, 1), 0u); ASSERT_EQ(z.at<uchar>(1, 1), 0u);

    const Mat o = Mat::ones(2, 2, CV_8UC1);
    ASSERT_EQ(o.at<uchar>(0, 0), 1u); ASSERT_EQ(o.at<uchar>(1, 0), 1u);
    ASSERT_EQ(o.at<uchar>(0, 1), 1u); ASSERT_EQ(o.at<uchar>(1, 1), 1u);

    const Mat e = Mat::eye(2, 2, CV_8UC1);
    ASSERT_EQ(e.at<uchar>(0, 0), 1u); ASSERT_EQ(e.at<uchar>(1, 0), 0u);
    ASSERT_EQ(e.at<uchar>(0, 1), 0u); ASSERT_EQ(e.at<uchar>(1, 1), 1u);
}

}//namespace rrOpenCV::test
