#include <iostream>
#include <vector>
#include "training.h"

// definitions

void try_pointer(int *a, int*b) {
    *a = 5;
    *b = 6;
}

void try_pointer_vector(std::vector<int> a, std::vector<int> b){
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        std::cout << *it << std::endl;
    }

    std::cout << " ----- " << std::endl;

    for(std::vector<int>::iterator it = b.begin(); it != b.end(); ++it){
        std::cout << *it << std::endl;
    }
}
