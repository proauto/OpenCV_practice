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
    IplImage *image, *edge, *gray;
    
    //load camera image
    CvCapture *video = cvCaptureFromCAM(-1);
    
    //create window
    cvNamedWindow("Original Video",0);
    cvNamedWindow("Edge Video",0);
    
    
    //show camera image
    while(1){
        cvGrabFrame(video);
        image = cvRetrieveFrame(video);
        cvShowImage("Original Video", image);
        
        //create image
        gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
        edge = cvCreateImage(cvGetSize(image), IPL_DEPTH_16S, 1);
        
        //convert RGB > GRAY
        cvCvtColor(image, gray, CV_BGR2GRAY);
        
        //wait key input
        if(cvWaitKey(10)>=0)
            break;
        
        //catch edge by sobel
        cvSobel(gray, edge, 1, 1, 3);
        cvConvertScale(edge, gray, 1, 0);
        
        //flip it ordinary
        gray->origin = image->origin;
        cvShowImage("Edge Video", gray);
        
    }
    
    //release memory
    cvReleaseImage(&gray);
    cvReleaseImage(&edge);
    cvReleaseCapture(&video);
    cvDestroyWindow("Original Video");
    cvDestroyWindow("Reverse Video");
    
    return 0;
}