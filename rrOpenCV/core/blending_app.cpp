//===-- Blending ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBlending 混合
/// \ingroup gCore
///
/// \sa <https://docs.opencv.org/3.4.2/d5/dc4/tutorial_adding_images.html>
///
/// \author zhengrr
/// \version 2018-07-19
/// \since 2018-03-01
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace rrOpenCV {

/// @addtogroup gBlending
/// @{

///
/// \brief 混合。
/// \details 按配比混合两图像。
///          \f[
///            I_{\textrm{rtn}} = α_{\textrm{ratio1}}I_{\textrm{img1}} + (1-α_{\textrm{ratio1}})I_{\textrm{img2}}
///          \f]
///
/// \param img1    图像1；
/// \param ratio1  配比1；
/// \param img2    图像2。
/// \returns 结果图像。
///
cv::Mat Blend(const cv::Mat &img1, const double ratio1, const cv::Mat &img2)
{
    CV_Assert(0 <= ratio1, ratio1 <= 1);
    const double ratio2 = 1 - ratio1;
    cv::Mat tmp;
    cv::addWeighted(img1, ratio1, img2, ratio2, 0., tmp);
    return tmp;
}

/// @}

}// namespace rropencv

namespace {


}// namespace

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Incorrect number of arguments.\n"
            << "Usage: " << argv[0] << " <image1 path> <image2 path>\n";
        return EXIT_FAILURE;
    }

    const cv::Mat img1 = cv::imread(argv[1]);
    if (img1.empty()) {
        cout << "Can't open image " << argv[1] << ".\n";
        return EXIT_FAILURE;
    }

    const cv::Mat img2 = cv::imread(argv[2]);
    if (img2.empty()) {
        cout << "Can't open image " << argv[2] << ".\n";
        return EXIT_FAILURE;
    }

    if (img1.rows != img2.rows || img1.cols != img2.cols || img1.type() != img2.type()) {
        cout << "The two images aren't matched.\n";
        return EXIT_FAILURE;
    }

    const string window_name = "Blend Image";
    cv::namedWindow(window_name);

    cv::Mat img3;
    UserData data {img1, img2, img3, window_name};
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
        data->rsltImg = rrOpenCV::Blend(data->inpImg1, pos / 100., data->inpImg2);
        cv::imshow(data->wndName, data->rsltImg);
    }

    const std::string trackbar_name = "Ratio1";
    cv::createTrackbar(trackbar_name, window_name, nullptr, 100, OnTrackbarChange, &data);

    OnTrackbarChange(0, &data);
    cv::waitKey();
    return EXIT_SUCCESS;
}
