#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////Draw Shapes and Text////////////////////////////////////
void main()
{
	
	//Blank Image
	Mat img(512, 512,CV_8UC3,Scalar(255,255,255));//自定义图像

	//画圆(半径为155)
	circle(img, Point(256, 256), 155, Scalar(0, 88, 88),FILLED);

	//画矩形框
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255),FILLED);

	//画一条线
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	//放置文本
	putText(img, "Carelesswick", Point(137, 262), FONT_HERSHEY_DUPLEX, 1.2,Scalar(0, 69, 139),2);


	imshow("Image", img);
	waitKey(0);
}




