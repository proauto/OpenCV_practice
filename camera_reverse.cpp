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
    IplImage *image, *reverse;
    
    //load camera image
    CvCapture *video = cvCaptureFromCAM(-1);
    
    //create window
    cvNamedWindow("Original Video",0);
    cvNamedWindow("Reverse Video",0);
    
    //show camera image
    while(1){
        cvGrabFrame(video);
        image = cvRetrieveFrame(video);
        cvShowImage("Original Video", image);
        
        reverse = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
        
        //reverse
        cvNot(image, reverse);
        
        //wait key input
        if(cvWaitKey(10)>=0)
            break;
        
        reverse->origin = image->origin;
        cvShowImage("Reverse Video", reverse);
        
    }
    
    //release memory
    cvReleaseImage(&reverse);
    cvReleaseCapture(&video);
    cvDestroyWindow("Original Video");
    cvDestroyWindow("Reverse Video");
    
    return 0;
}