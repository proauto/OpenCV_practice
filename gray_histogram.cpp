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
    IplImage* src_image=0;
    IplImage* imgHistogram=0;
    
    int bins = 256;
    int sizes[] = {bins};
    
    float max_value=0, min_value =0;
    
    //ranges - grayscale 0 to 255
    float xranges[] = {0,255};
    float* ranges[] = {xranges};
    
    //get image
    src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    imgHistogram = cvCreateImage(cvGetSize(src_image), IPL_DEPTH_8U, 1);
    
    //create windows
    cvNamedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Histogram",CV_WINDOW_AUTOSIZE);
    
    //make histogram
    CvHistogram* histo = cvCreateHist(1,sizes, CV_HIST_ARRAY,ranges,1);
    cvCalcHist(&src_image,histo);
    
    //range arrange
    cvGetMinMaxHistValue(histo, &min_value,&max_value);
    cvConvertScale(histo->bins,histo->bins,((double)imgHistogram->height)/max_value,0);
    cvSet(imgHistogram,cvScalarAll(255),0);
    
    //show rectangles
    int bandwidth = cvRound((double)imgHistogram->width/bins);
    for(int i=0;i<bins;i++)
    {
        int val = cvRound(cvGetReal1D(histo->bins, i));
        cvRectangle(imgHistogram,cvPoint(i*bandwidth,imgHistogram->height),
                    cvPoint((i+1)*bandwidth, imgHistogram->height -val),
                    cvScalarAll(0),1);
    }
    
    //show image
    cvShowImage("Original Image", src_image);
    cvShowImage("Histogram", imgHistogram);
    
    //wait a key
    cvWaitKey(0);
    
    
    //release image
    cvReleaseImage(&src_image);
    cvReleaseImage(&imgHistogram);
    return 0;
}