//===-- Display -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gDisplay 显示图像
/// \ingroup gHighGUI
///
/// \sa <https://docs.opencv.org/4.0.1/db/deb/tutorial_display_image.html>
///
/// \version 2019-01-22
/// \since 2019-01-22
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return EXIT_FAILURE;

    auto img {cv::imread(argv[1])};
    if (img.empty())
        return EXIT_FAILURE;

    cv::namedWindow(argv[1]);
    cv::imshow(argv[1], img);
    cv::waitKey(0);
    return EXIT_SUCCESS;
}
