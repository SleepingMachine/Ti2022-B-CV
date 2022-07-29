#include "include/camera/camera-stream.hpp"
#include "include/switch/switch-control.hpp"
#include "include/serial/serial-port.hpp"
#include "asset/asset-define.hpp"

std::mutex mutex_camera_0;
std::mutex mutex_camera_1;

std::mutex mutex_serial;

static int64 sent_serial_port_data;

cv::Mat frame_camera_0 (cv::Size(FRAME_WIDTH,FRANE_HEIGHT), CV_8UC3);
cv::Mat frame_camera_1 (cv::Size(FRAME_WIDTH,FRANE_HEIGHT), CV_8UC3);

int main() {
    std::thread camera_thread(CameraStream::StreamRetrieve, &frame_camera_0, &frame_camera_1);
    std::thread switch_thread(SwitchControl::SwitchStream,  &frame_camera_0, &frame_camera_1);
    std::thread serial_thread(SerialPort::SendData,&sent_serial_port_data);

    switch_thread.join();
    camera_thread.join();
    serial_thread.join();
    return 0;
}
