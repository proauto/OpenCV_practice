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
    src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Multiply Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Divide Image", CV_WINDOW_AUTOSIZE);
    
    //create images
    bright_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 3);
    dark_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 3);
    
    //add&subtract
    cvAddS(src_image,CV_RGB(60,60,60),bright_image,NULL);
    cvSubS(src_image,CV_RGB(60,60,60),dark_image,NULL);
    
    
    //show the image
    cvShowImage("Original Image", src_image);
    cvShowImage("Multiply Image", bright_image);
    cvShowImage("Divide Image", dark_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src_image);
    cvReleaseImage(&bright_image);
    cvReleaseImage(&dark_image);
    
    return 0;
}