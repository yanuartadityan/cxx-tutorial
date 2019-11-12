//
// Created by Mirkwood Ape on 11/12/2019.
//

#include "challenges.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

// helpers
vector<string> split_strings(string input, char delimiter);

class Node{
public:
    int value = 0;
    pair<int, int> point = {0, 0};
    int H = 0;
    int G = 0;
    Node* parent = nullptr;

    // empty constructor
    Node()= default;

    // non-empty constructor
    Node(int val, pair<int, int> pt){
        value = val;
        point = pt;
    }

    int movingCost(Node other){
        if (value == 100)
            return 0;
        else
            return 1;
    }

    static int calcManhattan(pair<int, int> pt1, pair<int, int> pt2){
        return abs(pt1.first - pt2.first) + abs(pt1.second - pt2.first);
    }

    bool operator==(const Node &rhs){
        return (this->value == rhs.value) && (this->point.first == rhs.point.first)
               && (this->point.second == rhs.point.second);
    }
};

class Honeycombs{
public:
    int R;              // length of each edge of the grid
    int N;              // maximum steps of the ant
    int A;              // starting cell ID
    int B;              // cell ID which has honey
    int X;              // number of wax-hardened cells
    int startIdx;
    vector<int> IDs;    // all wax-hardened cells
    map<int, map<int, int>> hexMap;

    // constructor
    Honeycombs(int r, int n, int a, int b, int x, vector<int> ids, int startingNum){
        R = r;
        N = n;
        A = a;
        B = b;
        X = x;
        IDs = move(ids);
        startIdx = startingNum;

        // transform IDs
        for (int & ID : IDs){
            ID=ID-(startIdx+1);
        }
    }

    // all methods
    void gridCreate() {
        // build top half layer
        int j;
        int k = R;
        // start from row
        for (int i = 0; i < R; i++) {
            hexMap.insert(make_pair(i, map<int, int>()));
            // then walk through the column
            for (j = 0; j < k; j++)
                // if the cell ID 'j+startingNum' is found in the wax-hardened cells,
                // if yes, then hexagon value is 1 (un-walkable by the ant)
                if (find(IDs.begin(), IDs.end(), j + startIdx) != IDs.end())
                    hexMap[i].insert(make_pair(j + startIdx, 1));
                    // if not, hexagon value is 0 (walkable)
                else
                    hexMap[i].insert(make_pair(j + startIdx, 0));

            // increment row 'k' and 'startingNum'
            k += 1;
            startIdx = startIdx + j;
        }

        // build bottom half layer
        int jj;
        // start from row (bottom half)
        for (int i = 0; i < R - 1; i++) {
            hexMap.insert(make_pair(i + R, map<int, int>()));
            // then walk through the column
            for (jj = 0; jj < k - 2; jj++) {
                // if the cell ID 'j+startingNum' is found in the wax-hardened cells,
                // if yes, then hexagon value is 1 (un-walkable by the ant)
                if (find(IDs.begin(), IDs.end(), jj + startIdx) != IDs.end())
                    hexMap[i + R].insert(make_pair(jj + startIdx, 1));
                    // if not, hexagon value is 0 (walkable)
                else
                    hexMap[i + R].insert(make_pair(jj + startIdx, 0));
            }
            k -= 1;
            startIdx = startIdx + jj;
        }
    }

    void gridPrint(){
        // accessing through pointers
        map<int, map<int, int>>::iterator itr;
        map<int, int>::iterator ptr;
        for (itr=hexMap.begin(); itr!=hexMap.end(); itr++){
            for (ptr=itr->second.begin(); ptr!=itr->second.end(); ptr++){
                cout << "first key is " << itr->first
                     << " and second key is " << ptr->first
                     << " and value is " << ptr->second << endl;
            }
        }
    }

    bool gridCheck(pair<int, int> &output, int cellID){
        // create outer iterator (row)
        map<int, map<int, int>>::iterator itr;
        // create inner iterator (column)
        map<int, int>::iterator ptr;

        // check if the cell is passable/walkable
        for (itr=hexMap.begin(); itr!=hexMap.end(); itr++){
            for (ptr=itr->second.begin(); ptr!=itr->second.end(); ptr++){
                if (ptr->first == cellID) {
                    output = make_pair(itr->first, itr->second.size());
                    return ptr->second == 0;
                }
            }
        }
    }

    static bool isCellPresent(int cellID, vector<int> cellIDs){
        return find(cellIDs.begin(), cellIDs.end(), cellID) != cellIDs.end();
    }

    vector<int> gridGetRowElements(int rowID){
        vector<int> output;
        map<int, map<int, int>>::iterator itr;
        map<int, int>:: iterator ptr;

        for(itr=hexMap.begin(); itr!=hexMap.end(); itr++){
            if (distance(hexMap.begin(), itr) == rowID){
                for(ptr=itr->second.begin(); ptr!=itr->second.end(); ptr++){
                    output.push_back(ptr->first);
                }
                return output;
            }
        }
    }

    vector<int> gridGetNeighbours(int cellID){
        vector<int> neighbours;
        pair<int, int> kRowLen;

        // first check if it's a valid cell (non wax-hardened)
        if (gridCheck(kRowLen, cellID)){
            int row_idx = kRowLen.first;
            int row_elements = kRowLen.second;
            pair<int, int> temp;

            // list all elements for current cellID's row, above row and following row
            vector<int> currRowElements = gridGetRowElements(row_idx);
            vector<int> aboveRowElements = gridGetRowElements(row_idx-1);
            vector<int> belowRowElements = gridGetRowElements(row_idx+1);

            // neighbor IDs are potentially located in 6 adjacent nodes as declared below
            // two in above row, two in same row and two in the following row
            // must check for all, based on where is current cellID's row is located, either
            // top half, exactly at the center of the hexagon map, or at the bottom half
            int idAboveLeft = 0, idAboveRight = 0, idBelowLeft = 0, idBelowRight = 0;
            int idLeft = cellID - 1;
            int idRight = cellID + 1;

            // half top
            if (row_idx < R - 1){
                idAboveLeft = cellID - row_elements;
                idAboveRight = cellID - (row_elements - 1);
                idBelowLeft = cellID + row_elements;
                idBelowRight = cellID + row_elements + 1;
            }

            // center row
            if (row_idx == R - 1) {
                idAboveLeft = cellID - row_elements;
                idAboveRight = cellID - (row_elements - 1);
                idBelowLeft = cellID + row_elements - 1;
                idBelowRight = cellID + row_elements;
            }

            // half bottom
            if (row_idx > R - 1){
                idAboveLeft = cellID - (row_elements + 1);
                idAboveRight = cellID - row_elements;
                idBelowLeft = cellID + row_elements - 1;
                idBelowRight = cellID + row_elements;
            }

            // adjacent nodes in above row
            if (isCellPresent(idAboveLeft, aboveRowElements)
                && gridCheck(temp, idAboveLeft))
                neighbours.push_back(idAboveLeft);
            if (isCellPresent(idAboveRight, aboveRowElements)
                && gridCheck(temp, idAboveRight))
                neighbours.push_back(idAboveRight);

            // adjacent nodes same row
            if (find(currRowElements.begin(), currRowElements.end(), idLeft) != currRowElements.end()
                && gridCheck(temp, idLeft))
                neighbours.push_back(idLeft);
            if (find(currRowElements.begin(), currRowElements.end(), idRight) != currRowElements.end()
                && gridCheck(temp, idRight))
                neighbours.push_back(idRight);

            // adjacent nodes in bottom row
            if (isCellPresent(idBelowLeft, belowRowElements)
                && gridCheck(temp, idBelowLeft))
                neighbours.push_back(idBelowLeft);
            if (isCellPresent(idBelowRight, belowRowElements)
                && gridCheck(temp, idBelowRight))
                neighbours.push_back(idBelowRight);
        }

        return neighbours;
    }

    vector<Node> gridBuildNodes(){
        map<int, map<int, int>>::iterator itr;
        map<int, int>::iterator ptr;

        vector<Node> output;

        // build Nodes grid
        for (itr=hexMap.begin(); itr!=hexMap.end(); itr++){
            for(ptr=itr->second.begin(); ptr!=itr->second.end(); ptr++)
                // push Nodes(value, (row, column)
                output.emplace_back(ptr->second, make_pair(itr->first, ptr->first));
        }

        return output;
    }

    vector<Node> aStarSearch(Node start, Node dest, vector<Node> grid){

        // reserve output
        vector<Node> path;

        // build open & closed sets for A* path finding algorithm buffers
        vector<Node> openSet, closeSet;

        // set the current Node where 0x67 ant is currently located, then add to openSet
        Node current = start;
        openSet.push_back(current);

        cout << "at: (" << current.point.first << ", " << current.point.second << ")" << endl;

        // traverse through openSet
        auto os = openSet.begin();
        while (os != openSet.end()){
            auto curr = min_element(openSet.begin(), openSet.end(), [](const Node &x, const Node &y){
                return (x.G + x.H) < (y.G + y.H);
            });

            cout << "at: (" << curr->point.first << ", " << curr->point.second << ")" << endl;

            // if it's the Node we want, retrace the path and return it
            if (*curr == dest){
                while (curr->parent != nullptr){
                    path.push_back(*curr);
                    *curr = *curr->parent;
                }

                path.push_back(*curr);
                reverse(path.begin(), path.end());
                return path;
            }

            // add to the closed set
            closeSet.push_back(*curr);

            // loop through the node's children/siblings
            vector<int> nn = gridGetNeighbours(curr->point.second);
            vector<Node> children;
            children.reserve(nn.size());
            for (auto n : nn){
                children.push_back(grid[n]);
            }

            for (auto c : children){

                // if node is already in closeSet, then skip it
                auto itc = find(closeSet.begin(), closeSet.end(), c);
                if (itc != closeSet.end()) {
                    cout << "\ttraversing: (" << itc->point.first << ", " << itc->point.second << ")" << endl;
                    cout << "\t(" << itc->point.first << ", " << itc->point.second << ") has been visited" << endl;
                    continue;
                }

                // if node is still in the openSet, then proceed
                auto ito = find(openSet.begin(), openSet.end(), c);
                if (ito != openSet.end())
                {
                    // check if we can beat the current G-score
                    int new_G = curr->G + curr->movingCost(*ito);
                    if (ito->G > new_G){
                        ito->G = new_G;

                        // set the parent to our current item
                        ito->parent = new Node();
                        *(ito->parent) = *curr;
                    }
                } else {
                    // if it's not in openSet as well, calculate G and H score for the node
                    c.G = curr->G + curr->movingCost(c);
                    c.H = Node::calcManhattan(c.point, dest.point);

                    // set the parent to our current item
                    c.parent = new Node();
                    *(c.parent) = *curr;

                    cout << "\ttraversing: (" << c.point.first << ", " << c.point.second << ")" << endl;

                    // add it to the set
                    openSet.push_back(c);
                }
            }

            // remove the item from the open set
            openSet.erase(curr);

            os++;
        }

        return path;
    }
};

void honeycomb_solver (){

    // get all inputs
    int R, N, A, B, X;
    cin >> R >> N >> A >> B >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // get the wax-hardened cells as vector of strings
    string s;
    getline(cin, s);
    vector<string> wax_cells_s = split_strings(s, ' ');

    // convert wax-hardened cells to vector of ints
    vector<int> wax_cell_int;
    wax_cell_int.reserve(wax_cells_s.size());
    for (const string &el: wax_cells_s)
        wax_cell_int.push_back(stoi(el));

    // init the honeycomb class
    Honeycombs h(R, N, A, B, X, wax_cell_int, 0);
    h.gridCreate();

    vector<int> ss = h.gridGetNeighbours(85);

    // init the Nodes
    vector<Node> grid = h.gridBuildNodes();

    // set the honey location
    grid[h.B-1].value = 100;
    vector<Node> path = h.aStarSearch(grid[h.A-1], grid[h.B-1], grid);

    // report
    cout << "DONE in " << path.size() << " steps" << endl;
}

// definitions
vector<string> split_strings(string input, char delimiter){
    string::iterator nEnd = std::unique(input.begin(), input.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input.erase(nEnd, input.end());

    while (input[input.length() - 1] == ' ') {
        input.pop_back();
    }

    vector<string> splits;

    size_t i = 0;
    size_t pos = input.find(delimiter);

    while (pos != string::npos){
        splits.push_back(input.substr(i, pos - i));

        i = pos + 1;
        pos = input.find(delimiter, i);
    }

    splits.push_back(input.substr(i, min(pos, input.length()) - i + 1));

    return splits;
}