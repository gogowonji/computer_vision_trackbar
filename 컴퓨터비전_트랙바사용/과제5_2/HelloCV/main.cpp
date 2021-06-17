#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


void drawText2();

int main()
{
	
	drawText2();
	return 0;
}

void drawText2() {
	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

	const String text = "Hello opencv";
	int fontFace = FONT_HERSHEY_TRIPLEX;
	double fontScale = 2.0;
	int thickness = 1;
	int baseline;

	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
	Size sizeImg = img.size();
	Size size = getTextSize(text, fontFace, fontScale, thickness, &baseline);
	
	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
	Point org2((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2 +baseline);
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	
	line(img, org, org + Point(sizeText.width, 0), Scalar(0, 0, 255),1);
	
	rectangle(img, org2, org2 + Point(sizeText.width, -(sizeText.height+baseline)), Scalar(0, 255, 0), 1);
	
	imshow("img", img);
	cout <<"baseline: "<< baseline << endl;
	waitKey();

	destroyAllWindows();
}
