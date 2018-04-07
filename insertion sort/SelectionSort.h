#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
void selectionSort(T arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    return;
}

#endif // SELECTION_SORT
