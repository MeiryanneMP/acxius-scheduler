#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

extern "C" {
void testFaceDetection() {
    cv::VideoCapture cam(0);

    if (!cam.isOpened()) {
        std::cerr << "Not access /dev/video0\n";
        return;
    }

    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")) {
        std::cerr << "Error Haar Cascade\n";
        return;
    }

    cv::Mat frame, gray;

    while (true) {
        cam >> frame;
        if (frame.empty()) break;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 4);

        for (auto &face : faces) {
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("Detect", frame);

        int key = cv::waitKey(1);
        if (key == 27) break;
    }

    cam.release();
    cv::destroyAllWindows();
}
}
