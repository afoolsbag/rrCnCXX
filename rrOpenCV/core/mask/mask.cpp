//===-- Mask ----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gMask 掩码
/// \ingroup gCore
///
/// \sa <https://docs.opencv.org/3.4.2/d7/d37/tutorial_mat_mask_operations.html>
///
/// \author zhengrr
/// \version 2018-07-19
/// \since 2018-02-27
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace rropencv {

/// @addtogroup gMask
/// @{

///
/// \brief 锐化。
///
/// \param img 输入图像。
/// \returns 结果图像。
///
cv::Mat Sharpen(const cv::Mat &img)
{
    CV_Assert(img.depth() == CV_8U);

    static const cv::Mat KERNEL = (cv::Mat_<char>(3, 3) <<
                                   0, -1, 0,
                                   -1, 5, -1,
                                   0, -1, 0);
    cv::Mat tmp;
    cv::filter2D(img, tmp, img.depth(), KERNEL);
    return tmp;
}

/// @}

}// namespace rropencv

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

    cv::Mat rsltImg = rropencv::Sharpen(inpImg);

    const std::string wndName = "Sharpen Image";
    cv::namedWindow(wndName);
    cv::imshow(wndName, rsltImg);

    cv::waitKey();
    return EXIT_SUCCESS;
}
