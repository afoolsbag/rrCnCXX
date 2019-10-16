//===-- Exp -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gExp 生成 `exp` 文件
/// \ingroup gHighGUI
///
/// \sa <https://docs.opencv.org/4.0.1/db/deb/tutorial_display_image.html>
///
/// \version 2019-01-23
/// \since 2019-01-22
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

struct Userdata {
    string path;
    cv::Mat img;
    cv::Mat buf;
};

void onMouseChange(int event, int x, int y, int flags, void *userdata);
void writeExp(const string &path, const cv::Mat &img, const cv::Point &pt1, const cv::Point &pt2);

int main(int argc, char *argv[])
{
    if (argc != 2)
        return EXIT_FAILURE;

    Userdata data;
    data.path = argv[1];
    data.img = cv::imread(data.path);
    if (data.img.empty())
        return EXIT_FAILURE;
    data.buf = data.img.clone();

    cv::namedWindow(data.path);
    cv::setMouseCallback(data.path, onMouseChange, &data);

    cv::imshow(data.path, data.buf);
    cv::waitKey(0);
    return EXIT_SUCCESS;
}

void onMouseChange(int event, int x, int y, int flags, void *userdata)
{
    auto &data = *reinterpret_cast<Userdata *>(userdata);

    static bool holding {false};
    static cv::Point pt1, pt2;

    switch (event) {
    case cv::EVENT_MOUSEMOVE:
        if (holding) {
            pt2.x = x;
            pt2.y = y;
            data.buf = data.img.clone();
            cv::rectangle(data.buf, pt1, pt2, cv::Scalar(0, 255, 0, 127), 2);
            cv::imshow(data.path, data.buf);
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
        writeExp(data.path, data.buf, pt1, pt2);
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

void writeExp(const string &path, const cv::Mat &img, const cv::Point &pt1, const cv::Point &pt2)
{
    const auto expPath {path + ".exp"};

    const int32_t quadbyte1 {4};
    const float quadbyte2 {min(pt1.x, pt2.x) / static_cast<float>(img.cols)};
    const float quadbyte3 {min(pt1.y, pt2.y) / static_cast<float>(img.rows)};
    const float quadbyte4 {max(pt1.x, pt2.x) / static_cast<float>(img.cols)};
    const float quadbyte5 {max(pt1.y, pt2.y) / static_cast<float>(img.rows)};

    fstream expFile;
    expFile.open(expPath, ios::out | ios::binary);
    expFile.write(reinterpret_cast<const char *>(&quadbyte1), sizeof quadbyte1);
    expFile.write(reinterpret_cast<const char *>(&quadbyte2), sizeof quadbyte2);
    expFile.write(reinterpret_cast<const char *>(&quadbyte3), sizeof quadbyte3);
    expFile.write(reinterpret_cast<const char *>(&quadbyte4), sizeof quadbyte4);
    expFile.write(reinterpret_cast<const char *>(&quadbyte5), sizeof quadbyte5);
    expFile.close();
}
