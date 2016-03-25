//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(){
    
    //initialize
    IplImage* src_image = 0;
    IplImage* bright_image = 0;
    IplImage* dark_image = 0;
    
    //load image
    src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Bright Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Dark Image", CV_WINDOW_AUTOSIZE);
    
    
    //create images
    bright_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 1);
    dark_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 1);
    
    //add
    cvAddS(src_image, CV_RGB(60,60,60), bright_image,NULL);
    cvSubS(src_image, CV_RGB(60,60,60), dark_image,NULL);
    
    
    //show the image
    cvShowImage("Original Image", src_image);
    cvShowImage("Bright Image", bright_image);
    cvShowImage("Dark Image", dark_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src_image);
    cvReleaseImage(&bright_image);
    cvReleaseImage(&dark_image);
    
    return 0;
}