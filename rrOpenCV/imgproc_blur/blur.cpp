//===-- Blur ----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBlur 模糊处理
/// \ingroup gImgProc
///
/// \sa <https://docs.opencv.org/3.4.2/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html>
///
/// \author zhengrr
/// \version 2018-07-20
/// \since 2018-07-19
/// \copyright The MIT License
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace {

enum class BlurType {
    ORIGINAL,     ///< 原始图像。
    HOMOGENEOUS,  ///< 归一化模糊。
    GAUSSIAN,     ///< 高斯模糊。
    MEDIAN,       ///< 中值模糊。
    BILATERAL,    ///< 双边模糊。
    RANGELAST = BILATERAL
};

struct UserData {
    const cv::Mat &inpImg;
    BlurType &blurType;
    int &blurParam;
    cv::Mat &rsltImg;
    const std::string &wndName;

    UserData() = delete;
};

void Blur(const UserData &data)
{
    const auto &src = data.inpImg;
    auto &dst = data.rsltImg;

    int param;

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

    switch (data.blurType) {
    case BlurType::ORIGINAL:
        CV_UNUSED(watch());
        dst = src.clone();
        cv::putText(dst, "Original (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(data.wndName, dst);
        break;
    case BlurType::HOMOGENEOUS:
        param = 1 + data.blurParam / 2 * 2;
        CV_UNUSED(watch());
        cv::blur(src, dst, cv::Size(param, param), cv::Point(-1, -1));
        cv::putText(dst, "Homogeneous Blur (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(data.wndName, dst);
        break;
    case BlurType::GAUSSIAN:
        param = 1 + data.blurParam / 2 * 2;
        CV_UNUSED(watch());
        cv::GaussianBlur(src, dst, cv::Size(param, param), 0.);
        cv::putText(dst, "Gaussian Blur (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(data.wndName, dst);
        break;
    case BlurType::MEDIAN:
        param = 1 + data.blurParam / 2 * 2;
        CV_UNUSED(watch());
        cv::medianBlur(src, dst, param);
        cv::putText(dst, "Median Blur (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(data.wndName, dst);
        break;
    case BlurType::BILATERAL:
        param = data.blurParam;
        CV_UNUSED(watch());
        cv::bilateralFilter(src, dst, param, param * 2, param / 2);
        cv::putText(dst, "Bilateral Blur (" + watch() + ")", org, fontFace, fontScale, color);
        cv::imshow(data.wndName, dst);
        break;
    default:
        assert(false);
        break;
    }
}

void OnTypeTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<UserData *>(userdata);
    data.blurType = static_cast<BlurType>(pos);
    Blur(data);
}

void OnParamTrackbarChange(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<UserData *>(userdata);
    data.blurParam = pos;
    Blur(data);
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

    BlurType blurType {BlurType::ORIGINAL};
    int blurParam {0};
    cv::Mat rlstImg;
    UserData data {inpImg, blurType, blurParam, rlstImg, wndName};

    cv::createTrackbar("Type", wndName,
                       nullptr, static_cast<int>(BlurType::RANGELAST),
                       OnTypeTrackbarChange, &data);
    cv::createTrackbar("Param", wndName,
                       nullptr, 31,
                       OnParamTrackbarChange, &data);

    Blur(data);

    cv::waitKey(0);
    return 0;
}