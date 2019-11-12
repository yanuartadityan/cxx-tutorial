//
// Created by Mirkwood Ape on 11/9/2019.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){

    // get the stones
    unsigned long N = 0;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*  since both players take 2 consecutive turns each, this problem
        can be solved by simply finding the remainder of N divided by 2.

        this can be done by modulus operator % and return the residual.
        since the divisor is 2 in this case, the residual range is always
        0 <= residual < 2 */

    unsigned int residual = N % 2;

    if (residual == 0)
        cout << "Bob";
    else
        cout << "Alice";

    return 0;
}