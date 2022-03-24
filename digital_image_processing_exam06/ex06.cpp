//ex 06. 800 * 600 ũ���� �����츦����� ���콺�� ������ ��ư�������� 100 * 100 ũ���� �簢���� �׸���
// ���� ��ư�� ������ ������ 100�� ���� �׸��� ���α׷��� �ۼ��Ͻÿ�.

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) // ���콺 �̺�Ʈ
{
	if (event == EVENT_LBUTTONDOWN) // ���� ��ư
	{
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 10);
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN) // ������ ��ư
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