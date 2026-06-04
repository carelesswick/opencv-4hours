#include <opencv2/imgcodecs.hpp>// 图像读取与写入
#include <opencv2/highgui.hpp>// 显示图像、滑动条等GUI
#include <opencv2/imgproc.hpp>// 图像处理（画矩形、缩放等）
#include <opencv2/objdetect.hpp>//目标检测相关，比如人脸级联分类器
#include <iostream>


using namespace std;
using namespace cv;

////////////////////////////image////////////////////////////////////
void main ()
{
	string path = "Resources/test.png";
	Mat img = imread(path);

	//加载级联分类器
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) { cout << "XML ia not loaded" << endl; }

	vector<Rect> faces;//一个动态数组，每个元素代表一张检测到的人脸矩形。

	//执行检测
	faceCascade.detectMultiScale(img, faces, 1.1, 10);
	//画矩形框，rectangle() 在 img 上绘制矩形
	for (int i = 0;i < faces.size();i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 255, 255), 3);
	}

	imshow("Image",img);
	waitKey(0);
}