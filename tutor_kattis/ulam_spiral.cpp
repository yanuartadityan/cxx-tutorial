//
// Created by Mirkwood Ape on 11/16/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

// def
#define MAX_N 100

using namespace std;

// class declaration
class Spiral {
public:
    Spiral ();
    void build(unsigned, unsigned);
    static bool isPrime(unsigned u);
    vector<pair<int, int>> find_neighbor(unsigned);
    map<pair<int, int>, int> bfs(unsigned, unsigned);
    pair<int, int> find_in_array(unsigned);
    unsigned get_num_from_pos(unsigned, unsigned);

private:
    unsigned mx, my;
    // FIXME put these following vectors to map instead
    vector<unsigned> arr_prime;
    vector<unsigned> arr_all;
    void order(unsigned);
};

// class definition
Spiral::Spiral() {
    // constructor
    mx = 0;
    my = 0;
    arr_prime.clear();
}

void Spiral::build(unsigned n, unsigned startAt=0){
    // build prime spiral
    mx = n;
    unsigned area = n * n;
    my = static_cast<unsigned>(log10(static_cast<long double>(area)))+ 1;

    // build the array of all real numbers's boolean representation of being prime or not
    // init with zeroes
    for (unsigned i = 0; i < area; i++) {
        arr_prime.push_back(0);
        arr_all.push_back(0);
    }

    // build and arrange
    order(startAt);
}

bool Spiral::isPrime(unsigned u) {
    // check if given positive integer it's prime or not
    if (u < 4) return u > 1;
    if (!(u % 2) || !(u % 3)) return false;

    auto k = static_cast<unsigned>(sqrt(static_cast<long double>( u )));
    unsigned c = 5;
    while (c <= k) {
        if (!(u % c) || !(u % (c + 2))) return false;
        c += 6;
    }

    return true;
}

void Spiral::order(unsigned s_at) {
    // order/arrange the spiral
    unsigned step_limit = 1, step_count = 0, n = 1, idx = mx >> 1, idy = idx;
    int inc_x = 1, inc_y = 0;

    while(idx < mx && idy < mx ) {
        arr_prime.at(idx + idy * mx ) = isPrime(s_at ) ? s_at : 0;
        arr_all.at(idx + idy * mx) = s_at;
        s_at++;

        if( inc_x ) {
            idx += inc_x;
            if(++step_count == step_limit ) {
                inc_y = -inc_x;
                // reset x and step_count
                inc_x = 0;
                step_count = 0;
            }
        } else {
            idy += inc_y;
            if(++step_count == step_limit ) {
                inc_x = inc_y;
                // reset y and step_count
                inc_y = 0;
                step_count = 0;
                step_limit++;
            }
        }
    }
}

unsigned Spiral::get_num_from_pos(unsigned pos_x, unsigned pos_y){
    // return the number given coordinates, first get array ID
    int arr_id = pos_y + pos_x * mx;
    return arr_all[arr_id];
}

pair<int, int> Spiral::find_in_array(unsigned s_at){
    // find the coordinate of the current number
    auto it = find(arr_all.begin(), arr_all.end(), s_at);

    // get the arr-idx
    auto arr_idx = distance(arr_all.begin(), it);

    // return the result
    return make_pair(arr_idx/mx, arr_idx%mx);
}

vector<pair<int, int>> Spiral::find_neighbor(unsigned s_at) {
    // list of adjacent cells (non diagonal) that are not primes
    vector<pair<int, int>> output;

    // find coordinate of s_at first
    pair<int, int> curr = find_in_array(s_at);

    // (pos_x+1, pos_y) -- right
    if (!isPrime(get_num_from_pos(curr.first+1, curr.second)))
        output.emplace_back(curr.first+1, curr.second);

    // (pos_x, pos_y-1) -- top
    if (!isPrime(get_num_from_pos(curr.first, curr.second-1)))
        output.emplace_back(curr.first, curr.second-1);

    // (pos_x-1, pos_y) -- left
    if (!isPrime(get_num_from_pos(curr.first-1, curr.second)))
        output.emplace_back(curr.first-1, curr.second);

    // (pos_x, pos_y+1) -- bottom
    if (!isPrime(get_num_from_pos(curr.first, curr.second+1)))
        output.emplace_back(curr.first, curr.second+1);

    return output;
}

map<pair<int, int>, int> Spiral::bfs(unsigned origin, unsigned dest){
    // finding path from origin to destination, returns map of coordinate and steps
    map<pair<int, int>, int> bfs_path;
    queue<pair<int, int>> Q;

    // find origin coordinate
    pair<int, int> origin_xy = find_in_array(origin);
    pair<int, int> dest_xy = find_in_array(dest);

    // push curr position to queue
    Q.push(origin_xy);

    // BFS (Breadth-First Search), traverse queues
    while (!Q.empty()){
        // get next in queue
        pair<int, int> curr = Q.front();
        Q.pop();

        // get non prime neighbors
        vector<pair<int, int>> n = find_neighbor(get_num_from_pos(curr.first, curr.second));

        // for all neighbors, check if they have been visited or not
        for (auto &nn : n){
            // if already traversed
            if (bfs_path.count({nn.first, nn.second}))
                continue;

            // if not
            bfs_path[nn] = bfs_path[curr] + 1;

            // push current neighbor to queue
            Q.push(nn);
        }
    }

    // return bfs path
    return bfs_path;
}

int main (int argc, char* argv[]){
    // get input
    unsigned x, y;
    while (cin >> x >> y) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // build the spiral
        Spiral s;
        s.build(MAX_N, 1);
        vector<pair<int, int>> temp = s.find_neighbor(20);

        // find path
        map<pair<int, int>, int> path = s.bfs(x, y);

        if (path[s.find_in_array(y)] == 0 && x != y)
            cout << "impossible" << endl;
        else
            cout << path[s.find_in_array(y)] << endl;
    }

    return 0;
}