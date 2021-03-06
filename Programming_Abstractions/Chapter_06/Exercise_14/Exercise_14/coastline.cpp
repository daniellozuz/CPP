#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const int HEIGHT = 480;
const int WIDTH = 640;
const double DEG_TO_RAD = 3.141592 / 180.0;

void my_line(Mat img, Point start, Point end);
void draw_coastline(Mat img, Point start, Point end, int order);
double rad(int angle);

int main(void) {
	Mat img(HEIGHT, WIDTH, CV_8UC3, Scalar(0, 0, 0));

	draw_coastline(img, Point(WIDTH / 4, HEIGHT / 2), Point(3 * WIDTH / 4, HEIGHT / 2), 4);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	resizeWindow("image", WIDTH, HEIGHT);

	waitKey(0);
	return 0;
}

void my_line(Mat img, Point start, Point end) {
	line(img, start, end, Scalar(255, 255, 255), 1, 8, 0);
}

void draw_coastline(Mat img, Point start, Point end, int order) {
	if (order == 0)
		my_line(img, start, end);
	else {
		int angle = 60;
		if (rand() % 2)
			angle = -60;
		Point p1 = start + (end - start) / 3;
		Point p3 = start + 2 * (end - start) / 3;
		Point v = p1 - start;
		Point p2 = Point(p1.x + v.x*cos(rad(angle)) - v.y*sin(rad(angle)), p1.y + v.x*sin(rad(angle)) + v.y*cos(rad(angle)));
		draw_coastline(img, start, p1, order - 1);
		draw_coastline(img, p1, p2, order - 1);
		draw_coastline(img, p2, p3, order - 1);
		draw_coastline(img, p3, end, order - 1);
	}
}

double rad(int angle) {
	return double(angle) * DEG_TO_RAD;
}
