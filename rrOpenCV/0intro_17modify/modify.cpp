//===-- Modify --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 加载、修改和保存图像
/// \sa <https://docs.opencv.org/master/db/d64/tutorial_load_save_image.html>
///
/// \version 2019-10-16
/// \since 2019-10-15
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

        const auto img = cv::imread(cv::samples::findFile(argv[1]), cv::IMREAD_COLOR);
        if (img.empty()) {
            cerr << "failure: img.empty()" << endl;
            return EXIT_FAILURE;
        }

        cv::Mat gray_img;
        cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);

#if 0
        cv::imwrite("path/to/file", grayimg);
#endif

        cv::namedWindow("color");
        cv::namedWindow("gray");

        cv::imshow("color", img);
        cv::imshow("gray", gray_img);

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
