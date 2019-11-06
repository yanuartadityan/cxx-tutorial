//
// Created by Yanuar Nugraha on 31/10/19.
//

#include "challenges.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> split_string(string);
int jumpingOnClouds(vector<int>);

void cloud_jumping(void){
    // get first line of input (number of clouds)
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // get second line of input (clouds)
    string clouds;
    getline(cin, clouds);

    vector<string> split_clouds = split_string(clouds);

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

vector<string> split_string(string input_str){
    // removes multiple spaces
//    string::iterator new_end = unique(input_str.begin(), input_str.end(), [] (const char &x, const char &y){
//        return x == y and x == ' ';
//    });

    string::iterator new_end = unique(input_str.begin(), input_str.end());

    // removes trailing unused chars, and preserve only uniques
    input_str.erase(new_end, input_str.end());

    while (input_str[input_str.length() - 1] == ' ') {
        input_str.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_str.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_str.substr(i, pos - i));

        i = pos + 1;
        pos = input_str.find(delimiter, i);
    }

    splits.push_back(input_str.substr(i, min(pos, input_str.length()) - i + 1));

    return splits;
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