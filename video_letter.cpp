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
    CvFont font;
    cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX,0.8f, 0.8f, 0, 2);
    

    IplImage *frame;
    
    CvVideoWriter *writer = 0;
    int fps=30;

    //load video
    CvCapture *video = cvCaptureFromFile("/Users/ihong-gyu/MyProject/OpenCVTest/video.mp4");
    
    cvNamedWindow("Original Video",0);
    
    //show video
    while(1){
        cvGrabFrame(video);
        frame = cvRetrieveFrame(video);
        cvPutText(frame, "I Love You", cvPoint(20,20), &font,CV_RGB(255,0,0));
        
        if(!frame)
            break;
        
        writer =cvCreateVideoWriter("/Users/ihong-gyu/MyProject/OpenCVTest/video1.avi", CV_FOURCC('M','J','P','G'), fps, cvGetSize(frame));
        
        cvShowImage("Original Video",frame);
        cvWriteFrame(writer,frame);
        
        if(cvWaitKey(10)>=0)
            break;
    }
    
    
    //release memory
    cvReleaseCapture(&video);
    
    cvDestroyWindow("Original Video");
    
    
    return 0;
}