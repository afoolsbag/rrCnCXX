//===-- OpenCV Tutorials - Core - Scan --------------------------*- C++ -*-===//
///
/// \file
/// \brief OpenCV教程：扫描图像
///
/// \sa http://opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html
/// \sa https://docs.opencv.org/3.4.1/db/da5/tutorial_how_to_scan_images.html
///
/// \author zhengrr
/// \version 2018-2-28
/// \since 2018-2-24
/// \copyright The MIT License
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace {

/// \brief 颜色缩减
///
/// \param rsltimg  成果图像
/// \param kinpimg  输入图像
/// \param kdivisor 缩减系数
void color_reduce(cv::Mat &rsltimg, const cv::Mat &kinpimg, const int kdivisor = 4)
{
    CV_Assert(0 < kdivisor);
    cv::Mat maptbl(1, 256, CV_8U);
    for (int i = 0; i < 256; ++i)
        maptbl.ptr()[i] = i / kdivisor * kdivisor;

    LUT(kinpimg, maptbl, rsltimg);
}

struct userdata {
    const cv::Mat &kinpimg;       ///< input image
    cv::Mat &rsltimg;             ///< result image
    const std::string &kwndname;  ///< window name
};

/// \brief 滑动条滑动回调
void on_trackbar_change(int pos, void *usrd)
{
    auto const kusrd = reinterpret_cast<struct userdata *>(usrd);
    color_reduce(kusrd->rsltimg, kusrd->kinpimg, 0 < pos ? pos : 1);
    cv::imshow(kusrd->kwndname, kusrd->rsltimg);
}

}// namespace

int main(int argc, char *argv[])
{
    // input

    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image path>" << std::endl;
        return EXIT_FAILURE;
    }

    const cv::Mat kinpimg = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if (kinpimg.empty()) {
        std::cout << "Can't open image \"" << argv[1] << "\"." << std::endl;
        return EXIT_FAILURE;
    }

    // result buffer

    cv::Mat rsltimg;

    // window

    const std::string kwndname = "Reduce Image Color";
    cv::namedWindow(kwndname);

    // trackbar

    struct userdata usrd { kinpimg, rsltimg, kwndname };

    const std::string ktrkbarname = "Divisor";

    int kslidermax;
    switch (kinpimg.depth()) {
    case CV_8U: //FALLTHROUGH
    default: kslidermax = std::pow(2, sizeof(uchar) * 8 - 1); break;
    }

    cv::createTrackbar(ktrkbarname, kwndname, nullptr, kslidermax, on_trackbar_change, &usrd);

    // start-up

    on_trackbar_change(0, &usrd);

    cv::waitKey(0);
    return EXIT_SUCCESS;
}
