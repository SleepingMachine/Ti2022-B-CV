# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/203/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/203/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ti_CV_2022.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ti_CV_2022.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ti_CV_2022.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ti_CV_2022.dir/flags.make

CMakeFiles/Ti_CV_2022.dir/main.cpp.o: CMakeFiles/Ti_CV_2022.dir/flags.make
CMakeFiles/Ti_CV_2022.dir/main.cpp.o: ../main.cpp
CMakeFiles/Ti_CV_2022.dir/main.cpp.o: CMakeFiles/Ti_CV_2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ti_CV_2022.dir/main.cpp.o"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ti_CV_2022.dir/main.cpp.o -MF CMakeFiles/Ti_CV_2022.dir/main.cpp.o.d -o CMakeFiles/Ti_CV_2022.dir/main.cpp.o -c /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/main.cpp

CMakeFiles/Ti_CV_2022.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ti_CV_2022.dir/main.cpp.i"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/main.cpp > CMakeFiles/Ti_CV_2022.dir/main.cpp.i

CMakeFiles/Ti_CV_2022.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ti_CV_2022.dir/main.cpp.s"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/main.cpp -o CMakeFiles/Ti_CV_2022.dir/main.cpp.s

CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o: CMakeFiles/Ti_CV_2022.dir/flags.make
CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o: ../src/camera/camera-stream.cpp
CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o: CMakeFiles/Ti_CV_2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o -MF CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o.d -o CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o -c /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/camera/camera-stream.cpp

CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.i"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/camera/camera-stream.cpp > CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.i

CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.s"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/camera/camera-stream.cpp -o CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.s

CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o: CMakeFiles/Ti_CV_2022.dir/flags.make
CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o: ../src/Identify/identify-shape.cpp
CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o: CMakeFiles/Ti_CV_2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o -MF CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o.d -o CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o -c /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/Identify/identify-shape.cpp

CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.i"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/Identify/identify-shape.cpp > CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.i

CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.s"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/Identify/identify-shape.cpp -o CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.s

CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o: CMakeFiles/Ti_CV_2022.dir/flags.make
CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o: ../src/switch/switch-control.cpp
CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o: CMakeFiles/Ti_CV_2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o -MF CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o.d -o CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o -c /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/switch/switch-control.cpp

CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.i"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/switch/switch-control.cpp > CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.i

CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.s"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/switch/switch-control.cpp -o CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.s

CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o: CMakeFiles/Ti_CV_2022.dir/flags.make
CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o: ../src/serial/serial-port.cpp
CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o: CMakeFiles/Ti_CV_2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o -MF CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o.d -o CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o -c /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/serial/serial-port.cpp

CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.i"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/serial/serial-port.cpp > CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.i

CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.s"
	/usr/libx32/local/gcc-11.2/bin/g++-11.2 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/src/serial/serial-port.cpp -o CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.s

# Object files for target Ti_CV_2022
Ti_CV_2022_OBJECTS = \
"CMakeFiles/Ti_CV_2022.dir/main.cpp.o" \
"CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o" \
"CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o" \
"CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o" \
"CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o"

# External object files for target Ti_CV_2022
Ti_CV_2022_EXTERNAL_OBJECTS =

Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/main.cpp.o
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/src/camera/camera-stream.cpp.o
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/src/Identify/identify-shape.cpp.o
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/src/switch/switch-control.cpp.o
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/src/serial/serial-port.cpp.o
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/build.make
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.2.0
Ti_CV_2022: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.2.0
Ti_CV_2022: CMakeFiles/Ti_CV_2022.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Ti_CV_2022"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ti_CV_2022.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ti_CV_2022.dir/build: Ti_CV_2022
.PHONY : CMakeFiles/Ti_CV_2022.dir/build

CMakeFiles/Ti_CV_2022.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ti_CV_2022.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ti_CV_2022.dir/clean

CMakeFiles/Ti_CV_2022.dir/depend:
	cd /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug /home/eaibot71/Ti/TI@2022-CV-FullSize/Ti2022-B-CV/cmake-build-debug/CMakeFiles/Ti_CV_2022.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ti_CV_2022.dir/depend

