#include "include/camera/camera-stream.hpp"
#include "include/switch/switch-control.hpp"
#include "asset/asset-define.hpp"

std::mutex mutex_camera_0;
std::mutex mutex_camera_1;

cv::Mat frame_camera_0 (cv::Size(FRAME_WIDTH,FRANE_HEIGHT), CV_8UC3);
cv::Mat frame_camera_1 (cv::Size(FRAME_WIDTH,FRANE_HEIGHT), CV_8UC3);

int main() {
    std::thread camera_thread(CameraStream::StreamRetrieve, &frame_camera_0, &frame_camera_1);
    std::thread switch_thread(SwitchControl::SwitchStream,  &frame_camera_0, &frame_camera_1);

    switch_thread.join();
    camera_thread.join();
    return 0;
}
