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
    int dilations =4;
    
    IplImage *src;
    IplImage *dst;
    
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    
    
    //dilation
    IplConvKernel *element = cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_RECT);
    
    cvDilate(src,dst,element, dilations);
    
    //create window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Closing Image",CV_WINDOW_AUTOSIZE);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("Closing Image",dst);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    
    return 0;
}


