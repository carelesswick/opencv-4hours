#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// 基于HSV色彩空间转黑夜效果的函数
Mat hsvDayToNight(const Mat& image) {
    // 1. 将 BGR 图像转换到 HSV 色彩空间
    Mat hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);

    // 2. 分离 H(色相), S(饱和度), V(明度/亮度) 三个通道
    vector<Mat> hsv_channels;
    split(hsv, hsv_channels);

    // 3. 分别降低饱和度和亮度
    // 使用 convertTo 进行快速矩阵乘法计算，公式：新值 = 原值 * alpha + beta
    // 第二个参数 -1 表示输出矩阵的深度(类型)与原矩阵相同 (即仍保持 CV_8U)
    // 内部自带 saturate_cast，能完美处理边界溢出问题

    // 降低饱和度 S (索引为1) 到原来的 50%
    hsv_channels[1].convertTo(hsv_channels[1], -1, 0.5, 0);

    // 降低亮度/明度 V (索引为2) 到原来的 30%
    hsv_channels[2].convertTo(hsv_channels[2], -1, 0.3, 0);

    // 4. 重新合并这三个通道
    merge(hsv_channels, hsv);

    // 5. 将处理后的 HSV 图像转换回默认的 BGR 格式
    Mat night_img;
    cvtColor(hsv, night_img, COLOR_HSV2BGR);

    return night_img;
}

int main() {
    // 读取正常拍摄的图片
    Mat img = imread("C:/Users/carelesswick/Desktop/1.jpg");

    if (img.empty()) {
        cout << "无法读取图片，请检查路径是否正确！" << endl;
        return -1;
    }

    // 调用HSV转换函数
    Mat night_img = hsvDayToNight(img);

    // 创建窗口并显示结果
    namedWindow("Original", WINDOW_NORMAL);
    namedWindow("Night Effect (HSV)", WINDOW_NORMAL);

    imshow("Original", img);
    imshow("Night Effect (HSV)", night_img);
    imwrite("C:/Users/carelesswick/Desktop/4.jpg",night_img);

    // 等待按键按下后退出
    waitKey(0);
    destroyAllWindows();

    return 0;
}