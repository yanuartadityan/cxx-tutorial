//
// Created by Mirkwood Ape on 01/04/2023.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    std::filesystem::path assets_path = std::filesystem::current_path() / "assets/";
    std::cout << "Loading assets in " << assets_path << std::endl;
    Mat img = imread(assets_path / "flower.jpeg");

    if (img.empty()) {
        std::cout << "Could not load the sample image: " << std::endl;
        return 1;
    }

    imshow("Display window", img);
    int k = waitKey(0);

    if (k == 's') {
        imwrite(assets_path / "flower.jpeg", img);
    }

    return 0;
}
