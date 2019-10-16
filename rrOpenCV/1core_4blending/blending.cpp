//===-- Blending ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 使用 OpenCV 混合两张图像
/// \sa <https://docs.opencv.org/master/d5/dc4/tutorial_adding_images.html>
///
/// \version 2018-10-16
/// \since 2018-03-01
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;

namespace rropencv {

/// \brief 混合。
/// \details 按配比混合俩图像。
///          \f[
///            I_{\textrm{rtn}} = α_{\textrm{ratio1}}I_{\textrm{img1}} + (1-α_{\textrm{ratio1}})I_{\textrm{img2}}
///          \f]
///
/// \param img1    图像1；
/// \param ratio1  配比1；
/// \param img2    图像2。
/// \returns 结果图像。
///
cv::Mat blend(const cv::Mat &img1, double ratio1, const cv::Mat &img2)
{
    CV_Assert(0 <= ratio1 && ratio1 <= 1);
    const double ratio2 = 1 - ratio1;
    cv::Mat tmp;
    cv::addWeighted(img1, ratio1, img2, ratio2, 0, tmp);
    return tmp;
}

}

int main(int argc, char *argv[]) noexcept
{
    try {
        if (argc != 3) {
            cerr << "failure: argc != 3" << endl;
            return EXIT_FAILURE;
        }

        const auto img1 = cv::imread(cv::samples::findFile(argv[1]), cv::IMREAD_UNCHANGED);
        if (img1.empty()) {
            cerr << "failure: img1.empty()" << endl;
            return EXIT_FAILURE;
        }

        const auto img2 = cv::imread(cv::samples::findFile(argv[2]), cv::IMREAD_UNCHANGED);
        if (img2.empty()) {
            cerr << "failure: img2.empty()" << endl;
            return EXIT_FAILURE;
        }

        if (img1.rows != img2.rows || img1.cols != img2.cols || img1.type() != img2.type()) {
            cout << "failure: img1 and img2 aren't matched" << endl;
            return EXIT_FAILURE;
        }

        struct trackbar_callback_userdata_t {
            const cv::Mat &img1;
            const cv::Mat &img2;
            cv::Mat &img3;
            const string &wnd_name;
        };
        static const auto on_trackbar_change = [](int pos, void *userdata) -> void {
            auto const p = reinterpret_cast<trackbar_callback_userdata_t *>(userdata);
            p->img3 = rropencv::blend(p->img1, pos / 100.0, p->img2);
            cv::imshow(p->wnd_name, p->img3);
        };
        cv::Mat img3;
        const string wnd_name = "blend";
        trackbar_callback_userdata_t data {img1, img2, img3, wnd_name};

        cv::namedWindow(wnd_name);
        int initial_value = 50;
        cv::createTrackbar("Ratio1", wnd_name, &initial_value, 100, on_trackbar_change, &data);
        on_trackbar_change(initial_value, &data);
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
