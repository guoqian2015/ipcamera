#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include "opencv2/highgui/highgui_c.h"

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

using namespace cv;
using namespace std;

int htmain()
{
IplImage *in = NULL;
cvNamedWindow("In",CV_WINDOW_AUTOSIZE);
in = cvLoadImage("liyusan.jpg");
cvShowImage("In",in);
cvWaitKey();

/*  IplImage *frame = NULL;
       CvCapture *capture = NULL;
      capture = cvCaptureFromAVI("detect.mp4");
      //CvCapture* capture = cvCreateFileCapture( "D:\\sample.avi");  
        frame = cvQueryFrame(capture);
       cvNamedWindow("frame");

       // frame = cvQueryFrame(capture);
       //  cvSaveImage("1.jpg",frame);
       int i=1;
       char image_name[10];
       int count_tmp = 0;
      while(frame){
          // if (count_tmp % 30== 0) {
          cvShowImage("frame", frame);
      //    sprintf(image_name, "%d%s",i, ".jpg");//±£´æµÄÍ¼Æ¬Ãû 
        //  cvSaveImage(image_name,frame);
           cvWaitKey(34);
        //   cout << "Frame Grabbed." << endl;
           i++;
       //   }
        frame = cvQueryFrame(capture);
       // count_tmp++;
       }

/*if(!capture.isOpened())
return 1;
double rate=capture.get(CV_CAP_PROP_FPS);
bool stop(false);
namedWindow("Canny Video");
int delay=1000/rate;
while(!stop)
{
if(!capture.read(frame))
break;
Mat result;
Canny(frame,result,100,200);
threshold(result,result,128,255,THRESH_BINARY);
imshow("Canny Video",result);
if(waitKey(delay)>=0)
stop=true;
}*/

cvDestroyWindow("In");
cvReleaseImage(&in);

//capture.release();
return 0;
}