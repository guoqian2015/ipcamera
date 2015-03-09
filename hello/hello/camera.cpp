#include "stdafx.h"
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include "opencv2/highgui/highgui_c.h"

#include <windows.h>
#pragma comment(lib,"PlayCtrl.lib")
#include <PlayM4.h>

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace cv;
using namespace std;

int ctmain()
{
long port=100;
LONG *nPort=&port;
HWND hWnd;
cvNamedWindow("In");
hWnd = (HWND) cvGetWindowHandle("In");

LPSTR sFileName="demo.mp4";
if(PlayM4_GetPort(nPort))
{
       if(PlayM4_OpenFile(*nPort,sFileName))
       {
           if(PlayM4_Play(*nPort,hWnd))
		   {
	          cvWaitKey();
		    }
        }
}
PlayM4_Stop(*nPort);
PlayM4_CloseFile(*nPort);
PlayM4_FreePort(*nPort);
cout<<"success"<<endl;
return 0;
}
