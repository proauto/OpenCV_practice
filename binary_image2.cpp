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
    IplImage* dst_image1 = 0;
    IplImage* dst_image2 = 0;
    IplImage* dst_image3 = 0;
    
    double threshold1 = 64;
    double threshold2 = 128;
    double threshold3 = 172;
    
    double max_value=255;
    
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Binary Image T=64", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Binary Image T=128", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Binary Image T=172", CV_WINDOW_AUTOSIZE);
    
    //create images
    dst_image1 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image2 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image3 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    
    //make Binary image
    cvThreshold(src1_image, dst_image1, threshold1, max_value, CV_THRESH_BINARY);
    cvThreshold(src1_image, dst_image2, threshold2, max_value, CV_THRESH_BINARY);
    cvThreshold(src1_image, dst_image3, threshold3, max_value, CV_THRESH_BINARY);
    
    //show the image
    cvShowImage("Original Image", src1_image);
    cvShowImage("Binary Image T=64" , dst_image1);
    cvShowImage("Binary Image T=128" , dst_image2);
    cvShowImage("Binary Image T=172" , dst_image3);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    
    return 0;
}