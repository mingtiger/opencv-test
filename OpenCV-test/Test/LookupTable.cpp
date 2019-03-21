#include <opencv2/opencv.hpp>
#include <iostream>
/*
	类似与替换像素值
	单调增函数
	单调减函数
*/
using namespace cv;
using namespace std;
void customColorMap(Mat &image);
int main(int argc, const char *argv[])
{
	Mat src = imread("F:/opencv_tutorial-master/images/canjian.jpg");
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	Mat gray, dst;
	// 使用LUT
	//applyColorMap(src, dst, COLORMAP_SUMMER);
	applyColorMap(src, dst, 9);
	/*
		COLORMAP-SUMMER=6
		--<0~12>
	
	
	*/
	// 显示结果
	imshow("colorMap", dst);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);
	customColorMap(gray);

	waitKey(0);
	return 0;
}

void customColorMap(Mat &image) {				//Mat &image  &引用（取别名）int a=10;int &b=a;b与a
	int lut[256];										//同一个人，两个名字
	for (int i = 0; i < 256; i++) {
		if (i < 127)
			lut[i] = 0;
		else
			lut[i] = 255;
	}

	int h = image.rows;
	int w = image.cols;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int pv = image.at<uchar>(row, col);
			image.at<uchar>(row, col) = lut[pv];
		}
	}
	imshow("lut demo", image);
}

