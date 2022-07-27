//
// Created by eaibot71 on 22-7-27.
//

#include "../../include/identify/identify-shape.hpp"

extern std::mutex mutex_camera_0;

ShapeIdentify::ShapeIdentify() {}

cv::Mat ShapeIdentify::import_src_;
cv::Mat ShapeIdentify::import_hsv_;
cv::Mat ShapeIdentify::color_mask_R_;
cv::Mat ShapeIdentify::color_mask_B_;
cv::Mat ShapeIdentify::dst_mask_R_;
cv::Mat ShapeIdentify::dst_mask_B_;

int ShapeIdentify::hmin_R_;
int ShapeIdentify::hmax_R_;
int ShapeIdentify::smin_R_;
int ShapeIdentify::smax_R_;
int ShapeIdentify::vmin_R_;
int ShapeIdentify::vmax_R_;

int ShapeIdentify::hmin_B_;
int ShapeIdentify::hmax_B_;
int ShapeIdentify::smin_B_;
int ShapeIdentify::smax_B_;
int ShapeIdentify::vmin_B_;
int ShapeIdentify::vmax_B_;

int ShapeIdentify::open_;
int ShapeIdentify::close_;
int ShapeIdentify::erode_;
int ShapeIdentify::dilate_;

void ShapeIdentify::ShapeIdentifyStream(cv::Mat *import_src_0) {
    cv::Mat temp_src_0;
    if (mutex_camera_0.try_lock()) {
        temp_src_0 = *import_src_0;
        mutex_camera_0.unlock();
    }
    if (!temp_src_0.empty()){
        temp_src_0.copyTo(import_src_);
    }

    ImagePreprocessing();


    cv::imshow("test", import_src_);
    cv::waitKey(1);
}

void ShapeIdentify::ImagePreprocessing() {
    cv::resize(import_src_,import_src_, cv::Size(400, 400));
    cv::cvtColor(import_src_, import_hsv_, cv::COLOR_BGR2HSV);
    cv::inRange(import_hsv_, cv::Scalar(hmin_R_, smin_R_, vmin_R_),
                cv::Scalar(hmax_R_, smax_R_, vmax_R_),
                color_mask_R_);
    cv::inRange(import_hsv_, cv::Scalar(hmin_B_, smin_B_, vmin_B_),
                cv::Scalar(hmax_B_, smax_B_, vmax_B_),
                color_mask_B_);

    morphologyEx(color_mask_R_, dst_mask_R_,   2, getStructuringElement(cv::MORPH_RECT,cv::Size(open_,   open_)));
    morphologyEx(dst_mask_R_,   dst_mask_R_,   3, getStructuringElement(cv::MORPH_RECT,cv::Size(close_,  close_)));
    morphologyEx(dst_mask_R_,   dst_mask_R_,   0, getStructuringElement(cv::MORPH_RECT,cv::Size(erode_,  erode_)));
    morphologyEx(dst_mask_R_,   dst_mask_R_,   1, getStructuringElement(cv::MORPH_RECT,cv::Size(dilate_, dilate_)));

    morphologyEx(color_mask_B_, dst_mask_B_,   2, getStructuringElement(cv::MORPH_RECT,cv::Size(open_,   open_)));
    morphologyEx(dst_mask_B_,   dst_mask_B_,   3, getStructuringElement(cv::MORPH_RECT,cv::Size(close_,  close_)));
    morphologyEx(dst_mask_B_,   dst_mask_B_,   0, getStructuringElement(cv::MORPH_RECT,cv::Size(erode_,  erode_)));
    morphologyEx(dst_mask_B_,   dst_mask_B_,   1, getStructuringElement(cv::MORPH_RECT,cv::Size(dilate_, dilate_)));

}
