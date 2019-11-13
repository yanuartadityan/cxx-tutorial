//
// Created by Yanuar Nugraha on 31/10/19.
//

#include "challenges.h"
#include "helper/string_split.h"

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

int jumpingOnClouds(vector<int>);

void cloud_jumping(void){
    // get first line of input (number of clouds)
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // get second line of input (clouds)
    string clouds;
    getline(cin, clouds);

    vector<string> split_clouds = string_split(clouds, ' ');

    // create container as many as the input cloud
    vector<int> c(n);

    // convert from char to int
    for (int i=0; i<n; i++){
        c[i] = stoi(split_clouds[i]);
    }

    // result
    int result = jumpingOnClouds(c);

    cout << result << endl;
}

int jumpingOnClouds(vector<int> cloud_vals){
    // create a result=0
    int result = 0;

    for (auto i = cloud_vals.begin(); i < cloud_vals.end()-1;)
        // assuming that index zero is always safe cloud
        if (*(i+2) == 0) {
            i+=2;
            result += 1;
        } else {
            ++i;
            result += 1;
        }

    return result;
}