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
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    dst_image1 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image2 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image3 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    
    
    //make mask & apply mask
    double mask1[3][3]={{1.0,-2.0,1.0},
        {-2.0, 5.0,-2.0},
        {1.0, -2.0, 1.0}};
    
    double mask2[3][3]={{0.0,-1.0,0.0},
        {-1.0, 5.0,-1.0},
        {0.0, -1.0, 0.0}};
    
    double mask3[3][3]={{-1.0,-1.0,-1.0},
        {-1.0, 9.0,-1.0},
        {-1.0, -1.0, -1.0}};
    
    CvMat kernel1 = cvMat(3,3, CV_64FC1,mask1);
    cvFilter2D(src1_image, dst_image1, &kernel1);
    
    CvMat kernel2 = cvMat(3,3, CV_64FC1,mask2);
    cvFilter2D(src1_image, dst_image2, &kernel2);
    
    CvMat kernel3 = cvMat(3,3, CV_64FC1,mask3);
    cvFilter2D(src1_image, dst_image3, &kernel3);
    
    
    //create a window
    cvNamedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Sharpened Image1", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Sharpened Image2", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Sharpened Image3", CV_WINDOW_AUTOSIZE);
    
    
    //show the image
    cvShowImage("Source Image", src1_image);
    cvShowImage("Sharpened Image1" , dst_image1);
    cvShowImage("Sharpened Image2" , dst_image2);
    cvShowImage("Sharpened Image3" , dst_image3);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    cvReleaseImage(&dst_image1);
    cvReleaseImage(&dst_image2);
    cvReleaseImage(&dst_image3);
    
    
    return 0;
}