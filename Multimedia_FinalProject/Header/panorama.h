//
//  panorama.h
//  Multimedia_FinalProject
//
//  Created by DYS on 6/13/22.
//
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/stitching.hpp>

using namespace cv;
using namespace std;

Mat myPanorama(vector<Mat> imagesVector){
    Mat pano;

    Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA);
    Stitcher::Status status = stitcher->stitch(imagesVector,pano);

    if(status != Stitcher::OK) {
        cout << "can't stitch images" << endl;
        return pano;
    }

    imwrite("panorama_320_scans.jpg", pano);

    return pano;
}

int myPanoramaFunction() {
    vector<Mat> imgs;
    int start = 1;
    int end = 3;

    for(int i=start; i<=end;i++){
        string fname = "/Users/dys/Desktop/test_";
        fname = fname + to_string(i) + ".png";
        Mat _img = imread(fname.c_str());

        if(_img.empty()){
            cout << "unable to read the images" << endl;
            return -1;
        }

        imgs.push_back(_img);
    }

    Mat result;
    result = myPanorama(imgs);

    cout << "Success stitching!! Please wait for the result" << endl;

    imshow("left Image",imgs[0]);
    imshow("middle Image",imgs[1]);
    imshow("right Image",imgs[2]);
    imshow("Panorama result",result);

    return 0;
}
