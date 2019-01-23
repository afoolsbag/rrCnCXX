//===-- Trackbar ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gTrackbar 滑动条
/// \ingroup gHighGUI
///
/// \sa <https://docs.opencv.org/4.0.1/da/d6a/tutorial_trackbar.html>
///
/// \version 2019-01-22
/// \since 2018-02-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

void onTrackbarChange(int pos, void *userdata);

static const char windowName[] {"Window with Trackbar"};
static const char trackbarName[] {"Trackbar"};

int main()
{
    cv::Mat img;

    cv::namedWindow(windowName);
    cv::createTrackbar(trackbarName, windowName, nullptr, UINT8_MAX, onTrackbarChange, &img);

    onTrackbarChange(0, &img);

    cv::waitKey(0);
    return 0;
}

void onTrackbarChange(int pos, void *userdata)
{
    auto &img = *reinterpret_cast<cv::Mat *>(userdata);

    img = cv::Mat(300, 400, CV_8UC3, cv::Scalar::all(pos));
    cv::imshow(windowName, img);
}
