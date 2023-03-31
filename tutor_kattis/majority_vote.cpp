//
// Created by Mirkwood Ape on 11/17/2019.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void majority_vote(vector<int> &votes){
    int sum = 0;
    for (auto n: votes)
        sum += n;

    // check if no winner (all elements are equal in values)
    if (equal(votes.begin() + 1, votes.end(), votes.begin())) {
        cout << "no winner" << endl;
        return;
    }

    int max_vote = 0;
    int max_vote_id = 0;
    int tie_flag = false;
    for (auto it=votes.begin(); it!=votes.end(); it++){
        // otherwise, track the winner
        if (*it > max_vote) {
            tie_flag = false;
            max_vote = *it;
            max_vote_id = static_cast<int>(distance(votes.begin(), it)) + 1;
        } else if (*it == max_vote){
            tie_flag = true;
        }
    }

    if (tie_flag)
        cout << "no winner" << endl;
    else
        // print out who's the winner and type of winning
        cout << (max_vote > sum / 2 ? "majority" : "minority") << " winner " << max_vote_id << endl;
}

int main(int argc, char* argv[]){
    int test_case;
    cin >> test_case;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (test_case > 0){
        int candidate, votes;
        cin >> candidate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> candidate_votes;
        for (int i=0; i<candidate; i++){
            cin >> votes;
            candidate_votes.push_back(votes);
        }
        majority_vote(candidate_votes);
        test_case--;
    }

    return 0;
}
