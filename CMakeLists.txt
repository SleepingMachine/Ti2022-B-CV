cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Ti_CV_2022)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Ti_CV_2022 main.cpp src/camera/camera-stream.cpp include/camera/camera-stream.hpp asset/asset-define.hpp src/Identify/identify-shape.cpp include/identify/identify-shape.hpp src/switch/switch-control.cpp include/switch/switch-control.hpp include/identify/identify-tools.hpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

SET(CROSS_COMPILE 0)

IF(CROSS_COMPILE)
    SET(CMAKE_SYSTEM_NAME linux)
    SET(TOOLCHAIN_DIR "/usr/local/arm-toolchain/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu")

    # specify the cross compiler
    SET(CMAKE_C_COMPILER   ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-gcc)
    SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-g++)
    #SET(GNU_FLAGS "-mfpu=vfp -fPIC")
    SET(CMAKE_CXX_FLAGS "${GNU_FLAGS} ")
    SET(CMAKE_C_FLAGS "${GNU_FLAGS} ")

    # where is the target environment
    SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
            ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/include
            ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/lib)

    # search for programs in the build host directories (notnecessary)
    SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

    # for libraries and headers in the target directories
    SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

ENDIF(CROSS_COMPILE)
