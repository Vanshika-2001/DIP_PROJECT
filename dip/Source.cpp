#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void main()
{
	//string path =  "C:/Users/parul/source/repos/dip/dip/Resources/number-plate-vehicle-registration-plates-of-russia-RY5M1B.jpg"  ;                  //Image path
	//string path = "C:/Users/parul/source/repos/dip/dip/Resources/download.jpg";
	//string path= "C:/Users/parul/source/repos/dip/dip/Resources/download.jpg";
	string path = "C:/Users/parul/source/repos/dip/dip/Resources/russian plate.jpg";
	Mat img = imread(path);
	
	

	CascadeClassifier plateCascade;
	plateCascade.load("C:/Users/parul/source/repos/dip/dip/Resources/haarcascade_russian_plate_number.xml");              //XML file path

	if (plateCascade.empty())
	{
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> plates;
	plateCascade.detectMultiScale(img, plates, 1.1, 10);

	for (int i = 0; i < plates.size(); i++)
	{
		Mat imgCrop = img(plates[i]);
		imshow(to_string(i), imgCrop);
		rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
	}
	imshow("Image", img);
	waitKey(0);
}