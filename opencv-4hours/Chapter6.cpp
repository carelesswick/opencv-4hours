#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////颜色检测////////////////////////////////////
int main ()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);




	imshow("Image",img);
	imshow("Image_hsv", imgHSV);


	waitKey(0);
	return 0;
}



