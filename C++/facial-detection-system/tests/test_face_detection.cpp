#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

int main()
{

    const std::string modelPath = "models/haarcascade_frontalface_default.xml";

    cv::CascadeClassifier faceDetector;

    if(!faceDetector.load(modelPath)){
        std::cerr << "Error: Could not load face-detection model:\n"<< modelPath << '\n';
        return 1;
    }
    std::cout<< "Test passed: Face-detection model loaded.\nFace detection model loaded successfully.\n";

    cv::Mat BlankImage = cv::Mat::zeros(480, 640, CV_8UC3); // Create a blank image (black) of size 640x480
    
    std::vector<cv::Rect> faces; // Create a vector to hold the detected faces
    faceDetector.detectMultiScale(
        BlankImage,
        faces,
        1.1,
        5,
        0,
        cv::Size(30, 30)
    );
     if (!faces.empty()) {
        std::cerr << "Test failed: Detected a face in a blank image.\n";
        return 1;
    }

    std::cout << "Test passed: Blank image produced zero detections.\n";
    return 0;

}