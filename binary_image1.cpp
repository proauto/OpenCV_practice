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
    IplImage* image;
    int height,width;
    uchar *data;
    int i,j;
    
    //load image
    image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/lena_gray.png",0);
    
    //get image datas
    height  = image->height;
    width   = image->width;
    data    = (uchar *)image->imageData;
    
    
    //make binary image
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(data[i*width+j]>128)
                data[i*width+j]=255;
            else
                data[i*width+j]=0;
            
        }
    }
    
    //create window
    cvNamedWindow("Lena Image", CV_WINDOW_AUTOSIZE);
    //show the image
    cvShowImage("Lena Image", image);
    
    
    //wait for a key
    cvWaitKey(0);
    
    // release the image
    cvReleaseImage(&image);
    
    return 0;
}