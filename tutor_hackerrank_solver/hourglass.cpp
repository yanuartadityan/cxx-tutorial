//
// Created by Mirkwood Ape on 11/6/2019.
//

#include "challenges.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

int hourglassSolver(vector<vector<int>>);
int sumHourglass(vector<vector<int>> &arr, pair<int, int> &center);

void hourglass(){

    // init 2D vectors
    vector<vector<int>> arr(6);
    for (auto i=0; i<6; i++){
        arr[i].resize(6);

        for(int j=0; j<6; j++){
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSolver(arr);

    cout << result << '\n';
}

int hourglassSolver(vector<vector<int>> arrInput){

    // get shape of the array
    int row = arrInput.size();
    int col = arrInput[0].size();

    // get coordinate of centers
    int r_min = 1;
    int r_max = row - 1;
    int c_min = 1;
    int c_max = col - 1;

    // build all hourglass center coordinates
    vector<pair<int, int>> centers;
    for (int r=r_min; r<r_max; r++){
        for (int c=c_min; c<c_max; c++){
            centers.emplace_back(r, c);
        }
    }

    // get hourglass values
    vector<int> hourglassSum;
    for (auto &center : centers) {
        int sumVal = sumHourglass(arrInput, center);
        hourglassSum.push_back(sumVal);
    }

    // return max
    return *max_element(hourglassSum.begin(), hourglassSum.end());
}

int sumHourglass(vector<vector<int>> &arr, pair<int, int> &center){

    // store all elements
    vector<int> elements;

    // extract top & bottom row
    for (int i=center.second-1; i<=center.second+1; i++){
        elements.push_back(arr[center.first-1][i]);
        elements.push_back(arr[center.first+1][i]);
    }

    // extract center
    elements.push_back(arr[center.first][center.second]);

    // sum
    int sum_elements = 0;
    for (auto &n : elements)
        sum_elements += n;

    return sum_elements;
}