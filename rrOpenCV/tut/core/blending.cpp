//===-- OpenCV Tutorials - Core - Blending ----------------------*- C++ -*-===//
///
/// \file
/// \brief OpenCV教程：混合图像
///
/// \sa http://opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/adding_images/adding_images.html#adding-images
/// \sa https://docs.opencv.org/3.4.1/d5/dc4/tutorial_adding_images.html
///
/// \author zhengrr
/// \version 2018-06-04
/// \since 2018-03-01
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace blending {

/// \brief 混合
///
/// \f[
///   I_{\textrm{rslt}} = α_{\textrm{ratio1}}I_{\textrm{inp1}} + (1-α_{\textrm{ratio1}})I_{\textrm{inp2}}
/// \f]
///
void blend(
    cv::Mat &rsltimg,         ///< [out] 成果图像（result image）
    const cv::Mat &kinpimg1,  ///< [in]  输入图像1（(const) input image 1）
    const cv::Mat &kinpimg2,  ///< [in]  输入图像2（(const) input image 2）
    const double kratio1      ///< [in]  配比1（(const) ratio 1）
)
{
    CV_Assert(0 <= kratio1);
    CV_Assert(kratio1 <= 1);

    const double kratio2 = 1 - kratio1;

    cv::addWeighted(kinpimg1, kratio1, kinpimg2, kratio2, 0.0, rsltimg);
}

struct userdata {
    const cv::Mat &kinpimg1;      ///< (const) input image 1
    const cv::Mat &kinpimg2;      ///< (const) input image 2
    cv::Mat &rsltimg;             ///< result image
    const std::string &kwndname;  ///< (const) window name
};

/// 滑动条滑动回调
void on_trackbar_change(int pos, void *usrd)
{
    auto const kusrd = reinterpret_cast<struct userdata *>(usrd);
    blend(kusrd->rsltimg, kusrd->kinpimg1, kusrd->kinpimg2, pos / 100.);
    cv::imshow(kusrd->kwndname, kusrd->rsltimg);
}

}// namespace blending

using namespace blending;

int main(int argc, char *argv[])
{
    // input

    if (argc != 3) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image1 path> <image2 path>" << std::endl;
        return EXIT_FAILURE;
    }

    const cv::Mat kinpimg1 = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);  // (const) imput image 1
    if (kinpimg1.empty()) {
        std::cout << "Can't open image \"" << argv[1] << "\"." << std::endl;
        return EXIT_FAILURE;
    }

    const cv::Mat kinpimg2 = cv::imread(argv[2], CV_LOAD_IMAGE_COLOR);  // (const) imput image 2
    if (kinpimg2.empty()) {
        std::cout << "Can't open image \"" << argv[2] << "\"." << std::endl;
        return EXIT_FAILURE;
    }

    CV_Assert(kinpimg1.rows == kinpimg2.rows);
    CV_Assert(kinpimg1.cols == kinpimg2.cols);
    CV_Assert(kinpimg1.type() == kinpimg2.type());

    // result buffer

    cv::Mat rsltimg;  // result image

    // window

    const std::string kwndname = "Blend Image";  // (const) window name
    cv::namedWindow(kwndname);

    // trackbar

    struct userdata usrd = {kinpimg1, kinpimg2, rsltimg, kwndname};  // user data

    const std::string ktrkbarname = "Ratio1";  // (const) trackbar name

    cv::createTrackbar(ktrkbarname, kwndname, nullptr, 100, on_trackbar_change, &usrd);

    // start-up
    on_trackbar_change(0, &usrd);

    cv::waitKey(0);
    return EXIT_SUCCESS;
}
