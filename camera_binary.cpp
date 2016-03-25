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
    
    //setting threshold
    int threshold = 128;
    
    //initialize images
    IplImage *image, *output, *gray;
    
    //linking camera
    CvCapture *video = cvCaptureFromCAM(-1);
    
    
    //create windows
    cvNamedWindow("Original Video",0);
    cvNamedWindow("Binary Video",0);
    
    
    
    //Attach Trackbar to Original Video& Change threshold
    cvCreateTrackbar("T", "Original Video", &threshold, 255,NULL);
    
    
    //show video
    while(1){
        
        
        cvGrabFrame(video);
        image = cvRetrieveFrame(video);
        cvShowImage("Original Video", image);
        
        
        //null check
        if(!image)
            break;
        
        //setting gray image
        gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
        //setting output image
        output = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
        
        
        cvCvtColor(image,gray,CV_RGB2GRAY);
        
        
        if(cvWaitKey(10)>=0)
            break;
        
        
        //Apply threshold
        cvThreshold(gray, output, threshold,255,CV_THRESH_BINARY);
        
        //flip it ordinary
        output->origin = image->origin;
        cvShowImage("Binary Video", output);
        
    }
    
    
    //release memory
    cvReleaseImage(&gray);
    cvReleaseImage(&output);
    cvReleaseCapture(&video);
    cvDestroyWindow("Original Video");
    cvDestroyWindow("Binary Video");
    
    return 0;
}