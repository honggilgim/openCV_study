#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/lenna.jpg");
	Mat dst;

	blur(src, dst, Size(5, 5));
	imshow("source", src);
	imshow("result", dst);

	waitKey(0);
	return 0;
}

// 평균값 필터링 연산 수행