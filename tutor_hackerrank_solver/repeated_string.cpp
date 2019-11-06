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

long repeatedStringSolver(string &s, long n);

void repeated_string(){

    // get input
    string s;
    getline(cin, s);

    // get number of repeats
    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize >::max(), '\n');

    // result
    long result = repeatedStringSolver(s, n);

    cout << result << endl;
}

long repeatedStringSolver(string &s, long n){
    // repeated string
    long result;

    // find out how many repeat is needed, without ceiling
    long multiplier = long(n / s.size());
    long residual = long(n % s.size());

    // multiply with number of found 'a'
    result = count(s.begin(), s.end(), 'a') * multiplier;

    // inspect residual
    result += count(s.begin(), s.begin()+residual, 'a');

    return result;
}