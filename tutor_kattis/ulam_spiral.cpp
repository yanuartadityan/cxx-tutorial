//
// Created by Mirkwood Ape on 11/16/2019.
// mailto: yanuart.adityan@gmail.com
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

// def
#define MAX_N 10000

using namespace std;

// class declaration
class Spiral {
public:
    Spiral();
    void build(unsigned);
    static bool isPrime(unsigned u);
    vector<pair<int, int>> find_neighbor(unsigned);
    map<pair<int, int>, int> bfs(unsigned, unsigned);
    pair<int, int> find_in_array(unsigned);
    unsigned get_num_from_pos(unsigned, unsigned);

private:
    unsigned mx, my;
    // TODO maybe combine these two in a map<pair<int,int> int>?

    // FIXME see if these really works
    map<pair<int, int>, int> dict_to_val;
    vector<pair<int, int>> dict_to_coord{MAX_N, {0, 0}};
    void order(unsigned);
};

// class definition
Spiral::Spiral() {
    // constructor
    mx = 0;
    my = 0;
}

void Spiral::build(unsigned s_at=0){
    // build prime spiral
    int curr_px = 0;
    int curr_py = 0;

    // init
    dict_to_val[{curr_px, curr_py}] = s_at;
    dict_to_coord[s_at] = {curr_px, curr_py};

    // update the current element
    unsigned curr = s_at + 1;
    int steps = 1;

    while (curr <= MAX_N) {
        // the spiral starts at coordinate {0, 0}, with the spiral starts
        // going to the positive x direction first, then follow counter-
        // clockwise direction
        for (int i=0; i<4 && curr <= MAX_N; i++){
            for (int j=0; j<steps && curr <= MAX_N; j++){
                // first step, going to the right (x+1)
                if (i==0)
                    curr_px++;
                // second step, going upwards (y-1)
                if (i==1)
                    curr_py--;
                // third step, going left (x-1)
                if (i==2)
                    curr_px--;
                // fourth (last) step, going downward (y+1)
                if (i==3)
                    curr_py++;

                // after each step, new {x, y} coordinate is obtained
                // update dictionary maps of the prime maze
                dict_to_val[{curr_px, curr_py}] = curr;
                dict_to_coord[curr] = {curr_px, curr_py};

                curr++;
            }

            // when one complete loop is done, update the step size
            if (i % 2 == 1)
                steps++;
        }
    }
}

bool Spiral::isPrime(unsigned u) {
    // check if given positive integer it's prime or not
    if (u < 4) return u > 1;
    if (!(u % 2) || !(u % 3)) return false;

    auto k = static_cast<unsigned>(sqrt(static_cast<long double>(u)));
    unsigned c = 5;
    while (c <= k) {
        if (!(u % c) || !(u % (c + 2))) return false;
        c += 6;
    }

    return true;
}

void Spiral::order(unsigned s_at) {
    int curr_px = 0;
    int curr_py = 0;

    // init
    dict_to_val[{curr_px, curr_py}] = s_at;
    dict_to_coord[s_at] = {curr_px, curr_py};

    // update the current element
    unsigned curr = s_at + 1;
    int steps = 1;

    while (curr <= MAX_N) {
        // the spiral starts at coordinate {0, 0}, with the spiral starts
        // going to the positive x direction first, then follow counter-
        // clockwise direction
        for (int i=0; i<4 && curr <= MAX_N; i++){
            for (int j=0; j<steps && curr <= MAX_N; j++){
                // first step, going to the right (x+1)
                if (i==0)
                    curr_px++;
                // second step, going upwards (y-1)
                if (i==1)
                    curr_py--;
                // third step, going left (x-1)
                if (i==2)
                    curr_px--;
                // fourth (last) step, going downward (y+1)
                if (i==3)
                    curr_py++;

                // after each step, new {x, y} coordinate is obtained
                // update dictionary maps of the prime maze
                dict_to_val[{curr_px, curr_py}] = curr;
                dict_to_coord[curr] = {curr_px, curr_py};

                curr++;
            }

            // when one complete loop is done, update the step size
            if (i % 2 == 1)
                steps++;
        }
    }
}

unsigned Spiral::get_num_from_pos(unsigned pos_x, unsigned pos_y) {
    // return the number given coordinates, first get array ID
    return dict_to_val[{pos_x, pos_y}];
}

pair<int, int> Spiral::find_in_array(unsigned s_at) {
    // find the coordinate of the current number
    return dict_to_coord[s_at];
}

vector<pair<int, int>> Spiral::find_neighbor(unsigned s_at) {
    // TODO might be much faster just to search based on boolean of primes or not?
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

    // build the spiral
    Spiral s = *new Spiral();
    s.build(MAX_N, 1);

    // while there's input
    int case_id = 1;
    while (cin >> x >> y) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // FIXME: a bug, have to swap dest/origin when origin is bigger than dest
        unsigned temp;
        if (x > y){
            temp = x;
            x = y;
            y = temp;
        }

        // find path
        map<pair<int, int>, int> path = s.bfs(x, y);

        if (path[s.find_in_array(y)] == 0 && x != y)
            cout << "Case " << case_id << ": impossible" << endl;
        else
            cout << "Case " << case_id << ": " << path[s.find_in_array(y)] << endl;

        case_id++;
    }

    return 0;
}