#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////Basic Funcitons////////////////////////////////////
void main ()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3,3), 5, 0);//高斯模糊
	Canny(imgBlur, imgCanny, 5, 75);//Canny边缘检测

	//该函数会构建并返回一个结构元素，该元素可进一步传递给 #erode、#dilate 或 #morphologyEx 函数
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//矩形元素
	dilate(imgCanny, imgDia, kernel);//图像膨胀函数（一般需要上面的函数来创建核的大小）

	erode(imgDia, imgErode, kernel);//腐蚀函数


	imshow("Image",img);
	imshow("Image-Gray", imgGray);
	imshow("Image-Blur",imgBlur);
	imshow("Image-Canny", imgCanny);
	imshow("Image-Dia", imgDia);
	imshow("Image-erode", imgErode);

	waitKey(0);
}




