#include <opencv2/imgcodecs.hpp>// 图像读取与写入
#include <opencv2/highgui.hpp>// 显示图像、滑动条等GUI
#include <opencv2/imgproc.hpp>// 图像处理（画矩形、缩放等）
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////image////////////////////////////////////
//void main ()
//{
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	imshow("Image",img);
//	waitKey(0);
//}


//////////////////////video///////////////////////////////////////
//void main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(2);
//	}
//}


//////////////////////camera///////////////////////////////////////
void main()
{
	
	VideoCapture cap(0);
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}

