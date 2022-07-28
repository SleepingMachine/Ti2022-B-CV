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

std::vector<std::vector<cv::Point2i>> ShapeIdentify::all_contours_B_;
std::vector<cv::Vec4i> ShapeIdentify::hierarchy_B_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::suspected_shape_contours_B_;
std::vector<cv::RotatedRect> ShapeIdentify::suspected_shape_rects_B_;

std::vector<std::vector<cv::Point2i>> ShapeIdentify::all_contours_R_;
std::vector<cv::Vec4i> ShapeIdentify::hierarchy_R_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::suspected_shape_contours_R_;
std::vector<cv::RotatedRect> ShapeIdentify::suspected_shape_rects_R_;

std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_square_B_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_round_B_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_triangle_B_;

std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_square_R_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_round_R_;
std::vector<std::vector<cv::Point2i>> ShapeIdentify::shape_contours_triangle_R_;

std::vector<cv::RotatedRect> ShapeIdentify::shape_square_rects_B_;
std::vector<cv::RotatedRect> ShapeIdentify::shape_round_rects_B_;
std::vector<cv::RotatedRect> ShapeIdentify::shape_triangle_rects_B_;

std::vector<cv::RotatedRect> ShapeIdentify::shape_square_rects_R_;
std::vector<cv::RotatedRect> ShapeIdentify::shape_round_rects_R_;
std::vector<cv::RotatedRect> ShapeIdentify::shape_triangle_rects_R_;

int ShapeIdentify::hmin_R_ = 112;
int ShapeIdentify::hmax_R_ = 199;
int ShapeIdentify::smin_R_ = 98;
int ShapeIdentify::smax_R_ = 206;
int ShapeIdentify::vmin_R_ = 175;
int ShapeIdentify::vmax_R_ = 204;

int ShapeIdentify::hmin_B_ = 92;
int ShapeIdentify::hmax_B_ = 172;
int ShapeIdentify::smin_B_ = 122;
int ShapeIdentify::smax_B_ = 255;
int ShapeIdentify::vmin_B_ = 26;
int ShapeIdentify::vmax_B_ = 99;

int ShapeIdentify::open_   = 4;
int ShapeIdentify::close_  = 5;
int ShapeIdentify::erode_  = 7;
int ShapeIdentify::dilate_ = 7;

ShapePara ShapeIdentify::shapePara_ = ShapeParaFactory::getShapePara();

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
    SuspectedShapeFilter();
    ShapeClassification();
    AuxiliaryGraphicsDrawing();
    ResourceRelease();

}

void ShapeIdentify::ImagePreprocessing() {

    if (!import_src_.empty()){
        cv::Rect m_select;
        m_select = cv::Rect(120,40,400,400);
        import_roi_ = import_src_(m_select).clone();
    }

    cv::cvtColor(import_roi_, import_hsv_, cv::COLOR_BGR2HSV);

    if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::RED){
        cv::inRange(import_hsv_, cv::Scalar(hmin_R_, smin_R_, vmin_R_),
                    cv::Scalar(hmax_R_, smax_R_, vmax_R_),
                    color_mask_R_);

        morphologyEx(color_mask_R_, dst_mask_R_,   2, getStructuringElement(cv::MORPH_RECT,cv::Size(open_,   open_)));
        morphologyEx(dst_mask_R_,   dst_mask_R_,   3, getStructuringElement(cv::MORPH_RECT,cv::Size(close_,  close_)));
        morphologyEx(dst_mask_R_,   dst_mask_R_,   0, getStructuringElement(cv::MORPH_RECT,cv::Size(erode_,  erode_)));
        morphologyEx(dst_mask_R_,   dst_mask_R_,   1, getStructuringElement(cv::MORPH_RECT,cv::Size(dilate_, dilate_)));
    }
    else if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::BLUE){
        cv::inRange(import_hsv_, cv::Scalar(hmin_B_, smin_B_, vmin_B_),
                    cv::Scalar(hmax_B_, smax_B_, vmax_B_),
                    color_mask_B_);

        morphologyEx(color_mask_B_, dst_mask_B_,   2, getStructuringElement(cv::MORPH_RECT,cv::Size(open_,   open_)));
        morphologyEx(dst_mask_B_,   dst_mask_B_,   3, getStructuringElement(cv::MORPH_RECT,cv::Size(close_,  close_)));
        morphologyEx(dst_mask_B_,   dst_mask_B_,   0, getStructuringElement(cv::MORPH_RECT,cv::Size(erode_,  erode_)));
        morphologyEx(dst_mask_B_,   dst_mask_B_,   1, getStructuringElement(cv::MORPH_RECT,cv::Size(dilate_, dilate_)));
    }
}

void ShapeIdentify::AuxiliaryGraphicsDrawing() {

    if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::RED){
        for (int i = 0; i < shape_square_rects_R_.size(); ++i) {
            //IdentifyTools::drawRotatedRect(import_roi_, suspected_shape_rects_B_[i], cv::Scalar(170, 255, 32),  2, 16);
            cv::putText(import_roi_, "SQUARE", shape_square_rects_R_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0, 165, 255), 2);
        }
        for (int i = 0; i < shape_round_rects_R_.size(); ++i) {
            //cv::circle(import_roi_, shape_round_rects_B_[i].center, (shape_round_rects_B_[i].size.width + shape_round_rects_B_[i].size.height)/4, cv::Scalar(170, 255, 32), 2);
            cv::putText(import_roi_, "CIRCLE", shape_round_rects_R_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0, 165, 255), 2);
        }
        for (int i = 0; i < shape_triangle_rects_R_.size(); ++i) {
            cv::putText(import_roi_, "TRIANGLE", shape_triangle_rects_R_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0, 165, 255), 2);
        }
        cv::imshow("mask_R", dst_mask_R_);
    }
    else if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::BLUE){
        for (int i = 0; i < shape_square_rects_B_.size(); ++i) {
            //IdentifyTools::drawRotatedRect(import_roi_, suspected_shape_rects_B_[i], cv::Scalar(170, 255, 32),  2, 16);
            cv::putText(import_roi_, "SQUARE", shape_square_rects_B_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(170, 255, 32), 2);
        }
        for (int i = 0; i < shape_round_rects_B_.size(); ++i) {
            //cv::circle(import_roi_, shape_round_rects_B_[i].center, (shape_round_rects_B_[i].size.width + shape_round_rects_B_[i].size.height)/4, cv::Scalar(170, 255, 32), 2);
            cv::putText(import_roi_, "CIRCLE", shape_round_rects_B_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(170, 255, 32), 2);
        }
        for (int i = 0; i < shape_triangle_rects_B_.size(); ++i) {
            cv::putText(import_roi_, "TRIANGLE", shape_triangle_rects_B_[i].center, cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(170, 255, 32), 2);
        }
        cv::imshow("mask_B", dst_mask_B_);
    }
    cv::imshow("src", import_roi_);
    cv::waitKey(1);
}

void ShapeIdentify::ResourceRelease() {
    suspected_shape_rects_B_   .clear();
    suspected_shape_contours_B_.clear();
    all_contours_B_            .clear();
    hierarchy_B_               .clear();

    suspected_shape_rects_R_   .clear();
    suspected_shape_contours_R_.clear();
    all_contours_R_            .clear();
    hierarchy_R_               .clear();

    shape_contours_square_B_   .clear();
    shape_contours_round_B_    .clear();
    shape_contours_triangle_B_ .clear();

    shape_square_rects_B_      .clear();
    shape_round_rects_B_       .clear();
    shape_triangle_rects_B_    .clear();

    shape_square_rects_R_      .clear();
    shape_round_rects_R_       .clear();
    shape_triangle_rects_R_    .clear();
}

void ShapeIdentify::SuspectedShapeFilter(){
    if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::RED){
        cv::findContours(dst_mask_R_, all_contours_R_, hierarchy_R_, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        for (int i = 0; i < all_contours_R_.size(); ++i) {
            if (hierarchy_R_[i][3] == -1) {
                cv::RotatedRect scanRect = cv::minAreaRect(all_contours_R_[i]);                    //检测最小面积的矩形
                cv::Point2f vertices[4];
                scanRect.points(vertices);
                if (scanRect.size.area() < shapePara_.min_shape_rect_area){
                    continue;
                }
                if (IdentifyTools::getRectLengthWidthRatio(scanRect) < shapePara_.min_shape_length_width_ratio || IdentifyTools::getRectLengthWidthRatio(scanRect) > shapePara_.max_shape_length_width_ratio){
                    continue;
                }
                suspected_shape_rects_R_.push_back(scanRect);
                suspected_shape_contours_R_.push_back(all_contours_R_[i]);
            }
        }
    }
    else if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::BLUE){
        cv::findContours(dst_mask_B_, all_contours_B_, hierarchy_B_, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        for (int i = 0; i < all_contours_B_.size(); ++i) {
            if (hierarchy_B_[i][3] == -1) {
                cv::RotatedRect scanRect = cv::minAreaRect(all_contours_B_[i]);                    //检测最小面积的矩形
                cv::Point2f vertices[4];
                scanRect.points(vertices);
                if (scanRect.size.area() < shapePara_.min_shape_rect_area){
                    continue;
                }
                if (IdentifyTools::getRectLengthWidthRatio(scanRect) < shapePara_.min_shape_length_width_ratio || IdentifyTools::getRectLengthWidthRatio(scanRect) > shapePara_.max_shape_length_width_ratio){
                    continue;
                }
                suspected_shape_rects_B_.push_back(scanRect);
                suspected_shape_contours_B_.push_back(all_contours_B_[i]);
            }
        }
    }
}

void ShapeIdentify::ShapeClassification() {
    if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::RED) {
        for (int i = 0; i < suspected_shape_contours_R_.size(); ++i) {
            std::vector<cv::Point2i> test_points;
            cv::approxPolyDP(suspected_shape_contours_R_[i], test_points, 20, true);

            if (IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_R_[i]) <= shapePara_.max_square_length_width_ratio && (cv::contourArea(suspected_shape_contours_R_[i]) / suspected_shape_rects_R_[i].size.area()) >= shapePara_.min_square_duty_cycle && test_points.size() <= 5){
                //shape_contours_square_B_.push_back(suspected_shape_contours_B_[i]);
                shape_square_rects_R_.push_back(suspected_shape_rects_R_[i]);
                continue;
            }
            else if(IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_R_[i]) <= shapePara_.max_square_length_width_ratio && (cv::arcLength(suspected_shape_contours_R_[i], true) / 3.1415 * (suspected_shape_rects_R_[i].size.height + suspected_shape_rects_R_[i].size.width) * 0.5)>= shapePara_.min_circumference_ratio && test_points.size() > 3){
                //shape_contours_round_B_.push_back(suspected_shape_contours_B_[i]);
                shape_round_rects_R_.push_back(suspected_shape_rects_R_[i]);
                continue;
            }
            else if (IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_R_[i]) <= shapePara_.max_square_length_width_ratio && (cv::contourArea(suspected_shape_contours_R_[i]) / suspected_shape_rects_R_[i].size.area()) <= shapePara_.max_triangle_duty_cycle && test_points.size() <= 4){
                //shape_contours_triangle_B_.push_back(suspected_shape_contours_B_[i]);
                shape_triangle_rects_R_.push_back(suspected_shape_rects_R_[i]);
            }
            else if((cv::contourArea(suspected_shape_contours_R_[i]) / suspected_shape_rects_R_[i].size.area()) <= shapePara_.max_triangle_duty_cycle && suspected_shape_rects_R_[i].size.area() >= shapePara_.min_shape_rect_area*1.5){
                shape_triangle_rects_R_.push_back(suspected_shape_rects_R_[i]);
            }
        }
    }
    else if (SwitchControl::functionConfig_._operating_mode == OPERATING_MODE::BLUE){

        for (int i = 0; i < suspected_shape_contours_B_.size(); ++i) {
            std::vector<cv::Point2i> test_points;
            cv::approxPolyDP(suspected_shape_contours_B_[i], test_points, 20, true);

            if (IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_B_[i]) <= shapePara_.max_square_length_width_ratio && (cv::contourArea(suspected_shape_contours_B_[i]) / suspected_shape_rects_B_[i].size.area()) >= shapePara_.min_square_duty_cycle && test_points.size() <= 5){
                //shape_contours_square_B_.push_back(suspected_shape_contours_B_[i]);
                shape_square_rects_B_.push_back(suspected_shape_rects_B_[i]);
                continue;
            }
            else if(IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_B_[i]) <= shapePara_.max_square_length_width_ratio && (cv::arcLength(suspected_shape_contours_B_[i], true) / 3.1415 * (suspected_shape_rects_B_[i].size.height + suspected_shape_rects_B_[i].size.width) * 0.5)>= shapePara_.min_circumference_ratio && test_points.size() > 3){
                //shape_contours_round_B_.push_back(suspected_shape_contours_B_[i]);
                shape_round_rects_B_.push_back(suspected_shape_rects_B_[i]);
                continue;
            }
            else if (IdentifyTools::getRectLengthWidthRatio(suspected_shape_rects_B_[i]) <= shapePara_.max_square_length_width_ratio && (cv::contourArea(suspected_shape_contours_B_[i]) / suspected_shape_rects_B_[i].size.area()) <= shapePara_.max_triangle_duty_cycle && test_points.size() <= 4){
                //shape_contours_triangle_B_.push_back(suspected_shape_contours_B_[i]);
                shape_triangle_rects_B_.push_back(suspected_shape_rects_B_[i]);
            }
            else if((cv::contourArea(suspected_shape_contours_B_[i]) / suspected_shape_rects_B_[i].size.area()) <= shapePara_.max_triangle_duty_cycle && suspected_shape_rects_B_[i].size.area() >= shapePara_.min_shape_rect_area*1.5){
                shape_triangle_rects_B_.push_back(suspected_shape_rects_B_[i]);
            }
        }
    }

}
