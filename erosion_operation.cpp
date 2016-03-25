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
    IplImage *dst;
    
    
    //erosion iteration
    int erosions = 1;
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena_2.jpeg",0);
    dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
    
    //erosion
    cvErode(src, dst, 0, erosions);
    
    //create window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Eroded Image",CV_WINDOW_AUTOSIZE);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("Eroded Image",dst);
    
    //wait key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    
    return 0;
}

