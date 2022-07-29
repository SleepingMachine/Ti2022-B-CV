//
// Created by eaibot71 on 22-7-27.
//

#ifndef TI_CV_2022_ASSET_DEFINE_HPP
#define TI_CV_2022_ASSET_DEFINE_HPP

const int FRAME_WIDTH  = 640;
const int FRANE_HEIGHT = 480;

enum OPERATING_MODE{
    WAIT = 0,
    SEARCH,
    RED,
    BLUE,
    RING
};

enum TARGET_TYPE{
    UNKONW = 0,
    SQUARE_R,
    ROUND_R,
    TRIANGLE_R,
    SQUARE_B,
    ROUND_B,
    TRIANGLE_B,
};

#endif //TI_CV_2022_ASSET_DEFINE_HPP
