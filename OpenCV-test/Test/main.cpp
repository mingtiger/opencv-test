#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>




using namespace cv;

int main(int agrc, char** agrv) {

	Mat dst;
	Mat src = imread("C:\\Users\\lenovo\\Desktop\\opencvnote\\1.png");
	CV_Assert(src.depth() == CV_8U);
	namedWindow("mask_demo", WINDOW_AUTOSIZE);
	imshow("mask_demo", src);

	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	/*//clone current image
	Mat resultimage;
	src.copyTo(resultimage);
	int nchannels = src.channels();
	int height = src.rows;
	int cols = src.cols;
	int width = src.cols * nchannels;
	for (int row = 1; row < height - 1; row++)
	{
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row);
		uchar* output = resultimage.ptr<uchar>(row);

		for (int col = nchannels; col < nchannels*(src.cols - 1); col++)
		{
			*output = saturate_cast<uchar>(5 * current[col] - previous[col] - next[col] - current[col - nchannels] - current[col + nchannels]);
			output++;
		}

	}*/
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);
	double timeconsume = (getTickCount() - t) / getTickFrequency();

	namedWindow("OPENCV", WINDOW_AUTOSIZE);
	imshow("OPENCV", dst);
	waitKey(0);
	return 0;
}