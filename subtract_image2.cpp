//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//
//  pixel subtract

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(){
    
    //initialize
    IplImage* src1_image = 0;
    IplImage* src2_image = 0;
    IplImage* dst_image = 0;
    
    int height,width,channels;
    uchar *data1, *data2, *data3;
    int i,j,k,temp;
    
    //load images
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",1);
    src2_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena_2.jpeg",1);
    
    
    //get the image data
    height = src1_image->height;
    width = src1_image->width;
    channels = src1_image->nChannels;
    data1 = (uchar *)src1_image->imageData;
    
    
    //create a window
    cvNamedWindow("First Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Second Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Destination Image", CV_WINDOW_AUTOSIZE);
    
    //create image
    dst_image = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 3);
    
    //set data variables
    data2 = (uchar *)src2_image->imageData;
    data3 = (uchar *)dst_image->imageData;
    
    //Subtract image2 from one image1
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            for(k=0;k<channels;k++){
                temp=data1[i*width*channels+j*channels+k]-data2[i*width*channels+j*channels+k];
                if(temp<0) data3[i*width*channels+j*channels+j*channels+k]=0;
                else
                    data3[i*width*channels+j*channels+k]=temp;
            }
    
    //show the image
    cvShowImage("First Image", src1_image);
    cvShowImage("Second Image", src2_image);
    cvShowImage("Destination Image", dst_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    cvReleaseImage(&src2_image);
    cvReleaseImage(&dst_image);
    
    return 0;
}