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
    IplImage* mul_image = 0;
    IplImage* div_image = 0;
    IplImage* tmp_image = 0;
    
    //load image
    src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Multiply Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Divide Image", CV_WINDOW_AUTOSIZE);
    
    //make images
    tmp_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 1);
    mul_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 1);
    div_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 1);
    
    //multiply&divide
    cvSet(tmp_image,cvScalarAll(1),NULL);
    cvMul(src_image,tmp_image,mul_image,1.5);
    cvMul(src_image,tmp_image,div_image,1.0/2.0);
    
    
    //show the image
    cvShowImage("Original Image", src_image);
    cvShowImage("Multiply Image", mul_image);
    cvShowImage("Divide Image", div_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src_image);
    cvReleaseImage(&mul_image);
    cvReleaseImage(&div_image);
    
    return 0;
}