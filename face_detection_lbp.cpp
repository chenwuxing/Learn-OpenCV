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

// global variables
String window_name = "Capture-face detection";


void detect_face(Mat frame,String classifier_name)
{
	Mat frame_gray;
	vector<Rect> faces;
	CascadeClassifier face_classifier;
	if (!face_classifier.load(classifier_name))
	{
		cout << "error load classifier" << endl;
	}
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_classifier.detectMultiScale(frame_gray, faces, 1.1, 1, 0, Size(20, 20), Size(100, 100));

	for (size_t i = 0; i < faces.size(); i++)
	{
		rectangle(frame, faces[i], Scalar(0, 0, 255), 2, 8, 0);

	}
	namedWindow(window_name);
	imshow(window_name, frame);

}

Mat load_img(String pic_name)
{
	Mat frame;
	frame = imread(pic_name);
	return frame;
}

int main()
{
	String picture_path = "e:\\test.jpg";
	String classifier_path = "E:\\DiyProgram\\opencv\\sources\\data\\lbpcascades\\lbpcascade_frontalface.xml";	// classifier path
	//String classifier_path = "E:\\DiyProgram\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml";
	detect_face(load_img(picture_path), classifier_path);
	if (waitKey(0) == 'q')
		return 0;

	return 0;



	
}