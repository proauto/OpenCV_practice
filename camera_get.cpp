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
    CvCapture *capture = cvCaptureFromCAM(-1);
    
    //create window
    cvNamedWindow("Video",0);
    
    //show camera image
    while(1){
        cvGrabFrame(capture);
        frame = cvRetrieveFrame(capture);
        
        //null checker
        if(!frame)
            break;
        
        cvShowImage("Video", frame);
        
        //wait key input
        if(cvWaitKey(10)>=0)
            break;
    }
    
    //releas memory
    cvReleaseCapture(&capture);
    cvDestroyWindow("Video");
    
    return 0;
}