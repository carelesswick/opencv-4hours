#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////Resize Crop////////////////////////////////////
void main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;
	cout << img.size() << endl;
	//调整大小
	//resize(img, imgResize, Size(640, 640));
	resize(img, imgResize, Size(), 1.2, 1.2);
	cout << imgResize.size() << endl;

	//这里表示以图像左上角为原点，左上角坐标为 (x=100, y=100)，宽 300，高 250。
	Rect roi(100,100,300,250);
	imgCrop = img(roi);




	imshow("Image", img);
	imshow("ImageResize", imgResize);
	imshow("ImageCrop", imgCrop);

	waitKey(0);
}




