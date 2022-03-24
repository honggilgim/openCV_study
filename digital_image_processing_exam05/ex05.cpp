// opencv를 이용하여 도형 그리기
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
	//검정색으로 초기화된 800 * 600 영상 생성
	Mat image = Mat(800, 600, CV_8UC3, Scalar(0, 0, 0));

	circle(image, Point(100, 100), 50, Scalar(255, 0, 0), 3);

	imshow("Image", image);
	waitKey(0);
	return(0);
}