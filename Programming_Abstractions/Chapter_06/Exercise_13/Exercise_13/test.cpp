#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const int HALF_INCH_TICK = 32;
const int HEIGHT = 240;
const int WIDTH = 320;

void my_line(Mat img, Point start, Point end);
void draw_ticks(Mat img, Point start, Point end, int n_steps, int tick_size);

int main(void) {
	Mat img(HEIGHT, WIDTH, CV_8UC3, Scalar(0, 0, 0));

	my_line(img, Point(WIDTH / 4, HEIGHT / 2), Point(3 * WIDTH / 4, HEIGHT / 2));
	draw_ticks(img, Point(WIDTH / 4, HEIGHT / 2), Point(3 * WIDTH / 4, HEIGHT / 2), 4, HALF_INCH_TICK);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	resizeWindow("image", WIDTH, HEIGHT);

	waitKey(0);
	return 0;
}

void my_line(Mat img, Point start, Point end) {
	line(img, start, end, Scalar(255, 255, 255), 1, 8, 0);
}

void draw_ticks(Mat img, Point start, Point end, int n_steps, int tick_size) {
	if (n_steps > 0) {
		Point middle = (start + end) / 2;
		Point top_middle = middle;
		top_middle.y -= tick_size;
		draw_ticks(img, start, middle, n_steps - 1, tick_size / 2);
		draw_ticks(img, middle, end, n_steps - 1, tick_size / 2);
		my_line(img, middle, top_middle);
	}
}
