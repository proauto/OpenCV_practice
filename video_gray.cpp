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
    IplImage *frame;
    IplImage *gray;
    
    //load video
    CvCapture *video = cvCaptureFromFile("/Users/ihong-gyu/MyProject/OpenCVTest/video.mp4");
    
    //create window
    cvNamedWindow("OriginalVideo",0);
    cvNamedWindow("Gray Video",0);
    
    //show video
    while(1){
        cvGrabFrame(video);
        frame = cvRetrieveFrame(video);
        
        //null checker
        if(!frame)
            break;
        
        cvShowImage("Original Video", frame);
        
        //make gray video
        gray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
        
        cvCvtColor(frame, gray, CV_BGR2GRAY);
        
        //flip it ordinary
        gray->origin = frame->origin;
        
        cvShowImage("Gray Video", gray);
        
        //wait key input
        if(cvWaitKey(10)>=0)
            break;
    }
    
    //release memory
    cvReleaseCapture(&video);
    
    cvDestroyWindow("Original Video");
    cvDestroyWindow("Gray Video");
    
    return 0;
}