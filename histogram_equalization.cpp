//
//  camerabinary.cpp
//  OpenCVTest
//
//  Created by 이홍규 on 2016. 3. 25..
//  Copyright © 2016년 이홍규. All rights reserved.
//

#include <opencv/cv.h>
#include <opencv/highgui.h>

void DrawHist(IplImage* src_image,IplImage* hist_image);


int main(){
    
    //initialize
    IplImage* src=0;
    
    //get image
    src = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    IplImage* dst =cvCreateImage(cvGetSize(src), 8, 1);
    IplImage* hist_gray =cvCreateImage(cvGetSize(src), 8, 1);
    IplImage* hist_dst =cvCreateImage(cvGetSize(src), 8, 1);
    
    //equalization
    cvEqualizeHist(src,dst);
    
    //drawing
    DrawHist(src,hist_gray);
    DrawHist(dst,hist_dst);
    
    //create window
    cvNamedWindow("Original Image",1);
    cvNamedWindow("Equalized Image",1);
    cvNamedWindow("Original Histogram",1);
    cvNamedWindow("Histogram Equalized",1);
    
    //show images
    cvShowImage("Original Image",src);
    cvShowImage("Equalized Image",dst);
    cvShowImage("Original Histogram",hist_gray);
    cvShowImage("Histogram Equalized",hist_dst);
    
    //wait a key input
    cvWaitKey(0);
    
    //release memeroy
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    cvReleaseImage(&hist_gray);
    cvReleaseImage(&hist_dst);
    
    cvDestroyWindow("Original Image");
    cvDestroyWindow("Equalized Image");
    cvDestroyWindow("Original Histogram");
    cvDestroyWindow("Histogram Equalized");
    
    
    return 0;
}

//drawing histogram
void DrawHist(IplImage* src_image,IplImage* hist_image){
    int bin_no=256;
    int hist_size[] = {256};
    float max_value=0;
    int i,bin_w;
    
    IplImage* dst_image = cvCloneImage(src_image);
    
    CvHistogram *hist = cvCreateHist(1,hist_size,CV_HIST_ARRAY);
    
    cvCalcHist( &dst_image, hist, 0, NULL );
    cvZero( dst_image );
    cvGetMinMaxHistValue( hist, 0, &max_value, 0, 0 );
    cvScale( hist->bins, hist->bins, ((double)hist_image->height)/max_value, 0 );
    /*cvNormalizeHist( hist, 1000 );*/
    
    cvSet( hist_image, cvScalarAll(255), 0 );
    bin_w = cvRound((double)hist_image->width/bin_no);
    
    for(i=0;i<bin_no;i++)
        cvRectangle( hist_image, cvPoint(i*bin_w, hist_image->height),
                    cvPoint((i+1)*bin_w, hist_image->height - cvRound(cvGetReal1D(hist->bins,i))),
                    cvScalarAll(0), -1, 8, 0 );
    
    cvReleaseImage(&dst_image);
    cvReleaseHist(&hist);
    
    
}