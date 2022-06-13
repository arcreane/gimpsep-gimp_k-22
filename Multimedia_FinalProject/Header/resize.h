//
//  resize.h
//  Multimedia_FinalProject
//
//  Created by DYS on 6/13/22.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

Mat myResize(Mat src,float width,float height){
    Mat dst;

    resize(src, dst, Size(width, height), INTER_LINEAR);

    return dst;
}

int myResizeFunction(String filename){
    Mat dst;

    Mat src = imread(filename, IMREAD_UNCHANGED);

    if(!src.data) {
        cout << "There is no image. The program will end" << endl;
        return 0;
    }

    int width,height;
    cout << "*Enter width and height you want to resize*" << "\n";
    cin >> width >> height;

    imshow("Before Resizing", src);
    cout << ">>Before Resizing: " << src.rows << " " << src.cols << endl;

    dst = myResize(src, width, height);
    imshow("After Resizing", dst);
    cout << ">>After Resizing: " << dst.rows << " " << dst.cols << endl;

    return 0;
}
