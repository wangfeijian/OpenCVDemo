#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "?????򴰿ڡ?"

void on_MouseHandle(int event, int x, int y, int flags, void * param);
void DrawRectangle(Mat & img, Rect box);
void ShowHelpText();

Rect g_rectangle;
bool g_bDrawingBox = false;
RNG g_rng(12345);

int main(int argc, char* argv[])
{
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);

	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);

	namedWindow(WINDOW_NAME);
	imshow(WINDOW_NAME, srcImage);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, static_cast<void *>(&srcImage));

	while (waitKey(10) != 27)
	{
		srcImage.copyTo(tempImage);
		if (g_bDrawingBox)
		{
			DrawRectangle(tempImage, g_rectangle);
			imshow(WINDOW_NAME, tempImage);
		}
	}

	waitKey(0);
	return 0;
}


void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat & image = *static_cast<Mat*>(param);
	switch (event)
	{
		case EVENT_MOUSEMOVE:
		{
			if (g_bDrawingBox)
			{
				g_rectangle.width = x - g_rectangle.x;
				g_rectangle.height = y - g_rectangle.y;
			}
		}
		break;
		case EVENT_LBUTTONDOWN:
		{
			g_bDrawingBox = true;
			g_rectangle = Rect(x, y, 0, 0);
		}
		break;
		case EVENT_LBUTTONUP:
		{
			g_bDrawingBox = false;
			if (g_rectangle.width < 0)
			{
				g_rectangle.x += g_rectangle.width;
				g_rectangle.width *= -1;
			}
			if (g_rectangle.height < 0)
			{
				g_rectangle.y += g_rectangle.height;
				g_rectangle.height *= -1;
			}
			DrawRectangle(image, g_rectangle);
		}
		break;
	}
}


void DrawRectangle(Mat& img, Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}
