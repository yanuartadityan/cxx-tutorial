#include <iostream>
#include <vector>
#include "primes_1.h"

using namespace std;

vector<int> listPrimes(int min, int max){

    vector<int> temp;

    // start with the first prime number
    temp.push_back(2);

    for (int i = min; i < max; i++)
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            else if (i == j+1)
                temp.push_back(i);
        }

    return temp;
}

void wrapper_list_prime(){
    int min = 0;
    int max = 1000;

    // output
    vector<int> allPrimes = listPrimes(min, max);

    // print
    for(auto i = allPrimes.begin(); i != allPrimes.end(); i++)
        cout << *i << " ";
    cout << endl;
}