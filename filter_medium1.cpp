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
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    
    //create a window
    cvNamedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Mean Filtered Image (3x3)", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Mean Filtered Image (5x5)", CV_WINDOW_AUTOSIZE);
    
    //create images
    dst_image1 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image2 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    
    //filitering image
    cvSmooth(src1_image, dst_image1,CV_MEDIAN,3,3);
    cvSmooth(src1_image, dst_image2,CV_MEDIAN,5,5);
    
    //show the image
    cvShowImage("Source Image", src1_image);
    cvShowImage("Mean Filtered Image (3x3)" , dst_image1);
    cvShowImage("Mean Filtered Image (5x5)" , dst_image2);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    cvReleaseImage(&dst_image1);
    cvReleaseImage(&dst_image2);
    
    
    return 0;
}