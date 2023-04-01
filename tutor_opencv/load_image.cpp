//
// Created by Mirkwood Ape on 01/04/2023.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);

    if (img.empty()) {
        std::cout << "Could not load the sample image: " << image_path << std::endl;
        return 1;
    }

    imshow("Display window", img);
    int k = waitKey(0);

    if (k == 's') {
        imwrite("starry_night.png", img);
    }

    return 0;
}