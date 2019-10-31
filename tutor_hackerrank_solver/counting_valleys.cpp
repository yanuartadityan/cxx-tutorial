//
// Created by ytriadit on 2019-10-31.
//

#include "challenges.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

int countValleys(int, string);

void counting_valleys(void) {

    // get the number of steps
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // save the steps
    string s;
    getline(cin, s);

    // get result
    int result = countValleys(n, s);

    cout << result << '\n';
}

int countValleys(int n, string s){

    // n = number of steps
    // s = steps
    int valleyCount = 0;
    int hillCount = 0;

    // start at sea level
    int level = 0;

    for (char c : s){
        if (c =='U'){
            if (level == -1){
                valleyCount++;
            }
            level++;
        }
        // if going downhill
        else{
            if (level == 1){
                hillCount++;
            }
            level--;
        }
    }

    return valleyCount;
}