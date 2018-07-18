//===-- OpenCV - Core - Scan ------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 扫描
///
/// \sa <https://docs.opencv.org/3.4.2/db/da5/tutorial_how_to_scan_images.html>
///
/// \author zhengrr
/// \version 2018-07-17
/// \since 2018-02-24
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace rropencv {

///
/// \brief 颜色缩减。
/// \details
///     \f[
///       I_{\textrm{rslt}} = (\frac{I_{\textrm{inp}}}{n_{\textrm{divisor}}}) × n_{\textrm{divisor}}
///     \f]
///
/// \param[out] rsltImg 成果图像（result image）
/// \param[in]  inpImg  输入图像（input image）
/// \param[in]  divisor 缩减系数（divisor）
///
void ColorReduce(cv::Mat *const rsltImg, const cv::Mat &inpImg, const int divisor = 4)
{
    CV_Assert(CV_8U == inpImg.depth(), 1 <= divisor, divisor <= 1 + UINT8_MAX);

    cv::Mat mapTbl(1, 1 + UINT8_MAX, CV_8U);
    for (int i = 0; i < UINT8_MAX; ++i)
        mapTbl.ptr()[i] = i / divisor * divisor;

    cv::LUT(inpImg, mapTbl, *rsltImg);  // look up table
}

}// namespace rropencv

namespace {

struct UserData {
    const cv::Mat &inpImg;
    cv::Mat &rsltImg;
    const std::string &wndName;

    UserData() = delete;
};

void OnTrackbarChange(int pos, void *userdata)
{
    auto const data = reinterpret_cast<UserData *>(userdata);
    rropencv::ColorReduce(&data->rsltImg, data->inpImg, std::max(1, pos));
    cv::imshow(data->wndName, data->rsltImg);
}

}// namespace

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image path>" << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const cv::Mat inpImg = cv::imread(argv[1]);
    if (inpImg.empty()) {
        std::cout << "Can NOT open image \"" << argv[1] << "\"." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }
    if (inpImg.depth() != CV_8U) {
        std::cout << "The image depth is NOT CV_8U." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const std::string wndName = "Reduce Image Color";
    cv::namedWindow(wndName);

    cv::Mat rsltImg;
    UserData data = {inpImg, rsltImg, wndName};

    const std::string trkbarName = "Divisor";
    cv::createTrackbar(trkbarName, wndName, nullptr, 1 + UINT8_MAX, OnTrackbarChange, &data);

    OnTrackbarChange(0, &data);
    cv::waitKey();
    return EXIT_SUCCESS;
}
