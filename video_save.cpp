//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

int main(){
    
    //initialize
    IplImage *frame;
    
    //load video
    CvCapture *video = cvCaptureFromFile("/Users/ihong-gyu/MyProject/OpenCVTest/video.mp4");
    
    //create writer
    CvVideoWriter *writer = 0;
    int fps=30;
    
    //create window
    cvNamedWindow("Original Video",0);
    
    //show video
    while(1){
        cvGrabFrame(video);
        frame = cvRetrieveFrame(video);
        
        //null checker
        if(!frame)
            break;
        
        //write&save
        writer =cvCreateVideoWriter("/Users/ihong-gyu/MyProject/OpenCVTest/video1.avi”,
                                    CV_FOURCC('M','J','P','G'), fps, cvGetSize(frame));
                                    
       cvShowImage("Original Video",frame);
       cvWriteFrame(writer,frame);
       
        //wait key input
       if(cvWaitKey(10)>=0)
       break;
       }
        //release memory
       cvReleaseCapture(&video);
                                    
       cvDestroyWindow("Original Video");
                                    
                                    
       return 0;
    }