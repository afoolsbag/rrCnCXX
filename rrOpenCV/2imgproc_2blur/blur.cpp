//===-- Blur ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 模糊处理
/// \sa <https://docs.opencv.org/master/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html>
///
/// \version 2019-10-16
/// \since 2018-07-19
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;

namespace {

enum class blur_type_t {
    original,     ///< 原始图像
    homogeneous,  ///< 归一化模糊
    gaussian,     ///< 高斯模糊
    median,       ///< 中值模糊
    bilateral,    ///< 双边模糊
    range_last = bilateral
};

struct data_t {
    const cv::Mat &src;
    blur_type_t &blur_type;
    int &blur_param;
    cv::Mat &dst;
    const string &wnd_name;
};

void blur(const data_t &data)
{
    // 生成距上次调用经过的时间的字串
    auto const watch = []() -> string {
        static int64 tick = 0;
        const auto cur = cv::getTickCount();
        const std::string tmp = std::to_string(static_cast<double>(cur - tick) / cv::getTickFrequency()) + "s";
        tick = cur;
        return tmp;
    };

    const cv::Point org = cv::Point(static_cast<int>(0.01 * data.src.cols), static_cast<int>(0.98 * data.src.rows));
    const int font_face = cv::FONT_HERSHEY_TRIPLEX;
    const int font_scale = 1;
    const cv::Scalar color = cv::Scalar::all(127);

    int param;

    switch (data.blur_type) {
    case blur_type_t::original:
        CV_UNUSED(watch());
        data.dst = data.src.clone();
        cv::putText(data.dst, "Original (" + watch() + ")", org, font_face, font_scale, color);
        cv::imshow(data.wnd_name, data.dst);
        break;
    case blur_type_t::homogeneous:
        param = 1 + data.blur_param / 2 * 2;
        CV_UNUSED(watch());
        cv::blur(data.src, data.dst, cv::Size(param, param), cv::Point(-1, -1));
        cv::putText(data.dst, "Homogeneous Blur (" + watch() + ")", org, font_face, font_scale, color);
        cv::imshow(data.wnd_name, data.dst);
        break;
    case blur_type_t::gaussian:
        param = 1 + data.blur_param / 2 * 2;
        CV_UNUSED(watch());
        cv::GaussianBlur(data.src, data.dst, cv::Size(param, param), 0.);
        cv::putText(data.dst, "Gaussian Blur (" + watch() + ")", org, font_face, font_scale, color);
        cv::imshow(data.wnd_name, data.dst);
        break;
    case blur_type_t::median:
        param = 1 + data.blur_param / 2 * 2;
        CV_UNUSED(watch());
        cv::medianBlur(data.src, data.dst, param);
        cv::putText(data.dst, "Median Blur (" + watch() + ")", org, font_face, font_scale, color);
        cv::imshow(data.wnd_name, data.dst);
        break;
    case blur_type_t::bilateral:
        param = data.blur_param;
        CV_UNUSED(watch());
        cv::bilateralFilter(data.src, data.dst, param, param * 2.0, param / 2.0);
        cv::putText(data.dst, "Bilateral Blur (" + watch() + ")", org, font_face, font_scale, color);
        cv::imshow(data.wnd_name, data.dst);
        break;
    default:
        CV_Assert(false);
        break;
    }
}

void on_type_trackbar_change(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);
    data.blur_type = static_cast<blur_type_t>(pos);
    blur(data);
}

void on_param_trackbar_change(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);
    data.blur_param = pos;
    blur(data);
}

}

int main(int argc, char *argv[])
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


        blur_type_t blur_type {blur_type_t::original};
        int blur_param {0};
        cv::Mat show;
        const string wnd_name {"Blur"};
        data_t data {img, blur_type, blur_param, show, wnd_name};

        cv::namedWindow(wnd_name);
        cv::createTrackbar("Type", wnd_name,
                           nullptr, static_cast<int>(blur_type_t::range_last),
                           on_type_trackbar_change, &data);
        cv::createTrackbar("Param", wnd_name,
                           nullptr, 31,
                           on_param_trackbar_change, &data);

        blur(data);
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
