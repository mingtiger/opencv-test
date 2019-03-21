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
	//inputarray 构造函数支持将Mat转为inputarray
	// 直接读取图像像素
	//数组遍历
	int height = src.rows;
	int width = src.cols;
	int ch = src.channels();		//获取通道BGR或者单通道，三通道
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					Vec3b bgr = src.at<Vec3b>(row, col);  //Vec3b 是包含3个字节的数据结构体-CV_8UC3
					bgr[0] = 255 - bgr[0];					//Vec3f是图像CV_32FC的时候用的
					bgr[1] = 255 - bgr[1];	//取反通道值
					bgr[2] = 255 - bgr[2];
					src.at<Vec3b>(row, col) = bgr;	//重新赋值
				}
				else if (ch == 1) {
					int gray = src.at<uchar>(row, col);
					src.at<uchar>(row, col) = 255 - gray;
				}
			}
		}
	}
	imshow("output", src);

	// 指针读取，遍历
	Mat result = Mat::zeros(src.size(), src.type());  //空白图像
	int blue = 0, green = 0, red = 0;
	int gray;
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			uchar* curr_row = src.ptr<uchar>(row);		//获取图像首地址		
			uchar* result_row = result.ptr<uchar>(row);	//输出地址
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					blue = *curr_row++;		//地址加1
					green = *curr_row++;
					red = *curr_row++;

					*result_row++ = blue;
					*result_row++ = green;
					*result_row++ = red;
				}
				else if (ch == 1) {
					gray = *curr_row++;
					*result_row++ = gray;
				}
			}
		}
	}
	imshow("result", result);

	waitKey(0);
	return 0;
}
