#include <iostream>
#include <cstring>
#include "merge_sort.h"

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create a temp array
    int L[n1], R[n2];

    // copy data to temp arrays
    memcpy(&L[0], &arr[l], n1 * sizeof(int));
    memcpy(&R[0], &arr[m+1], n2 * sizeof(int));

    // merge the temp arrays back into arr[l..r]
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // copy remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // sama as (l+r)/2, but avoids overflow for large l and h
        int m = l+(r-l)/2;

        // sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

