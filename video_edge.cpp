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
    IplImage *edge;
    
    //load video
    CvCapture *video = cvCaptureFromFile("/Users/ihong-gyu/MyProject/OpenCVTest/video.mp4");
    
    //create window
    cvNamedWindow("OriginalVideo",0);
    cvNamedWindow("Edge Video",0);
    
    //show video
    while(1){
        cvGrabFrame(video);
        frame = cvRetrieveFrame(video);
        
        //null checker
        if(!frame)
            break;
        
        cvShowImage("Original Video", frame);
        
        //change gray & catch edge
        gray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
        edge = cvCreateImage(cvGetSize(frame), IPL_DEPTH_16S, 1);
        
        cvCvtColor(frame, gray, CV_BGR2GRAY);
        
        cvSobel(gray,edge,1,1,3);
        cvConvertScale(edge, gray, 1, 0);
        
        //flip it ordinary
        gray->origin = frame->origin;
        
        cvShowImage("Edge Video", gray);
        
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