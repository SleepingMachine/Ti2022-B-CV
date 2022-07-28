//
// Created by eaibot71 on 22-7-27.
//

#ifndef TI_CV_2022_IDENTIFY_SHAPE_HPP
#define TI_CV_2022_IDENTIFY_SHAPE_HPP
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../../include/identify/identify-tools.hpp"
#include "../../include/switch/switch-control.hpp"
#include "../../tools/tools-config.hpp"

class ShapeIdentify{
private:
    static cv::Mat import_src_;
    static cv::Mat import_roi_;
    static cv::Mat import_hsv_;

    static cv::Mat color_mask_R_;
    static cv::Mat color_mask_B_;
    static cv::Mat dst_mask_R_;
    static cv::Mat dst_mask_B_;

    static int hmin_R_;
    static int hmax_R_;
    static int smin_R_;
    static int smax_R_;
    static int vmin_R_;
    static int vmax_R_;

    static int hmin_B_;
    static int hmax_B_;
    static int smin_B_;
    static int smax_B_;
    static int vmin_B_;
    static int vmax_B_;

    static int open_;
    static int close_;
    static int erode_;
    static int dilate_;

    static std::vector<std::vector<cv::Point2i>> all_contours_B_;
    static std::vector<cv::Vec4i> hierarchy_B_;
    static std::vector<std::vector<cv::Point2i>> suspected_shape_contours_B_;
    static std::vector<cv::RotatedRect> suspected_shape_rects_B_;

    static std::vector<std::vector<cv::Point2i>> all_contours_R_;
    static std::vector<cv::Vec4i> hierarchy_R_;
    static std::vector<std::vector<cv::Point2i>> suspected_shape_contours_R_;
    static std::vector<cv::RotatedRect> suspected_shape_rects_R_;

    static std::vector<std::vector<cv::Point2i>> shape_contours_square_B_;
    static std::vector<std::vector<cv::Point2i>> shape_contours_round_B_;
    static std::vector<std::vector<cv::Point2i>> shape_contours_triangle_B_;

    static std::vector<cv::RotatedRect> shape_square_rects_B_;
    static std::vector<cv::RotatedRect> shape_round_rects_B_;
    static std::vector<cv::RotatedRect> shape_triangle_rects_B_;

    static std::vector<std::vector<cv::Point2i>> shape_contours_square_R_;
    static std::vector<std::vector<cv::Point2i>> shape_contours_round_R_;
    static std::vector<std::vector<cv::Point2i>> shape_contours_triangle_R_;

    static std::vector<cv::RotatedRect> shape_square_rects_R_;
    static std::vector<cv::RotatedRect> shape_round_rects_R_;
    static std::vector<cv::RotatedRect> shape_triangle_rects_R_;

    static void ImagePreprocessing();
    static void AuxiliaryGraphicsDrawing();
    static void ResourceRelease();
    static void SuspectedShapeFilter();
    static void ShapeClassification();

    static ShapePara shapePara_;

public:
    friend class SwitchControl;
    static void ShapeIdentifyStream(cv::Mat *import_src_0);
    ShapeIdentify();
    ~ShapeIdentify();
};
#endif //TI_CV_2022_IDENTIFY_SHAPE_HPP
