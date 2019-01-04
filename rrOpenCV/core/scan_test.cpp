//===------------------------------------------------------------*- C++ -*-===//
///
/// \sa <https://docs.opencv.org/master/db/da5/tutorial_how_to_scan_images.html>
///
/// \version 2018-11-01
/// \since 2018-10-31
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
using namespace cv;

namespace rrOpenCV::test {

const array<uchar, 256> defaultTable {[] {
    array<uchar, 256> tmp {};
    for (index i = 0; i < static_cast<index>(tmp.size()); ++i)
        tmp[i] = static_cast<uchar>(i / 10 * 10);
    return tmp;
}()};

Mat &colorReducePointer(Mat &img, const array<uchar, 256> &table = defaultTable)
{
    CV_Assert(img.depth() == CV_8U);

    if (img.isContinuous()) {
        const index c = img.rows * img.cols * img.channels();
        auto *const p = img.ptr();
        for (index i = 0; i < c; ++i)
            p[i] = table[p[i]];
    } else {
        const index ci = img.rows;
        const index cj = img.cols * img.channels();
        for (auto i = 0; i < ci; ++i) {
            auto *const p = img.ptr(i);
            for (index j = 0; j < cj; ++j)
                p[j] = table[p[j]];
        }
    }
    return img;
}

TEST(scan, pointer)
{
    Mat img {2560, 1600, CV_8UC3, Scalar::all(0)};

    auto t = static_cast<double>(getTickCount());
    colorReducePointer(img);
    t -= getTickCount();

    cout << "colorReducePointer time cost: " << -t / getTickFrequency() << "s.\n";
}

Mat &colorReduceIterator(Mat &img, const array<uchar, 256> &table = defaultTable)
{
    CV_Assert(img.depth() == CV_8U);

    switch (img.channels()) {
    case 1:
        for (auto it = img.begin<uchar>(); it != img.end<uchar>(); ++it)
            *it = table[*it];
        break;
    case 3:
        for (auto it = img.begin<Vec3b>(); it != img.end<Vec3b>(); ++it) {
            (*it)[0] = table[(*it)[0]];
            (*it)[1] = table[(*it)[1]];
            (*it)[2] = table[(*it)[2]];
        }
        break;
    default:
        abort();
    }

    return img;
}

TEST(scan, iterator)
{
    Mat img {2560, 1600, CV_8UC3, Scalar::all(0)};

    auto t = static_cast<double>(getTickCount());
    colorReduceIterator(img);
    t -= getTickCount();

    cout << "colorReduceIterator time cost: " << -t / getTickFrequency() << "s.\n";
}

Mat &colorReduceRandomAccess(Mat &img, const array<uchar, 256> &table = defaultTable)
{
    CV_Assert(img.depth() == CV_8U);

    switch (img.channels()) {
    case 1:
        for (auto i = 0; i < img.rows; ++i)
            for (auto j = 0; j < img.cols; ++j)
                img.at<uchar>(i, j) = table[img.at<uchar>(i, j)];
        break;
    case 3:
        for (auto i = 0; i < img.rows; ++i)
            for (auto j = 0; j < img.cols; ++j) {
                img.at<Vec3b>(i, j)[0] = table[img.at<Vec3b>(i, j)[0]];
                img.at<Vec3b>(i, j)[1] = table[img.at<Vec3b>(i, j)[1]];
                img.at<Vec3b>(i, j)[2] = table[img.at<Vec3b>(i, j)[2]];
            }
        break;
    default:
        abort();
    }
    return img;
}

TEST(scan, randomAccess)
{
    Mat img {2560, 1600, CV_8UC3, Scalar::all(0)};

    auto t = static_cast<double>(getTickCount());
    colorReduceRandomAccess(img);
    t -= getTickCount();

    cout << "colorReduceRandomAccess time cost: " << -t / getTickFrequency() << "s.\n";
}

Mat colorReduceLookUpTable(const Mat &img, const array<uchar, 256> &table = defaultTable)
{
    CV_Assert(img.depth() == CV_8U);

    Mat tb(1, 256, CV_8U);
    for (index i = 0; i < 256; ++i)
        tb.ptr()[i] = table[i];

    Mat tmp;
    LUT(img, tb, tmp);
    return tmp;
}

/// \brief 颜色缩减。
/// \details \f[
///            I_{\textrm{rtn}} = (\frac{I_{\textrm{img}}}{n_{\textrm{divisor}}}) × n_{\textrm{divisor}}
///          \f]
TEST(scan, lookUpTable)
{
    const Mat img {2560, 1600, CV_8UC3, Scalar::all(0)};

    auto t = static_cast<double>(getTickCount());
    colorReduceLookUpTable(img);
    t -= getTickCount();

    cout << "colorReduceLookUpTable time cost: " << -t / getTickFrequency() << "s.\n";
}

}//namespace rrOpenCV::test
