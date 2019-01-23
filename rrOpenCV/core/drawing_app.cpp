//===-- OpenCV - Core - Drawing ---------------------------------*- C++ -*-===//
///
/// \file
/// \brief 绘制
///
/// \sa <https://docs.opencv.org/3.4.2/d3/d96/tutorial_basic_geometric_drawing.html>
///
/// \author zhengrr
/// \version 2018-07-18
/// \since 2018-07-18
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char *argv[])
{
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    const int sl = 400;  // side length
    cv::Mat img = cv::Mat::zeros(sl, sl, CV_8UC3);

    const int sl1p4 = sl / 4;
    const int sl1p5 = sl / 5;
    const int sl1p6 = sl / 6;
    const int sl1p8 = sl / 8;

    cv::circle(img, cv::Point(sl1p4, sl1p4), sl1p5, cv::Scalar(255, 0, 0));
    cv::ellipse(img, cv::Point(3 * sl1p4, sl1p4), cv::Size(sl1p5, sl1p6), 20, 0, 360, cv::Scalar(0, 255, 0));
    cv::line(img, cv::Point(sl1p8, 7 * sl1p8), cv::Point(3 * sl1p8, 5 * sl1p8), cv::Scalar(0, 0, 255));
    cv::rectangle(img, cv::Point(5 * sl1p8, 5 * sl1p8), cv::Point(7 * sl1p8, 7 * sl1p8), cv::Scalar(255, 255, 255));

    cv::imshow("Draw Image", img);

    cv::waitKey();
    return EXIT_SUCCESS;
}
