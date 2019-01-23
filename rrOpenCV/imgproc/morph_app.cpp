//===-- Morphology Transformations ------------------------------*- C++ -*-===//
///
/// \defgroup gMorph 形态变换
/// \ingroup gImgProc
///
/// \sa <https://docs.opencv.org/3.4.2/db/df6/tutorial_erosion_dilatation.html>
/// \sa <https://docs.opencv.org/3.4.2/d3/dbe/tutorial_opening_closing_hats.html>
///
/// \author zhengrr
/// \version 2018-07-20
/// \since 2018-07-20
/// \copyright The MIT License
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace {

struct UserData {
    const cv::Mat     &inpImg;
    cv::MorphTypes    &morphType;
    cv::MorphShapes   &morphShape;
    int               &morphSize;
    cv::Mat           &rsltImg;
    const std::string &wndName;

    UserData() = delete;
};

void Morph(const UserData &data)
{
    const auto &src = data.inpImg;
    const auto &type = data.morphType;
    const auto &shape = data.morphShape;
    const auto &size = data.morphSize;
    auto &dst = data.rsltImg;
    const auto &wnd = data.wndName;

    const cv::Mat ker = cv::getStructuringElement(shape, cv::Size(1 + size / 2 * 2, 1 + size / 2 * 2));

    auto const watch = []() -> std::string {
        static int64 tick = 0;
        const int64 cur = cv::getTickCount();
        const std::string tmp = std::to_string((cur - tick) / cv::getTickFrequency()) + "s";
        tick = cur;
        return tmp;
    };

    const cv::Point org = cv::Point(static_cast<int>(.01 * src.cols), static_cast<int>(.98 * src.rows));
    const int fontFace = CV_FONT_HERSHEY_TRIPLEX;
    const int fontScale = 1;
    const cv::Scalar color = cv::Scalar::all(127);

    switch (type) {
    case static_cast<cv::MorphTypes>(-1):
        CV_UNUSED(watch());
        dst = src.clone();
        cv::putText(dst, "Original (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_ERODE:  // 侵蚀
        CV_UNUSED(watch());
        cv::erode(src, dst, ker);
        cv::putText(dst, "Erode (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_DILATE:  // 膨胀
        CV_UNUSED(watch());
        cv::dilate(src, dst, ker);
        cv::putText(dst, "Dilate (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_OPEN:  // 开运算
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "Open = Erode & Dilate (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_CLOSE:  // 闭运算
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "Close = Dilate & Erode (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_GRADIENT:  // 梯度运算
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "Gradient = Dilate - Erode (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_TOPHAT:  // 顶帽
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "TopHat = Source - Open (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_BLACKHAT:  // 黑帽
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "BlackHat = Close - Source (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    case cv::MorphTypes::MORPH_HITMISS:
        CV_UNUSED(watch());
        cv::morphologyEx(src, dst, type, ker);
        cv::putText(dst, "HitMiss (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(wnd, dst);
        break;
    default:
        assert(false);
        break;
    }
}

void OnTypeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<UserData *>(userdata);
    data.morphType = static_cast<cv::MorphTypes>(pos - 1);
    Morph(data);
}

void OnShapeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<UserData *>(userdata);
    data.morphShape = static_cast<cv::MorphShapes>(pos);
    Morph(data);
}

void OnSizeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<UserData *>(userdata);
    data.morphSize = pos;
    Morph(data);
}

}// namespace

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

    cv::MorphTypes morphType = static_cast<cv::MorphTypes>(-1);
    cv::MorphShapes morphShape = cv::MorphShapes::MORPH_RECT;
    int morphSize = 0;
    cv::Mat rlstImg;
    UserData data {inpImg, morphType, morphShape, morphSize, rlstImg, wndName};

    cv::createTrackbar("Type", wndName,
                       nullptr, 1 + cv::MorphTypes::MORPH_BLACKHAT,
                       OnTypeTrackbarChange, &data);
    cv::createTrackbar("Shape", wndName,
                       nullptr, cv::MorphShapes::MORPH_ELLIPSE,
                       OnShapeTrackbarChange, &data);
    cv::createTrackbar("Size", wndName,
                       nullptr, 43,
                       OnSizeTrackbarChange, &data);

    Morph(data);

    cv::waitKey(0);
    return 0;
}
