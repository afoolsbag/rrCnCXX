//===------------------------------------------------------------*- C++ -*-===//
///
/// \sa <https://docs.opencv.org/master/d7/d37/tutorial_mat_mask_operations.html>
///
/// \version 2018-11-01
/// \since 2018-11-01
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
using namespace std;

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

namespace rrOpenCV::test {


/// \brief 锐化。
Mat sharpen(const Mat &img)
{
    CV_Assert(img.depth() == CV_8U);

    static const Mat kernel {(Mat_<char>(3, 3) <<
                              0, -1, 0,
                              -1, 5, -1,
                              0, -1, 0)};

    Mat tmp;
    filter2D(img, tmp, img.depth(), kernel);
    return tmp;
}

TEST(mark, sharpen)
{
    const Mat img {2560, 1600, CV_8UC3, Scalar::all(0)};

    auto t = static_cast<double>(getTickCount());
    sharpen(img);
    t -= getTickCount();

    cout << "sharpen time cost: " << -t / getTickFrequency() << "s.\n";
}

}//namespace rrOpenCV::test
