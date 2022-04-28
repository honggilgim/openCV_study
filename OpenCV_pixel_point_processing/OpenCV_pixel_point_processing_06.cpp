
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int contrastEnh(int input)
{
	double output;
	if (0 <= input && input <= 100) {
		output = input;
	}
	else if (100 < input && input <= 192) {
		output = 0;
	}
	else if (192 < input && input <= 255) {
		output = input;
	}
	return (int)output;
}

int main()
{
	Mat image = imread("d:/lenna.jpg");
	Mat oimage = image.clone();
	Mat dst;

	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			for (int ch = 0; ch < 3; ch++) {
				int output = contrastEnh(image.at<Vec3b>(r, c)[ch]);
				oimage.at<Vec3b>(r, c)[ch] = saturate_cast<uchar>(output);
			}
		}
	}

	//	int threshold_value = 100;
	//	threshold(image, dst, threshold_value, 0, THRESH_BINARY);


	imshow("원영상", image);
	imshow("결과영상", oimage);
	waitKey();
}