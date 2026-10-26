#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>


int main()
{
    const std::string modelPath = "models/haarcascade_frontalface_default.xml";

    cv::CascadeClassifier faceDetector;

    if (!faceDetector.load(modelPath)) {
        std::cerr << "Error: Could not load face-detection model:\n"
                  << modelPath << '\n';
        return 1;
    }

    cv::VideoCapture camera(0); // Open the default camera (camera index 0)

    if(!camera.isOpened()){
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    std::cout << "Webcam opened succcessfully. \n";
    std::cout << "PRESS Q OR ESC TO QUIT THE PROGRAM. \n";

    cv::Mat frame; // Create a matrix to hold the captured frame
    cv::Mat grayFrame; // Create a matrix to hold the grayscale version of the frame

    //--- INITIALIZE VIDEOCAPTURE ---//

    while (true) {
        camera >> frame; // Capture a frame from the camera

        if (frame.empty()) {
            std::cerr << "Error: Could not read a frame.\n";
            break;
        }

        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY); // Convert the captured frame to grayscale
        cv::equalizeHist(grayFrame, grayFrame);         // Equalize the histogram of the grayscale image to improve contrast 

        std::vector<cv::Rect> faces; // Create a vector to hold the detected faces

        faceDetector.detectMultiScale( // Detect faces in the grayscale image
            grayFrame,  // Input image (grayscale)
            faces,      // Vector to store the detected faces
            1.1,        // Scale factor for image pyramid
            5,          // Minimum number of neighbors each candidate rectangle should have to retain it
            0,          // Flags for the detection process (0 means no flags)
            cv::Size(30, 30) // Minimum size of the detected faces
        );

        for (const cv::Rect& face : faces) { // Iterate through the detected faces and draw rectangles around them
            cv::rectangle(              // Draw a rectangle around the detected face
                frame,                  // Input image (original frame)
                face,                   // Rectangle representing the detected face
                cv::Scalar(0, 255, 0),  // Color of the rectangle (green in BGR format)
                2
            );
        }

        cv::putText(                    // Overlay the number of detected faces on the frame
            frame,                      // Input image (original frame)
            "Faces detected: " + std::to_string(faces.size()), // Text to display (number of detected faces)
            cv::Point(20, 40),          // Position of the text on the image (x=20, y=40)
            cv::FONT_HERSHEY_SIMPLEX,   // Font type for the text
            1.0,                        // Font scale (size of the text)
            cv::Scalar(0, 255, 0),      // Color of the text (green in BGR format)
            2                           // Thickness of the text
        );

        cv::imshow("Facial Detection", frame); // Display the frame with detected faces in a window titled "Facial Detection"

        int key = cv::waitKey(30);  // Wait for a key press for 30 milliseconds

        if (key == 'q' || key == 'Q' || key == 27) { // Check if the pressed key is 'q', 'Q', or ESC (ASCII code 27)
            break;
        }
    }
    camera.release(); // Release the camera resource
    cv::destroyAllWindows(); // Close all OpenCV windows
    return 0;
    

}