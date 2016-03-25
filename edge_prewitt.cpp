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
    IplImage* src_image = cvLoadImage("/Users/ihong-gyu/MyProject/OpenCVTest/Lena.jpeg",0);
    IplImage* edge_image = cvCreateImage(cvGetSize(src_image), IPL_DEPTH_8U, 1);
    
    int height,width;
    uchar *data, *data1, temp[512][521];
    int i, j, x, y, row, col;
    double Gx, Gy, Gradient;
    double threshold = 128;
    
    //get the image data
    height = src_image->height;
    width = src_image->width;
    data = (uchar *)src_image->imageData;
    
    //create window
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Edge Image", CV_WINDOW_AUTOSIZE);
    
    //set image datas
    data1 = (uchar *)edge_image->imageData;
    
    for(i=0;i<height;i++)
        for(j=0;j<width;j++){
            temp[i][j]=data[i*width+j];
        }
    
    //make custom mask
    double mask1[3][3]={{-1.0,0.0,1.0},{-1.0,0.0,1.0},{-1.0,0.0,1.0}};
    double mask2[3][3]={{-1.0,-1.0,-1.0},{0.0,0.0,0.0},{1.0,1.0,1.0}};
    
    //prewitt operator
    for(x=1;x<height-1;x++)
        for(y=1;y<width-1;y++){
            Gx=0, Gy=0;
            for(row=0;row<3;row++)
                for(col=0;col<3;col++)
                {
                    Gx=Gx+temp[x+row-1][y+col-1]*mask1[row][col];
                    Gy=Gy+temp[x+row-1][y+col-1]*mask2[row][col];
                }
            
            Gradient = fabs(Gx)+fabs(Gy);
            printf("%d\n",Gradient);
            if(Gradient > threshold)
            {
                data1[x*width+y]=255;
                
            }else{
                data1[x*width+y]=0;
            }
        }
    
    
    
    cvShowImage("Original Image", src_image);
    cvShowImage("Edge Image", edge_image);
    
    //wait a key input
    cvWaitKey(0);
    
    //release image
    cvReleaseImage(&src_image);
    cvReleaseImage(&edge_image);
    
    
    
    return 0;
}