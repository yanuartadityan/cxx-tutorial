#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;

    q.push(0);
    q.push(2);
    q.push(5);

    cout << "printing queue with length " << q.size() << endl;

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}
