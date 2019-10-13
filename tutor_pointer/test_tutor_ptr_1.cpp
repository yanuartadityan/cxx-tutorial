#include <iostream>
#include <vector>
#include "training.h"


using namespace std;


void test_pointer(){
    int a = 3;
    int b = 4;

    cout << a << endl;
    cout << b << endl;
    cout << "inside function" << endl;
    try_pointer(&a, &b);
    cout << "after function" << endl;
    cout << a << endl;
    cout << b << endl;
}

void test_vector(){
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {9, 8, 7, 6, 5};
    cout << "inside function" << endl;
    try_pointer_vector(a, b);
    cout << "after function" << endl;
}


int main(){

    test_pointer();
    test_vector();

    return 0;
}