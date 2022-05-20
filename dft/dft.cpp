#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void disDFT(Mat& src)
{
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };
	split(src, image_array); // DFT 결과 영상을 2개의 영상으로 분리

	Mat mag_image;
	// 퓨리에 변환의 절대값 계산
	magnitude(image_array[0], image_array[1], mag_image);

	// 퓨리에 변환 계수들은 상당히 크기 때문에 로그 스케일로 변환 및 0이 나오지 않도록 1을 더해줌
	mag_image += Scalar::all(1);
	log(mag_image, mag_image);
	// 0에서 255로 범위를 정규화
	normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);

	imshow("DFT", mag_image);

	waitKey(0);
}

void shuffleDFT(Mat& src)
{
	int cx = src.cols / 2;
	int cy = src.rows / 2;

	Mat q1(src, Rect(0, 0, cx, cy));
	Mat q2(src, Rect(cx, 0, cx, cy));
	Mat q3(src, Rect(0, cy, cx, cy));
	Mat q4(src, Rect(cx, cy, cx, cy));

	Mat tmp;
	q1.copyTo(tmp);
	q4.copyTo(q1);
	tmp.copyTo(q4);
	q2.copyTo(tmp);
	q3.copyTo(q2);
	tmp.copyTo(q3);
}
int main()
{
	Mat src = imread("D:/lenna.jpg");
	Mat dst;
	Mat sat;
	Mat dst_float;
	Mat dft_image;
	blur(src, dst, Size(3, 3)); // 3*3 사이즈 필터링

	dst.convertTo(dst_float, CV_32FC1, 1.0 / 255.0); // 그레이 스케일 영상을 알 수 있게 실수로 변환

	dft(dst_float, dft_image, DFT_COMPLEX_OUTPUT); // DFT 수행

	//imshow("3*3 후 dft", dft_image); -> 결과는 복소수이므로, 출력할수가 없음. DFT를 출력해주는 코드를 따로 짜야 함.

	shuffleDFT(dft_image);
	disDFT(dft_image);
	waitKey(0);
	return 1;
}