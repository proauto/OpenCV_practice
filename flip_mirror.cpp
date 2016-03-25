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
    IplImage* src;
    IplImage *dst1,*dst2,*dst3;
    
    int flip_model1=0;
    int flip_model2=1;
    int flip_model3=-1;
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    dst1 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,3);
    dst2 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,3);
    dst3 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,3);
    
    //flip image
    cvFlip(src,dst1,flip_model1);
    cvFlip(src,dst2,flip_model2);
    cvFlip(src,dst3,flip_model3);
    
    //create window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Vertical Flipping",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Horizontal Flipping",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Vertical-Horizontal Flipping",CV_WINDOW_AUTOSIZE);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("Vertical Flipping",dst1);
    cvShowImage("Horizontal Flipping",dst2);
    cvShowImage("Vertical-Horizontal Flipping",dst3);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst1);
    cvReleaseImage(&dst2);
    cvReleaseImage(&dst3);
    
    
    
    return 0;
}
