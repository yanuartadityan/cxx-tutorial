#include "quick_sort.h"
#include "../tutor_utils/tutor_utils.h"


int partition(int arr[], int low, int high)
{
    // define pivot
    int pivot = arr[high];

    // index of smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // if curr element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            
            // swap
            swap(&arr[i], &arr[j]);
        }
    }

    // swap back
    swap(&arr[i+1], &arr[high]);
    return (i+1);    
}

// the main function that implements QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, get it from partition()
        int pi = partition(arr, low, high);

        // separately sort elements, before and after
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}