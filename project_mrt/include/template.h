//
// Created by Mirkwood Ape on 4/11/2020.
//

#ifndef CXX_TUTOR_TEMPLATE_H
#define CXX_TUTOR_TEMPLATE_H

template<typename T1, typename T2, typename T3> struct vector3 {
    T1 x;
    T2 y;
    T3 z;
};

template<typename T1, typename T2> struct vector2 {
    T1 x;
    T2 y;
};

void reverse_array(int *first, int* last);

#endif //CXX_TUTOR_TEMPLATE_H
