#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	Mat src = imread("F:/opencv_tutorial-master/images/test.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat m1 = src.clone(); //克隆

							//数据部分
	Mat m2;
	src.copyTo(m2);			//复制			区别 克隆与复制，克隆与原没有关系

	// 赋值法--取另一个名字
	Mat m3 = src;

	// 创建空白图像
	Mat m4 = Mat::zeros(src.size(), src.type());
	Mat m5 = Mat::zeros(Size(512, 512), CV_8UC3);
	Mat m6 = Mat::ones(Size(512, 512), CV_8UC3);

	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	namedWindow("m4",WINDOW_AUTOSIZE);
	imshow("m4",kernel);
	waitKey(0);
	return 0;
}
