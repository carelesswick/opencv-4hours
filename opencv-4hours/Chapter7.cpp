#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgput,Mat imgdraw) {
	/*contours = {	{点1, 点2, 点3, ...},   // 第1个轮廓
					{点1, 点2, 点3, ...},   // 第2个轮廓   }*/
	//这是findContours函数规定的变量类型
	vector<vector<Point>> contours;//二维动态数组用来存储轮廓。
	vector<Vec4i> hierarchy;//轮廓间的层级关系，包含四个整数（四个整数：同级后一个轮廓、同级前一个轮廓、第一个子轮廓、父轮廓的索引）
	
	double area,peri;
	//从二值图像中提取轮廓。注意findContours的第一个传入参数必须是二值图像
	findContours(imgput,contours, hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	//RETR_EXTERNAL：只检索最外层轮廓，忽略内部嵌套的轮廓（例如一个圆环只取外圆）
	//CHAIN_APPROX_SIMPLE：压缩轮廓点，只保留拐点。比如一条直线只用两个端点表示，大大减少点数。

	//conPoly用来存储每个轮廓经过 多边形近似 后的顶点
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objname;

	//通过计算每个轮廓的面积来过滤噪点（设置面积的阈值）
	for (int i = 0;i < contours.size();i++) {
		area = contourArea(contours[i], false);
		cout << area << endl;
		if (area > 300) {
			//计算轮廓周长（曲线长度）。若 true，则认为轮廓是闭合的（首尾连接）
			peri = arcLength(contours[i], true);
			//approxPolyDP(输入轮廓, 输出近似多边形, 精度参数, 是否闭合)
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			//drawContours(目标图像, 轮廓集合, 轮廓索引, 颜色, 线宽)
			drawContours(imgdraw, conPoly, i, Scalar(255, 0, 255), 2);
			
			cout << conPoly[i].size() << endl;
			//
			boundRect[i] = boundingRect(conPoly[i]);
			//rectangle(目标图像, 左上角, 右下角, 颜色, 线宽)
			rectangle(imgdraw, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			int objCor = (int)conPoly[i].size();
			switch (objCor) {
				case 3:
					objname = "triangle";
					break;
				case 4:
					objname = "rectangle";
					break;
				default:
					objname = "circle";
					break;

			}
			putText(imgdraw, objname, {boundRect[i].x,boundRect[i].y - 5}, FONT_HERSHEY_SCRIPT_SIMPLEX, 0.3, Scalar(0, 69, 255), 2);
		}
	}
}
/////////////////////////image////////////////////////////////////
void main ()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;
	///////////////////////预处理/////////////////////////////////////////////
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);//高斯模糊
	Canny(imgBlur, imgCanny, 5, 75);//Canny边缘检测
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//矩形元素
	dilate(imgCanny, imgDia, kernel);//图像膨胀函数（一般需要上面的函数来创建核的大小）
	

	getContours(imgDia,img);



	imshow("Image", img);
	//imshow("Image-Gray", imgGray);
	//imshow("Image-Blur", imgBlur);
	//imshow("Image-Canny", imgCanny);
	//imshow("Image-Dia", imgDia);
	
	waitKey(0);
}



