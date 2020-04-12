//
// Created by Mirkwood Ape on 4/12/2020.
//

#ifndef CXX_TUTOR_STOP_H
#define CXX_TUTOR_STOP_H

#include <string>
#include "template.h"

class Stop{
private:
    std::string name;
    std::string address;
    std::pair<float, float> latLon;
    std::pair<float, float> area;

    int numPlatform;
    vector3<float, float, float> shelter;
    bool sheltered;
    bool disableFriendly;

public:

};

#endif //CXX_TUTOR_STOP_H
