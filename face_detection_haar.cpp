#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<opencv2/objdetect.hpp>
#include<opencv2/video.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//global variables
String face_cascade_path = "E:\\DiyProgram\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml";
CascadeClassifier face_cascade;
String window_name = "Capture-face detection";

void detect_display(Mat frame)
{
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	
	// detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, CV_HAAR_DO_ROUGH_SEARCH, Size(30, 30), Size(100, 100));

	for (size_t i = 0; i < faces.size(); i++)
	{
		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);

	}
	namedWindow(window_name, 2);
	imshow(window_name, frame);
}

int main()
{
	String picture_name = "e:\\test.jpg";
	Mat frame = imread(picture_name);
	if (!face_cascade.load(face_cascade_path))
	{
		cout << "error loading face cascade classifier" << endl;
		
	}
	detect_display(frame);
	int c = waitKey(0);
	if ((char)c == 27)
	{
		return 0;
	}
	return 0;
}

