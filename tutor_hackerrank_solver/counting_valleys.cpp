//
// Created by ytriadit on 2019-10-31.
//

#include "challenges.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

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
    cout << n << endl;
    cout << s << endl;

    int output;
    return output = 0;
}