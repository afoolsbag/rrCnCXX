//===-- Random --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 随机
///
/// \sa <https://docs.opencv.org/master/df/d61/tutorial_random_generator_and_text.html>
///
/// \version 2019-10-16
/// \since 2018-07-18
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;

namespace {

constexpr int times {100};
constexpr int delay {5};

constexpr int window_width {900};
constexpr int window_height {600};
constexpr int x_min {static_cast<int>(-0.5 * window_width)};
constexpr int x_max {static_cast<int>(1.5 * window_width)};
constexpr int y_min {static_cast<int>(-0.5 * window_height)};
constexpr int y_max {static_cast<int>(1.5 * window_width)};

cv::Scalar random_color(cv::RNG &rng)
{
    const uint32_t random32bit {static_cast<uint32_t>(rng)};
    return cv::Scalar {
        static_cast<double>(random32bit & UINT8_MAX),
        static_cast<double>(random32bit >> 8 & UINT8_MAX),
        static_cast<double>(random32bit >> 16 & UINT8_MAX)};
}

void draw_random_lines(cv::Mat &img, cv::RNG &rng, const string &wnd_name)
{
    cv::Point pt1, pt2;
    int thickness;

    for (int i = 0; i < times; ++i) {
        pt1.x = rng.uniform(x_min, x_max);
        pt1.y = rng.uniform(y_min, y_max);
        pt2.x = rng.uniform(x_min, x_max);
        pt2.y = rng.uniform(y_min, y_max);
        thickness = rng.uniform(1, 10);
        cv::line(img, pt1, pt2, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }
}

void draw_random_rectangles(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point pt1, pt2;
    int thickness;

    for (int i = 0; i < times; ++i) {
        pt1.x = rng.uniform(x_min, x_max);
        pt1.y = rng.uniform(y_min, y_max);
        pt2.x = rng.uniform(x_min, x_max);
        pt2.y = rng.uniform(y_min, y_max);
        thickness = std::max(-1, rng.uniform(-3, 10));
        cv::rectangle(img, pt1, pt2, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }
}

void draw_random_ellipses(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point center;
    cv::Size axes;
    double angle;
    int thickness;

    for (int i = 0; i < times; i++) {
        center.x = rng.uniform(x_min, x_max);
        center.y = rng.uniform(y_min, y_max);
        axes.width = rng.uniform(0, 200);
        axes.height = rng.uniform(0, 200);
        angle = rng.uniform(0, 180);
        thickness = rng.uniform(-1, 9);
        cv::ellipse(img, center, axes, angle, angle - 100, angle + 200, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }
}

void draw_random_polylines(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point pl1[3];
    cv::Point pl2[3];
    const cv::Point *const ppl[] {pl1, pl2};
    int npl[] {3, 3};
    int thickness;

    for (int i = 0; i < times; i++) {
        pl1[0].x = rng.uniform(x_min, x_max);
        pl1[0].y = rng.uniform(y_min, y_max);
        pl1[1].x = rng.uniform(x_min, x_max);
        pl1[1].y = rng.uniform(y_min, y_max);
        pl1[2].x = rng.uniform(x_min, x_max);
        pl1[2].y = rng.uniform(y_min, y_max);
        pl2[0].x = rng.uniform(x_min, x_max);
        pl2[0].y = rng.uniform(y_min, y_max);
        pl2[1].x = rng.uniform(x_min, x_max);
        pl2[1].y = rng.uniform(y_min, y_max);
        pl2[2].x = rng.uniform(x_min, x_max);
        pl2[2].y = rng.uniform(y_min, y_max);
        thickness = rng.uniform(1, 10);
        cv::polylines(img, ppl, npl, 2, true, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }
}

void draw_random_filled_polygons(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point pl1[3];
    cv::Point pl2[3];
    const cv::Point *ppl[] {pl1, pl2};
    int npl[] {3, 3};

    for (int i = 0; i < times; i++) {
        pl1[0].x = rng.uniform(x_min, x_max);
        pl1[0].y = rng.uniform(y_min, y_max);
        pl1[1].x = rng.uniform(x_min, x_max);
        pl1[1].y = rng.uniform(y_min, y_max);
        pl1[2].x = rng.uniform(x_min, x_max);
        pl1[2].y = rng.uniform(y_min, y_max);
        pl2[0].x = rng.uniform(x_min, x_max);
        pl2[0].y = rng.uniform(y_min, y_max);
        pl2[1].x = rng.uniform(x_min, x_max);
        pl2[1].y = rng.uniform(y_min, y_max);
        pl2[2].x = rng.uniform(x_min, x_max);
        pl2[2].y = rng.uniform(y_min, y_max);
        cv::fillPoly(img, ppl, npl, 2, random_color(rng));

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }

}

void draw_random_circles(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point center;
    int radius;
    int thickness;

    for (int i = 0; i < times; i++) {
        center.x = rng.uniform(x_min, x_max);
        center.y = rng.uniform(y_min, y_max);
        radius = rng.uniform(0, 300);
        thickness = rng.uniform(-1, 9);
        cv::circle(img, center, radius, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) != -1)
            exit(EXIT_SUCCESS);
    }
}

void display_random_text(cv::Mat &img, cv::RNG &rng, const std::string &wnd_name)
{
    cv::Point org;
    int font_face;
    double font_scale;
    int thickness;

    for (int i = 1; i < times; i++) {
        org.x = rng.uniform(x_min, x_max);
        org.y = rng.uniform(y_min, y_max);
        font_face = rng.uniform(0, 8);
        font_scale = rng.uniform(0, 100) * 0.05 + 0.1;
        thickness = rng.uniform(1, 10);

        cv::putText(img, "Testing text rendering", org, font_face, font_scale, random_color(rng), thickness);

        cv::imshow(wnd_name, img);
        if (cv::waitKey(delay) >= 0)
            exit(EXIT_SUCCESS);
    }
}

void display_big_end(cv::Mat &img, cv::RNG &, const std::string &wnd_name)
{
    cv::Size textsize = cv::getTextSize("OpenCV forever!", cv::FONT_HERSHEY_COMPLEX, 3, 5, nullptr);
    cv::Point org((window_width - textsize.width) / 2, (window_height - textsize.height) / 2);
    cv::Mat img2;

    for (int i = 0; i < UCHAR_MAX; i += 2) {
        img2 = img - cv::Scalar::all(i);
        cv::putText(img2, "OpenCV forever!", org, cv::FONT_HERSHEY_COMPLEX, 3, cv::Scalar(i, i, UCHAR_MAX), 5, cv::LINE_8);

        cv::imshow(wnd_name, img2);
        if (cv::waitKey(delay) >= 0)
            exit(EXIT_SUCCESS);
    }
}

}

int main(int argc, char *argv[])
{
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    cv::Mat img = cv::Mat::zeros(window_height, window_width, CV_8UC3);

    const string wnd_name = "Random";
    cv::imshow(wnd_name, img);

    cv::RNG rng {0xFFFFFFFF};
    draw_random_lines(img, rng, wnd_name);
    draw_random_rectangles(img, rng, wnd_name);
    draw_random_ellipses(img, rng, wnd_name);
    draw_random_polylines(img, rng, wnd_name);
    draw_random_filled_polygons(img, rng, wnd_name);
    draw_random_circles(img, rng, wnd_name);
    display_random_text(img, rng, wnd_name);
    display_big_end(img, rng, wnd_name);

    cv::waitKey(0);
    return EXIT_SUCCESS;
}
