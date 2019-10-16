//===-- Scan ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 使用 OpenCV 扫描图像、查找表和测量时间
/// \sa <https://docs.opencv.org/master/db/da5/tutorial_how_to_scan_images.html>
///
/// \version 2019-10-15
/// \since 2018-10-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
#include <gsl/gsl>

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace gsl;

namespace rropencv {

using map_table_t = array<uchar, 1 + UCHAR_MAX>;

/// \brief 获取映射表
map_table_t get_map_table(int divide_with = 10)
{
    map_table_t tmp {};
    for (index i = 0; i < static_cast<index>(tmp.size()); ++i)
        tmp[i] = static_cast<uchar>(i / divide_with * divide_with);
    return tmp;
}

/// \brief 颜色缩减：使用指针
/// \details \f[
///            I_{\textrm{rtn}} = (\frac{I_{\textrm{img}}}{n_{\textrm{divisor}}}) × n_{\textrm{divisor}}
///          \f]
cv::Mat &color_reduce_pointer(cv::Mat &img, const map_table_t &tbl)
{
    CV_Assert(img.depth() == CV_8U);

    if (img.isContinuous()) {
        // 若行内存连续：
        const index cnt = img.rows * img.cols * img.channels();
        auto *const base = img.ptr();
        for (index idx = 0; idx < cnt; ++idx)
            base[idx] = tbl[base[idx]];
    } else {
        // 若行内存不连续：
        const index cnt_in_a_row = img.cols * img.channels();
        for (index row = 0; row < img.rows; ++row) {
            auto *const row_base = img.ptr(static_cast<int>(row));
            for (index idx = 0; idx < cnt_in_a_row; ++idx)
                row_base[idx] = tbl[row_base[idx]];
        }
    }
    return img;
}

/// \brief 颜色缩减：使用迭代器
cv::Mat &color_reduce_iterator(cv::Mat &img, const map_table_t &tbl)
{
    CV_Assert(img.depth() == CV_8U);

    switch (img.channels()) {
    case 1:
        for (auto it = img.begin<uchar>(); it != img.end<uchar>(); ++it)
            *it = tbl[*it];
        break;
    case 3:
        for (auto it = img.begin<cv::Vec3b>(); it != img.end<cv::Vec3b>(); ++it) {
            (*it)[0] = tbl[(*it)[0]];
            (*it)[1] = tbl[(*it)[1]];
            (*it)[2] = tbl[(*it)[2]];
        }
        break;
    default:
        abort();
    }

    return img;
}

/// \brief 颜色缩减：使用随机访问
cv::Mat &color_reduce_random_access(cv::Mat &img, const map_table_t &tbl)
{
    CV_Assert(img.depth() == CV_8U);

    switch (img.channels()) {
    case 1:
        for (auto i = 0; i < img.rows; ++i)
            for (auto j = 0; j < img.cols; ++j)
                img.at<uchar>(i, j) = tbl[img.at<uchar>(i, j)];
        break;
    case 3: {
        cv::Mat_<cv::Vec3b> ref = img;
        for (auto i = 0; i < ref.rows; ++i)
            for (auto j = 0; j < ref.cols; ++j) {
                ref(i, j)[0] = tbl[ref(i, j)[0]];
                ref(i, j)[1] = tbl[ref(i, j)[1]];
                ref(i, j)[2] = tbl[ref(i, j)[2]];
            }
        break;
    }
    default:
        abort();
    }
    return img;
}

/// \brief 颜色缩减：使用 `LUT`
cv::Mat color_reduce_look_up_table(const cv::Mat &img, const cv::Mat &tbl)
{
    CV_Assert(img.depth() == CV_8U);
    CV_Assert(tbl.rows == 1);
    CV_Assert(tbl.cols == 1 + UCHAR_MAX);
    CV_Assert(tbl.depth() == CV_8U);

    cv::Mat tmp;
    cv::LUT(img, tbl, tmp);
    return tmp;
}

constexpr index test_times {10};

TEST(scan, pointer)
{
    cv::Mat img {2560, 1600, CV_8UC3, cv::Scalar::all(0)};
    cv::randu(img, cv::Scalar::all(0), cv::Scalar::all(UCHAR_MAX));

    const auto map_tbl = get_map_table();

    auto tick = cv::getTickCount();
    for (index i = 0; i < test_times; ++i)
        color_reduce_pointer(img, map_tbl);
    tick -= cv::getTickCount();

    cout << "color_reduce_pointer average time cost: " << -tick / cv::getTickFrequency() / test_times << "s.\n";
}

TEST(scan, iterator)
{
    cv::Mat img {2560, 1600, CV_8UC3, cv::Scalar::all(0)};
    cv::randu(img, cv::Scalar::all(0), cv::Scalar::all(UCHAR_MAX));

    const auto map_tbl = get_map_table();

    auto tick = cv::getTickCount();
    for (index i = 0; i < test_times; ++i)
        color_reduce_iterator(img, map_tbl);
    tick -= cv::getTickCount();

    cout << "color_reduce_iterator average time cost: " << -tick / cv::getTickFrequency() / test_times << "s.\n";
}

TEST(scan, random_access)
{
    cv::Mat img {2560, 1600, CV_8UC3, cv::Scalar::all(0)};
    cv::randu(img, cv::Scalar::all(0), cv::Scalar::all(UCHAR_MAX));

    const auto map_tbl = get_map_table();

    auto tick = cv::getTickCount();
    for (index i = 0; i < test_times; ++i)
        color_reduce_random_access(img, map_tbl);
    tick -= cv::getTickCount();

    cout << "color_reduce_random_access average time cost: " << -tick / cv::getTickFrequency() / test_times << "s.\n";
}

TEST(scan, look_up_table)
{
    cv::Mat img {2560, 1600, CV_8UC3, cv::Scalar::all(0)};
    cv::randu(img, cv::Scalar::all(0), cv::Scalar::all(UCHAR_MAX));

    const auto map_tbl = get_map_table();
    cv::Mat lut_tbl {1, 1 + UCHAR_MAX, CV_8U, cv::Scalar::all(0)};
    for (index i = 0; i < 1 + UCHAR_MAX; ++i)
        lut_tbl.ptr()[i] = map_tbl[i];

    auto tick = cv::getTickCount();
    for (index i = 0; i < test_times; ++i)
        color_reduce_look_up_table(img, lut_tbl);
    tick -= cv::getTickCount();

    cout << "color_reduce_look_up_table average time cost: " << -tick / cv::getTickFrequency() / test_times << "s.\n";
}

}
