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
    IplImage* dst_image = 0;
    
    int height, width,channels;
    uchar *data, *data1;
    int i,j,k;
    
    
    //load&create image
    src1_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    dst_image = cvCreateImage(cvGetSize(src1_image), IPL_DEPTH_8U, 3);
    
    //set image data
    height = src1_image->height;
    width = src1_image->width;
    channels = src1_image->nChannels;
    data = (uchar *)src1_image->imageData;
    data1 = (uchar *)dst_image->imageData;
    
    //reverse
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            for(k=0;k<channels;k++){
                data1[i*width*channels+j*channels+k]=255-data[i*width*channels+j*channels+k];
            }
        }
    }
    
    //create a window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Reverse Image", CV_WINDOW_AUTOSIZE);
    
    
    //show the image
    cvShowImage("Original Image", src1_image);
    cvShowImage("Reverse Image", dst_image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    //release the image
    cvReleaseImage(&src1_image);
    
    return 0;
}