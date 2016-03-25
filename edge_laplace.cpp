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
    IplImage* src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    IplImage* edge_image = cvCreateImage(cvGetSize(src_image), IPL_DEPTH_16S, 1);
    IplImage* dst_image = cvCreateImage(cvGetSize(src_image), IPL_DEPTH_8U, 1);
    
    //create window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Edge Image", CV_WINDOW_AUTOSIZE);
    
    
    //catch edge by laplace
    cvLaplace(src_image,edge_image,3);
    cvConvertScale(edge_image,dst_image,1,0);
    
    //show image
    cvShowImage("Original Image", src_image);
    cvShowImage("Edge Image", dst_image);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src_image);
    cvReleaseImage(&edge_image);
    cvReleaseImage(&dst_image);
    
    
    return 0;
}