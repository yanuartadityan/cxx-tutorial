//
// Created by Mirkwood Ape on 11/17/2019.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

void odometer(vector<pair<int, int>> &logs){
    int sum=0;
    for (auto & log : logs){
        sum += log.first * log.second;
    }

    cout << sum << " miles" << endl;
}

int main(int argc, char* argv[]){

    while (cin) {
        int num_logs;
        cin >> num_logs;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (num_logs > 0) {
            int init_clock = 0;
            vector<pair<int, int>> logs;
            for (int i = 0; i < num_logs; i++) {
                int speed, clock;
                cin >> speed >> clock;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                logs.emplace_back(speed, clock - init_clock);
                init_clock = clock;
            }

            odometer(logs);
        }
        else
            return 0;
    }
}
