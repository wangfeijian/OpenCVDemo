#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	Mat image = imread("D:\\Study\\opencv\\OpenCVDemo\\OpenCvImwriteDemo\\ImWriteDemo\\Í¸Ã÷AlphaÖµÍ¼.png");
	Mat logo = imread("D:\\Study\\opencv\\OpenCVDemo\\OpenCvImwriteDemo\\ImWriteDemo\\windows_logo.jpg");

	namedWindow("source");
	namedWindow("logo");

	imshow("source", image);
	imshow("logo", logo);

	Mat imageRoi;
	imageRoi = image(Rect(300, 300, logo.cols, logo.rows));

	addWeighted(imageRoi, 0.5, logo, 0.5, 0., imageRoi);

	namedWindow("add");
	imshow("add", image);
	waitKey(0);
}
