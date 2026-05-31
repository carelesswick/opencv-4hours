#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;
/////////////////////////颜色检测////////////////////////////////////
int main ()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV,mask;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);//转成HSV空间，更易用于颜色检测
	//namedWindow 用于创建一个窗口，该窗口可作为图像和滑动条的占位符，通过滑动窗口来寻找匹配的速度
	namedWindow("Trackbars", WINDOW_NORMAL);
	resizeWindow("Trackbars", 1024, 640);
	//函数 createTrackbar 会创建一个指定名称和范围的滑块（即滑动条或范围控件），将变量值与滑块位置同步
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);



	//检查数组元素是否位于另外两个数组元素之间。
	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);


		imshow("Image", img);
		imshow("Image_hsv", imgHSV);
		imshow("Image_mask", mask);

		waitKey(1);
	}
	return 0;
}



