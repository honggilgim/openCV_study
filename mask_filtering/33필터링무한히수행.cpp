#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/lenna.jpg");
	Mat dst;
	Mat sat;
	blur(src, dst, Size(3, 3));

	for (int i = 0; i < 100000; i++)
	{
		blur(dst, sat, Size(3, 3));
		dst = sat;
		cout << i << "\n";
	}

	imshow("100000", dst);

	waitKey(0);
	return 0;
}