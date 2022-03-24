// opencv�� �̿��Ͽ� ���� �׸���
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
	//���������� �ʱ�ȭ�� 800 * 600 ���� ����
	Mat image = Mat(800, 600, CV_8UC3, Scalar(0, 0, 0));

	circle(image, Point(100, 100), 50, Scalar(255, 0, 0), 3);

	imshow("Image", image);
	waitKey(0);
	return(0);
}