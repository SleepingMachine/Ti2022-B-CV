//
// Created by eaibot71 on 22-7-27.
//

#ifndef TI_CV_2022_SWITCH_CONTROL_HPP
#define TI_CV_2022_SWITCH_CONTROL_HPP
#include "../../include/switch/switch-read-config.hpp"
#include "../../include/identify/identify-shape.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

class SwitchControl{
private:

public:
    static void SwitchStream(cv::Mat* import_src_0, cv::Mat* import_src_1);
    SwitchControl();
    ~SwitchControl();

    static int ReadConfig();
};

#endif //TI_CV_2022_SWITCH_CONTROL_HPP
