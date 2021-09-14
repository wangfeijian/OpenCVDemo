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
			auto &rgba = mat.at<Vec3b>(i, j);
			rgba[0] = 0;
			rgba[1] = 0;
			rgba[2] = UCHAR_MAX;
		}
	}
}

int main()
{
	Mat mat(480, 640, CV_8UC3);
	createAlphaMat(mat);
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try
	{
		imwrite("͸��Alphaֵͼ.png", mat, compression_params);
		imshow("����PNGͼ", mat);
		fprintf(stdout, "PNGͼƬ�ļ���ޫa���ݱ������\n�����ڹ���Ŀ¼�²鿴��imwrite�������ɵ�ͼƬ\n");
		waitKey(0);
	}
	catch (runtime_error & ex)
	{
		fprintf(stderr, "ͼ��ת����PNG��ʽ��������%s\n", ex.what());
		return 1;
	}

	return 0;
}