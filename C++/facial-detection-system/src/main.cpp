#include <iostream>
#include <opencv2/opencv.hpp>



int main()
{
    cv::VideoCapture camera(0); // Open the default camera (camera index 0)

    if(!camera.isOpened()){
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    std::cout << "Webcam opened succcessfully. \n";
    std::cout << "PRESS Q OR ESC TO QUIT THE PROGRAM. \n";

    cv::Mat frame; // Create a matrix to hold the captured frame
    //--- INITIALIZE VIDEOCAPTURE ---//

    while  (true) {

        camera >> frame; // Capture a frame from the camera

        if(frame.empty()){
            std::cerr << "Error: Could not capture frame." << std::endl;
            break;
        }

        cv::imshow("-----Webcam Test-----", frame); // Display the captured frame in a window
        int key = cv::waitKey(30); // Wait for 30 milliseconds for a key press

        if(key == 27 || key == 'q' || key == 'Q'){ // Check if the pressed key is ESC (27) or 'q' or 'Q'
            std::cout << "Exiting program." << std::endl;
            break; // Exit the loop and end the program
        }
    }
    camera.release(); // Release the camera resource
    cv::destroyAllWindows(); // Close all OpenCV windows
    return 0;
    

}