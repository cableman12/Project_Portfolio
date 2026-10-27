# Real-Time Facial Detection System

A real-time facial detection application built in C++ using OpenCV. The program captures video from a webcam, detects faces using a pretrained Haar Cascade classifier, draws bounding boxes around detected faces, displays the number of faces, and reports the processing frame rate.

## Features

- Real-time webcam video capture
- Frontal-face detection using OpenCV Haar Cascade
- Green bounding boxes around detected faces
- Live face count
- FPS performance display
- Error handling for unavailable cameras or missing model files
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
Draw bounding boxes and display results
```

The application uses OpenCV’s `CascadeClassifier` and the pretrained `haarcascade_frontalface_default.xml` model. This project performs face detection only; it does not identify individuals or save facial data.

## Prerequisites

Install the following:

- Visual Studio C++ Build Tools
- CMake
- vcpkg
- Visual Studio Code
- A working webcam

## Build Instructions

Open a Developer Command Prompt or terminal with the MSVC compiler configured.

From the project directory, configure CMake:

```powershell
cmake -S . -B build -A x64 -DCMAKE_TOOLCHAIN_FILE="C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\vcpkg\scripts\buildsystems\vcpkg.cmake"
```

Build the project:

```powershell
cmake --build build --config Debug
```

## Run the Application

From the project directory, run:

```powershell
.\build\Debug\facial_detection.exe
```

Press `Q` or `ESC` to close the application.

## Testing

The application was tested using:

- A working Windows webcam
- Single-face detection
- Multiple-face detection
- No-face conditions
- Different distances from the camera
- Different indoor lighting conditions
- FPS monitoring during live operation

## Limitations

- The Haar Cascade model primarily detects frontal faces.
- Detection accuracy may decrease with poor lighting, large head rotations, or partially covered faces.
- The program depends on the webcam being available.
- The model path must be correct when launching the application.
- This application performs detection, not facial recognition.

## Future Improvements

- Add support for profile and side-facing faces.
- Compare Haar Cascade performance with a modern DNN model.
- Add camera resolution controls.
- Add configurable detection sensitivity.
- Add face blurring for privacy.
- Export performance results for different lighting and resolution conditions.

## License and Model Attribution

The face-detection model is provided by the OpenCV project:

https://github.com/opencv/opencv/tree/4.x/data/haarcascades