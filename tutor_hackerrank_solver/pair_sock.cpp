//
// Created by Yanuar Nugraha on 31/10/19.
//

#include "challenges.h"
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

    vector<string> socks = split_string(line_temp, ' ');

    vector<int> ar(n);

    for (int i=0; i<n; i++){
        ar[i] = stoi(socks[i]);
    }

    // here is the result
    int result = sockMerchant(n, ar);

    // print
    cout << result << '\n';
}

vector<string> split_string(string input_string, char delimiter) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
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