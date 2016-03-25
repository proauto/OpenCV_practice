//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <time.h>
IplImage* ImpulseNoise(IplImage* img);

int main(){
    
    //initialize
    IplImage* img=0;
    IplImage* noise=0;
    IplImage* dst_image1=0;
    IplImage* dst_image2=0;
    
    //load image
    img = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    //create images
    dst_image1 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    dst_image2 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    
    //create a window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Impulse Noisy Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Noise Removal Image (1st Median)",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Noise Removal Image (2st Median)",CV_WINDOW_AUTOSIZE);
    
    //show the image
    cvShowImage("Original Image", img);
    
    //call GaussNoise function
    noise=ImpulseNoise(img);
    
    cvShowImage("Impulse Noisy Image", noise);
    
    //remove noise by filtering
    cvSmooth(noise, dst_image1,CV_MEDIAN,3,3);
    cvSmooth(dst_image1,dst_image2,CV_MEDIAN,3,3);
    
    cvShowImage("Noise Removal Image (1st Median)", dst_image1);
    cvShowImage("Noise Removal Image (2st Median)", dst_image2);
    
    //wait for a key
    cvWaitKey(0);
    
    
    //release the image
    cvReleaseImage(&img);
    cvReleaseImage(&noise);
    cvReleaseImage(&dst_image1);
    cvReleaseImage(&dst_image2);
    
    
    
    return 0;
}

//make impulse noise
IplImage* ImpulseNoise(IplImage* img){
    
    int height, width,step;
    uchar *data;
    
    height =img->height;
    width = img->width;
    step = img->widthStep;
    data = (uchar *)img->imageData;
    
    int r1, r2,i, img_size, NumOfNoise;
    double percent=0.1;
    time_t t;
    
    img_size=width*height;
    srand(time(&t));
    
    NumOfNoise = (int)(img_size*percent/2.0);
    
    for(i=0;i<NumOfNoise;i++){
        r1 =rand()%width;
        r2=rand()%height;
        data[r1*step+r2]=0;
        
    }
    
    
    for(i=0;i<NumOfNoise;i++){
        r1 =rand()%width;
        r2=rand()%height;
        data[r1*step+r2]=255;
        
    }
    
    return img;
}