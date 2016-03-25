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
    
    const double angle = 45.0;
    const double scale = 1.0;

    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,3);
    
    //rotation
    CvMat *rot_mat = cvCreateMat(2,3,CV_32FC1);
    
    cv2DRotationMatrix(cvPoint2D32f(src->width/2.0,src->height/2.0), angle, scale, rot_mat);
    cvWarpAffine(src, dst, rot_mat, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
    
    //create window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Rotated Image",CV_WINDOW_AUTOSIZE);
    
    //show image
    cvShowImage("Original Image",src);
    cvShowImage("Rotated Image",dst);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memory
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    
    
    
    return 0;
}