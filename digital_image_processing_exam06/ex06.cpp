//ex 06. 800 * 600 크기의 윈도우를만들고 마우스의 오른쪽 버튼을누르면 100 * 100 크기의 사각형을 그리고
// 왼쪽 버튼을 누르면 반지름 100인 원을 그리는 프로그램을 작성하시오.

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) // 마우스 이벤트
{
	if (event == EVENT_LBUTTONDOWN) // 왼쪽 버튼
	{
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 10);
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN) // 오른쪽 버튼
	{
		Mat& img = *(Mat*)(param);
		rectangle(img, Point(x, y), Point(x + 100, y + 100), Scalar(0, 255, 0), 5);
		imshow("src", img);
	}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {}
	else {}
}

int main() {
	Mat image = Mat(800, 600, CV_8UC3, Scalar(0, 0, 0));
	imshow("Image", image);

	setMouseCallback("Image", onMouse, &image);
	waitKey(0);
	return(0);
}