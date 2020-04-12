//
// Created by Mirkwood Ape on 4/11/2020.
//

#include <iostream>
#include "../include/template.h"

void reverse_array(int *first, int* last){
    if (first != last){
        while (true){
            std::swap(*first, *last);
            first++;
            if (first == last){
                break;
            }
            last--;
            if (first == last){
                break;
            }
        }
    }
}
