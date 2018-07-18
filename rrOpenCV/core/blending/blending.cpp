//===-- OpenCV - Core - Blending --------------------------------*- C++ -*-===//
///
/// \file
/// \brief 混合
///
/// \sa <https://docs.opencv.org/3.4.2/d5/dc4/tutorial_adding_images.html>
///
/// \author zhengrr
/// \version 2018-07-17
/// \since 2018-03-01
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace rropencv {

///
/// \brief 混合。
/// \details
///     \f[
///       I_{\textrm{rslt}} = α_{\textrm{ratio1}}I_{\textrm{inp1}} + (1-α_{\textrm{ratio1}})I_{\textrm{inp2}}
///     \f]
///
/// \param[out] rsltImg 成果图像；
/// \param[in]  inpImg1 输入图像1；
/// \param[in]  inpImg2 输入图像2；
/// \param[in]  ratio1  配比1；
///
void Blend(cv::Mat *const rsltImg, const cv::Mat &inpImg1, const cv::Mat &inpImg2, const double ratio1)
{
    CV_Assert(0 <= ratio1, ratio1 <= 1);
    const double ratio2 = 1 - ratio1;
    cv::addWeighted(inpImg1, ratio1, inpImg2, ratio2, 0., *rsltImg);
}

}// namespace rropencv

namespace {

struct UserData {
    const cv::Mat &inpImg1;
    const cv::Mat &inpImg2;
    cv::Mat &rsltImg;
    const std::string &wndName;

    UserData() = delete;
};

void OnTrackbarChange(int pos, void *userdata)
{
    auto const data = reinterpret_cast<UserData *>(userdata);
    rropencv::Blend(&data->rsltImg, data->inpImg1, data->inpImg2, pos / 100.);
    cv::imshow(data->wndName, data->rsltImg);
}

}// namespace

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image1 path> <image2 path>" << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const cv::Mat inpImg1 = cv::imread(argv[1]);
    if (inpImg1.empty()) {
        std::cout << "Can't open image \"" << argv[1] << "\"." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const cv::Mat inpImg2 = cv::imread(argv[2]);
    if (inpImg2.empty()) {
        std::cout << "Can't open image \"" << argv[2] << "\"." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    if (inpImg1.rows != inpImg2.rows ||
        inpImg1.cols != inpImg2.cols ||
        inpImg1.type() != inpImg2.type()) {
        std::cout << "The two images do not match." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const std::string wndName = "Blend Image";
    cv::namedWindow(wndName);

    cv::Mat rsltImg;
    UserData data = {inpImg1, inpImg2, rsltImg, wndName};

    const std::string trkbarName = "Ratio1";
    cv::createTrackbar(trkbarName, wndName, nullptr, 100, OnTrackbarChange, &data);

    OnTrackbarChange(0, &data);
    cv::waitKey();
    return EXIT_SUCCESS;
}
