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
    IplImage* src1_image = 0;
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",1);
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Reverse Image", CV_WINDOW_AUTOSIZE);
    
    
    //show the image
    cvShowImage("Original Image", src1_image);
    
    //revert the image
    
    cvNot(src1_image, src1_image);
    
    cvShowImage("Reverse Image", src1_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    
    return 0;
}