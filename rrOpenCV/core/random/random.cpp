//===-- OpenCV - Core - Random ----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 随机
///
/// \sa <https://docs.opencv.org/3.4.2/df/d61/tutorial_random_generator_and_text.html>
///
/// \author zhengrr
/// \version 2018-07-18
/// \since 2018-07-18
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace {

const int NUMBER = 100;
const int DELAY = 5;

const int WNDWD = 900;  // window width
const int WNDHT = 600;  // window heigth
const int XMIN = -WNDWD / 2;
const int XMAX = WNDWD * 3 / 2;
const int YMIN = -WNDHT / 2;
const int YMAX = WNDHT * 3 / 2;

cv::Scalar RandomColor(cv::RNG &rng)
{
    const uint32_t clr {static_cast<uint32_t>(rng)};
    return cv::Scalar {static_cast<double>(clr & UINT8_MAX),
        static_cast<double>(clr >> 8 & UINT8_MAX),
        static_cast<double>(clr >> 16 & UINT8_MAX)};
}

bool DrawingRandomLines(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point pt1, pt2;
    int thickness;

    for (int i = 0; i < NUMBER; ++i) {
        pt1.x = rng.uniform(XMIN, XMAX);
        pt1.y = rng.uniform(YMIN, YMAX);
        pt2.x = rng.uniform(XMIN, XMAX);
        pt2.y = rng.uniform(YMIN, YMAX);
        thickness = rng.uniform(1, 10);
        cv::line(img, pt1, pt2, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }
    return true;
}

bool DrawingRandomRectangles(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point pt1, pt2;
    int thickness;

    for (int i = 0; i < NUMBER; ++i) {
        pt1.x = rng.uniform(XMIN, XMAX);
        pt1.y = rng.uniform(YMIN, YMAX);
        pt2.x = rng.uniform(XMIN, XMAX);
        pt2.y = rng.uniform(YMIN, YMAX);
        thickness = std::max(-1, rng.uniform(-3, 10));
        cv::rectangle(img, pt1, pt2, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DrawingRandomEllipses(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point center;
    cv::Size axes;
    double angle;
    int thickness;

    for (int i = 0; i < NUMBER; i++) {
        center.x = rng.uniform(XMIN, XMAX);
        center.y = rng.uniform(YMIN, YMAX);
        axes.width = rng.uniform(0, 200);
        axes.height = rng.uniform(0, 200);
        angle = rng.uniform(0, 180);
        thickness = rng.uniform(-1, 9);
        cv::ellipse(img, center, axes, angle, angle - 100, angle + 200, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DrawingRandomPolylines(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point pl1[3];
    cv::Point pl2[3];
    const cv::Point *const pPl[] {pl1, pl2};
    int nPl[] {3, 3};
    int thickness;

    for (int i = 0; i < NUMBER; i++) {
        pl1[0].x = rng.uniform(XMIN, XMAX);
        pl1[0].y = rng.uniform(YMIN, YMAX);
        pl1[1].x = rng.uniform(XMIN, XMAX);
        pl1[1].y = rng.uniform(YMIN, YMAX);
        pl1[2].x = rng.uniform(XMIN, XMAX);
        pl1[2].y = rng.uniform(YMIN, YMAX);
        pl2[0].x = rng.uniform(XMIN, XMAX);
        pl2[0].y = rng.uniform(YMIN, YMAX);
        pl2[1].x = rng.uniform(XMIN, XMAX);
        pl2[1].y = rng.uniform(YMIN, YMAX);
        pl2[2].x = rng.uniform(XMIN, XMAX);
        pl2[2].y = rng.uniform(YMIN, YMAX);
        thickness = rng.uniform(1, 10);
        cv::polylines(img, pPl, nPl, 2, true, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DrawingRandomFilledPolygons(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point pl1[3];
    cv::Point pl2[3];
    const cv::Point *pPl[] {pl1, pl2};
    int nPl[] {3, 3};

    for (int i = 0; i < NUMBER; i++) {
        pl1[0].x = rng.uniform(XMIN, XMAX);
        pl1[0].y = rng.uniform(YMIN, YMAX);
        pl1[1].x = rng.uniform(XMIN, XMAX);
        pl1[1].y = rng.uniform(YMIN, YMAX);
        pl1[2].x = rng.uniform(XMIN, XMAX);
        pl1[2].y = rng.uniform(YMIN, YMAX);
        pl2[0].x = rng.uniform(XMIN, XMAX);
        pl2[0].y = rng.uniform(YMIN, YMAX);
        pl2[1].x = rng.uniform(XMIN, XMAX);
        pl2[1].y = rng.uniform(YMIN, YMAX);
        pl2[2].x = rng.uniform(XMIN, XMAX);
        pl2[2].y = rng.uniform(YMIN, YMAX);
        cv::fillPoly(img, pPl, nPl, 2, RandomColor(rng));

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DrawingRandomCircles(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point center;
    int radius;
    int thickness;

    for (int i = 0; i < NUMBER; i++) {
        center.x = rng.uniform(XMIN, XMAX);
        center.y = rng.uniform(YMIN, YMAX);
        radius = rng.uniform(0, 300);
        thickness = rng.uniform(-1, 9);
        cv::circle(img, center, radius, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DisplayingRandomText(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Point org;
    int fontFace;
    double fontScale;
    int thickness;

    for (int i = 1; i < NUMBER; i++) {
        org.x = rng.uniform(XMIN, XMAX);
        org.y = rng.uniform(YMIN, YMAX);
        fontFace = rng.uniform(0, 8);
        fontScale = rng.uniform(0, 100) * 0.05 + 0.1;
        thickness = rng.uniform(1, 10);

        cv::putText(img, "Testing text rendering", org, fontFace, fontScale, RandomColor(rng), thickness);

        cv::imshow(wndName, img);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

bool DisplayingBigEnd(cv::Mat &img, const std::string &wndName, cv::RNG &rng)
{
    cv::Size textsize = cv::getTextSize("OpenCV forever!", cv::FONT_HERSHEY_COMPLEX, 3, 5, 0);
    cv::Point org((WNDWD - textsize.width) / 2, (WNDHT - textsize.height) / 2);
    cv::Mat img2;

    for (int i = 0; i < 255; i += 2) {
        img2 = img - cv::Scalar::all(i);
        cv::putText(img2, "OpenCV forever!", org, cv::FONT_HERSHEY_COMPLEX, 3,
                    cv::Scalar(i, i, 255), 5, 8);

        cv::imshow(wndName, img2);
        if (cv::waitKey(DELAY) >= 0)
            return false;
    }

    return true;
}

}// namespace

int main(int argc, char *argv[])
{
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    cv::Mat img = cv::Mat::zeros(WNDHT, WNDWD, CV_8UC3);

    const std::string wndName = "Random";
    cv::imshow(wndName, img);

    cv::RNG rng(0xFFFFFFFF);

    if (!DrawingRandomLines(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DrawingRandomRectangles(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DrawingRandomEllipses(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DrawingRandomPolylines(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DrawingRandomFilledPolygons(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DrawingRandomCircles(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DisplayingRandomText(img, wndName, rng))
        return EXIT_SUCCESS;

    if (!DisplayingBigEnd(img, wndName, rng))
        return EXIT_SUCCESS;

    cv::waitKey(0);
    return EXIT_SUCCESS;
}
