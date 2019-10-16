//===-- Display -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 加载和显示图像
/// \sa <https://docs.opencv.org/master/db/deb/tutorial_display_image.html>
///
/// \version 2019-10-16
/// \since 2019-01-22
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

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

        cv::namedWindow("display");
        cv::imshow("display", img);
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
