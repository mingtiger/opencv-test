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

	Mat m1 = src.clone(); //��¡

							//���ݲ���
	Mat m2;
	src.copyTo(m2);			//����			���� ��¡�븴�ƣ���¡��ԭû�й�ϵ

	// ��ֵ��--ȡ��һ������
	Mat m3 = src;

	// �����հ�ͼ��
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
