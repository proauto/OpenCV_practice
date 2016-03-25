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
    IplImage* dst_image1 = 0;
    IplImage* dst_image2 = 0;
    
    
    int height, width;
    uchar *data, *data1, *data2, temp[512][512];
    int i,j,x,y,sum;
    
    //load image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    
    //get the image data
    height = src1_image->height;
    width = src1_image->width;
    data =(uchar *)src1_image->imageData;
    
    //create a window
    cvNamedWindow("Source Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Mean Filtered Image (3x3)", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Mean Filtered Image (5x5)", CV_WINDOW_AUTOSIZE);
    
    //create image & set data
    dst_image1 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    dst_image2 = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 1);
    
    data1 = (uchar *)dst_image1->imageData;
    data2 = (uchar *)dst_image2->imageData;
    
    for(i=0;i<height;i++)
        for(j=0;j<width;j++){
            temp[i][j]=data[i*width+j];
        }
    
    //3x3  mean filtering
    
    for(x=1;x<height-1;x++)
        for(y=1;y<width-1;y++){
            sum=0;
            for(i=0;i<3;i++)
                for(j=0;j<3;j++){
                    sum=sum+temp[x+i-1][y+j-1];
                }
            data1[x*width+y]=(unsigned char)(sum/9.0);
        }
    
    
    //5x5  mean filtering
    
    for(x=2;x<height-2;x++)
        for(y=2;y<width-2;y++){
            sum=0;
            for(i=0;i<5;i++)
                for(j=0;j<5;j++){
                    sum=sum+temp[x+i-2][y+j-2];
                }
            data2[x*width+y]=(unsigned char)(sum/25.0);
        }
    
    //show the image
    cvShowImage("Source Image", src1_image);
    cvShowImage("Mean Filtered Image (3x3)" , dst_image1);
    cvShowImage("Mean Filtered Image (5x5)" , dst_image2);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    cvReleaseImage(&dst_image1);
    cvReleaseImage(&dst_image2);
    
    
    return 0;
}