//
//  lightenDarken.h
//  Multimedia_FinalProject
//
//  Created by DYS on 6/13/22.
//

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"


using namespace cv;
using namespace std;

int myLightDarkFunction(string filename) {

   int brightness,darkness;
   cout << "* Please enter a brishtness and darkness level [Under195] *" << endl;
   cout << " (The larger the number, the brighter/darker it becomes)" << endl << endl;
   cout << "Brightness: ";
   cin >> brightness;
   cout << "Darkness: ";
   cin >> darkness;


   Mat img_1 = imread(filename, 0);   //이미지를 grayscale로 불러옴

   Mat img_2 = img_1 + brightness;
   Mat img_3 = img_1 - darkness;

   imshow("original", img_1);
   imshow("img_Brighter", img_2);
   imshow("img_Darker", img_3);

   return 0;
}
