//===-- OpenCV - Core - Mat -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 矩阵
///
/// \sa <https://docs.opencv.org/3.4.2/d6/d6d/tutorial_mat_the_basic_image_container.html>
///
/// \author zhengrr
/// \version 2018-07-17
/// \since 2018-07-17
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/core/core.hpp>

int main(int argc, char *argv[])
{
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    // 只创建信息头
    cv::Mat matrix;

    // 二维矩阵 2rows 2cols 8bit-unsigned 3channel
    const cv::Mat matrix_2x2_8uc3(2, 2, CV_8UC3, cv::Scalar::all(0));
    std::cout << "matrix_2x2_8uc3 = " << "\n"
        << matrix_2x2_8uc3 << std::endl;

    int sz[] = {2, 2, 2};
    // 三维矩阵 2x2x2 8bit-unsigned (1channel)
    const cv::Mat matrix_2x2x2_8u(3, sz, CV_8U, cv::Scalar::all(0));

    // 二维矩阵 4rows 4cols 32bit-floating (1channel) eye
    const cv::Mat matrix_4x4_32f_eye = cv::Mat::eye(4, 4, CV_32F);
    std::cout << "matrix_4x4_32f_eye = " << "\n"
        << matrix_4x4_32f_eye << std::endl;

    // 二维矩阵 4rows 4cols 32bit-floating (1channel) ones
    const cv::Mat matrix_4x4_32f_ones = cv::Mat::ones(4, 4, CV_32F);
    std::cout << "matrix_4x4_32f_ones = " << "\n"
        << matrix_4x4_32f_ones << std::endl;

    // 二维矩阵 4rows 4cols 32bit-floating (1channel) zeros
    const cv::Mat matrix_4x4_32f_zeros = cv::Mat::zeros(4, 4, CV_32F);
    std::cout << "matrix_4x4_32f_zeros = " << "\n"
        << matrix_4x4_32f_zeros << std::endl;

    std::system("TIMEOUT /T 15");
    return EXIT_SUCCESS;
}
