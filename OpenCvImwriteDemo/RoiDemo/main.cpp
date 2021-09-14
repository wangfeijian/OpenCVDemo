#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <imgproc.hpp>

using namespace cv;

bool ROI_AddImage(Mat srcImage, Mat logoImage);

int main(int argc, char* argv[])
{
	Mat image = imread("D:\\Study\\opencv\\OpenCVDemo\\OpenCvImwriteDemo\\ImWriteDemo\\透明Alpha值图.png");
	Mat logo = imread("D:\\Study\\opencv\\OpenCVDemo\\OpenCvImwriteDemo\\ImWriteDemo\\windows_logo.jpg");

	ROI_AddImage(image, logo);
	waitKey(0);
}

bool ROI_AddImage(Mat srcImage, Mat logoImage)
{
	Mat mask;
	cvtColor(logoImage, mask, COLOR_BGR2GRAY);

	Mat imageRoi = srcImage(Rect(100, 100, logoImage.cols, logoImage.rows));
	logoImage.copyTo(imageRoi, mask);
	imshow("结果", srcImage);
	return true;
}
