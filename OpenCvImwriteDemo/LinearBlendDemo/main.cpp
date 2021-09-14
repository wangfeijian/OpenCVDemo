#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void LinearBlend(Mat input1, Mat input2);

int main(int argc, char* argv[])
{
	std::vector<Mat> channels;
	Mat image1 = imread("D:\\Desktop Image\\1.jpg");
	Mat image2 = imread("D:\\Desktop Image\\2.jpg");
	Mat dstImage;

	LinearBlend(image1, image2);

	split(image1, channels);
	imshow("blue", channels.at(0));
	imshow("green", channels.at(1));
	imshow("red", channels.at(2));

	std::vector<Mat> dou;
	dou.push_back(channels.at(0));
	dou.push_back(channels.at(1));
	dou.push_back(channels.at(0));

	merge(dou, dstImage);
	imshow("merge", dstImage);
	waitKey(0);
}

void LinearBlend(Mat input1, Mat input2)
{
	Mat output;
	double alphaValue = 0.5, betaValue = 0.5, gamaValue = 0.8;
	addWeighted(input1, alphaValue, input2, betaValue, gamaValue, output);
	imshow("½á¹û", output);
}

