#include <iostream>
#include <random>
#include "tutor_utils.h"

using namespace std;

void printArray(int A[], int size)
{
    int i;
    for (i=1; i<size; i++)
    {
        cout << A[i] << endl;
    }
}

void swap(int *a, int *b)
{
    // pass by pointer
    int t = *a;
    *a = *b;
    *b = t;
}

void shuffleList(int arr[], int n)
{
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);

        swap(&arr[i], &arr[j]);
    }
}