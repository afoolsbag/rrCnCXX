//===-- Trackbar ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 滑动条等
/// \sa <https://docs.opencv.org/master/da/d6a/tutorial_trackbar.html>
///
/// \version 2019-10-17
/// \since 2018-02-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <bitset>
#include <sstream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;

namespace {
constexpr char window_name[] {"Window"};
constexpr int window_width {800};
constexpr int window_height {600};
constexpr char trackbar_name[] {"Trackbar"};
struct data_t {
    const cv::Mat &background;
    cv::Mat &canvas;
};
void on_mouse_change(int event, int x, int y, int flags, void *userdata);
void on_trackbar_change(int pos, void *userdata);
}

int main() noexcept
{
    try {

        const cv::Mat background {window_height, window_width, CV_8UC3, cv::Scalar::all(0)};
        cv::Mat canvas {background.clone()};
        data_t data {background, canvas};

        cv::namedWindow(window_name);
        cv::setMouseCallback(window_name, on_mouse_change, &data);
        cv::createTrackbar(trackbar_name, window_name, nullptr, UINT8_MAX, on_trackbar_change, &data);

        cv::imshow(window_name, data.canvas);
        cv::waitKey(0);
        return EXIT_SUCCESS;

    } catch (const exception &e) {
        cerr << "failure: exception " << e.what() << endl;
        return EXIT_FAILURE;

    } catch (...) {
        cerr << "failure: exception ..." << endl;
        return EXIT_FAILURE;

    }
}

namespace {

void on_mouse_change(int event, int x, int y, int flags, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);

    static bool holding {false};
    static cv::Point pt1, pt2;

    switch (event) {
    case cv::EVENT_MOUSEMOVE:
        if (holding) {
            data.background.copyTo(data.canvas);

            ostringstream oss;
            oss << "on_mouse_change: event=" << event << ", x=" << x << ", y=" << y << ", flags=" << bitset<6> {static_cast<unsigned long long>(flags)};
            cv::Point org {static_cast<int>((0.01 * window_width)), static_cast<int>((0.98 * window_height))};
            cv::putText(data.canvas, oss.str(), org, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar::all(UCHAR_MAX));

            pt2.x = x;
            pt2.y = y;
            cv::rectangle(data.canvas, pt1, pt2, cv::Scalar(0, 255, 0, 127), 2);

            cv::imshow(window_name, data.canvas);
        }
        break;
    case cv::EVENT_LBUTTONDOWN:
        pt1.x = x;
        pt1.y = y;
        pt2.x = x;
        pt2.y = y;
        holding = true;
        break;
    case cv::EVENT_LBUTTONUP:
        holding = false;
        break;
    default:
        break;
    }
}

void on_trackbar_change(int pos, void *userdata)
{
    auto &data = *reinterpret_cast<data_t *>(userdata);

    data.background.copyTo(data.canvas);

    ostringstream oss;
    oss << "on_trackbar_change: pos=" << pos;
    cv::Point org {static_cast<int>((0.01 * window_width)), static_cast<int>((0.98 * window_height))};
    cv::putText(data.canvas, oss.str(), org, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar::all(UCHAR_MAX));

    cv::imshow(window_name, data.canvas);
}

}
