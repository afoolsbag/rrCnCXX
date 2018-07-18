//===-- OpenCV - Core - Mask ------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 掩码
///
/// \sa <https://docs.opencv.org/3.4.2/d7/d37/tutorial_mat_mask_operations.html>
///
/// \author zhengrr
/// \version 2018-07-17
/// \since 2018-02-27
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace rropencv {

///
/// \brief 锐化。
///
/// \param[out] rsltImg 成果图像；
/// \param[in]  inpImg  输入图像。
///
void Sharpen(cv::Mat *const rsltImg, const cv::Mat &inpImg)
{
    CV_Assert(inpImg.depth() == CV_8U);

    static const cv::Mat Kernel = (cv::Mat_<char>(3, 3) <<
                                   0, -1, 0,
                                   -1, 5, -1,
                                   0, -1, 0);

    cv::filter2D(inpImg, *rsltImg, inpImg.depth(), Kernel);
}

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

    cv::Mat rsltImg;
    rropencv::Sharpen(&rsltImg, inpImg);

    const std::string wndName = "Sharpen Image";
    cv::namedWindow(wndName);
    cv::imshow(wndName, rsltImg);

    cv::waitKey();
    return EXIT_SUCCESS;
}
