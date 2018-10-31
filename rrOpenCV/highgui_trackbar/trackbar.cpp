//===-- Trackbar ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gTrkbar 滑动条
/// \ingroup gHighGUI
///
/// \sa <https://docs.opencv.org/3.4.2/da/d6a/tutorial_trackbar.html>
///
/// \author zhengrr
/// \version 2018-7-19
/// \since 2018-2-28
/// \copyright The MIT License
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace {

///
/// \brief 自定义数据。
///
struct UserData {
    cv::Mat &img;
    const std::string &wndName;

    UserData() = delete;
};

///
/// \brief 滑动条滑动回调。
///
void OnTrackbarChange(int pos, void *userdata)
{
    const auto val = std::min(std::max(0, pos), static_cast<int>(UINT8_MAX));
    auto &data = *reinterpret_cast<UserData *>(userdata);

    data.img = cv::Mat(300, 400, CV_8UC3, cv::Scalar::all(val));
    cv::imshow(data.wndName, data.img);
}

}// namespace

int main(int argc, char *argv[])
{
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    cv::Mat img;

    const std::string wndName = "Window";
    cv::namedWindow(wndName);

    UserData data {img, wndName};
    const std::string trkbarName = "Trackbar";
    cv::createTrackbar(trkbarName, wndName, nullptr, UINT8_MAX, OnTrackbarChange, &data);

    OnTrackbarChange(0, &data);
    cv::waitKey(0);
    return 0;
}
