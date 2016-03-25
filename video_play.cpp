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
    CvCapture *video = cvCaptureFromFile("/Users/ihong-gyu/MyProject/OpenCVTest/video.mp4");
    
    //create window
    cvNamedWindow("Video",0);
    
    //show video
    while(1){
        cvGrabFrame(video);
        frame = cvRetrieveFrame(video);
        
        //null checker
        if(!frame)
            break;
        cvShowImage("Video", frame);
        
        //wait key input
        if(cvWaitKey(10)>=0)
            break;
    }
    
    //release memory
    cvReleaseCapture(&video);
    
    
    
    
    return 0;
}