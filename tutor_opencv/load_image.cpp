//
// Created by Mirkwood Ape on 01/04/2023.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

#define MAX_PIXEL 640 // pixels


void scaled_ratio(int original_width, int original_height, int max_pixel, int *out_width, int *out_height) {
    // determine the orientation
    if (original_width > original_height) {
        // landscape
        auto ratio = float(original_width) / float(max_pixel);
        *out_width = max_pixel;
        *out_height = int(float(original_height) / ratio);
    } else {
        auto ratio = float(original_height) / float(max_pixel);
        *out_width = int(float(original_width) / ratio);
        *out_height = max_pixel;
    }
}

int main(int argc, char* argv[]) {
    std::filesystem::path assets_path = std::filesystem::current_path() / "assets/";
    std::cout << "Loading assets in " << assets_path << std::endl;

    // Load unscaled image
    Mat img = imread(assets_path / "flower.jpeg");
    Mat resized_img;
    int new_w, new_h;
    scaled_ratio(img.size().width, img.size().height, MAX_PIXEL, &new_w, &new_h);
    resize(img, resized_img, Size(new_w, new_h), INTER_LINEAR);
    
    if (resized_img.empty()) {
        std::cout << "Could not load the sample image: " << std::endl;
        return 1;
    }

    imshow("Display window", resized_img);
    int k = waitKey(0);

    if (k == 's') {
        imwrite(assets_path / "flower.jpeg", resized_img);
    }

    return 0;
}
