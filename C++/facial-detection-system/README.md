# Real-Time Facial Detection System

A real-time facial detection application built in C++ using OpenCV. The program captures video from a webcam, detects frontal faces using a pretrained Haar Cascade classifier, draws bounding boxes around detected faces, displays the number of faces, and reports the processing frame rate.

## Features

- Real-time webcam video capture
- Frontal-face detection using OpenCV Haar Cascade
- Green bounding boxes around detected faces
- Live face count
- FPS performance display
- Error handling for unavailable cameras or missing model files
- Automated testing with CMake and CTest
- No facial recognition or identity storage

## Technologies

- C++
- OpenCV 4.12
- CMake
- vcpkg
- Microsoft Visual C++ compiler
- Visual Studio Code
- Windows

## Project Structure

```text
facial-detection-system/
├── models/
│   └── haarcascade_frontalface_default.xml
├── src/
│   └── main.cpp
├── tests/
│   └── test_face_detection.cpp
├── CMakeLists.txt
├── vcpkg.json
├── vcpkg-configuration.json
└── README.md
```

## How It Works

The application follows this processing pipeline:

```text
Webcam frame
    ↓
Convert to grayscale
    ↓
Improve image contrast
    ↓
Detect faces with Haar Cascade
    ↓
Draw bounding boxes
    ↓
Display face count and FPS
```

The application uses OpenCV's `CascadeClassifier` and the pretrained `haarcascade_frontalface_default.xml` model.

This project performs face detection only. It does not identify individuals, recognize identities, or save facial data.

## Prerequisites

Install or configure the following:

- Visual Studio C++ Build Tools
- CMake
- vcpkg
- Visual Studio Code
- A working webcam

The project uses the Microsoft Visual C++ compiler and is built for 64-bit Windows.

## Build Instructions

Open a Developer Command Prompt or a terminal with the MSVC compiler configured.

From the project directory, configure CMake:

```powershell
cmake -S . -B build -A x64 -DCMAKE_TOOLCHAIN_FILE="C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\vcpkg\scripts\buildsystems\vcpkg.cmake"
```

Build the application and test executable:

```powershell
cmake --build build --config Debug
```

## Run the Application

From the project directory, run:

```powershell
.\build\Debug\facial_detection.exe
```

The webcam window will display:

- Live camera video
- Green boxes around detected faces
- The number of detected faces
- The current FPS

Press `Q` or `ESC` to close the application.

## Automated Testing

This project uses CMake and CTest to run automated checks for the face-detection system.

The automated test verifies that:

- The Haar Cascade model loads successfully.
- A blank image produces zero detected faces.

Build the test executable:

```powershell
cmake --build build --config Debug
```

Run the tests:

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

A successful test run should display:

```text
100% tests passed, 0 tests failed out of 1
```

The webcam is tested manually because webcam testing depends on hardware availability, lighting conditions, and camera access.

## Testing Performed

The application was tested using:

- A working Windows webcam
- Single-face detection
- Multiple-face detection
- No-face conditions
- Different distances from the camera
- Different indoor lighting conditions
- FPS monitoring during live operation
- Automated model-loading validation
- Automated blank-image detection validation

## Results

The application successfully captured live webcam video, detected frontal faces, displayed bounding boxes and face counts, and reported real-time FPS performance.

The automated tests also confirmed that the face-detection model loads correctly and that a blank image produces zero detections.

## Limitations

- The Haar Cascade model primarily detects frontal faces.
- Detection accuracy may decrease with poor lighting.
- Detection accuracy may decrease with large head rotations or partially covered faces.
- The program depends on a working webcam.
- The model path must be correct when launching the application.
- This application performs detection, not facial recognition.
- Haar Cascade is less robust than newer deep-learning-based detectors.

## Future Improvements

- Add support for profile and side-facing faces.
- Compare Haar Cascade performance with a modern DNN model.
- Add camera resolution controls.
- Add configurable detection sensitivity.
- Add face blurring for privacy.
- Export performance results for different lighting and resolution conditions.
- Add additional test images containing one or more faces.
- Add continuous integration testing through GitHub Actions.

## License and Model Attribution

The face-detection model is provided by the OpenCV project:

https://github.com/opencv/opencv/tree/4.x/data/haarcascades