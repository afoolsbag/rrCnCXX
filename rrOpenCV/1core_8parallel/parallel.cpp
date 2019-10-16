//===-- Parallel ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 并行运算
/// \sa <https://docs.opencv.org/master/d7/dff/tutorial_how_to_use_OpenCV_parallel_for_.html>
/// \sa [“曼德博集合”](https://zh.wikipedia.org/wiki/曼德博集合). *Wikipedia*
///
/// \version 2019-10-16
/// \since 2019-10-16
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
    CV_UNUSED(argc);
    CV_UNUSED(argv);

    try {
        cv::Mat img {1080, 1920, CV_8U, cv::Scalar::all(0)};
        const float x1 = -2.1f, x2 = 0.6f;
        const float y1 = -1.2f, y2 = 1.2f;
        const float scale_x = static_cast<float>(img.cols) / (x2 - x1);
        const float scale_y = static_cast<float>(img.rows) / (y2 - y1);

        static const auto mandelbrot = [](const complex<float> &z0, const int max) -> int {
            complex<float> z = z0;
            for (int t = 0; t < max; t++) {
                if (z.real()*z.real() + z.imag()*z.imag() > 4.0f)
                    return t;
                z = z * z + z0;
            }
            return max;
        };

        static const auto mandelbrot_formula = [](const complex<float> &z0, const int max_iter = 500) -> int {
            const auto value = mandelbrot(z0, max_iter);
            if (max_iter - value == 0)
                return 0;
            return cvRound(sqrt(static_cast<float>(value) / static_cast<float>(max_iter)) * 255);
        };

        auto tick = cv::getTickCount();
        cv::parallel_for_(cv::Range {0, img.rows * img.cols}, [&](const cv::Range& range) {
            for (int r = range.start; r < range.end; r++) {
                const int i = r / img.cols;
                const int j = r % img.cols;

                const float x0 = static_cast<float>(j) / scale_x + x1;
                const float y0 = static_cast<float>(i) / scale_y + y1;

                complex<float> z0 {x0, y0};
                const auto value = static_cast<uchar>(mandelbrot_formula(z0));
                img.ptr<uchar>(i)[j] = value;
            }
        });
        tick -= cv::getTickCount();
        cout << "time cost: " << -tick / cv::getTickFrequency() << "s.\n";

        cv::imshow("Mandelbrot", img);
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
