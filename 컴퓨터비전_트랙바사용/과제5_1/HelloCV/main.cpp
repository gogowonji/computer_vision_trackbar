#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

void on_level_change(int pos, void* userdata);
void on_level_change2(int pos2, void* userdata2);

int main()
{
	

	Mat img1, img2;
	img1 = imread("lenna.bmp", IMREAD_REDUCED_COLOR_2); //컬러
	img2 = imread("lenna.bmp", IMREAD_REDUCED_GRAYSCALE_2); //흑백

	if (img1.empty() || img2.empty())
	{
		cerr << "image load failed!" << endl;
		return -1;
	}

	//문제1

	namedWindow("img1");

	int value = 0;
	createTrackbar("color", "img1", &value, 5, on_level_change, (void*)&img1);

	imshow("img1", img1);
	
	setTrackbarPos("color", "img1", 1);
	setTrackbarPos("color", "img1", 0); //초기화면을 보되, 트랙바 콜백함수를 호출해주기 위해서
	
	

	//문제2

	namedWindow("img2");

	int value2 = 0;
	createTrackbar("Intensity", "img2", &value2, 64, on_level_change2, (void*)&img2);
	
	imshow("img2", img2);
	setTrackbarPos("Intensity", "img2", 1);
	setTrackbarPos("Intensity", "img2", 0); //초기화면을 보되, 트랙바 콜백함수를 호출해주기 위해서
	





	waitKey();

	destroyAllWindows();

	return 0;
}


void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata;
	Mat mask(256, 256, CV_8UC1, Scalar(128)); //네모하나만들고
	circle(mask, Point(128, 128), 100, Scalar(0), -1); //원 뚫기
	
	const String text = "Lenna";
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 1.0;
	Point textPoint(100, 128);
	

	if (pos == 0) {
		img.setTo(Scalar(255, 0, 0),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(255, 0, 0), 1);

	}
	else if (pos == 1) {
		img.setTo(Scalar(0, 255, 0),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(0, 255, 0), 1);

	}
	else if (pos == 2) {
		img.setTo(Scalar(0, 0, 255),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(0, 0, 255), 1);

	}
	else if (pos == 3) {
		img.setTo(Scalar(255, 255, 0),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(255, 255, 0), 1);

	}
	else if (pos == 4) {
		img.setTo(Scalar(0, 255, 255),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(0, 255, 255), 1);

	}
	else {
		img.setTo(Scalar(255, 0, 255),mask);
		putText(img, text, textPoint, fontFace, fontScale, Scalar(255, 0, 255), 1);

	}

	imshow("img1", img);
}


void on_level_change2(int pos2, void* userdata2) {
	Mat img2 = *(Mat*)userdata2;
	Mat img = img2.clone();

	Mat mask(256, 256, CV_8UC1, Scalar(128)); //네모하나만들고
	circle(mask, Point(128, 128), 100, Scalar(0), -1); //원 뚫기
	
	String text = " ";
	int textTemp = 96 + pos2;

	text = to_string(textTemp);
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 1.0;
	Point textPoint(100, 128);
	
	
	putText(img, text, textPoint, fontFace, fontScale, Scalar(255, 255, 255), 1);

	img.setTo(96+pos2, mask);
	
	imshow("img2", img);

}