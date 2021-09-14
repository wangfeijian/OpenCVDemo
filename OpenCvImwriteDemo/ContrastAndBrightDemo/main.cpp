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

	namedWindow("��Ч��ͼ���ڡ�", 1);

	createTrackbar("�Աȶȣ�", "��Ч��ͼ���ڡ�", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("���ȣ�", "��Ч��ͼ���ڡ�", &g_nBrightValue, 200, on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (waitKey(10) != 27)
	{

	}
	return 0;
}

void on_ContrastAndBright(int, void*)
{
	namedWindow("��ԭʼͼ���ڡ�", 1);

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

	imshow("��ԭʼͼ���ڡ�", g_srcImage);
	imshow("��Ч��ͼ���ڡ�", g_dstImage);
}
