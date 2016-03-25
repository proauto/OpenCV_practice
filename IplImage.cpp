//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(){
    
    //initialize
    IplImage* image;
    uchar *data;
    
    //load an image
    image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    data = (uchar *)image->imageData;
    
    //print datas
    
    printf(" number of channels = %d \n",image->nChannels);
    printf(" origin = %d \n",image->origin);
    printf(" width = %d \n",image->width);
    printf(" height = %d \n",image->height);
    printf(" widthStep = %d bytes (width x channelsO. \n",image->widthStep);
    printf(" depth = %d \n",image->depth);
    printf(" imageSize = %d bytes (width x height x channels) \n",image->width);
    printf(" imageData = %d \n",data[100]);
    
    //release the image
    cvReleaseImage(&image);
}