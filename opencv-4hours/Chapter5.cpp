#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;

/////////////////////////透视变换：模拟 3D 空间中，物体投影到 2D 平面的人眼视觉效果////////////////////////////////////

float w = 250, h = 350;
Mat matrix, imgWrap;
void main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f,},{w,0.0f},{0.0f,h},{w,h} };


	//透视变换
	//getPerspectiveTransform(src, dst) 正是根据 4 个源点和 4 个目标点解线性方程组，计算出这个 3×3 单应矩阵（Mat），返回给你。
	matrix = getPerspectiveTransform(src,dst);
	warpPerspective(img, imgWrap, matrix, Point(w, h));


	//判断点是否正确
	for (int i = 0;i < 4;i++) {

		circle(img, src[i], 10, Scalar(33, 65, 99), FILLED);
	}


	imshow("Image", img);
	imshow("ImageWrap", imgWrap);
	waitKey(0);
}
