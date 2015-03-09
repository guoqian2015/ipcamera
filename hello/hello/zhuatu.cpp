#include "stdafx.h"
#include <cstdio>  
#include <iostream>  
#include <ctime>  
#include <Windows.h>  
#include <PlayM4.h> 
#include <HCNetSDK.h> 
#include <highgui.h>  
#include <cv.h>  
  
#pragma comment(lib,"PlayCtrl.lib")
#pragma comment(lib,"HCNetSDK.lib")  
using namespace cv;  
using namespace std;  
int ztmain(int argc, char * argv[])   
{     
    NET_DVR_Init();  
    //设置连接时间与重连时间  
    NET_DVR_SetConnectTime(2000, 1);  
    NET_DVR_SetReconnect(10000, true);  

    // 注册设备  
    LONG lUserID;  
    NET_DVR_DEVICEINFO_V30 struDeviceInfo;  
    lUserID = NET_DVR_Login_V30("172.18.183.204", 8000, "admin", "1592746", &struDeviceInfo);  
    if (lUserID < 0)  
    {  
        printf("Login error, %d\n", NET_DVR_GetLastError());  
        NET_DVR_Cleanup();  
        return -1;  
    }     
 
    //定义JPEG图像质量  
    LPNET_DVR_JPEGPARA JpegPara = new NET_DVR_JPEGPARA;  
    JpegPara->wPicQuality = 0;  
    JpegPara->wPicSize = 9;  
      
    char * Jpeg = new char[200*1024];  
    DWORD len = 200*1024;  
    LPDWORD Ret = 0;  
              
    if(!NET_DVR_SetCapturePictureMode(BMP_MODE))  
    {  
        cout<<"Set Capture Picture Mode error!"<<endl;  
        cout<<"The error code is "<<NET_DVR_GetLastError()<<endl;  
    }  
   
    vector<char>data(200*1024);  

    /*while(1)  
    {  
    bool capture = NET_DVR_CaptureJPEGPicture_NEW(lUserID,1,JpegPara,Jpeg,len,Ret);  
    if(!capture)  
    {  
        printf("Error: NET_DVR_CaptureJPEGPicture_NEW = %d", NET_DVR_GetLastError());  
        return -1;    
    }     
  
    for(int i=0;i<200*1024;i++)  
        data[i] = Jpeg[i];  
  
    Mat img = imdecode(Mat(data),1);  
    imshow("camera",img);  
	//cvShowImage("camera",Jpeg);
    cvWaitKey(1);  
      
    } */

     if(NET_DVR_CaptureJPEGPicture(lUserID,1,JpegPara,"test.jpg"))
	 {
			IplImage *frame = NULL;
			frame = cvLoadImage("test.jpg");
            cvNamedWindow("camera",CV_WINDOW_AUTOSIZE);
			cvShowImage("camera",frame);
            cvWaitKey();
			cvDestroyWindow("camera");
            cvReleaseImage(&frame);
	 }
    //FILE * fp = fopen("3.jpg","wb");  
    //fwrite(Jpeg,1,123*1024,fp);  
    //fclose(fp);  
      
    return 0;  
}  