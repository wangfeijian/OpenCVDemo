#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv.hpp>

using namespace cv;
using namespace std;

void colorReduce(Mat & inputImage, Mat & outputImage, int div);

int main(int argc, char* argv[])
{
	Mat srcImage = imread("D:\\Desktop Image\\1.jpg");
	imshow("原始图像", srcImage);

	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

	auto time0 = static_cast<double>(getTickCount());

	colorReduce(srcImage, dstImage, 2);

	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "此方法运行时间为:" << time0 << "秒" << endl;

	imshow("效果图", dstImage);
	waitKey(0);
}

//使用指针操作
/*
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	cvtColor(inputImage, outputImage, COLOR_BGR2GRAY);
	//outputImage = inputImage.clone();
	int rows = outputImage.rows;
	int cols = outputImage.cols*outputImage.channels();

	for (int i = 0; i < rows; i++)
	{
		const auto data = outputImage.ptr<uchar>(i);
		for (int j = 0; j < cols; j++)
		{
			if (data[j]>30)
			{
				data[j] = 255;
			}
			else
			{
				data[j] = 0;
			}
		}
	}
}
*/

//使用迭代器操作
/*
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	auto it = outputImage.begin<Vec3b>();
	auto itEnd = outputImage.end<Vec3b>();

	for (; it != itEnd; ++it)
	{
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
}
*/

//动态地址操作
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rows = outputImage.rows;
	int cols = outputImage.cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2;
		}
	}
}
