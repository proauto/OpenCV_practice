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
    IplImage *dst1, *dst2, *dst3;
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    dst1 = cvCreateImage(cvSize(src->width*5, src->height*5), src->depth, src->nChannels);
    dst2 = cvCreateImage(cvSize(src->width*5, src->height*5), src->depth, src->nChannels);
    dst3 = cvCreateImage(cvSize(src->width*5, src->height*5), src->depth, src->nChannels);
    
    //scale image
    cvResize(src, dst1,CV_INTER_NN);
    cvResize(src, dst2,CV_INTER_LINEAR);
    cvResize(src, dst3,CV_INTER_CUBIC);
    
    //create window
    cvNamedWindow("Original Image",1);
    cvNamedWindow("INTER_NN Image",1);
    cvNamedWindow("INTER_LINEAR Image",1);
    cvNamedWindow("INTER_CUBIC Image",1);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("INTER_NN Image",dst1);
    cvShowImage("INTER_LINEAR Image",dst2);
    cvShowImage("INTER_CUBIC Image",dst3);
    
    //waite a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst1);
    cvReleaseImage(&dst2);
    cvReleaseImage(&dst3);
    
    
    return 0;
}
