//
// Created by Mirkwood Ape on 11/9/2019.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main (int argc, char* argv[]){
    // get the attempt
    int attempt;
    cin >> attempt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // for every at attempt, get the time when Edward was looking away
    vector<pair<int, int>> lookAway;
    for (int i=0; i<attempt; i++){
        int a, b;
        cin >> a >> b;
        lookAway.emplace_back(a, b);
    }

    /* the solution here is to understand the looking away timestamp Gunilla
     * has collected during attempted boiling from Edward.
     *
     * Gunilla is correct, if she can prove that the biggest value of any
     * starting point of Edward's looking away or 'a', is always smaller than
     * the earliest looking back time or 'b'.
     *
     * for example:
     *  attempt1 ---> [3, 5]
     *  attempt2 ---> [4, 6]
     *  attempt3 ---> [2, 7]
     * the biggest 'a' is 4, and still smaller than smallest 'b' which is 5.
     * that means, Gunilla has proved that boiling point for all attempts are
     * somewhere between biggest 'a' and smallest 'b', 4 <= boil_time <= 5.
     *
     * another example:
     *  attempt1 ---> [2, 6]
     *  attempt2 ---> [6, 6]
     *  attempt3 ---> [7, 8]
     * the biggest 'a' is 7, and bigger than smallest 'b' which is 6. this is
     * when Edward's silly theorem is actually correct!
     *
     * */

    // find the biggest 'a', equal to max_a.first
    auto max_a = *max_element(lookAway.begin(), lookAway.end(), [](const auto &x, const auto &y){
        return x.first < y.first;
    });

    // find the smallest 'b', equal to min_b.second
    auto min_b = *min_element(lookAway.begin(), lookAway.end(), [](const auto &x, const auto &y){
        return x.second < y.second;
    });

    // now check if 'a' is bigger than 'b'
    if (max_a.first > min_b.second)
        cout << "edward is right";
    else
        cout << "gunilla has a point";

    return 0;
}