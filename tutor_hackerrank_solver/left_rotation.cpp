//
// Created by Mirkwood Ape on 11/8/2019.
//

#include "challenges.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> split_string(string);
vector<int> rotLeft(vector<int> &a, int &d);

void left_rotation(void){
    // get first line
    int n, d;
    cin >> n >> d;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // get the array
    string temp;
    getline(cin, temp);
    vector<string> a_temp = split_string(temp);

    vector<int> a(n);

    for (int i=0; i<n; i++){
        int a_item = stoi(a_temp[i]);
        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i=0; i<result.size(); i++){
        cout << result[i];
        if (i != result.size() -1) {
            cout << " ";
        }
    }

    cout << "\n";
}

vector<string> split_string(string input){
    string::iterator nEnd = std::unique(input.begin(), input.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input.erase(nEnd, input.end());

    while (input[input.length() - 1] == ' ') {
        input.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input.find(delimiter);

    while (pos != string::npos){
        splits.push_back(input.substr(i, pos - i));

        i = pos + 1;
        pos = input.find(delimiter, i);
    }

    splits.push_back(input.substr(i, min(pos, input.length()) - i + 1));

    return splits;
}

vector<int> rotLeft(vector<int> &a, int &d){
    // check length of the array
    int len = a.size();

    // number of shift
    int shift = d % len;

    // do the shift by slicing them first
    vector<int> temp = vector<int>(a.begin()+shift, a.end());
    temp.insert(temp.end(), a.begin(), a.begin()+shift);

    return temp;
}