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
    IplImage* image=0;
    
    int bins = 256;
    float ranges0 [] = {0,255};
    float *ranges[] = {ranges0};
    float rmax_value, gmax_value, bmax_value;
    
    //get image
    image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",-1);
    
    
    //create windows
    cvNamedWindow("R_channel",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("G_channel",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("B_channel",CV_WINDOW_AUTOSIZE);
    
    cvNamedWindow("R_histogram",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("G_histogram",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("B_histogram",CV_WINDOW_AUTOSIZE);
    

    IplImage *R_plane = cvCreateImage(cvGetSize(image), 8, 1);
    IplImage *G_plane = cvCreateImage(cvGetSize(image), 8, 1);
    IplImage *B_plane = cvCreateImage(cvGetSize(image), 8, 1);
    
    
    IplImage *rhist_img = cvCreateImage(cvGetSize(image), 8, 1);
    IplImage *ghist_img = cvCreateImage(cvGetSize(image), 8, 1);
    IplImage *bhist_img = cvCreateImage(cvGetSize(image), 8, 1);
    
    CvHistogram *rhist = cvCreateHist(1,&bins, CV_HIST_ARRAY,ranges,1);
    CvHistogram *ghist = cvCreateHist(1,&bins, CV_HIST_ARRAY,ranges,1);
    CvHistogram *bhist = cvCreateHist(1,&bins, CV_HIST_ARRAY,ranges,1);
    
    
    cvSplit(image, B_plane, G_plane, R_plane, 0);
    
    cvCalcHist(&R_plane, rhist, 0 ,NULL);
    cvCalcHist(&G_plane, ghist, 0 ,NULL);
    cvCalcHist(&B_plane, bhist, 0 ,NULL);
    
    //Get the maximum number of pixels in a histogram bar
    cvGetMinMaxHistValue(rhist,0,&rmax_value,0,0);
    cvGetMinMaxHistValue(ghist,0,&gmax_value,0,0);
    cvGetMinMaxHistValue(bhist,0,&bmax_value,0,0);
    
    //scale the histogram bar heights to fit into the histogram image window
    cvScale(rhist->bins,rhist->bins,((double)rhist_img->height)/rmax_value,0);
    cvScale(ghist->bins,ghist->bins,((double)ghist_img->height)/gmax_value,0);
    cvScale(bhist->bins,bhist->bins,((double)bhist_img->height)/bmax_value,0);
    
    //Background of histogram window is set to white (255)
    cvSet( rhist_img, cvScalarAll(255),0);
    cvSet( ghist_img, cvScalarAll(255),0);
    cvSet( bhist_img, cvScalarAll(255),0);
    
    //width of each bin is same for all the three histograms R,G,B
    int bin_w = cvRound((double)rhist_img->width/bins);
    
    for(int i =0;i<bins;i++)
    {
        
        cvRectangle(rhist_img, cvPoint(i*bin_w,rhist_img->height),
                    cvPoint((i+1)*bin_w, rhist_img->height - cvRound(cvGetReal1D(rhist->bins,i))),
                    cvScalarAll(0),1);
        
        cvRectangle(ghist_img, cvPoint(i*bin_w,ghist_img->height),
                    cvPoint((i+1)*bin_w, ghist_img->height - cvRound(cvGetReal1D(ghist->bins,i))),
                    cvScalarAll(0),1);
        cvRectangle(bhist_img, cvPoint(i*bin_w,bhist_img->height),
                    cvPoint((i+1)*bin_w, bhist_img->height - cvRound(cvGetReal1D(bhist->bins,i))),
                    cvScalarAll(0),1);
        
        
    }
    
    //show image
    cvShowImage("R_histogram", rhist_img);
    cvShowImage("G_histogram", ghist_img);
    cvShowImage("B_histogram", bhist_img);
    
    cvShowImage("R_channel", R_plane);
    cvShowImage("G_channel", G_plane);
    cvShowImage("B_channel", B_plane);
    cvShowImage("Image", image);
    
    
    
    //wait a key
    cvWaitKey(0);
    
    
    //release image
    cvReleaseImage(&image);
    cvReleaseImage(&R_plane);
    cvReleaseImage(&G_plane);
    cvReleaseImage(&B_plane);
    cvReleaseImage(&rhist_img);
    cvReleaseImage(&ghist_img);
    cvReleaseImage(&bhist_img);
    
    return 0;
}