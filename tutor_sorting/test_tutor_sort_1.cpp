#include <iostream>
#include "merge_sort.h"
#include "quick_sort.h"
#include "../tutor_utils/tutor_utils.h"

using namespace std;


// main
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 14, 5, 3, 1, 24};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is: " << endl;
    printArray(arr, arr_size);

    shuffleList(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    cout << "[MergeSort] Sorted array is: " << endl;
    printArray(arr, arr_size);

    shuffleList(arr, arr_size);
    quickSort(arr, 0, arr_size - 1);
    cout << "[QuickSort] Sorted array is: " << endl;
    printArray(arr, arr_size);

    return 0;
}