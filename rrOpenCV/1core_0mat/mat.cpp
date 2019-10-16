//===-- Mat -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 矩阵
/// \sa <https://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html>
///
/// \version 2019-10-15
/// \since 2018-10-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <gtest/gtest.h>
#include <opencv2/core/core_c.h>
#include <opencv2/opencv.hpp>

using namespace std;

namespace rropencv {

/// \brief OpenCV 中 C 风格的数据组织方式。
/// \details 用于不支持 C++ 的环境，如部分嵌入式环境。
TEST(mat, c_style)
{
    [[maybe_unused]] const IplImage *image {nullptr};
}

/// \brief OpenCV 中 C++ 风格的数据组织方式。
/// \details 优先选用此方式。
TEST(mat, cxx_style)
{
    // 仅信息头
    [[maybe_unused]] const cv::Mat matrix;

    // 二维矩阵
    // 2*2 8bits-unsiged-4channels
    [[maybe_unused]] const cv::Mat matrix_2x2_8uc4 {2, 2, CV_8UC4, cv::Scalar::all(0)};
    // 二维矩阵可以使用 << 运算符输出到流进行显示
    cout << "matrix_2x2_8uc4 = \n" << matrix_2x2_8uc4 << endl;

    // 三维矩阵
    // 2*2*2 8bit-signed-5channels
    constexpr int sz[] {2, 2, 2};
    [[maybe_unused]] const cv::Mat matrix_2x2x2_8sc5 {3, sz, CV_8SC(5), cv::Scalar::all(0)};
}

TEST(mat, memory)
{
    // 创建信息头和数据体
    const cv::Mat data {5, 5, CV_8UC3, cv::Scalar::all(0)};

    // 仅创建信息头，数据体指向 data
    cv::Mat ref1_to_data {data};
    // 同上
    cv::Mat ref2_to_data;
    ref2_to_data = data;

    // 创建信息头并复制数据体
    cv::Mat copy1_from_data {data.clone()};
    // 同上
    cv::Mat copy2_from_data;
    copy2_from_data = data.clone();
    // 同上
    cv::Mat copy3_from_data;
    data.copyTo(copy3_from_data);
}

/// \breif 几种手动创建矩阵的方式
TEST(mat, explicitly)
{
    // 二维矩阵，指定初值
    [[maybe_unused]] const cv::Mat matrix_5x5_initial {5, 5, CV_8UC1, cv::Scalar::all(5)};

    // 二维全零矩阵
    [[maybe_unused]] const auto matrix_5x5_zeros = cv::Mat::zeros(5, 5, CV_8UC1);

    // 二维全一矩阵
    [[maybe_unused]] const auto matrix_5x5_ones = cv::Mat::ones(5, 5, CV_8UC1);

    // 二维对角矩阵
    [[maybe_unused]] const auto matrix_5x5_eye = cv::Mat::eye(5, 5, CV_8UC1);

    // 二维矩阵，手动赋值
    // OpenCV 将 “<<” 和 “,” 重载，以支持下述语法
    [[maybe_unused]] const cv::Mat matrix_2x2_custom {(cv::Mat_<uchar>(2, 2) << 11, 12, 21, 22)};
    cout << "matrix_2x2_custom = \n" << matrix_2x2_custom << endl;

    // 二维矩阵，随机赋值
    [[maybe_unused]] cv::Mat matrix_5x5_random {3, 2, CV_8UC3};
    cv::randu(matrix_5x5_random, cv::Scalar::all(0), cv::Scalar::all(UCHAR_MAX));
}

}
