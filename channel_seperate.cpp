//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(){
    
    
    //initialize
    IplImage *image = 0;
    
    
    //load an image
    image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    //Create a window
    cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("R_channel",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("G_channel",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("B_channel",CV_WINDOW_AUTOSIZE);
    
    //seperate RGB
    IplImage *R_plane = cvCreateImage(cvGetSize(image),8, 1);
    IplImage *G_plane = cvCreateImage(cvGetSize(image),8, 1);
    IplImage *B_plane = cvCreateImage(cvGetSize(image),8, 1);
    cvSplit(image, B_plane, G_plane, R_plane, 0);
    
    
    //show images
    cvShowImage("Image",image);
    cvShowImage("R_channel",B_plane);
    cvShowImage("G_channel",G_plane);
    cvShowImage("B_channel",R_plane);
    
    cvWaitKey(0);
    
    
    //release the image
    
    cvReleaseImage(&image);
    cvReleaseImage(&R_plane);
    cvReleaseImage(&G_plane);
    cvReleaseImage(&B_plane);
    
}