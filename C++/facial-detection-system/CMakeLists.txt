cmake_minimum_required(VERSION 3.20)

project(FacialDetectionSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(facial_detection
    src/main.cpp
)

target_link_libraries(facial_detection
    PRIVATE ${OpenCV_LIBS}
)

target_include_directories(facial_detection
    PRIVATE ${OpenCV_INCLUDE_DIRS}
)

include(CTest)

enable_testing()

add_executable(face_detection_tests
    tests/test_face_detection.cpp
)

target_link_libraries(face_detection_tests
    PRIVATE ${OpenCV_LIBS}
)

target_include_directories(face_detection_tests
    PRIVATE ${OpenCV_INCLUDE_DIRS}
)

add_test(
    NAME FaceDetectionTests
    COMMAND face_detection_tests
)

set_tests_properties(
    FaceDetectionTests
    PROPERTIES WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)