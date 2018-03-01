//===-- OpenCV Tutorials - HighGui - Trackbar -------------------*- C++ -*-===//
///
/// \file
/// \brief OpenCV教程：滑动条
///
/// \sa http://opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/highgui/trackbar/trackbar.html
/// \sa https://docs.opencv.org/3.4.1/da/d6a/tutorial_trackbar.html
///
/// \author zhengrr
/// \version 2018-2-28
/// \since 2018-2-28
/// \copyright The MIT License
//===----------------------------------------------------------------------===//

#include <opencv2/highgui.hpp>

namespace {

/// \brief 滑动条滑动回调
void on_trackbar_change(int pos, void *userdata) {}

}// namespace

int main(int argc, char *argv[])
{
    const std::string kwndname = "Window Name";
    const std::string ktrkbarname = "Trackbar Name";
    const int kslidermax = 100;
    int slider = 0;

    cv::namedWindow(kwndname);
    cv::createTrackbar(ktrkbarname, kwndname, &slider, kslidermax, on_trackbar_change);

    cv::imshow(kwndname, cv::Mat(300, 400, CV_8UC3, cv::Scalar(128, 128, 128)));

    cv::waitKey(0);
    return 0;
}
