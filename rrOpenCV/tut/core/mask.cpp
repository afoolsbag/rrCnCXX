//===-- OpenCV Tutorials - Core - Mask --------------------------*- C++ -*-===//
///
/// \file
/// \brief OpenCV教程：掩码操作
///
/// \sa http://opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/mat-mask-operations/mat-mask-operations.html
/// \sa https://docs.opencv.org/3.4.1/d7/d37/tutorial_mat_mask_operations.html
///
/// \author zhengrr
/// \version 2018-2-28
/// \since 2018-2-27
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/// 锐化
void sharpen(
    cv::Mat &rsltimg,       ///< [out] 成果图像（result image）
    const cv::Mat &kinpimg  ///< [in]  输入图像（(const) input image）
)
{
    const cv::Mat kker = (cv::Mat_<char>(3, 3) <<
                          0, -1, 0,
                          -1, 5, -1,
                          0, -1, 0);  // (const) kernel

    cv::filter2D(kinpimg, rsltimg, kinpimg.depth(), kker);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image path>" << std::endl;
        return EXIT_FAILURE;
    }

    const cv::Mat kinpimg = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);  // (const) imput image
    if (kinpimg.empty()) {
        std::cout << "Can't open image \"" << argv[1] << "\"." << std::endl;
        return EXIT_FAILURE;
    }

    cv::Mat rsltimg;  // result image
    sharpen(rsltimg, kinpimg);

    const std::string kwndname = "Sharpen Image";  // (const) window name
    cv::namedWindow(kwndname);
    cv::imshow(kwndname, rsltimg);

    cv::waitKey(0);
    return EXIT_SUCCESS;
}