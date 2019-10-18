//===-- Morphology Transformations ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 形态变换
/// \sa <https://docs.opencv.org/master/db/df6/tutorial_erosion_dilatation.html>
/// \sa <https://docs.opencv.org/master/d3/dbe/tutorial_opening_closing_hats.html>
///
/// \version 2019-10-17
/// \since 2018-07-20
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;

namespace {

struct data_t {
    const cv::Mat     &src;
    int               &morph_type;
    cv::MorphShapes   &morph_shape;
    int               &morph_size;
    cv::Mat           &dst;
    const std::string &wnd_name;
};

void morph(const data_t &data)
{
    const cv::Mat ker = cv::getStructuringElement(data.morph_shape, cv::Size(1 + data.morph_size / 2 * 2, 1 + data.morph_size / 2 * 2));

    // 生成距上次调用经过的时间的字串
    auto const watch = []() -> std::string {
        static int64 tick = 0;
        const int64 cur = cv::getTickCount();
        const std::string tmp = std::to_string(static_cast<double>(cur - tick) / cv::getTickFrequency()) + "s";
        tick = cur;
        return tmp;
    };

    const cv::Point org = cv::Point(static_cast<int>(.01 * data.src.cols), static_cast<int>(.98 * data.src.rows));
    const int font_face = cv::FONT_HERSHEY_TRIPLEX;
    const int font_scale = 1;
    const cv::Scalar color = cv::Scalar::all(127);

    switch (data.morph_type) {
        case -1:
            CV_UNUSED(watch());
            data.dst = data.src.clone();
            cv::putText(data.dst, "Original (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_ERODE:  // 侵蚀
            CV_UNUSED(watch());
            cv::erode(data.src, data.dst, ker);
            cv::putText(data.dst, "Erode (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_DILATE:  // 膨胀
            CV_UNUSED(watch());
            cv::dilate(data.src, data.dst, ker);
            cv::putText(data.dst, "Dilate (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_OPEN:  // 开运算
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "Open = Erode & Dilate (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_CLOSE:  // 闭运算
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "Close = Dilate & Erode (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_GRADIENT:  // 梯度运算
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "Gradient = Dilate - Erode (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_TOPHAT:  // 顶帽
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "TopHat = Source - Open (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_BLACKHAT:  // 黑帽
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "BlackHat = Close - Source (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        case cv::MorphTypes::MORPH_HITMISS:
            CV_UNUSED(watch());
            cv::morphologyEx(data.src, data.dst, data.morph_type, ker);
            cv::putText(data.dst, "HitMiss (" + watch() + ")", org, font_face, font_scale, color);
            cv::imshow(data.wnd_name, data.dst);
            break;
        default:
            assert(false);
            break;
    }
}

void OnTypeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);
    data.morph_type = static_cast<cv::MorphTypes>(pos - 1);
    morph(data);
}

void OnShapeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);
    data.morph_shape = static_cast<cv::MorphShapes>(pos);
    morph(data);
}

void OnSizeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);
    data.morph_size = pos;
    morph(data);
}

}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Incorrect number of arguments." << "\n"
            << "Usage: " << argv[0] << " <image path>" << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const cv::Mat inpImg = cv::imread(argv[1]);
    if (inpImg.empty()) {
        std::cout << "Can NOT open image \"" << argv[1] << "\"." << std::endl;
        std::system("TIMEOUT /T 15");
        return EXIT_FAILURE;
    }

    const std::string wndName {"Blur"};
    cv::namedWindow(wndName);

    int morphType = -1;
    cv::MorphShapes morphShape = cv::MorphShapes::MORPH_RECT;
    int morphSize = 0;
    cv::Mat rlstImg;
    data_t data {inpImg, morphType, morphShape, morphSize, rlstImg, wndName};

    cv::createTrackbar("Type", wndName,
                       nullptr, 1 + cv::MorphTypes::MORPH_BLACKHAT,
                       OnTypeTrackbarChange, &data);
    cv::createTrackbar("Shape", wndName,
                       nullptr, cv::MorphShapes::MORPH_ELLIPSE,
                       OnShapeTrackbarChange, &data);
    cv::createTrackbar("Size", wndName,
                       nullptr, 43,
                       OnSizeTrackbarChange, &data);

    morph(data);
    cv::waitKey(0);
    return 0;
}
