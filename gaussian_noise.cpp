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
IplImage* GaussNoise(IplImage* img);

int main(){
    
    //initialize
    IplImage* img=0;
    IplImage* noise=0;
    
    //load image
    img = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    
    //create a window
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Gaussian Noisy Image",CV_WINDOW_AUTOSIZE);
    
    //show the image
    cvShowImage("Original Image", img);
    
    //call GaussNoise function
    noise=GaussNoise(img);
    
    cvShowImage("Gaussian Noisy Image", noise);
    
    //wait for a key
    cvWaitKey(0);
    
    
    //release the image
    cvReleaseImage(&img);
    cvReleaseImage(&noise);
    
    
    
    return 0;
}


//make gaussian noise
IplImage* GaussNoise(IplImage* img){
    
    int height, width,step;
    uchar *data;
    
    height =img->height;
    width = img->width;
    step = img->widthStep;
    data = (uchar *)img->imageData;
    
    int r1,r2,img_size;
    double rand1,rand2,normal,std_normal,tmp;
    time_t t;
    double std=20;
    img_size=width*height;
    srand(time(&t));
    
    do{
        r1 =rand()%width;
        r2=rand()%height;
        
        rand1 = (double)rand()/RAND_MAX;
        rand2=(double)rand()/RAND_MAX;
        
        std_normal=sqrt(-2.0*log(rand1))*cos(2*3.141592*rand2);
        normal=std*std_normal;
        
        tmp=data[r1*step+r2]+normal;
        
        if(tmp<0) data[r1*step+r2]=0;
        else if(tmp>255) data[r1*step+r2]=255;
        else data[r1*step+r2]=(unsigned char)tmp;
        
        img_size--;
        printf("%d %d\n",r1,r2);
    }while(img_size>0);
    
    return img;
}