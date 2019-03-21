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
	//inputarray ���캯��֧�ֽ�MatתΪinputarray
	// ֱ�Ӷ�ȡͼ������
	//�������
	int height = src.rows;
	int width = src.cols;
	int ch = src.channels();		//��ȡͨ��BGR���ߵ�ͨ������ͨ��
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					Vec3b bgr = src.at<Vec3b>(row, col);  //Vec3b �ǰ���3���ֽڵ����ݽṹ��-CV_8UC3
					bgr[0] = 255 - bgr[0];					//Vec3f��ͼ��CV_32FC��ʱ���õ�
					bgr[1] = 255 - bgr[1];	//ȡ��ͨ��ֵ
					bgr[2] = 255 - bgr[2];
					src.at<Vec3b>(row, col) = bgr;	//���¸�ֵ
				}
				else if (ch == 1) {
					int gray = src.at<uchar>(row, col);
					src.at<uchar>(row, col) = 255 - gray;
				}
			}
		}
	}
	imshow("output", src);

	// ָ���ȡ������
	Mat result = Mat::zeros(src.size(), src.type());  //�հ�ͼ��
	int blue = 0, green = 0, red = 0;
	int gray;
	for (int c = 0; c < ch; c++) {
		for (int row = 0; row < height; row++) {
			uchar* curr_row = src.ptr<uchar>(row);		//��ȡͼ���׵�ַ		
			uchar* result_row = result.ptr<uchar>(row);	//�����ַ
			for (int col = 0; col < width; col++) {
				if (ch == 3) {
					blue = *curr_row++;		//��ַ��1
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
