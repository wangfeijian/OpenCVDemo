#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void on_ContrastAndBright(int, void *);

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImage, g_dstImage;

int main(int argc, char* argv[])
{
	g_srcImage = imread("D:\\Desktop Image\\1.jpg");

	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	g_nContrastValue = 80;
	g_nBrightValue = 80;

	namedWindow("【效果图窗口】", 1);

	createTrackbar("对比度：", "【效果图窗口】", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("亮度：", "【效果图窗口】", &g_nBrightValue, 200, on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (waitKey(10) != 27)
	{

	}
	return 0;
}

void on_ContrastAndBright(int, void*)
{
	namedWindow("【原始图窗口】", 1);

	for (int i = 0;i<g_srcImage.rows;i++)
	{
		for (int j = 0;j<g_srcImage.cols;j++)
		{
			for (int k = 0;k<3;k++)
			{
				g_dstImage.at<Vec3b>(i, j)[k] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(i, j)[k]) + g_nBrightValue);
			}
		}
	}

	imshow("【原始图窗口】", g_srcImage);
	imshow("【效果图窗口】", g_dstImage);
}
