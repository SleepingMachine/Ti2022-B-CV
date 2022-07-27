//
// Created by eaibot71 on 22-7-27.
//

#include "../../include/identify/identify-shape.hpp"

extern std::mutex mutex_camera_0;

ShapeIdentify::ShapeIdentify() {}

cv::Mat ShapeIdentify::import_src_;
cv::Mat ShapeIdentify::import_roi_;
cv::Mat ShapeIdentify::import_hsv_;

cv::Mat ShapeIdentify::color_mask_R_;
cv::Mat ShapeIdentify::color_mask_B_;
cv::Mat ShapeIdentify::dst_mask_R_;
cv::Mat ShapeIdentify::dst_mask_B_;

std::vector<std::vector<cv::Point2i>> ShapeIdentify::all_contours_;
std::vector<cv::Vec4i> ShapeIdentify::hierarchy_;

int ShapeIdentify::hmin_R_;
int ShapeIdentify::hmax_R_;
int ShapeIdentify::smin_R_;
int ShapeIdentify::smax_R_;
int ShapeIdentify::vmin_R_;
int ShapeIdentify::vmax_R_;

int ShapeIdentify::hmin_B_ = 30;
int ShapeIdentify::hmax_B_ = 147;
int ShapeIdentify::smin_B_ = 79;
int ShapeIdentify::smax_B_ = 255;
int ShapeIdentify::vmin_B_ = 51;
int ShapeIdentify::vmax_B_ = 206;

int ShapeIdentify::open_   = 4;
int ShapeIdentify::close_  = 12;
int ShapeIdentify::erode_  = 4;
int ShapeIdentify::dilate_ = 8;

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
    ShapeClassification();
    AuxiliaryGraphicsDrawing();
    ResourceRelease();

}

void ShapeIdentify::ImagePreprocessing() {

    if (!import_src_.empty()){
        cv::Rect m_select;
        m_select = cv::Rect(120,40,400,400);
        import_roi_ = import_src_(m_select);
    }


    cv::cvtColor(import_roi_, import_hsv_, cv::COLOR_BGR2HSV);
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

void ShapeIdentify::AuxiliaryGraphicsDrawing() {
    cv::imshow("src", import_roi_);
    cv::imshow("mask_R", dst_mask_R_);
    cv::imshow("mask_B", dst_mask_B_);
    cv::waitKey(1);
}

void ShapeIdentify::ResourceRelease() {

}

void ShapeIdentify::ShapeClassification() {
    cv::findContours(dst_mask_B_, all_contours_, hierarchy_, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    for (int i = 0; i < all_contours_.size(); ++i) {
        if (hierarchy_[i][3] == -1 && hierarchy_[i][4] == -1) {
            cv::RotatedRect scanRect = cv::minAreaRect(all_contours_[i]);                    //检测最小面积的矩形
            cv::Point2f vertices[4];
            scanRect.points(vertices);
            if (scanRect.size.area() < orePara.min_ore_area){
                continue;
            }
            if (OreTool::getRectLengthWidthRatio(scanRect) < orePara.min_ore_length_width_ratio || OreTool::getRectLengthWidthRatio(scanRect) > orePara.max_ore_length_width_ratio){
                continue;
            }
            suspected_ore_rects_.push_back(scanRect);
            suspected_ore_contours_.push_back(all_contours_[i]);
        }
    }
}
