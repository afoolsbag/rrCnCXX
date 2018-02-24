//===-- OpenCV - Tutorials - Core - Scan ------------------------*- C++ -*-===//
///
/// \file
/// \brief OpenCV教程：扫描图像
///
/// \sa "How to scan images, lookup tables and time measurement with OpenCV". *OpenCV 2.3.2*.
///
/// \author zhengrr
/// \version 2018-2-24
/// \since 2018-2-24
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace {

/// \brief 扫描图像并缩减其颜色空间（C风格）
///
/// \param img    图像矩阵
/// \param maptbl 映射表（mapping table）
/// \return 处理后的图像矩阵
cv::Mat &scan_image_and_reduce_c(cv::Mat &img, const uchar *const maptbl)
{
    CV_Assert(img.depth() < sizeof(uchar));

    int rows = img.rows * img.channels();
    int cols = img.cols;

    if (img.isContinuous()) {
        cols *= rows;
        rows = 1;
    }

    for (int r = 0; r < rows; ++r) {
        uchar *p = img.ptr<uchar>(r);
        for (int c = 0; c < cols; ++c) {
            p[c] = maptbl[p[c]];
        }
    }

    return img;
}

/// \brief 扫描图像并缩减其颜色空间（迭代器）
///
/// \param img    图像矩阵
/// \param maptbl 映射表（mapping table）
/// \return 处理后的图像矩阵
cv::Mat &scan_image_and_reduce_iterator(cv::Mat &img, const uchar *const maptbl)
{
    CV_Assert(img.depth() < (int)sizeof(uchar));

    switch (img.channels()) {
    case 1: {
        for (auto it = img.begin<uchar>(); it != img.end<uchar>(); ++it)
            *it = maptbl[*it];
        break; }
    case 3: {
        for (auto it = img.begin<cv::Vec3b>(); it != img.end<cv::Vec3b>(); ++it) {
            (*it)[0] = maptbl[(*it)[0]];
            (*it)[1] = maptbl[(*it)[1]];
            (*it)[2] = maptbl[(*it)[2]];
        }
        break; }
    }

    return img;
}

/// \brief 扫描图像并缩减其颜色空间（随机访问）
///
/// \param img    图像矩阵
/// \param maptbl 映射表（mapping table）
/// \return 处理后的图像矩阵
cv::Mat &scan_image_and_reduce_random_access(cv::Mat &img, const uchar *const maptbl)
{
    CV_Assert(img.depth() < sizeof(uchar));

    switch (img.channels()) {
    case 1: {
        for (int r = 0; r < img.rows; ++r)
            for (int c = 0; c < img.cols; ++c)
                img.at<uchar>(r, c) = maptbl[img.at<uchar>(r, c)];
        break; }
    case 3: {
        for (int r = 0; r < img.rows; ++r)
            for (int c = 0; c < img.cols; ++c) {
                img.at<cv::Vec3b>(r, c)[0] = maptbl[img.at<cv::Vec3b>(r, c)[0]];
                img.at<cv::Vec3b>(r, c)[1] = maptbl[img.at<cv::Vec3b>(r, c)[1]];
                img.at<cv::Vec3b>(r, c)[2] = maptbl[img.at<cv::Vec3b>(r, c)[2]];
            }
        break; }
    }

    return img;
}

}// namespace

/// @}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "Not enough parameters." << std::endl;
        return -1;
    }

    cv::Mat img;
    if (argc == 4 && !strcmp(argv[3], "G"))
        img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    else
        img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (!img.data) {
        std::cout << "The image " << argv[1] << " could not be loaded." << std::endl;
        return -1;
    }

    int divide;
    std::stringstream str;
    str << argv[2];
    if (!str) {
        std::cout << "Invalid number entered for dividing." << std::endl;
        return -1;
    }
    str >> divide;

    uchar maptbl[256];
    for (int i = 0; i < sizeof(maptbl); ++i)
        maptbl[i] = divide * (i / divide);

    cv::Mat maptblmat(1, 256, CV_8U);
    uchar *p = maptblmat.data;
    for (int i = 0; i < 256; ++i)
        p[i] = maptbl[i];

    const int kTimes {1};
    cv::Mat redimg;
    double time;

    time = cv::getTickCount();
    for (int i = 0; i < kTimes; ++i)
        redimg = scan_image_and_reduce_c(img.clone(), maptbl);
    time = (cv::getTickCount() - time) / cv::getTickFrequency() * 1000;
    time /= kTimes;
    std::cout << "Time of reducing with the C operator [] (averaged for "
        << kTimes << " runs): " << time << " milliseconds." << std::endl;

    time = cv::getTickCount();
    for (int i = 0; i < kTimes; ++i)
        redimg = scan_image_and_reduce_iterator(img.clone(), maptbl);
    time = (cv::getTickCount() - time) / cv::getTickFrequency() * 1000;
    time /= kTimes;
    std::cout << "Time of reducing with the iterator (averaged for "
        << kTimes << " runs): " << time << " milliseconds." << std::endl;

    time = cv::getTickCount();
    for (int i = 0; i < kTimes; ++i)
        scan_image_and_reduce_random_access(img.clone(), maptbl);
    time = (cv::getTickCount() - time) / cv::getTickFrequency() * 1000;
    time /= kTimes;
    std::cout << "Time of reducing with the on-the-fly address generation - at function (averaged for "
        << kTimes << " runs): " << time << " milliseconds." << std::endl;

    time = cv::getTickCount();
    for (int i = 0; i < kTimes; ++i)
        LUT(img, maptblmat, redimg);
    time = (cv::getTickCount() - time) / cv::getTickFrequency() * 1000;
    time /= kTimes;
    std::cout << "Time of reducing with the LUT function (averaged for "
        << kTimes << " runs): " << time << " milliseconds." << std::endl;

    str.str(std::string());
    str.clear();
    str << "red" << divide << (img.channels() == 1 ? "G" : "") << ".jpg";
    cv::imwrite(str.str(), redimg);

    return 0;
}
