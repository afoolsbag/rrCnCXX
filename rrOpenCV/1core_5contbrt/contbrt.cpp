//===-- Contrast & Brightness -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 对比度和亮度
/// \sa <https://docs.opencv.org/master/d3/dc1/tutorial_basic_linear_transform.html>
///
/// \version 2019-10-16
/// \since 2018-07-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;

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

        struct trackbar_callback_userdata_t {
            const cv::Mat &img;
            int &alpha;
            int &beta;
            int &gamma;
            cv::Mat &show;
            const string &wnd_name;
        };
        static const auto on_trackbar_change = [](int alpha, int beta, int gamma, trackbar_callback_userdata_t *p) -> void {
            p->alpha = alpha;
            p->beta = beta;
            p->gamma = gamma;

            p->img.convertTo(p->show, -1, p->alpha / 100.0, p->beta - UCHAR_MAX);

            cv::Mat map_tbl(1, 1 + UCHAR_MAX, CV_8U);
            for (int i = 0; i < 1 + UCHAR_MAX; ++i)
                map_tbl.ptr()[i] = cv::saturate_cast<uchar>(pow(i / 255.0, p->gamma / 100.0) * 255.0);
            LUT(p->show, map_tbl, p->show);

            cv::imshow(p->wnd_name, p->show);
        };
        static const auto on_alpha_trackbar_change = [](int pos, void *userdata) -> void {
            auto const p = reinterpret_cast<trackbar_callback_userdata_t *>(userdata);
            on_trackbar_change(pos, p->beta, p->gamma, p);
        };
        static const auto on_beta_trackbar_change = [](int pos, void *userdata) -> void {
            auto const p = reinterpret_cast<trackbar_callback_userdata_t *>(userdata);
            on_trackbar_change(p->alpha, pos, p->gamma, p);
        };
        static const auto on_gamma_trackbar_change = [](int pos, void *userdata) -> void {
            auto const p = reinterpret_cast<trackbar_callback_userdata_t *>(userdata);
            on_trackbar_change(p->alpha, p->beta, pos, p);
        };
        int alpha = 100;
        int beta = UINT8_MAX;
        int gamma = 100;
        cv::Mat show;
        const string wnd_name = "contrast & brightness";
        trackbar_callback_userdata_t data {img, alpha, beta, gamma, show, wnd_name};

        cv::namedWindow(wnd_name);
        cv::createTrackbar("Alpha(%)", wnd_name, &alpha, 2 * alpha, on_alpha_trackbar_change, &data);
        cv::createTrackbar("Beta", wnd_name, &beta, 2 * beta, on_beta_trackbar_change, &data);
        cv::createTrackbar("Gamma(%)", wnd_name, &gamma, 2 * gamma, on_gamma_trackbar_change, &data);
        on_alpha_trackbar_change(alpha, &data);
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
