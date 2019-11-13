//
// Created by Yanuar Nugraha on 31/10/19.
//

#include "challenges.h"
#include "helper/string_split.h"

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// declarations
vector<string> split_string(string, char);
int sockMerchant(int length, vector<int> &input);

// definitions
void pair_sock(void){

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line_temp;
    getline(cin, line_temp);

    vector<string> socks = string_split(line_temp, ' ');

    vector<int> ar(n);

    for (int i=0; i<n; i++){
        ar[i] = stoi(socks[i]);
    }

    // here is the result
    int result = sockMerchant(n, ar);

    // print
    cout << result << '\n';
}

int sockMerchant(int length, vector<int> &input) {

    int result = 0;
    vector<int> temp;
    vector<int>::iterator it;

    for (int i=0; i<length; i++){
        // for the current sock, find if there's match in the temp
        it = find(temp.begin(), temp.end(), input[i]);

        // if there's match, increase the result
        if (it != temp.end()) {
            temp.erase(it);
            result++;
        }
        // if no match, then add it to the temp
        else {
            temp.push_back(input[i]);
        }
    }

    return result;
}