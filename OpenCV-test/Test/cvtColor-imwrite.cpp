#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int artc, char** argv) {
	// Mat src = imread("D:/vcprojects/images/test.png");
	Mat src = imread("F:/opencv_tutorial-master/images/hist_01.jpg");

	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	namedWindow("gray", WINDOW_AUTOSIZE);
	imshow("gray",gray);
	imwrite("F:/test-data/gray.png",gray);
	waitKey(0);
	return 0;
}



