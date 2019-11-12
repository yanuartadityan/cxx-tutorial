//
// Created by Mirkwood Ape on 11/9/2019.
//

#include "kattis.h"

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

void alice_bob(){

    // get the stones
    unsigned long N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*  since both players take 2 consecutive turns each, this problem
        can be solved by simply finding the remainder of N divided by 2.

        this can be done by modulus operator % */

    // since the divisor is 2 in this case, the residual range is always
    // 0 <= residual < 2
    unsigned int residual = N % 2;

    if (residual == 0)
        cout << "Bob";
    else
        cout << "Alice";
}