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
    IplImage* src1_image = 0;
    IplImage* dst_image = 0;
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    
    //create a window
    cvNamedWindow("RGB Color Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Grayscale Image", CV_WINDOW_AUTOSIZE);
    
    //RGB>gray
    dst_image = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    cvCvtColor(src1_image,dst_image,CV_RGB2GRAY);
    
    //show the image
    cvShowImage("RGB Color Image", src1_image);
    cvShowImage("Grayscale Image" , dst_image);
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    
    return 0;
}