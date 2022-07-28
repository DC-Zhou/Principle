cmake_minimum_required(VERSION 3.0.0)
project(stl_test VERSION 0.1.0)

#set(CMAKE_TOOLCHAIN_FILE E:/src/vcpkg/scripts/buildsystems/vcpkg.cmake)
#set(OpenCV_DIR E:/src/vcpkg/installed/x64-windows/share/opencv)

#find_package(OpenCV REQUIRED)
add_compile_options(-std=c++11)

# add_library(TextDetection main.cpp)
add_executable(Test e3_3.cpp)
#include_directories(OpenCV_INCLUDE_DIRS "C:/Program Files/Java/jdk-18.0.2/include" "C:/Program Files/Java/jdk-18.0.2/include/win32")
# include_directories(OpenCV_INCLUDE_DIRS)

#target_link_libraries( TextDetection ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

