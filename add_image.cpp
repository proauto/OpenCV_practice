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
    IplImage* src_image1 = 0;
    IplImage* src_image2 = 0;
    IplImage* dst_image = 0;
    
    //load images
    src_image1 = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/photo1.jpg",-1);
    src_image2 = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/photo1.jpg",-1);
    
    //create a window
    cvNamedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Background Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Destination Image", CV_WINDOW_AUTOSIZE);
    
    //add two images
    dst_image = cvCreateImage(cvGetSize(src_image1),IPL_DEPTH_8U, 3);
    cvAdd(src_image1,src_image2,dst_image,NULL);
    
    
    //show the image
    cvShowImage("Source Image", src_image1);
    cvShowImage("Background Image", src_image2);
    cvShowImage("Destination Image", dst_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src_image1);
    cvReleaseImage(&src_image2);
    cvReleaseImage(&dst_image);
    
    return 0;
}