//
//  canny.h
//  Multimedia_FinalProject
//
//  Created by DYS on 6/13/22.
//
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int myCannyFunction(string filename) {
   Mat img = imread(filename, 0);   //이미지를 grayscale로 불러옴

   //Mat img_threshold;

   Mat img_edge;

   Canny(img, img_edge, 50, 200);
   imshow("original", img);
   imshow("img_edge", img_edge);
   //imshow("erode2", img_erode2);

   return 0;
}
