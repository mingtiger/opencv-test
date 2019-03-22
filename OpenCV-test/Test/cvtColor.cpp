#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
/*
	cvtColor and inRange
*/
int main(int argc, const char *argv[])
{
	Mat src = imread("F:/opencv_tutorial-master/images/hist_02.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// RGB to HSV
	Mat hsv;
	cvtColor(src, hsv, COLOR_BGR2HSV);
	imshow("hsv", hsv);

	// RGB to YUV
	Mat yuv;
	cvtColor(src, yuv, COLOR_BGR2YUV);
	imshow("yuv", yuv);

	// RGB to YUV
	Mat ycrcb;
	cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
	imshow("ycrcb", ycrcb);

	Mat src2 = imread("F:/opencv_tutorial-master/images/hist_02.jpg");
	imshow("src2", src2);
	cvtColor(src2, hsv, COLOR_BGR2HSV);
	Mat mask;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);//指定色彩范围区域
	bitwise_not(src2,src2,mask);
	imshow("mask", mask);


	waitKey(0);
	return 0;
}