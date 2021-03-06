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
    IplImage *dst,*dst1,*dst2,*dst3,*dst4;
    
    int dilations = 1;
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena_2.jpeg",0);
    dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    dst1 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    dst2 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    dst3 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    dst4 = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    
    //dilation
    IplConvKernel *element = cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_CROSS);
    
    cvDilate(src, dst,element,dilations);
    cvDilate(dst, dst1,element,dilations);
    cvDilate(dst1, dst2,element,dilations);
    cvDilate(dst2, dst3,element,dilations);
    cvDilate(dst3, dst4,element,dilations);
    
    //create window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Dilated Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Dilated1 Image",CV_WINDOW_AUTOSIZE);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("Dilated Image",dst);
    cvShowImage("Dilated1 Image",dst4);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    
    return 0;
}


