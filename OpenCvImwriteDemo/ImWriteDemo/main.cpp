#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void createAlphaMat(Mat &mat)
{
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			auto &rgba = mat.at<Vec4b>(i, j);
			rgba[0] = rand()%UCHAR_MAX;
			rgba[1] = rand()%UCHAR_MAX;
			rgba[2] = rand()%UCHAR_MAX;
			rgba[3] = 1;
		}
	}
}

int main()
{
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try
	{
		imwrite("透明Alpha值图.png", mat, compression_params);
		imshow("生成PNG图", mat);
		fprintf(stdout, "PNG图片文件的瞢a数据保存完毕\n可以在工程目录下查看由imwrite函数生成的图片\n");
		waitKey(0);
	}
	catch (runtime_error & ex)
	{
		fprintf(stderr, "图像转换成PNG格式发生错误：%s\n", ex.what());
		return 1;
	}

	return 0;
}