#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char *argv[])
{
	Mat src = imread("F:/opencv_tutorial-master/images/hist_02.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	vector<Mat> mv;
	Mat dst1, dst2, dst3;
	// 蓝色通道为零
	split(src, mv);
	mv[0] = Scalar(0);		//B
	mv[1] = Scalar(0);		//G
	merge(mv, dst1);
	imshow("output1", dst1);

	// 绿色通道为零			//G
	split(src, mv);			//R
	mv[1] = Scalar(0);
	mv[2] = Scalar(0);
	merge(mv, dst2);
	imshow("output2", dst2);

	// 红色通道为零
	split(src, mv);				
	mv[2] = Scalar(0);			//R
	mv[0] = Scalar(0);			//B
	merge(mv, dst3);
	imshow("output3", dst3);

	waitKey(0);
	return 0;
}