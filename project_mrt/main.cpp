//
// Created by Mirkwood Ape on 4/11/2020.
//

#include <iostream>
#include "include/template.h"

using namespace std;

int main(){

    int *A = new int (5);

    for (int i=0; i<5; i++)
        A[i] = i;

    reverse_array(&A[0], &A[4]);

    return 0;
}