//
//  dilatation.h
//  Multimedia_FinalProject
//
//  Created by DYS on 6/13/22.
//
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

int myDilatationFunction(std::string filename){
    cv::Mat src;

    src = cv::imread(filename, cv::IMREAD_COLOR);
    cv::resize(src, src, cv::Size(src.cols/2, src.rows/2));
    
    if(src.empty()){
        std::cout << "Can't Open Image" << std::endl;
        return -1;
    }

    cv::Mat gray, binary;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::Mat erosion, dilation, original;
    cv::erode(binary, erosion, cv::Mat());
    cv::dilate(binary, dilation, cv::Mat());
    cv::imshow("erosion", erosion);
    cv::imshow("dilation", dilation);
    cv::imshow("source", src);

    return 0;
}

