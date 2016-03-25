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
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    dst_image1 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    
    //make custom mask & apply mask
    double mask[5][5] = {{1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0},
        {1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0},
        {1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0},
        {1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0},
        {1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0, 1.0/25.0}};
    
    CvMat kernel = cvMat(5,5,CV_64FC1, mask);
    cvFilter2D(src1_image, dst_image1, &kernel);
    
    //create a window
    cvNamedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Blurred Image", CV_WINDOW_AUTOSIZE);
    
    
    //show the image
    cvShowImage("Source Image", src1_image);
    cvShowImage("Blurred Image" , dst_image1);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    cvReleaseImage(&dst_image1);
    
    
    return 0;
}