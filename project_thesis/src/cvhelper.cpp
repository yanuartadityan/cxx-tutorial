//
// Created by Mirkwood Ape on 4/12/2020.
//

#include "opencv2/opencv.hpp"
#include "cvhelper.h"

using namespace cv;
using namespace std;

void getCvVersion(){
    cout << "OpenCV version : " << CV_VERSION << endl;
    cout << "Major version  : " << CV_MAJOR_VERSION << endl;
    cout << "Minor version  : " << CV_MINOR_VERSION << endl;
    cout << "Subminor ver   : " << CV_SUBMINOR_VERSION << endl;
}