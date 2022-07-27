//
// Created by eaibot71 on 22-7-27.
//

#ifndef TI_CV_2022_CAMERA_STREAM_HPP
#define TI_CV_2022_CAMERA_STREAM_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../../asset/asset-define.hpp"

#include <iostream>
#include <thread>

class CameraStream{
private:
    static cv::VideoCapture capture_0_;
    static cv::VideoCapture capture_1_;

public:
    static void StreamRetrieve(cv::Mat* pFrame_0, cv::Mat* pFrame_1);
    CameraStream();
    ~CameraStream();
};
#endif //TI_CV_2022_CAMERA_STREAM_HPP
