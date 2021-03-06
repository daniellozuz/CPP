#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const int HEIGHT = 480;
const int WIDTH = 640;
const double INITIAL_LENGTH = 80.0;
const double DEG_TO_RAD = 3.141592 / 180.0;

void my_line(Mat img, Point start, Point end);
void draw_tree(Mat img, Point start, double angle, double length);
double rad(double angle);

int main(void) {
	Mat img(HEIGHT, WIDTH, CV_8UC3, Scalar(0, 0, 0));

	draw_tree(img, Point(WIDTH / 2, 0.9 * HEIGHT), -90.0, INITIAL_LENGTH);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	resizeWindow("image", WIDTH, HEIGHT);

	waitKey(0);
	return 0;
}

void my_line(Mat img, Point start, Point end) {
	line(img, start, end, Scalar(255, 255, 255), 1, 8, 0);
}

void draw_tree(Mat img, Point start, double angle, double length) {
	Point end = Point(start.x + length * cos(rad(angle)), start.y + length * sin(rad(angle)));
	my_line(img, start, end);
	if (3 * length / INITIAL_LENGTH > double(rand()) / RAND_MAX) {
		draw_tree(img, end, angle + 20.0, 0.8 * length);
		draw_tree(img, end, angle - 20.0, 0.8 * length);
	}
}

double rad(double angle) {
	return angle * DEG_TO_RAD;
}
