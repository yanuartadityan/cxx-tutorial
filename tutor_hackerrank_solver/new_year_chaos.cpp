//
// Created by Mirkwood Ape on 11/8/2019.
//

#include "challenges.h"
#include "helper/string_split.h"

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

using namespace std;

int minimumBribes(int t, vector<int> &q, int *max_step);

void new_year_chaos(void){

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string s;
        getline(cin, s);

        vector<string> qq = string_split(s, ' ');
        vector<int> q;
        q.reserve(qq.size());

        for (auto &j : qq)
            q.push_back(stoi(j));

        int max_step;
        int num_bribe = minimumBribes(t, q, &max_step);

        if (max_step > 2)
            cout << "Too chaotic" << endl;
        else
            cout << num_bribe << endl;
    }

}

int minimumBribes(int t, vector<int> &q, int *max_step){

    vector<int> q_steps(q.size(), 0);
    vector<int> q_reference;
    q_reference.reserve(q.size());
    for (int i=0; i<static_cast<int>(q.size()); i++)
        q_reference.push_back(i+1);

    // iterate all members
    int bribe = 0;
    while (q_reference != q){
        for (int j = 0; j < static_cast<int>(q.size()) - 1; j++) {
            if (q[j] > q[j+1]) {
                q_steps[q[j]-1] += 1;
                swap(q[j], q[j + 1]);
                bribe++;
            } else
                continue;
        }
    }

    *max_step = *max_element(q_steps.begin(), q_steps.end());

    return bribe;
}