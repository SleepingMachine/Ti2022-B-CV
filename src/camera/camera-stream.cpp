//
// Created by eaibot71 on 22-7-27.
//

#include "../../include/camera/camera-stream.hpp"

extern std::mutex mutex_camera_0;
extern std::mutex mutex_camera_1;

CameraStream::CameraStream() {}

cv::VideoCapture CameraStream::capture_0_;
cv::VideoCapture CameraStream::capture_1_;

void CameraStream::StreamRetrieve(cv::Mat *pFrame_0, cv::Mat *pFrame_1) {
    //bool _camera_0_flag = false;
    //bool _camera_1_flag = false;


    capture_0_.open(0);
    capture_0_.set(cv::CAP_PROP_FRAME_WIDTH,  FRAME_WIDTH);
    capture_0_.set(cv::CAP_PROP_FRAME_HEIGHT, FRANE_HEIGHT);

    //capture_1_.open(1);
    //capture_1_.set(cv::CAP_PROP_FRAME_WIDTH,  FRAME_WIDTH);
    //capture_1_.set(cv::CAP_PROP_FRAME_HEIGHT, FRANE_HEIGHT);

    //capture_0_.set(cv::CAP_PROP_AUTO_EXPOSURE, 0.25);


    cv::Mat temp_frame_0; //定义一个矩阵接受帧
    //cv::Mat temp_frame_1; //定义一个矩阵接受帧

    if(!capture_0_.isOpened())  //打开摄像头
    {
        std::cout << "No Camera [0]" << std::endl;
        exit(0);
    }
    /*
    if(!capture_0_.isOpened())  //打开摄像头
    {
        std::cout << "No Camera [1]" << std::endl;
        exit(0);
    }
     */

    while (true)
    {
        capture_0_ >> temp_frame_0;
        //capture_1_ >> temp_frame_1;

        if(!temp_frame_0.empty() && mutex_camera_0.try_lock())
        {
            temp_frame_0.copyTo(*pFrame_0);
            mutex_camera_0.unlock();
        }

        /*
        if(!temp_frame_1.empty() && mutex_camera_1.try_lock())
        {
            temp_frame_1.copyTo(*pFrame_1);
            mutex_camera_1.unlock();
        }
         */
    }
}


