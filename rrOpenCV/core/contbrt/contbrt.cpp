//===-- OpenCV - Core - Contrast & Brightness -------------------*- C++ -*-===//
///
/// \file
/// \brief 对比度和亮度
///
/// \sa <https://docs.opencv.org/3.4.2/d3/dc1/tutorial_basic_linear_transform.html>
///
/// \author zhengrr
/// \version 2018-07-17
/// \since 2018-07-17
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace {

struct UserData {
    const cv::Mat &inpImg;
    cv::Mat &rsltImg;
    int &alpha;
    int &beta;
    const std::string &wndName;

    UserData() = delete;
};

void OnAlphaTrackbarChange(int pos, void *userdata)
{
    auto const data = reinterpret_cast<UserData *>(userdata);
    data->alpha = pos;
    data->inpImg.convertTo(data->rsltImg, -1, data->alpha / 100., data->beta - UINT8_MAX);
    cv::imshow(data->wndName, data->rsltImg);
}

void OnBetaTrackbarChange(int pos, void *userdata)
{
    auto const data = reinterpret_cast<UserData *>(userdata);
    data->beta = pos;
    data->inpImg.convertTo(data->rsltImg, -1, data->alpha / 100., data->beta - UINT8_MAX);
    cv::imshow(data->wndName, data->rsltImg);
}

}// namespace

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image1 path>" << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const cv::Mat inpImg = cv::imread(argv[1]);
    if (inpImg.empty()) {
        std::cout << "Can't open image \"" << argv[1] << "\"." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const std::string wndName = "Contrast & Brightness";
    cv::namedWindow(wndName);

    cv::Mat rsltImg;
    int alpha = 100;
    int beta = UINT8_MAX;
    UserData data = {inpImg, rsltImg, alpha, beta, wndName};

    const std::string alphaTrkbarName = "Alpha";
    cv::createTrackbar(alphaTrkbarName, wndName, &alpha, 200, OnAlphaTrackbarChange, &data);


    const std::string betaTrkbarName = "Beta";
    int betaTrkbarVal = UINT8_MAX;
    cv::createTrackbar(betaTrkbarName, wndName, &beta, 2 * UINT8_MAX, OnBetaTrackbarChange, &data);

    OnAlphaTrackbarChange(alpha, &data);
    cv::waitKey();
    return EXIT_SUCCESS;
}
