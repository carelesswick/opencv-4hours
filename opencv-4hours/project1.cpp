#include <opencv2/imgcodecs.hpp>// 图像读取与写入
#include <opencv2/highgui.hpp>// 显示图像、滑动条等GUI
#include <opencv2/imgproc.hpp>// 图像处理（画矩形、缩放等）
#include <iostream>


using namespace std;
using namespace cv;

void findColor(Mat&img)//写成(Mat img)有什么区别？
{
	Mat imgHSV;
	//没有实际搞清楚vector到底是什么？还需要彻底搞懂
	vector<vector<int>> mycolors{ {63,47,82,104,255,246} ,//天蓝色（青蛙王子的盖子）
								  {97,71,0,179,255,255}, };//深蓝色（唇膏的盖子）

	vector<Scalar> myColorValues{ {255,206,135},
								  {112,25,25} };

	 
	cvtColor(img, imgHSV, COLOR_BGR2HSV);


	for (int i = 0;i < mycolors.size();i++) {
		Scalar lower(mycolors[i][0], mycolors[i][1], mycolors[i][2]);
		Scalar upper(mycolors[i][3], mycolors[i][4], mycolors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		imshow(to_string(i), mask);
	}

	//落在范围内的像素 → 输出 255；不在范围内的像素 → 输出 0，这样就可以输出黑白的二值掩码了
	

}

/////////////////////////////camera///////////////////////////////////////
void main()
{

	VideoCapture cap(0);
	Mat img;
	while (true) {
		cap.read(img);//将摄像头抓取到的下一帧数据保存为img
		findColor(img);


		imshow("Image", img);
		waitKey(1);
	}
}

