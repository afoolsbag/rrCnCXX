//===-- Mask ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对矩阵进行蒙版运算
/// \sa <https://docs.opencv.org/master/d7/d37/tutorial_mat_mask_operations.html>
///
/// \version 2019-10-16
/// \since 2018-11-01
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;

namespace rropencv {

/// \brief 锐化。
cv::Mat sharpen(const cv::Mat &img)
{
    CV_Assert(img.depth() == CV_8U);

    // 蒙版、核
    static const cv::Mat kernel {(cv::Mat_<char>(3, 3) <<
         0, -1,  0,
        -1,  5, -1,
         0, -1,  0)};

    cv::Mat tmp;
    cv::filter2D(img, tmp, img.depth(), kernel);
    return tmp;
}

}

int main(int argc, char *argv[]) noexcept
{
    try {
        if (argc != 2) {
            cerr << "failure: argc != 2" << endl;
            return EXIT_FAILURE;
        }

        const auto img = cv::imread(cv::samples::findFile(argv[1]), cv::IMREAD_UNCHANGED);
        if (img.empty()) {
            cerr << "failure: img.empty()" << endl;
            return EXIT_FAILURE;
        }

        const auto sharpened_img = rropencv::sharpen(img);

        cv::namedWindow("original");
        cv::namedWindow("sharpened");

        cv::imshow("original", img);
        cv::imshow("sharpened", sharpened_img);

        cv::waitKey();

        return EXIT_SUCCESS;

    } catch (const exception &e) {
        cerr << "failure: exception " << e.what() << endl;
        return EXIT_FAILURE;

    } catch (...) {
        cerr << "failure: exception ..." << endl;
        return EXIT_FAILURE;

    }
}
