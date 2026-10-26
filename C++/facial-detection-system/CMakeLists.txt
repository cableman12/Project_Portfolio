cmake_minimum_required(VERSION 3.20)

project(FacialDetectionSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(facial_detection
    src/main.cpp
)

target_link_libraries(facial_detection PRIVATE ${OpenCV_LIBS})

target_include_directories(facial_detection PRIVATE ${OpenCV_INCLUDE_DIRS})