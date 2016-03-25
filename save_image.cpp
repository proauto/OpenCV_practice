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
    
    //load image
    IplImage* image;
    image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    //create window & show image
    cvNamedWindow("Lena Image",CV_WINDOW_AUTOSIZE);
    cvShowImage("Lena Image", image);
    
    //save image
    cvSaveImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena_1.jpeg", image);
    cvWaitKey(0);
    
    //release image
    cvReleaseImage(&image);
    
    return 0;
}