//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//
//  pixel add&subtract


#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(){
    
    //initialize
    IplImage* src_image = 0;
    IplImage* bright_image = 0;
    IplImage* dark_image = 0;
    
    int height, width, channels;
    uchar *data, *data1, *data2;
    int i,j,k,temp1,temp2;
    
    //load image
    src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    //get the image data
    height = src_image->height;
    width =src_image->width;
    channels = src_image->nChannels;
    data = (uchar *)src_image->imageData;
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Multiply Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Divide Image", CV_WINDOW_AUTOSIZE);
    
    //create images
    bright_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 3);
    dark_image = cvCreateImage(cvGetSize(src_image),IPL_DEPTH_8U, 3);
    
    //set data variables
    data1 = (uchar *)bright_image->imageData;
    data2 = (uchar *)dark_image->imageData;
    
    //add 60 to image
    for(i=0;i<height;i++)
        for(j=0;j<width;j++){
            for(k=0;k<channels;k++){
                temp1=data[i*width*channels+j*channels+k]+60;
                if(temp1>255) data1[i*width*channels+j*channels+k]=255;
                else
                    data1[i*width*channels+j*channels+k]=temp1;
            }
        }
    
    //subtract 60 from image
    for(i=0;i<height;i++)
        for(j=0;j<width;j++){
            for(k=0;k<channels;k++){
                temp2=data[i*width*channels+j*channels+k]-60;
                if(temp2<0) data2[i*width*channels+j*channels+k]=0;
                else
                    data2[i*width*channels+j*channels+k]=temp2;
            }
        }
    
    //show the image
    cvShowImage("Original Image", src_image);
    cvShowImage("Multiply Image", bright_image);
    cvShowImage("Divide Image", dark_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src_image);
    cvReleaseImage(&bright_image);
    cvReleaseImage(&dark_image);
    
    return 0;
}