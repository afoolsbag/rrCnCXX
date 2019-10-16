//===-- Discrete Fourier Transform ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 离散傅里叶变换
/// \sa <https://docs.opencv.org/master/d8/d01/tutorial_discrete_fourier_transform.html>
/// \sa <https://zhuanlan.zhihu.com/p/19763358>
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
    try {
        if (argc != 2) {
            cerr << "failure: argc != 2" << endl;
            return EXIT_FAILURE;
        }

        // 加载灰度图
        const auto img = cv::imread(cv::samples::findFile(argv[1]), cv::IMREAD_GRAYSCALE);
        if (img.empty()) {
            cerr << "failure: img.empty()" << endl;
            return EXIT_FAILURE;
        }

        // 离散傅里叶变换的性能取决于图像尺寸：对于边长为 2、3 和 5 的倍数的图像，它往往是最快的。
        // 因此，为取得最佳性能而为图像填充黑边（向下边和右边扩展填充）：
        const auto opt_cy = cv::getOptimalDFTSize(img.rows);
        const auto opt_cx = cv::getOptimalDFTSize(img.cols);
        cv::Mat padded;
        cv::copyMakeBorder(img, padded, 0, opt_cy - img.rows, 0, opt_cx - img.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

        // 构造复数图像，使填充图像为实部，全零图像为虚部
        cv::Mat planes[] = {cv::Mat_<float> {padded}, cv::Mat::zeros(padded.size(), CV_32F)};
        cv::Mat complex_img;
        merge(planes, 2, complex_img);

        // 就地进行离散傅里叶变换
        cv::dft(complex_img, complex_img);

        // 以实部和虚部计算幅度（正交向量合成的模）
        split(complex_img, planes);  // planes[0] = Re(DFT(I))
                                       // planes[1] = Im(DFT(I))
        magnitude(planes[0], planes[1], planes[0]);
        cv::Mat mag_img = planes[0];

        // 转换为对数刻度
        mag_img += cv::Scalar::all(1);
        cv::log(mag_img, mag_img);

        // 因之前填充了黑边，因而需要对结果进行调整

        // 若频谱边长不为偶数，裁剪一像素：
        mag_img = mag_img(cv::Rect {0, 0, mag_img.cols & -2, mag_img.rows & -2});
        const auto mag_hx = mag_img.cols / 2;
        const auto mag_hy = mag_img.rows / 2;

        // 调整象限，使原点居中
        // 0 | 1
        // --+--
        // 2 | 3
        cv::Mat q0(mag_img, cv::Rect {0, 0, mag_hx, mag_hy});
        cv::Mat q1(mag_img, cv::Rect {mag_hx, 0, mag_hx, mag_hy});
        cv::Mat q2(mag_img, cv::Rect {0, mag_hy, mag_hx, mag_hy});
        cv::Mat q3(mag_img, cv::Rect {mag_hx, mag_hy, mag_hx, mag_hy});
        cv::Mat tmp;

        q0.copyTo(tmp);
        q3.copyTo(q0);
        tmp.copyTo(q3);

        q1.copyTo(tmp);
        q2.copyTo(q1);
        tmp.copyTo(q2);

        // 将 0 ~ 1 的浮点值规格化
        cv::normalize(mag_img, mag_img, 0, 1, cv::NORM_MINMAX);

        // 显示
        cv::imshow("input", img);
        cv::imshow("spectrum magnitude", mag_img);
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
